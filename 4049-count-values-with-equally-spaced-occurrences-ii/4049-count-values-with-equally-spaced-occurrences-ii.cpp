class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;

        for (auto& [x, indices] : pos) {

            if (indices.size() < 3)
                continue;

            int diff = indices[1] - indices[0];

            bool special = true;

            for (int i = 2; i < indices.size(); i++) {
                if (indices[i] - indices[i - 1] != diff) {
                    special = false;
                    break;
                }
            }

            if (special)
                ans++;
        }

        return ans;
    }
};