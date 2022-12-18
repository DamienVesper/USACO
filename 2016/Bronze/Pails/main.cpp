#include <iostream>
#include <fstream>

using namespace std;

int main () {
    int X, Y, Z;
    int ans = 0;

    ofstream fout("pails.out");
    ifstream fin("pails.in");

    fin >> X >> Y >> Z;

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            int newAns = (X * i) + (Y * j);
            if (newAns <= Z) ans = max(ans, newAns);
        }
    }

    fout << ans;
}
