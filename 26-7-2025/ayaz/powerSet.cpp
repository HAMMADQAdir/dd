#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void powerSet(vector<int> arr, vector<int> output,int index){
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }
    powerSet(arr,output,index + 1);
    output.push_back(arr[index]);
   
    powerSet(arr,output,index+1);
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
    // vector<int> output;
    // powerSet(arr,output,0);
    // // tc O(2^n) 
    // // sc O(n)
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout << ans[i][j] << " ";
    //     }cout << endl;
    // }

    for(int i=0;i<arr.size();i++){
        vector<int> temp;
        for(int j=0;j<arr.size();j++){
            if(i & (1 << j)){
                temp.push_back(arr[j]);
            }
        }
        ans.push_back(temp);
    }
    int totalSubsets = (1 << arr.size());
    // tc O(n * 2^n)
    for(int i=0;i<totalSubsets;i++){
        for(int j=0;j<arr.size();j++){
            if(i & (1 << j)){
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}