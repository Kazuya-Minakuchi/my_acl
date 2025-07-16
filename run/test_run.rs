use std::io::{self, Write};
use std::collections::*;
use std::cmp::*;

// 型エイリアス
type ll = i64;
type ull = u64;
type vi = Vec<i32>;
type vll = Vec<i64>;
type vb = Vec<bool>;
type vvi = Vec<Vec<i32>>;
type vvll = Vec<Vec<i64>>;

// 定数
const INF: i32 = 2147483647;
const MOD: i64 = 1_000_000_007;
const LINF: i64 = 9223372036854775807;

// マクロ

macro_rules! dump {
    ($x:expr) => {
        eprintln!("{} = {:?}", stringify!($x), $x);
    };
}

macro_rules! yes {
    ($n:expr) => {
        println!("{}", if $n { "Yes" } else { "No" });
    };
}

macro_rules! YES {
    ($n:expr) => {
        println!("{}", if $n { "YES" } else { "NO" });
    };
}

macro_rules! scout {
    ($x:expr) => {
        print!("{}", $x);
    };
}

macro_rules! cout {
    ($x:expr) => {
        println!("{}", $x);
    };
}

macro_rules! scerr {
    ($x:expr) => {
        eprint!("{}", $x);
    };
}

macro_rules! cerr {
    ($x:expr) => {
        eprintln!("{}", $x);
    };
}

macro_rules! veccout {
    ($x:expr) => {
        for y in &$x {
            print!("{} ", y);
        }
        println!();
    };
}

macro_rules! veccerr {
    ($x:expr) => {
        for y in &$x {
            eprint!("{} ", y);
        }
        eprintln!();
    };
}

// 入力用のマクロ
macro_rules! input {
    () => {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    };
    ($t:ty) => {
        input!().parse::<$t>().unwrap()
    };
}

macro_rules! input_vec {
    ($t:ty) => {
        input!()
            .split_whitespace()
            .map(|s| s.parse::<$t>().unwrap())
            .collect::<Vec<$t>>()
    };
}

// より簡潔な入力処理
macro_rules! read {
    ($t:ty) => {
        {
            let mut line = String::new();
            io::stdin().read_line(&mut line).unwrap();
            line.trim().parse::<$t>().unwrap()
        }
    };
    ($($t:ty),+) => {
        {
            let mut line = String::new();
            io::stdin().read_line(&mut line).unwrap();
            let mut iter = line.split_whitespace();
            ($(iter.next().unwrap().parse::<$t>().unwrap()),+)
        }
    };
}

macro_rules! read_vec {
    ($t:ty) => {
        {
            let mut line = String::new();
            io::stdin().read_line(&mut line).unwrap();
            line.split_whitespace()
                .map(|s| s.parse::<$t>().unwrap())
                .collect::<Vec<$t>>()
        }
    };
}

// 便利な関数
fn chmax<T: PartialOrd>(a: &mut T, b: T) -> bool {
    if *a < b {
        *a = b;
        true
    } else {
        false
    }
}

fn chmin<T: PartialOrd>(a: &mut T, b: T) -> bool {
    if *a > b {
        *a = b;
        true
    } else {
        false
    }
}

fn main() {
    // 簡潔な入力処理
    let (n, l, r) = read!(i32, i32, i32);
    
    // デバッグ出力
    dump!(n);
    dump!(l);
    dump!(r);
    
    let mut x = Vec::new();
    let mut y = Vec::new();
    
    for _ in 0..n {
        let (xi, yi) = read!(i32, i32);
        x.push(xi);
        y.push(yi);
    }
    
    // デバッグ出力
    // veccerr!(x);
    // veccerr!(y);
    
    let mut ans = 0;
    for i in 0..n as usize {
        if x[i] <= l && r <= y[i] {
            ans += 1;
        }
    }
    cout!(ans);
}
