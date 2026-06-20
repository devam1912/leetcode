class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        long long MOD = 1e9 + 7;

        // Difference array
        vector<long long> freq(n + 1, 0);

        for (int i = 0; i < requests.size(); i++) {

            int start = requests[i][0];
            int end = requests[i][1];

            freq[start]++;

            //for making the frequency vector clearly
            if (end + 1 < n)
                freq[end + 1]--;
        }

        // Convert difference array to actual frequencies
        for (int i = 1; i < n; i++) {
            freq[i] += freq[i - 1];
        }

        // Remove extra element
        freq.pop_back();

        // Greedy: largest number ↔ largest frequency
        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans = (ans + (freq[i] * nums[i]) % MOD) % MOD;
        }

        return (int)ans;
    }
};