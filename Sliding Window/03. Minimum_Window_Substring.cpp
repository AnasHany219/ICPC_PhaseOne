#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    pair<int, int>sub(0, INT_MAX);
    unordered_map<char, int>umap;
    for(auto it : t)    umap[it]++;
    int l = 0, r = 0;
    int counter = t.size();
    while(r < s.size()){
        if(umap[s[r]] > 0)
            counter--;
        umap[s[r]]--;
        r++;
        while(counter == 0){
            if(r - l < sub.second){
                sub.second = r - l;
                sub.first = l;
            }
            umap[s[l]]++;
            if(umap[s[l]] > 0)
                counter++;
            l++;
        }
    }
    if(sub.second == INT_MAX)   return "";
    else                        return s.substr(sub.first, sub.second);
}
int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t);
    return 0;
}
/*
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

Input: 
    s = "ADOBECODEBANC", t = "ABC"
Output: 
    "BANC"
Explanation: 
    The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/
