#include<bits/stdc++.h>
#define SUPERPOWER  ios_base::sync_with_stdio(false); cout.tie(0);
#define ll          long long

using namespace std;
int characterReplacement(string s, int k) {
        int l = 0, r = 0, res = 0, sizeS = s.size();
        vector<int>freq(100, 0);
        int MaxF = 0;
        for(r = 0; r < sizeS; r++){
            freq[s[r]]++;
            MaxF = max(MaxF, freq[s[r]]);
            while((r - l + 1) - MaxF > k){
                freq[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
}
int main(){
    SUPERPOWER
    string s;
    int k;
    cin >> s >> k;
    cout << characterReplacement(s, k);
    return 0;
}
