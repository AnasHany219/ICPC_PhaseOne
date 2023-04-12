#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int N = nums.size();
    int l = 0, sum = 0, r = 0, res = INT_MAX;
    while(r < N){
        sum += nums[r];
        while(sum >= target){
            res = min(res, r - l + 1);
            sum -= nums[l];
            l++;
        }
        r++;
    }
    return res == INT_MAX? 0 : res;
}
int main(){
    int size_array, target;
    cin >> size_array >> target;
    vector<int>v(size_array);
    for(int i = 0; i < size_array; i++)
        cin >> v[i];
    cout << minSubArrayLen(target, nums);
    return 0;
}
/*
Given an array of positive integers nums and a positive integer target, 
    return the minimal length of a sub-array whose sum is greater than or equal to target. 
    If there is no such sub-array, return 0 instead.
    
Input: 
    target = 7, nums = [2,3,1,2,4,3]
Output: 
    2
Explanation: 
    The sub-array [4,3] has the minimal length under the problem constraint.
    
Input: 
    target = 4, nums = [1,4,4]
Output: 
    1

Input: 
    target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 
    0
*/
