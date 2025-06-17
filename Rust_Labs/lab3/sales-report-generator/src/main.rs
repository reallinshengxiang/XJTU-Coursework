use mysql::*;
use mysql::prelude::*;
use serde::Serialize;
use std::io::{self, Write};
use chrono::NaiveDateTime;

#[derive(Debug, Serialize)]
struct DailySalesReport {
    report_date: String,
    total_orders: i64,
    total_sales: f64,
    average_order_value: f64,
}

#[derive(Debug)]
struct Order {
    id: i32,
    order_date: String,
    total_amount: f64,
}

fn create_orders_table(pool: &Pool) -> mysql::Result<()> {
    let mut conn = pool.get_conn()?;
    let create_table_sql = r"
        CREATE TABLE IF NOT EXISTS orders (
            id INT AUTO_INCREMENT PRIMARY KEY,
            order_date DATETIME NOT NULL,
            total_amount DECIMAL(10, 2) NOT NULL
        )
    ";
    conn.query_drop(create_table_sql)?;
    insert_sample_data(&mut conn)?;
    Ok(())
}

fn insert_sample_data(conn: &mut PooledConn) -> mysql::Result<()> {
    let count: Option<u64> = conn.query_first("SELECT COUNT(*) FROM orders")?;
    if count.unwrap_or(0) == 0 {
        let insert_sql = r"
            INSERT INTO orders (order_date, total_amount) VALUES
            ('2023-01-01 10:00:00', 150.50),
            ('2023-01-01 14:30:00', 200.00),
            ('2023-01-02 09:15:00', 75.25),
            ('2023-01-02 16:45:00', 120.75)
        ";
        
        conn.query_drop(insert_sql)?;
        println!("插入了示例数据");
    }
    Ok(())
}

fn create_sales_view(pool: &Pool) -> mysql::Result<()> {
    let mut conn = pool.get_conn()?;    
    let view_sql = r"
        CREATE OR REPLACE VIEW daily_sales_view AS
        SELECT
            DATE(order_date) AS report_date,
            COUNT(*) AS total_orders,
            SUM(total_amount) AS total_sales,
            SUM(total_amount) / COUNT(*) AS average_order_value
        FROM orders
        GROUP BY report_date;
    ";
    conn.query_drop(view_sql)?;
    Ok(())
}

fn get_sales_report(
    pool: &Pool,
    start_date: &str,
    end_date: &str,
) -> mysql::Result<Vec<DailySalesReport>> {
    let mut conn = pool.get_conn()?;
    let query = r"
        SELECT 
            CAST(report_date AS CHAR) AS report_date,
            total_orders,
            CAST(total_sales AS DOUBLE) AS total_sales,
            CAST(average_order_value AS DOUBLE) AS average_order_value
        FROM daily_sales_view
        WHERE report_date BETWEEN ? AND ?
        ORDER BY report_date ASC
    ";
    let results = conn.exec_map(
        query,
        (start_date, end_date),
        |(report_date, total_orders, total_sales, average_order_value)| DailySalesReport {
            report_date,
            total_orders,
            total_sales,
            average_order_value,
        },
    )?;
    Ok(results)
}

fn insert_order(pool: &Pool, order_date: &str, total_amount: f64) -> mysql::Result<()> {
    let mut conn = pool.get_conn()?;    
    let query = r"
        INSERT INTO orders (order_date, total_amount)
        VALUES (?, ?)
    ";
    conn.exec_drop(query, (order_date, total_amount))?;
    println!("订单插入成功");
    Ok(())
}

fn query_orders(pool: &Pool) -> mysql::Result<Vec<Order>> {
    let mut conn = pool.get_conn()?;    
    let query = r"
        SELECT id, CAST(order_date AS CHAR) AS order_date, CAST(total_amount AS DOUBLE) AS total_amount
        FROM orders
        ORDER BY order_date ASC
    ";
    let results = conn.query_map(
        query,
        |(id, order_date, total_amount)| Order {
            id,
            order_date,
            total_amount,
        },
    )?;
    Ok(results)
}

fn delete_order(pool: &Pool, order_id: i32) -> mysql::Result<()> {
    let mut conn = pool.get_conn()?;    
    let query = r"
        DELETE FROM orders
        WHERE id = ?
    ";
    conn.exec_drop(query, (order_id,))?;
    let affected = conn.affected_rows();
    if affected > 0 {
        println!("订单删除成功");
    } else {
        println!("未找到订单 ID: {}", order_id);
    }
    Ok(())
}

fn display_menu() {
    println!("\n=== 订单管理系统 ===");
    println!("1. 添加订单");
    println!("2. 查询所有订单");
    println!("3. 删除订单");
    println!("4. 查看销售统计");
    println!("5. 退出");
    print!("请输入选项 (1-5): ");
    io::stdout().flush().unwrap();
}

fn get_input() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("读取输入失败");
    input.trim().to_string()
}

fn print_sales_report_as_table(reports: &[DailySalesReport]) {
    if reports.is_empty() {
        println!("没有销售数据可显示");
        return;
    }    
    println!("+------------+--------------+-------------+----------------------+");
    println!("| 日期       | 订单总数     | 销售总额    | 平均订单价值         |");
    println!("+------------+--------------+-------------+----------------------+");
    for report in reports {
        println!(
            "| {:<10} | {:<12} | {:<11.2} | {:<18.2} |",
            report.report_date,
            report.total_orders,
            report.total_sales,
            report.average_order_value
        );
    }
    println!("+------------+--------------+-------------+----------------------+");
    let total_orders: i64 = reports.iter().map(|r| r.total_orders).sum();
    let total_sales: f64 = reports.iter().map(|r| r.total_sales).sum(); 
    println!("| 总计       | {:<12} | {:<11.2} |                      |",
             total_orders, total_sales);
    println!("+------------+--------------+-------------+----------------------+");
}

fn main() -> mysql::Result<()> {
    let url = "mysql://root:Password@2025!@localhost:3306/mydatabase";
    let pool = Pool::new(url)?;
    create_orders_table(&pool)?;
    create_sales_view(&pool)?;
    loop {
        display_menu();
        let choice = get_input();
        match choice.as_str() {
            "1" => {
                print!("请输入订单日期 (YYYY-MM-DD HH:MM:SS): ");
                io::stdout().flush().unwrap();
                let order_date = get_input();
                print!("请输入订单金额: ");
                io::stdout().flush().unwrap();
                let amount_input = get_input();
                if let Ok(total_amount) = amount_input.parse::<f64>() {
                    if let Err(e) = insert_order(&pool, &order_date, total_amount) {
                        println!("插入订单失败: {}", e);
                    }
                } else {
                    println!("无效的金额格式");
                }
            }
            "2" => {
                match query_orders(&pool) {
                    Ok(orders) => {
                        if orders.is_empty() {
                            println!("没有订单记录");
                        } else {
                            println!("\n所有订单:");
                            println!("+----+---------------------+--------+");
                            println!("| ID | 日期                | 金额   |");
                            println!("+----+---------------------+--------+");
                            for order in orders {
                                println!(
                                    "| {:<2} | {:<19} | {:<6.2} |",
                                    order.id, order.order_date, order.total_amount
                                );
                            }
                            println!("+----+---------------------+--------+");
                        }
                    }
                    Err(e) => println!("查询订单失败: {}", e),
                }
            }
            "3" => {
                print!("请输入要删除的订单 ID: ");
                io::stdout().flush().unwrap();
                let id_input = get_input();
                if let Ok(order_id) = id_input.parse::<i32>() {
                    if let Err(e) = delete_order(&pool, order_id) {
                        println!("删除订单失败: {}", e);
                    }
                } else {
                    println!("无效的订单 ID");
                }
            }
            "4" => {
                print!("请输入开始日期 (YYYY-MM-DD): ");
                io::stdout().flush().unwrap();
                let start_date = get_input();
                print!("请输入结束日期 (YYYY-MM-DD): ");
                io::stdout().flush().unwrap();
                let end_date = get_input();
                match get_sales_report(&pool, &start_date, &end_date) {
                    Ok(reports) => {
                        if reports.is_empty() {
                            println!("指定日期范围内没有销售数据");
                        } else {
                            println!("\n销售统计:");
                            print_sales_report_as_table(&reports);
                        }
                    }
                    Err(e) => println!("查询统计失败: {}", e),
                }
            }
            "5" => {
                println!("退出程序");
                break;
            }
            _ => println!("无效选项，请输入 1-5"),
        }
    }
    Ok(())
}