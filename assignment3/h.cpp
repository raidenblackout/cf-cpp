#include <iostream>
using namespace std;
void reversestring(string s, int pos){
    if(pos==s.size()) return;
    reversestring(s,pos+1);
    cout<<s[pos];
}

int main(){
    string s;
    cin>>s;
    reversestring(s,0);
}