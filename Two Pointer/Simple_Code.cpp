#include <iostream>

using namespace std;
// U have a sorted array and need to find two numbers 
// such that they add up to a specific target.
int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]), target = 15;
    
    for(auto it : arr)
        cout << it << ' ';
    cout << '\n';
    
    int l = 0, r = size-1;
    while(l <= r){
        if(arr[l] + arr[r] == target){
            cout << l << ' ' << r;
            return 0;
        }
        else if(arr[l] + arr[r] < target){
            l++;
        }
        else if(arr[l] + arr[r] > target){
            r--;
        }
    }
    cout << "Not Found!";
    return 0;
}
