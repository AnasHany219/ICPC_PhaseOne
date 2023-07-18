#include <bits/stdc++.h>

using namespace std;

#define  ON(n, k)       (n | (1 << k))
#define  power2(k)      (1 << k)
#define  OFF(n, k)      (n & ~(1 << k))
#define  isON(n, k)     ((n >> k) & 1)

string getBinary(int x){
    string res = "";
    for(int i = 31; i >= 0; i--)
        res += to_string(isON(x, i));
    return res;
}

int main(){
    // The bitwise AND (&)
    // Constant time optimization
    // 1 & bit = bit # 0 & bit -> 0
    if(5 & 1)   cout << "odd" << '\n';  // 5 -> 101 & 001 -> 001 -> odd
    else        cout << "even"<< '\n';  // 6 -> 110 & 001 -> 000 -> even

    // The bitwise OR (|)
    // Constant time optimization
    // 1 & bit = 1 # 0 & bit -> bit
    cout << (5 | 6) << '\n'; // 101 | 110 = 111 = 7

    // The Bitwise NOT (~)
    // Constant time optimization
    // ~n = -(n + 1) -> ~5 = -(5 + 1) = -6
    cout << ~5 << '\n';

    // Convert from binary to decimal (0b + binart number)
    cout << 0b10000000000 << '\n';

    // The bitwise shift right (>>)
    // Constant time optimization
    // equal division by 2
    cout << (5 >> 1) << '\n';   // 5 >> 1 = 101 >> 1 = 10 = 2

    // The bitwise shift left (<<)
    // Constant time optimization
    // equal multiply by 2
    // 2 power n -> (1 << n) -> pow(2, 10) == (1 << 10)
    cout << (5 << 1) << ' '     // 5 << 1 = 101 >> 1 = 1010 = 10
         << (1 << 10) << '\n';  // 1 << 10 = 10000000000 = 1024

    // The bitwise XOR (^)
    // Constant time optimization
    cout << (5 ^ 7) << '\n'; // 101 ^ 111 = 010

    return 0;
}
