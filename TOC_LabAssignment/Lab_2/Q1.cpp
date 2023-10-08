/*
    Author: Rohit  Pandey ;)
    
*/ 
/*

Q. For a NFA over {a,b} such that all strings start and end with the same symbols, write a C
program to check whether a given string is accepted or not by NFA using its transition
table.

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<vector<vector<int>>>tran={
        {{1,3},{2,3}},{{1,3},{1}},{{2},{2,3}},{{-1},{-1}}
    };
    queue<int>st;
    st.push(0);
    for(int i=0;i<s.size();i++){
        queue<int>ne;
        while(st.size()!=0){
            for(int j=0;j<tran[st.front()][s[i]-'a'].size();j++){
                if(tran[st.front()][s[i]-'a'][j]!=-1)
                ne.push(tran[st.front()][s[i]-'a'][j]);
            }
            st.pop();
        }
        while(ne.size()!=0){
            st.push(ne.front());
            ne.pop();
        }
    }
    bool ans=false;
    while(st.size()!=0){
        if(st.front()==3)ans=true;
        st.pop();
    }
    if(ans)cout<<"String is accepted"<<endl;
    else cout<<"String is Rejected"<<endl;
}
