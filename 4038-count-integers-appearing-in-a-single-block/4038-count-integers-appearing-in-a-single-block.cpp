class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; ) {
            int x = nums[i];
            int count = 0;

            while (i < n && nums[i] == x) {
                i++;
                count++;
            }

            if (count == freq[x]) {
                ans++;
            }
        }

        return ans;
    }
};