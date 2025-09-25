#include <bits/stdc++.h>
using namespace std;

int min_triangle_sum(int i, int j, int n, vector <vector <int>> &grid, vector <vector <int>> &dp) {
    if(i == n-1) return grid[i][j];
    if(dp[i][j] != INT_MAX) return dp[i][j];

    int down = grid[i][j] + min_triangle_sum(i+1, j, n, grid, dp);
    int dia = grid[i][j] + min_triangle_sum(i+1, j+1, n, grid, dp);

    return dp[i][j] = min(down, dia);
}

int main(int args, char* argv[]) {
    int n;
    cin >> n;

    vector <vector <int>>triangle(n);
    for(int i=0; i<n; i++) {
        triangle[i].resize(i+1);
        for(int j=0; j<=i; j++) {
            cin >> triangle[i][j];
        }
    }

    vector <vector <int>> dp(n, vector <int>(n+1, INT_MAX));
    int mini_triangle_sum = min_triangle_sum(0, 0, n, triangle, dp);
    
    cout << "Minimum triangle sum: " << mini_triangle_sum << "\n";
    
    return 0;
}