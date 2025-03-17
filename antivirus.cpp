#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fdMin(string f1,string f2,string f3,string f4,string*& pos){
    int min = f1.size();
    pos = &f1;

    if(f2.size() < min) {
        min = f2.size();
        pos = &f2;
    }
    if(f3.size() < min){
        min = f3.size();
        pos = &f3;
    }
    if(f4.size() < min){
        min = f4.size();
        pos = &f4;
    }
    return min;
}

int find(string str, string sub){
    for(int i=0; i<str.size(); i++){
        if(str.substr(i, sub.size()) == sub){
            return i;
        }
    }
    return -1;
}

int main() {
     ifstream cin("antivirus_input_2.txt");
     ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N1, N2, N3, N4;
        cin >> N1 >> N2 >> N3 >> N4;

        int M;
        cin >> M;

        string F1;
        cin >> F1;

        string F2;
        cin >> F2;

        string F3;
        cin >> F3;

        string F4;
        cin >> F4;

        int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
        int idx1 = -2, idx2 = -2, idx3 = -2, idx4 = -2;


        string* pos = nullptr;
        for(int i=0; i<fdMin(F1,F2,F3,F4,pos)-M; i++){
            string sub = pos->substr(i,M);
            idx1 = -2; idx2 = -2; idx3 = -2; idx4 = -2;
            p1 = i; p2 = i; p3 = i; p4 = i;

            if(pos != &F1){
                idx1 = find(F1,sub);
                if(idx1 == -1) continue;
                p1 = idx1;
            }
            if(pos != &F2){
                idx2 = find(F2,sub);
                if(idx2 == -1) continue;
                p2 = idx2;
            }
            if(pos != &F3){
                idx3 = find(F3,sub);
                if(idx3 == -1) continue;
                p3 = idx3;
            }
            if(pos != &F4){
                idx4 = find(F4,sub);
                if(idx4 == -1) continue;
                p4 = idx4;
            }
            break;
        }


        cout << "Case #" << test << ": ";
        cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    }

    return 0;
}
