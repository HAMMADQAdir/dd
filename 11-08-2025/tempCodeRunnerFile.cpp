#include <iostream>
using namespace std;

int cntMagical(string s)
{
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    for(auto it : s){
        if(it == 'a') aCnt++;
        else if(it == 'e') eCnt = eCnt + aCnt;
        else if(it == 'i') iCnt = iCnt + eCnt;
        else if(it == 'o') oCnt = oCnt + iCnt;
        else if(it == 'u') uCnt = uCnt + oCnt;
    }
    return uCnt;
}
int main()
{
    string s;
    cin >> s;
    cout << cntMagical(s);
    return 0;
}