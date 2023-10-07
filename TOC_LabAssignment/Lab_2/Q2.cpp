/*
    Author: Rohit Pandey ;)
*/
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int main() {
    char s[50];
    scanf("%s",s);
    queue<int> st;
    st.push(0);
    if(strlen(s)==3){
        if(s[0]=='a' && s[1]=='b' && s[2]=='a'){
            cout<<"String is accepted";
        }
        return 0;
    }
    vector<vector<vector<int>>> tran = {
        {{1}, {-1}}, {{-1}, {2}}, {{2}, {2, 3}},{{4},{-1}}
    };

    queue<int>ne;
    for (int i = 0; i < strlen(s); i++) {
        while (st.size()>0) {
            int currentState = st.front();
            if(currentState!=4 && currentState!=-1)
            for (int j = 0; j < tran[currentState][s[i] - 'a'].size(); j++) {
                ne.push(tran[currentState][s[i] - 'a'][j]);
            }
            st.pop();
        }
        while(ne.size()>0){
            st.push(ne.front());
            ne.pop();
        }
    }

    bool ans = false;
    while (st.size()>0) {
        if (st.front() == 4) {
            ans = true;
            break; 
        }
        st.pop();
    }

    if (ans) {
        printf("String is accepted");
    } else {
        printf("Rejected");
    }

    cout << endl;

    return 0;
}