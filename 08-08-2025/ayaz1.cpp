#include<bits/stdc++.h>
using namespace std;

int findCnt(vector<int> arr,int goal){
    int left = 0;
    int right = 0;
    int cnt = 0;
    int sum = 0;
    while(right < arr.size()){
        sum += arr[right];
        while(sum > goal) {
            sum -= arr[left];
            left++;
        }

        cnt += (right - left + 1);
        right++;
    }
    return cnt;
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    while(n-->0){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int goal;
    cin >> goal;
    // prefixSum
    // int currrentSum = 0;
    // unordered_map<int,int> mp;
    // int cnt = 0;
    // for(int i=0;i<arr.size();i++){
    //     currrentSum += arr[i];
    //     if(currrentSum == goal){
    //         cnt++;
    //     }
    //     if(mp.find(currrentSum-goal) != mp.end()){
    //         cnt += mp[currrentSum-goal];
    //     }
    //     mp[currrentSum]++;
    // }

    // cout << cnt;
    cout << findCnt(arr,goal) - findCnt(arr,goal-1);

    return 0;
}