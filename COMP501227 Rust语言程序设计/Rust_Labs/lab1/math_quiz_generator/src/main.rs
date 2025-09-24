use rand::Rng;
use std::cmp::min;
use std::cmp::max;

fn main() {
    let mut rng = rand::thread_rng();
    let mut num1 = rng.gen_range(1..=20);
    let mut num2 = rng.gen_range(1..=20);
    let operator = rng.gen_range(0..=3);
    match operator {
        0 => {
            println!("question: {} + {} = ?", num1, num2);
            println!("answeer:  {}", num1 + num2);
        }
        1 => {
            while num1 == num2 {
                num1 = rng.gen_range(1..=20);
                num2 = rng.gen_range(1..=20);
                num1 = max(num1, num2);
                num2 = min(num1, num2);
            }
            println!("question: {} - {} = ?", num1, num2);
            println!("answeer:  {}", num1 - num2);

        }
        2 => {
            println!("question: {} * {} = ?", num1, num2);
            println!("answeer:  {}", num1 * num2);
        }
        3 => {
            num1 = max(num1, num2);
            num2 = min(num1, num2);
            while num1 % num2 != 0 || num1 == num2 {
                num1 = rng.gen_range(1..=20);
                num2 = rng.gen_range(1..=20);
                num1 = max(num1, num2);
                num2 = min(num1, num2);
            }
            println!("question: {} ÷ {} = ?", num1, num2);
            println!("answeer:  {}", num1 / num2);
        }
        _ => unreachable!(),
    }
}