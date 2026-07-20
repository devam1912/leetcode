class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> store;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                store.push_back(grid[i][j]);
            }
        }

        int s = store.size();
        k %= s;

        reverse(store.begin(), store.end());
        reverse(store.begin(), store.begin() + k);
        reverse(store.begin() + k, store.end());

        vector<vector<int>> ans(n, vector<int>(m));

        int idx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = store[idx++];
            }
        }

        return ans;
    }
};