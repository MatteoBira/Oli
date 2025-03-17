#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int t) {
    int N;
    cin >> N;
    vector<int> S(N, 0);
    for(int i = 0; i < N; i++) cin >> S[i];

    // aggiungi codice...
    vector<int> zIdx;
    for(int i=0;i<N;i++){
        if(S[i] == 0) zIdx.push_back(i);
    }

    int max = 0;

    if(zIdx.size() == 0){
        max = N;
        goto skip;
    }

    for(int i=0;i<zIdx.size();i++){
        S[zIdx[i]] = 1;
        int con = 1, cur=0;
        for(int j=0;j<N;j++){
            if(S[j] == 1){
                if(con==1){
                    cur++;
                }else{
                    cur=1;
                    con=1;
                }
            }else{
                if(cur > max){
                    max = cur;
                }
                cur = 0;
                con = 0;
            }
        }
        S[zIdx[i]] = 0;
    }


skip:    int risposta = max;

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("fib_soldatini_input_4.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
