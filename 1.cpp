#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 1) return 1;
    while(n > 1){
        if(n % 2){
            n = 3  * n + 1;
        }
        else n /= 2;
        cout << n << " ";
    }
    
    return 0;
}