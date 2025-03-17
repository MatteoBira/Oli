#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ifstream cin("caramelle_input_4.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> V(N);
        for (int i = 0; i < N; ++i)
            cin >> V[i];

        int c = V[0];
        for (int i = 1; i < N; ++i) {
            c = lcm(c, V[i]);
        }

        cout << "Case #" << test << ": ";
        cout << c << endl;
    }

    return 0;
}