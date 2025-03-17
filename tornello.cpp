#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int solve() {
    int N;
    cin >> N;

    int risposta = 0;  // memorizza qui la risposta
    int streak = 1;
    int balance = 0;
    int counter = 0;

    for (int i=0; i<N; i++) {
        int variazione;
        cin >> variazione;
        balance += variazione;
        counter++;
        if(balance == 0){
            if((counter/2) > streak) streak = (counter/2);
            counter = 0;
        }

        risposta == streak;
    }

    return abs(risposta);
}

int main() {

    freopen("tornello_input_2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);

    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
