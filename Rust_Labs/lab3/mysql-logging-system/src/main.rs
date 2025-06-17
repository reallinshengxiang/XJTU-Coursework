use mysql::*;
use mysql::prelude::*;
use chrono::{Local, NaiveDateTime, Duration};
use std::io;

type Result<T> = std::result::Result<T, Box<dyn std::error::Error>>;
type LogRecord = (i32, String, String, String);

fn main() -> Result<()> {
    let url = "mysql://root:Password@2025!@localhost:3306/mydatabase";
    let pool = Pool::new(url)?;
    create_log_table(&pool)?;
    loop {
        println!("\n=== 日志管理系统 ===");
        println!("1. 写入日志");
        println!("2. 查询最近24小时ERROR日志");
        println!("3. 查询最近24小时所有日志");
        println!("4. 退出系统");
        print!("请选择操作：");
        let choice = read_line()?;
        match choice.trim() {
            "1" => write_log_interactive(&pool)?,
            "2" => query_error_logs_interactive(&pool)?,
            "3" => query_all_logs_interactive(&pool)?,
            "4" => {
                println!("退出成功！");
                break;
            }
            _ => println!("无效选项，请重新输入"),
        }
    }
    Ok(())
}

fn create_log_table(pool: &Pool) -> Result<()> {
    let mut conn = pool.get_conn()?;
    conn.query_drop(
        r"CREATE TABLE IF NOT EXISTS app_logs (
            log_id INT AUTO_INCREMENT PRIMARY KEY,
            log_level ENUM('DEBUG', 'INFO', 'WARN', 'ERROR', 'FATAL') NOT NULL,
            content TEXT NOT NULL,
            created_at DATETIME NOT NULL
        )"
    )?;
    Ok(())
}

fn write_log(pool: &Pool, level: &str, content: &str, timestamp: &str) -> Result<()> {
    let mut conn = pool.get_conn()?;
    let naive_time = NaiveDateTime::parse_from_str(timestamp, "%Y-%m-%d %H:%M:%S")?;
    let timestamp_str = naive_time.format("%Y-%m-%d %H:%M:%S").to_string();
    conn.exec_drop(
        r"INSERT INTO app_logs (log_level, content, created_at)
        VALUES (:level, :content, :timestamp)",
        params! {
            "level" => level,
            "content" => content,
            "timestamp" => timestamp_str
        }
    )?;
    Ok(())
}

fn write_log_interactive(pool: &Pool) -> Result<()> {
    println!("\n=== 写入新日志 ===");
    let level = loop {
        println!("请输入日志级别 (DEBUG/INFO/WARN/ERROR/FATAL):");
        let input = read_line()?.trim().to_uppercase();
        if ["DEBUG", "INFO", "WARN", "ERROR", "FATAL"].contains(&input.as_str()) {
            break input;
        }
        println!("无效的日志级别，请重新输入");
    };
    let timestamp = loop {
        println!("请输入日志时间 (格式: YYYY-MM-DD HH:MM:SS):");
        let input = read_line()?;
        match NaiveDateTime::parse_from_str(&input, "%Y-%m-%d %H:%M:%S") {
            Ok(_) => break input,
            Err(_) => println!("时间格式错误，请参考示例：2024-07-30 14:30:00"),
        }
    };
    println!("请输入日志内容:");
    let content = read_line()?;
    write_log(pool, &level, &content, &timestamp)?;
    println!("日志写入成功！");
    Ok(())
}

fn query_recent_logs(pool: &Pool, level_filter: Option<&str>) -> Result<Vec<LogRecord>> {
    let mut conn = pool.get_conn()?;
    let time_threshold = Local::now()
        .checked_sub_signed(Duration::hours(24))
        .unwrap()
        .format("%Y-%m-%d %H:%M:%S")
        .to_string();
    let mut query = r"
        SELECT log_id, log_level, content, 
        DATE_FORMAT(created_at, '%Y-%m-%d %H:%i:%s') 
        FROM app_logs 
        WHERE created_at >= :time_threshold
    ".to_string();
    let params = match level_filter {
        Some(level) => {
            query.push_str(" AND log_level = :log_level");
            params! {
                "time_threshold" => time_threshold,
                "log_level" => level
            }
        },
        None => {
            params! {
                "time_threshold" => time_threshold
            }
        }
    };
    let logs = conn.exec_map(
        &query,
        params,
        |(log_id, log_level, content, created_at)| {
            (log_id, log_level, content, created_at)
        }
    )?;
    Ok(logs)
}

fn query_error_logs_interactive(pool: &Pool) -> Result<()> {
    let logs = query_recent_logs(pool, Some("ERROR"))?;
    print_logs("最近24小时ERROR日志", &logs);
    Ok(())
}

fn query_all_logs_interactive(pool: &Pool) -> Result<()> {
    let logs = query_recent_logs(pool, None)?;
    print_logs("最近24小时所有日志", &logs);
    Ok(())
}

fn print_logs(title: &str, logs: &[LogRecord]) {
    println!("\n=== {} ===", title);
    if logs.is_empty() {
        println!("没有找到相关日志");
        return;
    }
    println!("{:<6} | {:<8} | {:<19} | {}", "ID", "级别", "时间", "内容");
    println!("{}", "-".repeat(80));
    for (id, level, content, time) in logs {
        println!("{:<6} | {:<8} | {} | {}", id, level, time, content);
    }
}

fn read_line() -> io::Result<String> {
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;
    Ok(input.trim().to_string())
}