use std::io;

fn main() {
    let n: u32;
    loop {
        println!("input n:");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("error");
        match input.trim().parse::<u32>() {
            Ok(num) => {
                n = num;
                break;
            }
            Err(_) => {
                eprintln!("input error");
            }
        }
    }
    let mut ans: f64 = 0.0;
    for i in 1..=n {
        ans += 1.0 / ((i * i) as f64);
    }
    println!("{}", ans);
}
