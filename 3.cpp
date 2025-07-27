#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
//    brute
    // for(int i=0;i<32;i++){
    //     if(n == pow(2,i)) {
    //         cout << "YES" << endl;
    //         return 0;
    //     }
    // }
    // cout << "NO" << endl;

    if(n == 1) cout << "YES";
    if(n == INT_MIN) cout << "NO"; // INT_MIN is not a power of 2
    return 0;
    if((n & (n-1)) == 0) cout << "YES";
    else cout << "NO";
    
    return 0;
}