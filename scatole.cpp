// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solveCase(int A, int B) {
    int target = A + B;
    int n = 0;
    while ((n * (n + 1)) / 2 < target) {
        n++;
    }
    if ((n * (n + 1)) / 2 != target) {
        return "IMPOSSIBILE";
    }

    vector<int> box1, box2;
    int sumA = 0, sumB = 0;

    for (int i = n; i >= 1; --i) {
        if (sumA + i <= A) {
            sumA += i;
            box1.push_back(i);
        } else {
            sumB += i;
            box2.push_back(i);
        }
    }

    if (sumA != A || sumB != B) {
        return "IMPOSSIBILE";
    }

    string result = "";
    for (int i = 1; i <= n; ++i) {
        if (find(box1.begin(), box1.end(), i) != box1.end()) {
            result += "1";
        } else {
            result += "2";
        }
    }
    return result;
}


int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("scatole_input_2.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int A, B;
        cin >> A >> B;

        string X = "121";

        X = solveCase(A,B);

        cout << "Case #" << test << ": " << X << endl;
    }

    return 0;
}
