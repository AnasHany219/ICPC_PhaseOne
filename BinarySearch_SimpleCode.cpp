#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;      cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int x;      cin >> x;

    int l = 0, r = n-1, mid;

    while(l <= r){
        mid = (l + r) / 2;
        if(arr[mid] == x){
            cout << "Yes\n";
            return 0;
        }
        else if(arr[mid] > x)  r = mid -1;
        else if(arr[mid] < x)  l = mid +1;
    }

    cout << "No\n";

    return 0;
}
