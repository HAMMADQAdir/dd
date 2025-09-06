#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int n = s.length();
    
    // Calculate the prefix function (KMP algorithm)
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    
    // Find all period lengths
    vector<int> periods;
    
    // For each length i, we check if it's a valid period
    for (int i = 1; i <= n; i++) {
        // Optimization: We only need to check lengths where:
        // 1. i divides n perfectly, OR
        // 2. The border of the string (pi[n-1]) satisfies a certain condition
        if (n % i == 0 || (n - pi[n-1]) <= i) {
            bool isPeriod = true;
            // Check if the pattern repeats correctly
            for (int j = i; j < n && isPeriod; j++) {
                if (s[j] != s[j % i]) {
                    isPeriod = false;
                }
            }
            
            if (isPeriod) {
                periods.push_back(i);
            }
        }
    }
    
    // Print all period lengths
    for (size_t i = 0; i < periods.size(); i++) {
        cout << periods[i];
        if (i < periods.size() - 1) {
            cout << " ";
        }
    }
    
    return 0;
}
