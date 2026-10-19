class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift,vector<int>& colShift) 
    {

        vector<vector<int>> temp(n, vector<int>(n));
        vector<vector<int>> ans(n, vector<int>(n));

        // Shift rows to the left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][(j - rowShift[i] + n) % n] = grid[i][j];
            }
        }

        // Shift columns upward
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                ans[(i - colShift[j] + n) % n][j] = temp[i][j];
            }
        }

        return ans;
    }
};