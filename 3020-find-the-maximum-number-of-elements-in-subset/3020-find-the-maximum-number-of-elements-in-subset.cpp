class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        for (auto [x, f] : cnt) {

            if (x == 1) {
                ans = max(ans, f - (f % 2 == 0));
                continue;
            }

            long long cur = x;
            int len = 0;

            while (true) {
                if (cnt[cur] == 1) {
                    len++;
                    break;
                }
                if (cnt[cur] < 2)
                    break;

                len += 2;
                if (!cnt.count(cur * cur)) {
                    len--;
                    break;
                }
                cur = cur * cur;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};