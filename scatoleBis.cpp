#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string toBin(int num) {
    if (num == 0) {
        return "0";
    }

    string binary = "";

    while (num > 0) {
        binary += (num % 2 == 0) ? '0' : '1';
        num /= 2;
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int A, B;
        cin >> A >> B;

        string X = "121";
        string a,b;


        if((A & b) != 0) {
            X = "IMPOSSIBLE";
        }else{
            X = "";
            a = toBin(A);
            b = toBin(B);
            if(a.length() > b.length()) {
                for(int i=0; i<b.length(); i++){
                    if(a[i] == '1') X += '1';
                    else X += '2';
                }
                for(int i=0; i<( a.length()-b.length() ); i++) {
                    X += '1';
                }
            }else {
                for(int i=0; i<a.length(); i++){
                    if(b[i] == '1') X += '1';
                    else X += '2';
                }
                for(int i=0; i<( b.length()-b.length() ); i++) {
                    X += '2';
                }
            }
        }

        cout << "Case #" << test << ": " << X << endl;
    }

    return 0;
}
