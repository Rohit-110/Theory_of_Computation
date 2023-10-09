/*
    Author : Rohit Pandey ;)
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<vector<int>>>tran={
        {{-1},{1},{2}} , {{1,2},{2},{-1}} , {{0},{-1},{-1}}
    };
    queue<int>st;
    string s;
    cin>>s;
    st.push(0);
    for(int i=0;i<s.size();i++){
        queue<int>ne;
        while(!st.empty()){
            for(int j=0;j<tran[st.front()][s[i]-'a'].size();j++){
                if(tran[st.front()][s[i]-'a'][j]!=-1)
                ne.push(tran[st.front()][s[i]-'a'][j]);
            }
            for(int j=0;j<tran[st.front()][2].size();j++){
                if(tran[st.front()][2][j]!=-1){
                    for(int k=0;k<tran[tran[st.front()][2][j]][s[i]-'a'].size();k++){
                        if(tran[tran[st.front()][2][j]][s[i]-'a'][k]!=-1){
                            ne.push(tran[tran[st.front()][2][j]][s[i]-'a'][k]);
                        }
                    }
                }
            }
            cout<<st.front()<<endl;
            st.pop();
        }
        while(!ne.empty()){
            cout<<ne.front()<<" ";
            st.push(ne.front());
            ne.pop();
        }
        cout<<endl;
    }
    bool ans=false;
    while(!st.empty()){
        if(st.front()==0)ans=true;
        st.pop();
    }
    if(ans)cout<<"String is accepted"<<endl;
    else cout<<"Rejected"<<endl;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Second way Using sets
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<vector<int>>>tran{
        {{-1},{1},{2}},{{1,2},{2},{-1}},{{0},{-1},{-1}}
    };
    queue<int>st;
    st.push(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        set<int>a;
        while(!st.empty()){
            for(int j=0;j<tran[st.front()][s[i]-'a'].size();j++){
                if(tran[st.front()][s[i]-'a'][j]!=-1)
                a.insert(tran[st.front()][s[i]-'a'][j]);
            }
            for(int j=0;j<tran[st.front()][2].size();j++){
                if(tran[st.front()][2][j]!=-1){
                    for(int k=0;k<tran[tran[st.front()][2][j]][s[i]-'a'].size();k++){
                        if(tran[tran[st.front()][2][j]][s[i]-'a'][k]!=-1)
                        a.insert(tran[tran[st.front()][2][j]][s[i]-'a'][k]);
                    }
                }
            }
            st.pop();
        }
        for(auto p:a){
            st.push(p);
        }
    }
    bool ans=false;
    while(!st.empty()){
        if(st.front()==0)ans=true;
        st.pop();
    }
    if(ans)cout<<"String is accepted"<<endl;
    else cout<<"String is rejected"<<endl;
    
}
