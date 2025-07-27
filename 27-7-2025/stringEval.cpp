#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stack<pair<int,int>> st;
    int sum = 0, sign = 1;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            int num = 0;
            while(i < s.size() && isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            sum += (num * sign);
            sign = 1;
        }
        else if(s[i] == '('){
            st.push({sum,sign});
            sum = 0;
            sign = 1;
        }
        else if(s[i] == ')'){
            sum = st.top().first + (st.top().second * sum);
            st.pop();

        }
        else if(s[i] == '-'){
            sign = -1 * sign;
        }
    }
    cout << sum;
    return 0;
}