#include <iostream>
using namespace std;
int palindrome(string s, int l, int r){
    if(l>r){
        return 1;
    }
    if(s[l]==s[r]) return palindrome(s,l+1,r-1);
    else return 0;
    
}

int main(){
    string s;
    cin>>s;
    if(palindrome(s,0,s.size()-1)){
        cout<<"It's palindrome\n";
    }else{
        cout<<"It's not palindrome\n";
    }
}