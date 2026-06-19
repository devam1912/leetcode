class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {

        if (units[0].size() == 1) {
            long long ans = 0;
            for (auto &row : units) ans += row[0];
            return ans;
        }

        long long sum = 0;
        int globalMin = INT_MAX;
        int minSecond = INT_MAX;

        for (int i = 0; i < units.size(); i++) {
            sort(units[i].begin(), units[i].end());

            globalMin = min(globalMin, units[i][0]);
            minSecond = min(minSecond, units[i][1]);

            sum += units[i][1];
        }

        return sum - minSecond + globalMin;
    }
};