use std::io;

fn main() {
    let score: u8;
    loop {
        println!("Percentage system score:");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        match input.trim().parse::<u8>() {
            Ok(num) if (0..=100).contains(&num) => {
                score = num;
                break;
            }
            Ok(_) => {
                println!("The score range is not within 0-100");
            }
            Err(_) => {
                println!("The score range is not within 0-100");
            }
        }
    }
    let five_score = match score {
        90..=100 => 5,
        80..=89 => 4,
        70..=79 => 3,
        60..=69 => 2,
        0..=59 => 1,
        _ => unreachable!(),
    };
    println!("Five point system score: {}", five_score);
}
