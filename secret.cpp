#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
     ifstream cin("input.txt");
     ofstream cout("output.txt");

    int T;
    T=1;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, F, C;
        cin >> N >> F >> C;

        int nf = 0, nc = 0;

        nf = N/F;
        nc = (N%F)/C;

        cout << "Case #" << test << ": ";
        cout << nf << " " << nc << endl;
    }

    return 0;
}
