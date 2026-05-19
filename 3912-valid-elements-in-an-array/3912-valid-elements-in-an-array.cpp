class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> pre(n), suf(n);
        vector<int> ans;

        pre[0] = nums[0];

        for(int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i]);
        }

        suf[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], nums[i]);
        }

        for(int i = 0; i < n; i++) {

            if(i == 0 || i == n - 1) {
                ans.push_back(nums[i]);
            }

            else if(nums[i] > pre[i - 1] ||
                    nums[i] > suf[i + 1]) {

                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};