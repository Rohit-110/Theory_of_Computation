/*
    Author : Rohit Pandey ;)
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    vector<vector<vector<int>>>tran={
        {{0,1},{1}},{{-1},{2}},{{2},{2}}
    };
    set<vector<int>>uniquestates;
    vector<vector<vector<int>>>dfa;
    
    /*uniquestates.insert(tran[0][0]);
    uniquestates.insert(tran[0][1]);
    vector<vector<int>>q;
    q.pb(tran[0][0]);
    q.pb(tran[0][1]);
    dfa.pb(q);*/
    uniquestates.insert({0});
    for(auto p:uniquestates){
        
        cout<<endl;
        vector<vector<int>>b;
        set<int>c;
        for(int j=0;j<p.size();j++){
            for(int k=0;k<tran[p[j]][0].size();k++){
                if(tran[p[j]][0][k]!=-1)
                c.insert(tran[p[j]][0][k]);
            }
        }
        vector<int>d;
        if(c.size()==0){
            d.pb(-1);
        }
        for(auto x:c){
            d.pb(x);
        }
        b.pb(d);
        uniquestates.insert(d);
        c.clear();
        d.clear();
        for(int j=0;j<p.size();j++){
            for(int k=0;k<tran[p[j]][1].size();k++){
                c.insert(tran[p[j]][1][k]);
            }
        }
        if(c.size()==0){
            d.pb(-1);
        }
        for(auto x:c){
            d.pb(x);
        }
        b.pb(d);
        uniquestates.insert(d);
        dfa.pb(b);
        
    }
    int g=0;
    for(int i=0;i<dfa.size();i++){
        /*for(set<vector<int>>::iterator p=uniquestates.begin();p!=uniquestates.end();p++){
            for(int z=0;z<g;z++){
                p++;
            }
            for(int gf=0;gf<(*p).size();gf++){
                cout<<(*p)[gf]<<" ";
            }
        }
        cout<<" | "<<" ";*/
        for(int j=0;j<dfa[i].size();j++){
            for(int k=0;k<dfa[i][j].size();k++){
                cout<<dfa[i][j][k]<<" ";
            }
            cout<<"   ";
        }
        cout<<endl;
    }
}