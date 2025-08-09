#include <bits/stdc++.h>
using namespace std;

int findCnt(vector<int> arr, int goal)
{
    int left = 0;
    int right = 0;
    int cnt = 0;
    int sum = 0;
    while (right < arr.size())
    {
        sum += arr[right];
        while (sum > goal)
        {
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
    while (n-- > 0)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int i = 0, m = 0, j = arr.size() - 1;
    while(m <= j){
        if(arr[m] == 0) swap(arr[m++],arr[i++]);
        else if(arr[m] == 2) swap(arr[m],arr[j--]);
        else m++;
     }
    for (auto a : arr)
    {
        cout << a << " ";
    }
    return 0;
}