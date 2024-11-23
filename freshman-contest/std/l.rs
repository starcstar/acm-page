use std::cmp::max;
use std::io;

fn abs<T: std::cmp::PartialOrd + std::ops::Neg<Output = T> + Default>(x: T) -> T {
    if x < T::default() {
        -x
    } else {
        x
    }
}

fn work(n: usize, k: usize, a: &Vec<i64>, b: &Vec<i64>) -> i64 {
    let mut dp = vec![vec![0i64; k + 1]; n + 1];

    for i in 1..=n {
        for z in (0..=k).rev() {
            dp[i][z] = dp[i - 1][z];
            for j in 1..=i {
                let t = z as i64 - (i - j + 1) as i64;
                if t < 0 {
                    continue;
                }
                dp[i][z] = max(dp[i][z], dp[j - 1][t as usize] + abs(b[i - 1] - a[j - 1]));
            }
        }
    }

    dp[n][k]
}

fn main() {
    let stdin = io::stdin();
    let mut input = String::new();
    stdin.read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
    
    for _ in 0..t {
        input.clear();
        stdin.read_line(&mut input).unwrap();
        let tokens: Vec<usize> = input
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let n = tokens[0];
        let k = tokens[1];

        input.clear();
        stdin.read_line(&mut input).unwrap();
        let a: Vec<i64> = input
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        input.clear();
        stdin.read_line(&mut input).unwrap();
        let b: Vec<i64> = input
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        println!("{}", work(n, k, &a, &b));
    }
}
