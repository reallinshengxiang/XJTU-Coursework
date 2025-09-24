use std::io;

fn main() {
    println!("input s:");
    let mut input = String::new();
    let mut result = String::new();
    io::stdin().read_line(&mut input).expect("error");
    let s = input.trim();
    for c in s.chars() {
        if c.is_ascii_lowercase() {
            result.push(c.to_ascii_uppercase());
        } 
        else if c.is_ascii_uppercase() {
            result.push(c.to_ascii_lowercase());
        } 
        else {
            result.push(c);
        }
    }
    println!("output s:");
    println!("{}", result);
}    