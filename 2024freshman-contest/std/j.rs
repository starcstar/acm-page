use std::io::{self, BufRead};

fn work(a: &Vec<i64>, n: usize, x: i64) -> i64 {
    let mut sum = 0;
    let mut s = 0;
    for i in 0..n {
        if s >= x {
            sum += 1;
            s = 0;
        }
        s += a[i];
    }
    if s >= x {
        sum += 1;
    }
    sum
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let first_line = lines.next().unwrap().unwrap();
    let nums: Vec<i64> = first_line
        .split_whitespace()
        .map(|x| x.parse::<i64>().unwrap())
        .collect();
    let n = nums[0] as usize;
    let m = nums[1];

    let second_line = lines.next().unwrap().unwrap();
    let mut a: Vec<i64> = second_line
        .split_whitespace()
        .map(|x| x.parse::<i64>().unwrap())
        .collect();

    let mut l = 0;
    let mut r = a.iter().sum::<i64>();

    while l < r {
        let mid = (l + r + 1) / 2;
        if work(&a, n, mid) >= m {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    println!("{}", l);
}
