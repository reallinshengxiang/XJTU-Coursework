use actix_web::{get, post, web, App, HttpResponse, HttpServer, Responder};
use serde::{Deserialize, Serialize};
use std::sync::Mutex;

#[derive(Debug, Serialize, Deserialize, Clone)]
struct Book {
    id: u32,
    title: String,
    author: String,
}

struct AppState {
    books: Mutex<Vec<Book>>,
    next_id: Mutex<u32>,
}

impl AppState {
    fn new() -> Self {
        AppState {
            books: Mutex::new(Vec::new()),
            next_id: Mutex::new(1),
        }
    }
}

#[derive(Debug, Deserialize)]
struct NewBookRequest {
    title: String,
    author: String,
}

#[get("/")]
async fn index() -> impl Responder {
    HttpResponse::Ok()
        .content_type("text/html; charset=utf-8")
        .body(
            r#"
            <!DOCTYPE html>
            <html>
            <head>
                <title>图书管理系统</title>
                <style>
                    body { font-family: Arial, sans-serif; margin: 40px; }
                    form { margin: 20px 0; padding: 20px; border: 1px solid #ddd; border-radius: 5px; }
                    input, button { padding: 8px; margin: 5px 0; }
                    table { border-collapse: collapse; width: 100%; }
                    th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }
                    th { background-color: #f2f2f2; }
                </style>
            </head>
            <body>
                <h1>图书管理系统</h1>
                
                <form id="addBookForm">
                    <div>
                        <label for="title">书名:</label>
                        <input type="text" id="title" name="title" required>
                    </div>
                    <div>
                        <label for="author">作者:</label>
                        <input type="text" id="author" name="author" required>
                    </div>
                    <button type="submit">添加书籍</button>
                </form>
                
                <h2>书籍列表</h2>
                <div id="bookList">加载中...</div>
                
                <script>
                    // 获取书籍列表
                    async function fetchBooks() {
                        const response = await fetch('/books');
                        const books = await response.json();
                        
                        let html = '<table><tr><th>ID</th><th>书名</th><th>作者</th></tr>';
                        books.forEach(book => {
                            html += `<tr><td>${book.id}</td><td>${book.title}</td><td>${book.author}</td></tr>`;
                        });
                        html += '</table>';
                        
                        document.getElementById('bookList').innerHTML = html;
                    }
                    
                    // 添加新书
                    document.getElementById('addBookForm').addEventListener('submit', async (e) => {
                        e.preventDefault();
                        
                        const title = document.getElementById('title').value;
                        const author = document.getElementById('author').value;
                        
                        try {
                            const response = await fetch('/books', {
                                method: 'POST',
                                headers: {
                                    'Content-Type': 'application/json',
                                },
                                body: JSON.stringify({ title, author }),
                            });
                            
                            if (response.ok) {
                                alert('书籍添加成功!');
                                document.getElementById('addBookForm').reset();
                                fetchBooks(); // 刷新列表
                            } else {
                                alert('添加失败: ' + response.status);
                            }
                        } catch (error) {
                            alert('错误: ' + error);
                        }
                    });
                    
                    // 初始加载
                    fetchBooks();
                </script>
            </body>
            </html>
            "#,
        )
}

#[get("/books")]
async fn get_books(data: web::Data<AppState>) -> impl Responder {
    let books = data.books.lock().unwrap();
    HttpResponse::Ok().json(&*books)
}

#[post("/books")]
async fn add_book(
    data: web::Data<AppState>,
    book_req: web::Json<NewBookRequest>,
) -> impl Responder {
    let mut books = data.books.lock().unwrap();
    let mut next_id = data.next_id.lock().unwrap();
    
    let new_book = Book {
        id: *next_id,
        title: book_req.title.clone(),
        author: book_req.author.clone(),
    };
    
    books.push(new_book.clone());
    *next_id += 1;
    
    HttpResponse::Created().json(new_book)
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    let app_state = web::Data::new(AppState::new());
    {
        let mut books = app_state.books.lock().unwrap();
        books.push(Book {
            id: 0,
            title: "The Rust Programming Language".to_string(),
            author: "Steve Klabnik and Carol Nichols".to_string(),
        });
        *app_state.next_id.lock().unwrap() = 1;
    }

    println!("服务器运行在 http://127.0.0.1:8888");
    println!("请访问 http://127.0.0.1:8888 使用图书管理系统");

    HttpServer::new(move || {
        App::new()
            .app_data(app_state.clone())
            .service(index)
            .service(get_books)
            .service(add_book)
    })
    .bind("127.0.0.1:8888")?
    .run()
    .await
}