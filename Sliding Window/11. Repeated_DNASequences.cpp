#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> mp;
    int n = s.size();
    for(int i = 0; i <= n - 10; i++){
        string str = s.substr(i,10);
        mp[str]++;
    }
    vector<string> ans;
    for(auto x : mp)
        if(x.second > 1)
            ans.push_back(x.first);

    return ans;
}
int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string>v = findRepeatedDnaSequences(s);
    for(auto it : v)
        cout << it << ' ';
    return 0;
}
/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, 
return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. 
You may return the answer in any order.

Input: 
    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: 
    ["AAAAACCCCC","CCCCCAAAAA"]
    
Input: 
    s = "AAAAAAAAAAAAA"
Output: 
    ["AAAAAAAAAA"]
*/
