#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N;
    int K;
    cin >> N >> K;
    vector<int> R(N);
    for (int i = 0; i < N; i++) cin >> R[i];

    int risposta = 42;
    int counter = 0;

    if(K > N+1) {
        risposta = counter;
    }else{
        int lMax = R[0];
        int maxIdx = 0;
        for (int i=0; i<k; i++){
            if (R[i] > lMax){
                lMax = R[i];
                maxIdx = i;
            }
        }
        K -= maxIdx;
        K += lMax;
        counter++;
        if(K > N-maxIdx+1){
            risposta = counter;
            goto nigga;
        }else{
            
        }
    }
    //Extra incompleto: ragionato con i range in cui possiamo arrivare purchase by purchase;
    //Prima pero controlliamo se blah blah blah bleh bleh bleh bluh bluh
nigga:
    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
