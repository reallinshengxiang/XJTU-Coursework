use actix_web::{get, App, HttpResponse, HttpServer, Responder};
use actix_files::Files;

#[get("/")]
async fn root() -> impl Responder {
    HttpResponse::Ok()
        .content_type("text/html; charset=utf-8")
        .body(
            r#"
            <!DOCTYPE html>
            <html>
            <head>
                <title>Welcome</title>
                <link rel="stylesheet" href="/static/style.css">
            </head>
            <body>
                <h1>Welcome to my Rust Web Server!</h1>
                <p>This is a custom welcome page served by Actix-Web.</p>
                <p>Visit the <a href="/hello">hello page</a> or check out our 
                <a href="/static/sample.html">Static Page</a>.</p>
            </body>
            </html>
            "#
        )
}

#[get("/hello")]
async fn hello() -> impl Responder {
    HttpResponse::Ok().body("Hello, Rust!")
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    let static_dir = "./static";
    if !std::path::Path::new(static_dir).exists() {
        std::fs::create_dir(static_dir)?;
        println!("Created static directory: {}", static_dir);
    }

    let sample_html = r#"<!DOCTYPE html>
    <html>
    <head>
        <title>Sample</title>
        <style>
            body { 
                font-family: Arial, sans-serif; 
                margin: 40px; 
                background-color: #f5f5f5; 
                text-align: center;
            }
            .credit {
                margin: 20px;
                font-style: italic;
                color: #666;
            }
            .sphere {
                width: 100px;
                height: 100px;
                margin: 50px auto;
                border-radius: 50%;
                background: linear-gradient(45deg,rgb(49, 67, 227),rgb(187, 198, 215));
                animation: rotate 3s linear infinite;
                box-shadow: 0 0 20px rgba(0,0,0,0.2);
            }
            @keyframes rotate {
                from { transform: rotate(0deg); }
                to { transform: rotate(360deg); }
            }
        </style>
    </head>
    <body>
        <h1>Static Page</h1>
        <div class="sphere"></div>
        <div class="credit">Build by Shengxiang Lin</div>
    </body>
    </html>"#;

    std::fs::write(format!("{}/sample.html", static_dir), sample_html)?;
    println!("Created sample.html in static directory.");

    HttpServer::new(|| {
        App::new()
            .service(root)
            .service(hello)
            .service(Files::new("/static", "./static").show_files_listing())
    })
    .bind("127.0.0.1:8888")?
    .run()
    .await
}