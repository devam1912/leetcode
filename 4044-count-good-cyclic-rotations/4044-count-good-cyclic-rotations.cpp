class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        vector<int> temp = nums;
        temp.insert(temp.end(), nums.begin(), nums.end());

        vector<long long> prefix(2 * n + 1, 0);

        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + temp[i];
        }

        int ans = 0;
        for (int start = 0; start < n; start++) {

            long long first = prefix[start + half] - prefix[start];
            long long second = prefix[start + n] - prefix[start + half];

            if (first > second) {
                ans++;
            }
        }

        return ans;
    }
};