#include <bits/stdc++.h>
using namespace std;

// Booth's Algorithm: O(n)
int booth(string s) {
    s += s; // concatenate to simulate rotations
    int n = s.size();
    vector<int> f(n, -1); // failure function
    int k = 0; // least rotation start index
    
    for (int j = 1; j < n; j++) {
        char sj = s[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != s[k + i + 1]) {
            if (sj < s[k + i + 1]) k = j - i - 1;
            i = f[i];
        }
        if (sj != s[k + i + 1]) {
            if (sj < s[k]) k = j;
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
}

int main() {
    string s;
    cin >> s;
    int start = booth(s);
    cout << s.substr(start) + s.substr(0, start) << "\n";
    return 0;
}
