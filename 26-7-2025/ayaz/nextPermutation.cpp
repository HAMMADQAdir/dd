#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void permutaions(vector<int> arr, int index){
    if(index >= arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[i],arr[index]);
        permutaions(arr,i+1);
        swap(arr[i],arr[index]);
    }

}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // brute force
    // generate all permutaions
  
    int dipIndex = -1;
    for(int i=arr.size() - 2; i>=0; i--){
        if(arr[i] < arr[i+1]) {dipIndex = i;break;}
    }
    if(dipIndex == -1){ 
        reverse(arr.begin(),arr.end());
    }

    if(dipIndex != -1){
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[dipIndex] < arr[i]){
                swap(arr[dipIndex],arr[i]);
                break;
            }
        }
    }
    for(auto a : arr){
        cout << a << " ";
    }
    return 0;
}