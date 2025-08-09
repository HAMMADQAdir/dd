#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr;
    while(n-->0){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    int low = 1, high = *max_element(arr.begin(),arr.end());
    // brute force O(high * n)
    // for(int i = 1; i<= high; i++){

    //     int res = 0;
    //     for(auto pile : arr){
    //         res += ceil((double)pile/i);
           
    //     }
    //     if(res == k) {
    //         cout << i;
    //         return 0;
    //     }
    // }

    while(low <= high){
        int mid = (high + low) /2;
        int totalH = 0;
        for(auto pile : arr){
            totalH += ceil((double)pile/mid);
        }
        if(totalH > k){
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << low;
    
    return 0;
}