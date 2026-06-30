class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        // Sort intervals by start time
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        // Merge overlapping or touching intervals
        int s = occupiedIntervals[0][0];
        int e = occupiedIntervals[0][1];

        for (int i = 1; i < occupiedIntervals.size(); i++) {
            int ns = occupiedIntervals[i][0];
            int ne = occupiedIntervals[i][1];

            // Merge if intervals overlap or touch
            if (ns <= e + 1) {
                e = max(e, ne);
            } else {
                merged.push_back({s, e});
                s = ns;
                e = ne;
            }
        }

        // Add the last merged interval
        merged.push_back({s, e});

        vector<vector<int>> ans;

        // Remove the free interval from each merged interval
        for (auto &interval : merged) {
            int l = interval[0];
            int r = interval[1];

            // No overlap with free interval
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
            }
            // Overlap exists
            else {
                // Left portion remains
                if (l < freeStart) {
                    ans.push_back({l, freeStart - 1});
                }

                // Right portion remains
                if (r > freeEnd) {
                    ans.push_back({freeEnd + 1, r});
                }
            }
        }

        return ans;
    }
};