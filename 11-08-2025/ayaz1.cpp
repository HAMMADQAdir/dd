#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

long long countMagicalSubsequences(string s) {
    long long aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    for (char ch : s) {
        if (ch == 'a') {
            aCnt = (aCnt + 1) % MOD;
        }
        else if (ch == 'e') {
            eCnt = (eCnt + aCnt) % MOD;
        }
        else if (ch == 'i') {
            iCnt = (iCnt + eCnt) % MOD;
        }
        else if (ch == 'o') {
            oCnt = (oCnt + iCnt) % MOD;
        }
        else if (ch == 'u') {
            uCnt = (uCnt + oCnt) % MOD;
        }
    }
    return uCnt;
}

int main() {
    string s;
    cin >> s;
    cout << countMagicalSubsequences(s) << "\n";
    return 0;
}
