use std::cmp::max;
use std::io;

const MOD: i64 = 998_244_353;

fn main() {
    let stdin = io::stdin();
    let mut input = String::new();
    stdin.read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();

    for _ in 0..t {
        input.clear();
        stdin.read_line(&mut input).unwrap();
        let vals: Vec<i64> = input
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let (a, b, a1, b1, a2, b2) = (vals[0], vals[1], vals[2], vals[3], vals[4], vals[5]);

        if a < a1 || b < b1 || a < a2 || b < b2 {
            println!("0");
            continue;
        }

        let mut tot = (a - a1 + 1) * (b - b1 + 1) % MOD * (a - a2 + 1) % MOD * (b - b2 + 1) % MOD;
        let mut ta = (a - a1 + 1) * (a - a2 + 1) % MOD;
        let mut tb = (b - b1 + 1) * (b - b2 + 1) % MOD;

        if a >= a1 + a2 {
            ta = (ta - ((a - a1 - a2 + 2) * (a - a1 - a2 + 1) % MOD) + MOD) % MOD;
        }
        if b >= b1 + b2 {
            tb = (tb - ((b - b1 - b2 + 2) * (b - b1 - b2 + 1) % MOD) + MOD) % MOD;
        }

        tot = (tot - ta * tb % MOD + MOD) % MOD;
        println!("{}", tot);
    }
}
