use rand::Rng;
use std::io;

#[derive(Debug, Clone)]
enum Gesture {
    Rock,
    Scissors,
    Paper,
}

fn get_gesture(input: &str) -> Option<Gesture> {
    let trimmed = input.trim().to_lowercase();
    match trimmed.as_str() {
        "1" | "石头" | "rock" => Some(Gesture::Rock),
        "2" | "剪刀" | "scissors" => Some(Gesture::Scissors),
        "3" | "布" | "paper" => Some(Gesture::Paper),
        _ => None,
    }
}

fn judge_result(player: Gesture, computer: Gesture) -> i8 {
    match (player, computer) {
        (Gesture::Rock, Gesture::Scissors)|(Gesture::Scissors, Gesture::Paper)|(Gesture::Paper, Gesture::Rock) => 1,
        (Gesture::Rock, Gesture::Paper)|(Gesture::Scissors, Gesture::Rock)|(Gesture::Paper, Gesture::Scissors) => -1,
        _ => 0,
    }
}

fn main() {
    let mut player_wins = 0;
    let mut computer_wins = 0;
    let mut rng = rand::thread_rng();
    let mut round = 0;
    while player_wins < 2 && computer_wins < 2 {
        let player_gesture: Option<Gesture>;
        round = round + 1;
        loop {
            println!("The {} game starts, please enter your selection (1)stone, (2)scissors, (3)paper :",round);
            let mut input = String::new();
            io::stdin().read_line(&mut input).expect("error");
            if let Some(gesture) = get_gesture(&input) {
                player_gesture = Some(gesture.clone());
                println!("Your Choice: {:?}", gesture);
                break;
            } else {
                println!("Input Again!");
            }
        }
        let computer_choice = match rng.gen_range(0..3) {
            0 => Gesture::Rock,
            1 => Gesture::Scissors,
            2 => Gesture::Paper,
            _ => unreachable!(),
        };
        println!("Computer Choice: {:?}", computer_choice);
        if let Some(player_gesture) = player_gesture {
            let result = judge_result(player_gesture, computer_choice);
            match result {
                1 => {
                    player_wins += 1;
                    println!("Game {}: You won!", round);
                }
                -1 => {
                    computer_wins += 1;
                    println!("Game {}: You lose!", round);
                }
                0 => println!("Game {}: A tie!", round),
                _ => unreachable!(),
            }
        }
        if player_wins >= 2 {
            println!("You won this game with {} win {} loss!", player_wins, computer_wins);
            return;
        } else if computer_wins >= 2 {
            println!("You loss this game with {} win {} loss!", player_wins, computer_wins);
            return;
        }
    }
}    