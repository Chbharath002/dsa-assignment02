#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1005;
int dp[MAXN][MAXN];

string lcs(string s1, string s2) {
    int n = s1.length(), m = s2.length();

    // base case: LCS of empty strings is empty string
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    // fill up the dp table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // backtrack to find LCS
    int i = n, j = m;
    string lcs_str = "";
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            lcs_str = s1[i-1] + lcs_str;
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return lcs_str;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    string lcs_str = lcs(s1, s2);
    cout << "The Longest Common Subsequence is: " << lcs_str << endl;

    return 0;
}
