/*
    Author: Rohit Pandey ;)
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
void calc_eps_clo(int st,vector<vector<vector<int>>>tran,vector<int>&ans){
    if(st!=-1)ans.pb(st);
    for(int i=0;i<tran[st][2].size();i++){
        if(tran[st][2][i]==-1)return ;
        return calc_eps_clo(tran[st][2][i],tran,ans);
    }
    return;
}
int main(){
    vector<vector<vector<int>>>tran={
        {{-1},{1},{2}},{{1,2},{2},{-1}},{{0},{-1},{-1}}
    };
    cout<<"Enter the state to get its epsilon closure"<<endl;
    int st;
    cin>>st;
    vector<int>ans;
    calc_eps_clo(st,tran,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"****** NFA TABLE ********";
    cout<<endl;
    // calculating epsilon closure of each state
    vector<vector<int>>epsclosr(3);
    for(int i=0;i<3;i++){
        calc_eps_clo(i,tran,epsclosr[i]);
    }
    vector<vector<vector<int>>>nfa;
    for(int i=0;i<3;i++){
        vector<vector<int>>b;
        for(int j=0;j<2;j++){
            set<int>a;
            for(int k=0;k<epsclosr[i].size();k++){
                for(int l=0;l<tran[epsclosr[i][k]][j].size();l++){
                    if(tran[epsclosr[i][k]][j][l]!=-1){
                        a.insert(tran[epsclosr[i][k]][j][l]);
                    }
                    
                }
            }
            vector<int>d;
            set<int>c;
            for(auto p:a){
                for(int o=0;o<epsclosr[p].size();o++){
                    c.insert(epsclosr[p][o]);
                }
            }
            for(auto e:c){
                d.pb(e);
            }
            if(d.size()==0)d.pb(-1);
            b.pb(d);
        }
        nfa.pb(b);
    }
    for(int i=0;i<nfa.size();i++){
        for(int j=0;j<nfa[i].size();j++){
            for(int k=0;k<nfa[i][j].size();k++){
                cout<<nfa[i][j][k]<<" ";
            }
            cout<<"     ";
        }
        cout<<endl;
    }
    
}