#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> &s1, vector<int> &s2){
    for(int i=0;i<26; i++){
        if(s1[i] != s2[i])return false;
    }
    return true;
}
vector<int> findAnagrams(string s, string p) {
    int size_s = s.size(), size_p = p.size();
    vector<int>freq_s(26, 0);
    vector<int>freq_p(26, 0);
    vector<int>res;

    for(int i = 0; i < size_p; i++){
        freq_p[p[i] - 'a']++;
    }
    int l = 0, r = 0;
    while(r < size_s){
        freq_s[s[r] - 'a']++;
        if((r - l + 1) == size_p){
            if(check(freq_s, freq_p))
                res.push_back(l);
            freq_s[s[l] - 'a']--;
            l++;
        }
        r++;
    }
    return res;
}
int main()
{
    string s, p;
    cin >> s >> p;
    vector<int> ans = findAnagrams(s, p);

    for(auto it : ans)
        cout << it << ' ';
    return 0;
}
/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Input: 
  s = "cbaebabacd", p = "abc"
Output: 
  [0,6]
Explanation:
  The substring with start index = 0 is "cba", which is an anagram of "abc".
  The substring with start index = 6 is "bac", which is an anagram of "abc".
*/
