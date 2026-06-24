/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Scoring Scheme
const int MATCH = 1;
const int MISMATCH = -1;
const int GAP = -2;

void alignSequences(const string& seqA, const string& seqB) {
    int m = seqA.length();
    int n = seqB.length();

    // 2D DP Matrix initialization: (m+1) x (n+1) filled with 0s
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base cases: Initialize first row and column with gap penalties
    for (int i = 0; i <= m; ++i) dp[i][0] = i * GAP;
    for (int j = 0; j <= n; ++j) dp[0][j] = j * GAP;

    // Fill the DP Matrix
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int matchScore = (seqA[i - 1] == seqB[j - 1]) ? MATCH : MISMATCH;
            
            int diagonal = dp[i - 1][j - 1] + matchScore;
            int up = dp[i - 1][j] + GAP;
            int left = dp[i][j - 1] + GAP;

            dp[i][j] = max({diagonal, up, left});
        }
    }

    // Backtracking to find the optimal path/alignment
    string alignedA = "";
    string alignedB = "";
    int i = m, j = n;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + ((seqA[i - 1] == seqB[j - 1]) ? MATCH : MISMATCH)) {
            alignedA += seqA[i - 1];
            alignedB += seqB[j - 1];
            i--; j--;
        } 
        else if (i > 0 && dp[i][j] == dp[i - 1][j] + GAP) {
            alignedA += seqA[i - 1];
            alignedB += '-';
            i--;
        } 
        else {
            alignedA += '-';
            alignedB += seqB[j - 1];
            j--;
        }
    }

    // Since we traced backward from the end, reverse the final strings
    reverse(alignedA.begin(), alignedA.end());
    reverse(alignedB.begin(), alignedB.end());

    // Print Results
    cout << "\n=== Global Sequence Alignment Results ===" << endl;
    cout << "Optimal Alignment Score: " << dp[m][n] << endl << endl;
    cout << "Sequence A: " << alignedA << endl;
    cout << "Sequence B: " << alignedB << endl;
}

int main() {
    cout << "Enter DNA/RNA Sequence A: ";
    string seqA;
    cin >> seqA;

    cout << "Enter DNA/RNA Sequence B: ";
    string seqB;
    cin >> seqB;

    alignSequences(seqA, seqB);

    return 0;
}