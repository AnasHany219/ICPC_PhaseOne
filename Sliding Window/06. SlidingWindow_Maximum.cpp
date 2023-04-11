#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int size = nums.size();
    int l = 0, r = 0;
    deque<int>q;
    vector<int>res;
    while(r < size){
        while(!q.empty() && nums[q.back()] < nums[r])
            q.pop_back();

        q.push_back(r);
        if(l > q[0])
            q.pop_front();

        if(r + 1 >= k){
            res.push_back(nums[q[0]]);
            l++;
        }
        r++;
    }
    return res;
}
int main(){
    int n;  cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int k;  cin >> k;

    vector<int>ans = maxSlidingWindow(v, k);
    cout << '\n';
    for(auto it : ans)
        cout << it << ' ';
    return 0;
}
/*
You are given an array of integers nums, 
    there is a sliding window of size k 
    which is moving from the very left of the array to the very right. 
    You can only see the k numbers in the window. 
    Each time the sliding window moves right by one position.

Return the max sliding window.

Input: 
    nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: 
    [3,3,5,5,6,7]
Explanation: 
         Window position           Max
    --------------------------    -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7
*/
