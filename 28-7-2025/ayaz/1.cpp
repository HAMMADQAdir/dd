#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    while (n-- > 0)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int a = 0, b = 0, c = 0;
    for (auto bill : arr)
    {
        if (bill == 5)
            a++;
        else if (bill == 10)
        {
            if (a > 0)
            {
                a--;
                b++;
            } else
            {
                cout << "NO";
                return 0;
            }
        }
        else {
            if(b > 0){
                b--;
                if (a > 0)
                {
                    a--;
                }
                else
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
    return 0;
}