#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int pop(vector<int>& vec){
    int a = vec[vec.size()];
    vec.erase(vec.end());
    return a;
}

int pop_front(vector<int>& vec){
    int a = vec[0];
    vec.erase(vec.begin);
    return a;
}

vector<vector<int>> bordering(vector<int>& c, int k){
    vector<vector<int>> res;
    vector<int> mom = {};
    if(k%2 == 0){
        for(int i=0; i<k; i++){
            mom.push_back(c.pop());
            res.push_back(mom);
            mom.pop();

            mom.push_back(c.pop_front());
            res.push_back(mom);
            mom.pop();
        }
    }else{
        for(int i=0; i<k-1; i++){
            mom.push_back(c.pop());
            res.push_back(mom);
            mom.pop();

            mom.push_back(c.pop_front());
            res.push_back(mom);
            mom.pop();
        }
        mom.push_back(c.pop_front());
        res.push_back(mom);
    }
    return res;
}

int distribute(vector<int> c, vector<vector<int>> scaf){
    int curRes = 0;
    for(int i=0; i<c.size(); i++){
        int min = abs(scaf[0][0] - c[i]);
        int pos = 0;
        for(int j=0; j<scaf.size(); j++){
            int cur_min = abs(scaf[j][0] - c[i]);
            if(cur_min < min){
                pos = j; 
                min = cur_min;
            }
        }
        scaf[j].push_back(c[i]);
        curRes -= abs(scaf[j][0] - c[]) //PORCO DIO
    }
}

void solve(int t) {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    sort(C.begin(), C.end());

    int risposta = 42;

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
