#include<iostream>
using namespace std;
void tower(int n, char s,char h,char d){
    if(n == 0) return;
    tower(n-1,s,d,h);
    cout << "Move disk " << n << " from " << s << " to " << d << endl;
    tower(n-1,h,s,d);
}
int main(){
    int n;
    cin >> n;
    tower(n,'A','B','C');
}