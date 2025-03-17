#include <cstdio>
#include <iostream>

using namespace std;

void solve(int t) {
    int N, K;
    cin >> N >> K;

    int risposta = 42;

    // aggiungi codice...

    cout << "Case #" << t << ": " << risposta << endl;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        solve(t);
    }
}
