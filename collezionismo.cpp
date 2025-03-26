#include <bits/stdc++.h>

using namespace std;

// 1-sort the statue vector
// 2-while all k scaffali fill them with the statua with max D(defined by min D between next and previous statue)
// 3-distribute each remaining statue in the scaffale with hyp least D

int pop(vector<int>& vec) {
    int a = vec.back();
    vec.pop_back();
    return a;
}

int pop_front(vector<int>& vec) {
    int a = vec.front(); // Get first element
    vec.erase(vec.begin()); // Remove first element
    return a;
}

void distribute_first_layer(vector<vector<int>>& scaffali, vector<int>& vec, int k){
    int idx;
    vector<int> vec_copy = vec;
    for(int i=0; i<k; i++){
        idx = find_nmax_d(vec_copy, i);
        scaffali.push_back({vec_copy[i],vec_copy[i]}); // NOTE: idem a sotto 
        vec.erase(vec[i]); // NOTE: non so se cosi sia corretto
    }
}

void distribute_remaining_statues(vector<vector<int>>& scaffali, vector<int>& vec, int k){
    for(int i=0; i<vec.size(), i++){
        add_best_scafale(scaffali, vec[i], k);
    }


void add_best_scaffale(vector<vector<int>>& scaffali, vector<int>& vec, int k){
    int min = calcD(scaffali[0][0], scaffali[0][1]); // NOTE: non va bene cosi, devi inizializzare con primo valore ipotetico di vec[0]
    int minIdx = 0;
    for(int i=0; i<k; i++){
        if()
        
    }
}

int find_nmax_d(vector<int> vec, int n){
    return 0; // NOTE: to finish
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
