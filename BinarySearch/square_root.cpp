#include<iostream>
using namespace std;

double sqrt(double x){
    double l = 0, r = x, mid;
    while(abs(l - r) > 1e-7){
        mid = (l + r) / 2;
        if(mid * mid > x) r = mid;
        else l = mid;
    }
    return l;
}

int main(){
    double x;
    cin >> x;
    cout << "squrt(" << x << ") = " << sqrt(x);
    return 0;
}
