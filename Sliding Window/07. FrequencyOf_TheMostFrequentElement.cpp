#include<bits/stdc++.h>
#define SUPERPOWER  ios_base::sync_with_stdio(false); cout.tie(0);
#define ll          long long

using namespace std;
int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long size_n = nums.size(), l = 0, r = 0, res = 0, sum = 0;
    while(r < size_n){
        sum += nums[r];
        while(nums[r] * (r - l + 1) - sum > k){
            sum -= nums[l];
            l++;
        }
        res = max(res, (r - l + 1));
        r++;
    }
    return res;
}
int main(){
    SUPERPOWER
    int n, k;  cin >> n >> k;
    vector<int>v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << maxFrequency(v, k);
    return 0;
}
/*
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation,
you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

Input:
    nums = [1,2,4], k = 5
Output:
    3
Explanation:
    Increment the first element three times and the second element two times to make nums = [4,4,4].
    4 has a frequency of 3.
*/
