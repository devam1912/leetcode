class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        vector<vector<int>> ans;

        int i = 0, j = 0;
        int n = series1.size();
        int m = series2.size();

        while (i < n || j < m) {

            if (j == m || (i < n && series1[i][0] < series2[j][0])) {

                int sum = series1[i][1] + (j < m ? series2[j][1] : 0);
                ans.push_back({series1[i][0], sum});
                i++;
            }
            else if (i == n || series2[j][0] < series1[i][0]) {

                int sum = (i < n ? series1[i][1] : 0) + series2[j][1];
                ans.push_back({series2[j][0], sum});
                j++;
            }
            else {

                int sum = series1[i][1] + series2[j][1];
                ans.push_back({series1[i][0], sum});
                i++;
                j++;
            }
        }

        return ans;
    }
};