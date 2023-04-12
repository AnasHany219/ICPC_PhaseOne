#include<bits/stdc++.h>
#define SUPERPOWER  ios_base::sync_with_stdio(false); cout.tie(0);
#define ll          long long

using namespace std;
// s1 = "ab", s2 = "eidbaooo"
bool checkInclusion(string s1, string s2) {
    int size_s1 = s1.length();
    int size_s2 = s2.length();
    if(size_s1 > size_s2)
        return false;
    vector<int>freq_s1(26, 0);
    vector<int>freq_s2(26, 0);
    for(int i = 0; i < size_s1; i++){
        freq_s1[s1[i] - 'a']++;
        freq_s2[s2[i] - 'a']++;
    }
    int l = 0, r = size_s1, matches = 0, index;
    for(int i = 0; i < 26; i++)
        if(freq_s1[i] == freq_s2[i])
            matches++;
    while(r < size_s2){
        if(matches == 26)
            return true;

        index = s2[r] - 'a';
        freq_s2[index]++;
        if(freq_s1[index] == freq_s2[index])
            matches++;
        else if(freq_s1[index] + 1 == freq_s2[index])
            matches--;

        index = s2[l] - 'a';
        freq_s2[index]--;
        if(freq_s1[index] == freq_s2[index])
            matches++;
        else if(freq_s1[index] - 1 == freq_s2[index])
            matches--;
        r++, l++;
    }
    return matches == 26;
}
int main(){
    SUPERPOWER
    string s1, s2;
    cin >> s1 >> s2;
    if(checkInclusion(s1, s2))
        cout << "true";
    else
        cout << "false";

    return 0;
}
/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Input: 
    s1 = "ab", s2 = "eidbaooo"
Output: 
    true
Explanation: 
    s2 contains one permutation of s1 ("ba").

Input: 
    s1 = "ab", s2 = "eidboaoo"
Output: 
    false
*/
