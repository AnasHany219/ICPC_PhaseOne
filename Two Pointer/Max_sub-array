#include <iostream>

using namespace std;
// U have an array and need to find a max sub-array
int main(){
    int arr[] = {0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int pre[size+1] = {};
    int length = 3;

    for(int i = 0; i < size; i++){
        pre[i+1] = pre[i] + arr[i];
    }
    int l = 0, r = length-1;
    int sum = pre[r+1] - pre[l];
    int  mx = pre[r+1] - pre[l];
    while(r < size){
        sum = pre[r+1] - pre[l];
        mx = max(sum, mx);
        l++, r++;
    }
    cout << mx;
    return 0;
}
