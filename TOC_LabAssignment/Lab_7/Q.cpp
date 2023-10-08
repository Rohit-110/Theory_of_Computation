/*
    Author : Rohit Pandey ;)
*/

#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
void B(string s,string &p,int ind){
    if(s.size()==ind){
        p.pop_back();
        if(s==p){
            cout<<p<<" "<<endl;
        }
        else cout<<"String Does not Match"<<endl;
    }
    else if(s[ind]=='0'){
        p.pop_back();
        p+='0';
        p+='B';
        cout<<p<<endl;
        B(s,p,ind+1);
    }
    else{
        p.pop_back();
        p+='1';
        p+='B';
        cout<<p<<endl;
        B(s,p,ind+1);
        
    }
}
void A(string s,string &p,int ind){
    if(s[ind]=='0'){
        reverse(all(p));
        p.pop_back();
        p+='0';
        p+='A';
        reverse(all(p));
        cout<<p<<endl;
        A(s,p,ind+1);
    }
    else {
        reverse(all(p));
        p.pop_back();
        reverse(all(p));
        cout<<p<<endl;
        B(s,p,ind+1);
    }
}
int main(){
    string s;
    cin>>s;
    string p="A1B";
    A(s,p,0);
    
}
