#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main () {
    // Initialize pail size variables.
    int pailSizeS,
        pailSizeM,
        pailSizeL;  

    // Create filestreams.
    ofstream fout("pails.out");
    ifstream fin("pails.in");

    // Parse inputs to variables.
    fin >> pailSizeS >> pailSizeM >> pailSizeL;

    int mpAmtS = pailSizeL / pailSizeS; // Maximum number of of small pails that will fit into the large pail.
    int mpAmtM = pailSizeL / pailSizeM; // Maximum number of medium pails that will fit into the large pail.

    int pAmtS = mpAmtS; // Start at the maximum amount of small pails that can fit in the large pail.
    int pAmtM = 0; // Start at zero medium pails.

    int ans = mpAmtS * pailSizeS; // Initialize answer.

    // While the total volume is less than the volume of the large pail, and the number of medium pails is less than the maximum
    // number of medium pails that can fit, add a medium pail to the combination and adjust small accordingly, seeing if it is
    // possible to get a higher volume out of a different combination.
    while((pAmtS * pailSizeS + pAmtM * pailSizeM) <= pailSizeL && pAmtM < mpAmtM) {
        pAmtM++; // Add a medium pail.

        // Remove as many small pails necessary until the addition of the medium pail can be made to fit into the large pail.
        while((pAmtS * pailSizeS + pAmtM * pailSizeM) > pailSizeL) pAmtS--;

        // If more volume has been filled than previous answer, choose this as the answer.
        ans = max(ans, (pAmtS * pailSizeS + pAmtM * pailSizeM));

        if (ans == pailSizeL) break; // Break out of the loop if we have already reached the equivalent value (to discard equivalent iterations).
    }

    // Write answer to output file.
    fout << ans;
}
