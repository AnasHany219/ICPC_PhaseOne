#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int l = 0;
    int r = 0;
    int ans = 0;
    int n = s.length();
    vector<int>v(256, 0);
    while(r < n){
        v[s[r]]++;
        while(v[s[r]] > 1){
            v[s[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}
int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}
/*
Given a string s, find the length of the longest substring without repeating characters.
Input:
  s = "abcabcbb"
Output:
  3
Explanation:
  The answer is "abc", with the length of 3.
*/
