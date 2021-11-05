#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main () {
    int pailSizeS,
        pailSizeM,
        pailSizeL;  

    ofstream fout("pails.out");
    ifstream fin("pails.in");

    fin >> pailSizeS >> pailSizeM >> pailSizeL;

    int mpAmtS = floor(pailSizeL / pailSizeS);
    int mpAmtM = floor(pailSizeL / pailSizeM);

    cout << mpAmtS << endl << mpAmtM << endl;

    int pAmtS = mpAmtS;
    int pAmtM = 0;

    int totalAmount = 1001;
    int i = 0;
    do {
        i++;

        pAmtS--;
        pAmtM++;

        totalAmount = pAmtS * pailSizeS + pAmtM * pailSizeM;

        cout << "--------- ATTEMPT " << i << " ---------" << endl;
        cout << "S: " << pAmtS << endl;
        cout << "M: " << pAmtM << endl;
        cout << "T: " << totalAmount << endl;
    }
    while (totalAmount <= pailSizeL && pAmtS > 0);

    pAmtS++;
    pAmtM--;

    totalAmount = pAmtS * pailSizeS + pAmtM * pailSizeM;

    cout << "--------- FINAL RESPONSE ---------" << endl;
    cout << "S: " << pAmtS << endl;
    cout << "M: " << pAmtM << endl;
    cout << "T: " << totalAmount << endl;

    fout << totalAmount;
}
