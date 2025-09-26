#include <bits/stdc++.h>
using namespace std;

class UniquePaths {
public:
    // 1. Recursive + Memoization
    int unique_paths_memo(int i, int j, int n, int m, vector<vector<int>>& dp) {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = unique_paths_memo(i, j-1, n, m, dp);
        int up   = unique_paths_memo(i-1, j, n, m, dp);
        return dp[i][j] = left + up;
    }

    int solve_memo(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return unique_paths_memo(n-1, m-1, n, m, dp);
    }

    // 2. Bottom-Up DP (Tabulation)
    int solve_tabulation(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) dp[i][j] = 1;
                else {
                    int up   = (i>0) ? dp[i-1][j] : 0;
                    int left = (j>0) ? dp[i][j-1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }

    // 3. Space Optimized DP
    int solve_space_optimized(int n, int m) {
        vector<int> prev(m, 0);
        for(int i=0; i<n; i++) {
            vector<int> temp(m, 0);
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) temp[j] = 1;
                else {
                    int up   = (i>0) ? prev[j] : 0;
                    int left = (j>0) ? temp[j-1] : 0;
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[m-1];
    }

    // 4. Combinatorics
    int solve_combinatorics(int n, int m) {
        long long res = 1;
        int N = n + m - 2;        // total moves
        int r = min(n-1, m-1);    // choose smaller
        for(int i=1; i<=r; i++) {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};

int main() {
    UniquePaths solver;
    int n = 3, m = 7;

    cout << "Recursive + Memoization: " << solver.solve_memo(n, m) << endl;
    cout << "Bottom-Up DP: " << solver.solve_tabulation(n, m) << endl;
    cout << "Space Optimized DP: " << solver.solve_space_optimized(n, m) << endl;
    cout << "Combinatorics: " << solver.solve_combinatorics(n, m) << endl;

    return 0;
}
