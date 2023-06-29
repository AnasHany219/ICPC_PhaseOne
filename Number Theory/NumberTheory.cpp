#include <bits/stdc++.h>

// Modular Arithmetic
#define mod_mul(a, b, m) 	    ((a%m)*(b%m))%m
#define mod_add(a, b, m) 	    ((a%m)+(b%m))%m
#define mod_sub(a, b, m) 	    ((a%m)-(b%m))%m

using namespace std;

const int N = 1e6+6;

// !(0 <=)     a%b     < b
//   0 <= fixmod(a, b) < b
long long fixmod(long long a, long long b){
    return (a % b + b) % b;
}

vector<int> getDivisors(int n){ // O(sqr(N))
    vector<int>res;
    int i = 1;
    for(i; i*i < n; i++){
        if(n % i == 0){
            res.push_back(i);
            res.push_back(n/i);
        }
    }
    if(i*i == n){
        res.push_back(i);
    }
    return res;
}

vector<int> getMultiples(int x, int n){ // O(N/X)
    vector<int> res;
    for(int i = x; i <= n; i += x){
        res.push_back(i);
    }
    return res;
}

bool is_Prime(int n){
    for(int i = 2; i*i <= n;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

bool isPrime[N];
void sieve(){ // O(N) -> O(N*log(log(N)))
    fill(isPrime, isPrime+N, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i < N; i++){
        if(isPrime[i]){
            for(int m = i*i; m <= N; m += i){
                isPrime[m] = false;
            }
        }
    }
}

vector<int> getPrimeFactors(long long n){ // O(sqr(N))
    vector<int> res;
    for(int i = 2; i*i <= n; i++){
        while(n % i == 0){
            n /= i;
            res.push_back(i);
        }
    }
    if(n != 1){
        res.push_back(n);
    }
    return res;
}

// a * b = LCM * GCD
long long LCM(long long a, long long b){
    return a * (b / __gcd(a, b));
}

void printVector(vector<int>v){
    for(int x : v){
        cout << x << ' ';
    }
    cout << '\n';
}

int main(){
    cout << fixmod(1, 5) << '\n';

    printVector(getDivisors(36));

    printVector(getMultiples(5, 100));

    cout << (is_Prime(37) == 1? "Prime" : "Not") << '\n';

    sieve();
    cout << (isPrime[37] == 1? "Prime" : "Not") << '\n';

    printVector(getPrimeFactors(26));
    return 0;
}
