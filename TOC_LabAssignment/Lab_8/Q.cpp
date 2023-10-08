/*
    Author : Rohit Pandey ;)
*/

#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back
string removeunit(string s,vector<pair<string,string>>&p){
    if(s<="z" && s>="a")return s;
    else{
        string sp;
        for(int i=0;i<p.size();i++){
            if(s==p[i].first){
                p[i].first="#";
                sp=removeunit(p[i].second,p);
                return sp;
            }
        }
        return "#";
    }
}
int main(){
    vector<pair<string,string>>v;
    cout<<"Enter total transitions"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        v.pb({a,b});
    }
    for(int i=0;i<n;i++){
        if(v[i].second.size()==1 && v[i].second<="Z" && v[i].second>="A"){
            v[i].second=removeunit(v[i].second,v);
        }
    }
    for(int i=0;i<n;i++){
        if(v[i].second.size()==1 && v[i].second<="Z" && v[i].second>="A" || (v[i].first=="#"))continue;
        cout<<v[i].first<<" -> "<<v[i].second<<endl;
    }
}