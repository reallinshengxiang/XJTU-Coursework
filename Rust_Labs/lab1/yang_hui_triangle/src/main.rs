use std::io;

fn main() {
    println!("input n:");
    let mut input = String::new();
    let mut triangle: Vec<Vec<u64>> = Vec::new();
    io::stdin().read_line(&mut input).expect("error");
    let n: usize = input.trim().parse().expect("error");
    for i in 0..n {
        let mut row = vec![1; i+1];
        for j in 1..i {
            row[j] = triangle[i-1][j-1]+triangle[i-1][j];
        }
        triangle.push(row);
    }
    for row in triangle {
        for num in row {
            print!("{} ", num);
        }
        println!();
    }
}    
