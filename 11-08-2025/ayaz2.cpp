#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long redix = 26;

long long hashValue(const string &s, int m)
{
    long long hash = 0;
    for (int i = 0; i < m; i++)
    {
        hash = (hash * redix + (s[i] - 'a')) % mod;
    }
    return hash;
}

void rabinKarp(string s, string pattern)
{
    int n = s.length();
    int m = pattern.length();

    if (m > n)
        return ;

    long long maxWeight = 1;
    for (int i = 1; i < m; i++)
    {
        maxWeight = (maxWeight * redix) % mod;
    }

    long long patternHash = hashValue(pattern, m);
    long long stringHash = hashValue(s, m);

    for (int i = 0; i <= n - m; i++)
    {
        if (patternHash == stringHash)
        {

            if (s.substr(i, m) == pattern)
            {
                cout << "Pattern found at index " << i << "\n";
                return ;
            }
        }

        if (i < n - m)
        {
            stringHash = ((stringHash - ((s[i] - 'a') * maxWeight) % mod + mod) % mod);
            stringHash = (stringHash * redix + (s[i + m] - 'a')) % mod;
        }
    }

    cout << "Pattern not found" << endl;
}
int main()
{
    string s, pattern;
    cin >> s;
    cout << "Enter number of patterns ";
    int k;
    cin >> k;
    vector<string> patterns;
    for (int i = 0; i < k; i++)
    {
        string p;
        cin >> p;
        patterns.push_back(p);
    }

    for(auto p : patterns){
        rabinKarp(s,p);
    }

    return 0;
}
