use rusqlite::{Connection, Result, Row};
use std::io::{stdin, stdout, Write};
use std::time::{SystemTime, UNIX_EPOCH};
use chrono::{NaiveDateTime};

#[derive(Debug)]
enum AppError {
    RusqliteError(rusqlite::Error),
    IoError(std::io::Error),
}

impl From<rusqlite::Error> for AppError {
    fn from(err: rusqlite::Error) -> Self {
        AppError::RusqliteError(err)
    }
}

impl From<std::io::Error> for AppError {
    fn from(err: std::io::Error) -> Self {
        AppError::IoError(err)
    }
}

type AppResult<T> = std::result::Result<T, AppError>;

struct User {
    id: i32,
    username: String,
    password: String,
    created_at: i64,
}

impl User {
    fn from_row(row: &Row) -> Result<Self> {
        Ok(User {
            id: row.get(0)?,
            username: row.get(1)?,
            password: row.get(2)?,
            created_at: row.get(3)?,
        })
    }
}

fn format_timestamp(timestamp: i64) -> String {
    let datetime = NaiveDateTime::from_timestamp_opt(timestamp, 0)
        .unwrap_or_else(|| NaiveDateTime::from_timestamp(0, 0));
    datetime.format("%Y-%m-%d %H:%M:%S").to_string()
}

fn print_menu() {
    println!("\n=== 用户注册系统 ===");
    println!("1. 显示所有用户"); 
    println!("2. 注册新用户");
    println!("3. 查询用户");
    println!("4. 退出");
}

fn create_table(conn: &Connection) -> Result<()> {
    conn.execute(
        "CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            created_at INTEGER NOT NULL
        )",
        [],
    )?;
    println!("表已创建或已存在");
    Ok(())
}

fn list_all_users(conn: &Connection) -> AppResult<()> {
    let mut stmt = conn.prepare("SELECT id, username, password, created_at FROM users")?;
    let user_iter = stmt.query_map([], User::from_row)?;
    println!("\n所有用户信息:");
    println!("{:<5} {:<10} {:<10} {}", "ID", "用户名", "密码", "创建时间");
    println!("----------------------------------------");
    for user_result in user_iter {
        match user_result {
            Ok(user) => {
                println!("{:<5} {:<10} {:<10} {}", 
                        user.id, user.username, user.password, format_timestamp(user.created_at));
            }
            Err(e) => return Err(AppError::RusqliteError(e)),
        }
    }
    Ok(())
}

fn create_user_interactive(conn: &Connection) -> AppResult<()> {
    let username = read_line("请输入用户名: ")?;
    let password = read_line("请输入密码: ")?;  
    let timestamp = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .unwrap()
        .as_secs() as i64;  
    match conn.execute(
        "INSERT INTO users (username, password, created_at) VALUES (?1, ?2, ?3)",
        &[&username as &str, &password as &str, &timestamp.to_string() as &str],
    ) {
        Ok(_) => println!("用户 {} 注册成功", username),
        Err(e) => println!("注册失败: {}", e),
    }
    Ok(())
}

fn query_user_interactive(conn: &Connection) -> AppResult<()> {
    let username = read_line("请输入要查询的用户名: ")?;
    if let Some(user) = query_user_by_username(&conn, &username)? {
        println!("查询结果:");
        println!("ID: {}, 用户名: {}, 密码: {}, 创建时间: {}", 
                user.id, user.username, user.password, format_timestamp(user.created_at));
    } 
    else {
        println!("未找到用户 '{}'", username);
    }
    Ok(())
}

fn query_user_by_username(conn: &Connection, username: &str) -> Result<Option<User>> {
    let mut stmt = conn.prepare("SELECT id, username, password, created_at FROM users WHERE username = ?1")?;
    let user_iter = stmt.query_map(&[&username], User::from_row)?;
    for user in user_iter {
        return Ok(Some(user?));
    }
    Ok(None)
}

fn read_line(prompt: &str) -> AppResult<String> {
    print!("{}", prompt);
    stdout().flush()?;
    let mut input = String::new();
    stdin().read_line(&mut input)?;
    Ok(input.trim().to_string())
}    

fn main() -> AppResult<()> {
    let conn = Connection::open("users.db")?;
    create_table(&conn)?;
    loop {
        print_menu();
        let choice = read_line("请输入选项: ")?;
        match choice.as_str() {
            "1" => list_all_users(&conn)?, 
            "2" => create_user_interactive(&conn)?,
            "3" => query_user_interactive(&conn)?,
            "4" => break,
            _ => println!("无效选项，请重新输入"),
        }
    }
    println!("程序已退出");
    Ok(())
}