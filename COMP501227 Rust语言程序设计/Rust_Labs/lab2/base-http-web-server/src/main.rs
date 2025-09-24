use actix_web::{get, App, HttpResponse, HttpServer, Responder};

#[get("/")]
async fn root() -> impl Responder {
    HttpResponse::Ok().body("Welcome to the root page!")
}

#[get("/hello")]
async fn hello() -> impl Responder {
    HttpResponse::Ok().body("Hello, Rust!")
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
           .service(root)
           .service(hello)
    })
   .bind("127.0.0.1:8888")?
   .run()
   .await
}