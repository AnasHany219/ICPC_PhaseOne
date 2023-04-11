#include <iostream>
using namespace std;

int minFlips(string s) {
    string s1 = "", s2 = "";
    int N = s.length();
    s += s;
    for(int i = 0; i < 2 * N; i++){
        if(i % 2 == 0){
            s1.push_back('0');
            s2.push_back('1');
        }
        else {
            s1.push_back('1');
            s2.push_back('0');
        }
    }
    int res = s.length();
    int l = 0, r = 0, def1 = 0, def2 = 0;
    while(r < 2 * N){
        if(s[r] != s1[r])
            def1++;
        if(s[r] != s2[r])
            def2++;
        if(r - l + 1 > N){
            if(s[l] != s1[l])
                def1--;
            if(s[l] != s2[l])
                def2--;
            l++;
        }
        if(r - l + 1 == N){
            res = min(res, min(def1, def2));
        }
        r++;
    }
    return res;
}
int main(){
    string s;
    cin >> s;
    cout << minFlips(s);
    return 0;
}
/*
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Input: 
    s = "111000"
Output: 
    2
Explanation: 
    Use the first operation two times to make s = "100011".
    Then, use the second operation on the third and sixth elements to make s = "101010".

Input: 
    s = "010"
Output: 
    0
Explanation: 
    The string is already alternating.

Input: 
    s = "1110"
Output:
    1
Explanation: 
    Use the second operation on the second element to make s = "1010".
*/
