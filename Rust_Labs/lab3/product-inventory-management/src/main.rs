use anyhow::{Context, Result};
use chrono::Utc;
use dotenvy::dotenv;
use sqlx::{postgres::PgPoolOptions, PgPool};
use std::{env, io};
use uuid::Uuid;

#[derive(Debug, sqlx::FromRow)]
struct Product {
    id: Uuid,
    name: String,
    stock_quantity: i32,
    last_updated: chrono::DateTime<Utc>,
}

async fn create_products_table(pool: &PgPool) -> Result<()> {
    sqlx::query(
        r#"
        CREATE TABLE IF NOT EXISTS products (
            id UUID PRIMARY KEY,
            name TEXT NOT NULL,
            stock_quantity INTEGER NOT NULL CHECK (stock_quantity >= 0),
            last_updated TIMESTAMP WITH TIME ZONE NOT NULL
        )
        "#,
    )
    .execute(pool)
    .await
    .context("Failed to create products table")?;
    Ok(())
}

async fn add_product(pool: &PgPool, name: &str, initial_stock: i32) -> Result<Uuid> {
    let id = Uuid::new_v4();
    let now = Utc::now();    
    sqlx::query(
        r#"
        INSERT INTO products (id, name, stock_quantity, last_updated)
        VALUES ($1, $2, $3, $4)
        "#,
    )
    .bind(id)
    .bind(name)
    .bind(initial_stock)
    .bind(now)
    .execute(pool)
    .await
    .context("Failed to add product")?;
    Ok(id)
}

async fn get_product(pool: &PgPool, id: &Uuid) -> Result<Option<Product>> {
    let product = sqlx::query_as(
        r#"
        SELECT id, name, stock_quantity, last_updated
        FROM products
        WHERE id = $1
        "#,
    )
    .bind(id)
    .fetch_optional(pool)
    .await
    .context("Failed to get product")?;
    Ok(product)
}

async fn deduct_stock(pool: &PgPool, product_id: &Uuid, quantity: i32) -> Result<()> {
    if quantity <= 0 {
        return Err(anyhow::anyhow!("扣减数量必须大于0"));
    }
    let mut tx = pool.begin().await.context("Failed to begin transaction")?;
    let rows_affected = sqlx::query(
        r#"
        UPDATE products
        SET stock_quantity = stock_quantity - $1,
            last_updated = $2
        WHERE id = $3
            AND stock_quantity >= $1
        "#,
    )
    .bind(quantity)
    .bind(Utc::now())
    .bind(product_id)
    .execute(&mut *tx)
    .await
    .context("Failed to update stock")?
    .rows_affected();
    if rows_affected == 0 {
        tx.rollback().await.context("Failed to rollback transaction")?;
        return Err(anyhow::anyhow!("库存不足"));
    }
    tx.commit().await.context("Failed to commit transaction")?;
    Ok(())
}

async fn handle_add_product(pool: &PgPool) -> Result<()> {
    println!("请输入商品名称：");
    let mut name = String::new();
    io::stdin().read_line(&mut name).context("读取名称失败")?;
    println!("请输入初始库存量：");
    let mut stock = String::new();
    io::stdin().read_line(&mut stock).context("读取库存失败")?;
    let stock: i32 = stock.trim().parse().context("无效的库存数字")?;
    let id = add_product(pool, name.trim(), stock).await?;
    println!("商品添加成功！ID: {}", id);
    Ok(())
}

async fn handle_update_product(pool: &PgPool) -> Result<()> {
    println!("请输入要更新的商品ID：");
    let mut id_input = String::new();
    io::stdin().read_line(&mut id_input).context("读取ID失败")?;
    let id = Uuid::parse_str(id_input.trim()).context("无效的UUID格式")?;
    println!("请输入新的商品名称：");
    let mut new_name = String::new();
    io::stdin().read_line(&mut new_name).context("读取名称失败")?;
    update_product_name(pool, &id, new_name.trim()).await?;
    println!("商品名称更新成功！");
    Ok(())
}

async fn handle_deduct_stock(pool: &PgPool) -> Result<()> {
    println!("请输入商品ID：");
    let mut id_input = String::new();
    io::stdin().read_line(&mut id_input).context("读取ID失败")?;
    let id = Uuid::parse_str(id_input.trim()).context("无效的UUID格式")?;
    println!("请输入购买数量：");
    let mut quantity = String::new();
    io::stdin().read_line(&mut quantity).context("读取数量失败")?;
    let quantity: i32 = quantity.trim().parse().context("无效的数量数字")?;
    match deduct_stock(pool, &id, quantity).await {
        Ok(_) => println!("成功扣减库存 {} 件", quantity),
        Err(e) => println!("操作失败: {}", e),
    }
    Ok(())
}

async fn handle_get_product(pool: &PgPool) -> Result<()> {
    println!("请输入商品ID：");
    let mut id_input = String::new();
    io::stdin().read_line(&mut id_input).context("读取ID失败")?;
    let id = Uuid::parse_str(id_input.trim()).context("无效的UUID格式")?;
    if let Some(product) = get_product(pool, &id).await? {
        println!("\n=== 商品信息 ===");
        println!("ID: {}", product.id);
        println!("名称: {}", product.name);
        println!("库存量: {}", product.stock_quantity);
        println!("最后更新时间: {}", product.last_updated);
    } else {
        println!("未找到该商品");
    }
    Ok(())
}

async fn handle_low_stock(pool: &PgPool) -> Result<()> {
    let products = list_low_stock_products(pool).await?;
    if products.is_empty() {
        println!("当前没有低库存商品");
        return Ok(());
    }
    println!("\n=== 低库存商品列表 ===");
    for product in products {
        println!(
            "ID: {}, 名称: {}, 库存: {}",
            product.id, product.name, product.stock_quantity
        );
    }
    Ok(())
}

async fn update_product_name(pool: &PgPool, product_id: &Uuid, new_name: &str) -> Result<()> {
    sqlx::query(
        r#"
        UPDATE products
        SET name = $1, last_updated = $2
        WHERE id = $3
        "#,
    )
    .bind(new_name)
    .bind(Utc::now())
    .bind(product_id)
    .execute(pool)
    .await
    .context("更新商品名称失败")?;
    Ok(())
}

async fn list_low_stock_products(pool: &PgPool) -> Result<Vec<Product>> {
    let products = sqlx::query_as::<_, Product>(
        r#"
        SELECT id, name, stock_quantity, last_updated
        FROM products
        WHERE stock_quantity < 10
        ORDER BY stock_quantity ASC
        "#,
    )
    .fetch_all(pool)
    .await
    .context("查询低库存商品失败")?;
    Ok(products)
}

async fn list_all_products(pool: &PgPool) -> Result<Vec<Product>> {
    let products = sqlx::query_as::<_, Product>(
        r#"
        SELECT id, name, stock_quantity, last_updated
        FROM products
        ORDER BY last_updated DESC
        "#,
    )
    .fetch_all(pool)
    .await
    .context("查询所有商品失败")?;
    
    Ok(products)
}

async fn handle_list_all_products(pool: &PgPool) -> Result<()> {
    let products = list_all_products(pool).await?;
    if products.is_empty() {
        println!("当前没有商品记录");
        return Ok(());
    }
    println!("\n=== 所有商品列表 ===");
    println!("{:<36} | {:<20} | {:<6} | {}", "ID", "名称", "库存", "最后更新时间");
    println!("{}", "-".repeat(90));
    for product in products {
        println!(
            "{:<36} | {:<20} | {:<6} | {}",
            product.id,
            product.name,
            product.stock_quantity,
            product.last_updated.format("%Y-%m-%d %H:%M:%S")
        );
    }
    Ok(())
}

#[tokio::main]
async fn main() -> Result<()> {
    dotenv().ok();
    let database_url = env::var("DATABASE_URL").context("DATABASE_URL环境变量未设置")?;
    let pool = PgPoolOptions::new()
        .max_connections(5)
        .connect(&database_url)
        .await
        .context("Failed to connect to database")?;
    create_products_table(&pool).await?;
    loop {
        println!("\n=== 库存管理系统 ===");
        println!("1. 添加商品");
        println!("2. 更新商品名称");
        println!("3. 购买商品（扣减库存）");
        println!("4. 查询商品信息");
        println!("5. 查询低库存商品（<10件）");
        println!("6. 查看全部商品信息");
        println!("7. 退出系统");
        println!("请输入选项：");
        let mut choice = String::new();
        io::stdin()
            .read_line(&mut choice)
            .context("读取输入失败")?;
        match choice.trim() {
            "1" => handle_add_product(&pool).await?,
            "2" => handle_update_product(&pool).await?,
            "3" => handle_deduct_stock(&pool).await?,
            "4" => handle_get_product(&pool).await?,
            "5" => handle_low_stock(&pool).await?,
            "6" => handle_list_all_products(&pool).await?,
            "7" => {
                println!("感谢使用，再见！");
                break;
            }
            _ => println!("无效选项，请重新输入"),
        }
    }
    Ok(())
}