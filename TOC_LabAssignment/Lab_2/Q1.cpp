/*
    Author: Rohit  Pandey ;)
*/ 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    queue<int> st;
    st.push(0);

    vector<vector<vector<int>>> tran = {
        {{1}, {2}}, {{1, 3}, {1}}, {{2}, {2, 3}},{{3},{3}}
    };

    queue<int>ne;
    for (int i = 0; i < s.size(); i++) {
        while (st.size()>0) {
            int currentState = st.front();
            if(currentState!=3)
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
        if (st.front() == 3) {
            ans = true;
            break; 
        }
        st.pop();
    }

    if (ans) {
        cout << "String is Accepted";
    } else {
        cout << "Rejected";
    }

    cout << endl;

    return 0;
}