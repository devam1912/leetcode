class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        // forward[i] = cost to move i -> i+1
        vector<long long> forward(n - 1);

        // backward[i] = cost to move i+1 -> i
        vector<long long> backward(n - 1);

        // Build forward costs
        for(int i = 0; i < n - 1; i++) {

            bool isClosest = false;

            if(i == 0) {
                isClosest = true;
            }
            else {
                long long left  = nums[i] - nums[i - 1];
                long long right = nums[i + 1] - nums[i];

                if(right < left)
                    isClosest = true;
            }

            if(isClosest)
                forward[i] = 1;
            else
                forward[i] = nums[i + 1] - nums[i];
        }

        // Build backward costs
        for(int i = 1; i < n; i++) {

            bool isClosest = false;

            if(i == n - 1) {
                isClosest = true;
            }
            else {
                long long left  = nums[i] - nums[i - 1];
                long long right = nums[i + 1] - nums[i];

                if(left <= right)
                    isClosest = true;
            }

            if(isClosest)
                backward[i - 1] = 1;
            else
                backward[i - 1] = nums[i] - nums[i - 1];
        }

        // Prefix sums
        vector<long long> prefF(n, 0), prefB(n, 0);

        for(int i = 1; i < n; i++) {
            prefF[i] = prefF[i - 1] + forward[i - 1];
            prefB[i] = prefB[i - 1] + backward[i - 1];
        }

        vector<int> ans;

        for(auto &q : queries) {

            int l = q[0];
            int r = q[1];

            long long cost;

            if(l < r) {
                cost = prefF[r] - prefF[l];
            }
            else {
                cost = prefB[l] - prefB[r];
            }

            ans.push_back((int)cost);
        }

        return ans;
    }
};