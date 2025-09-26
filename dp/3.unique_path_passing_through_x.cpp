#include <bits/stdc++.h>
using namespace std;

class UniquePathsWithCheckpoint {
public:
    int solveMemo(int i, int j, int ex, int ey, vector<vector<int>> &dp) {
        if (i > ex || j > ey) return 0;   
        if (i == ex && j == ey) return 1; 
        if (dp[i][j] != -1) return dp[i][j];

        int right = solveMemo(i, j+1, ex, ey, dp);
        int down  = solveMemo(i+1, j, ex, ey, dp);

        return dp[i][j] = right + down;
    }

    int countPathsMemo(int sx, int sy, int ex, int ey) {
        vector<vector<int>> dp(ex+1, vector<int>(ey+1, -1));
        return solveMemo(sx, sy, ex, ey, dp);
    }


    int countPathsBottomUp(int sx, int sy, int ex, int ey) {
        int rows = ex - sx + 1;
        int cols = ey - sy + 1;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        dp[0][0] = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) continue;
                int up   = (i > 0) ? dp[i-1][j] : 0;
                int left = (j > 0) ? dp[i][j-1] : 0;
                dp[i][j] = up + left;
            }
        }
        return dp[rows-1][cols-1];
    }


    long long nCr(int N, int r) {
        long long res = 1;
        r = min(r, N-r);
        for (int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }
        return res;
    }

    long long countPathsCombi(int sx, int sy, int ex, int ey) {
        int down = ex - sx;
        int right = ey - sy;
        return nCr(down + right, down);
    }

 
    void solveCheckpoint(int m, int n, int x, int y) {
        cout << "Memoized DP: "
             << countPathsMemo(0, 0, x, y) * countPathsMemo(x, y, m-1, n-1)
             << endl;

        cout << "Bottom-Up DP: "
             << countPathsBottomUp(0, 0, x, y) * countPathsBottomUp(x, y, m-1, n-1)
             << endl;

        cout << "Combinatorics: "
             << countPathsCombi(0, 0, x, y) * countPathsCombi(x, y, m-1, n-1)
             << endl;
    }
};

int main() {
    UniquePathsWithCheckpoint solver;
    int m = 5, n = 5;
    int x = 2, y = 2;

    solver.solveCheckpoint(m, n, x, y);

    return 0;
}
