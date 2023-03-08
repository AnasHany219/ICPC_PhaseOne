#include <iostream>
#include <algorithm>

using namespace std;

int UpperBound(int arr[], int n, int x){
    int l = 0, r = n-1, mid, ans;
    while(l <= r){
        mid = (l + r) / 2;
        if(arr[mid] >= x){
            r = mid - 1;
            ans = arr[mid];
        }
        else l = mid + 1;
    }
    return ans;
}

int LowerBound(int arr[], int n, int x){
    int l = 0, r = n-1, mid, ans;
    while(l <= r){
        mid = (l + r) / 2;
        if(arr[mid] <= x){
            l = mid + 1;
            ans = arr[mid];
        }
        else r = mid - 1;
    }
    return ans;
}

int main()
{
    int n;  cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int x;  cin >> x;

    cout << "Upper Bound: " << UpperBound(arr, n, x);
    cout << '\n';
    cout << "Lower Bound: " << LowerBound(arr, n, x);
    return 0;
}
