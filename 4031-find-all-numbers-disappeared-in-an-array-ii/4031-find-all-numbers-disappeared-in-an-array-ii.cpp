class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int i = 0;
        int x = lower;

        while (x <= upper) {

            while (i < nums.size() && nums[i] < x)
                i++;

            if (i < nums.size() && nums[i] == x) {
                i++;
                x++;
                continue;
            }
            int start = x;

            while (x <= upper) {
                while (i < nums.size() && nums[i] < x)
                    i++;

                if (i < nums.size() && nums[i] == x)
                    break;

                x++;
            }
            ans.push_back({start, x - 1});
        }

        return ans;
    }
};