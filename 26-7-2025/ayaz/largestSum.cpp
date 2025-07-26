#include<bits/stdc++.h>

using namespace std;

int main(){
   

    int n;
    cout << "enter a number : ";
    cin >> n;
    vector<int> arr;
    while(n > 0){
        n--;
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // brute force
    // int maxSum = INT_MIN;
    // for(int i=0;i<arr.size();i++){
    //     int sum = 0;
    //     for(int j=i;j<arr.size();j++){
    //         sum += arr[j];
    //         maxSum = max(maxSum,sum);
    //     }
        
    // }

    int maxSum = INT_MIN;
    int currentSum = 0;
    for(int i=0;i<arr.size();i++){
        currentSum+=arr[i];

        if(currentSum > maxSum){
            maxSum = currentSum;
        }
        if(currentSum < 0){
           currentSum = 0;
        }
       
    }
    cout << maxSum;
}