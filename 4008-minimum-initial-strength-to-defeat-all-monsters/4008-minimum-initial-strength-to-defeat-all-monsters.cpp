class Solution {
public:
    bool can(long long start, vector<int>& monsters, vector<long long>& bonus) {
        long long cur = start;

        for (int i = 0; i < monsters.size(); i++) {

            if (cur + bonus[i] < monsters[i])
                return false;

            cur -= monsters[i];

            if (cur < 0)
                cur = 0;
        }

        return true;
    }

    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {

        int n = monsters.size();

        vector<long long> diff(n + 1, 0);

        // Difference array set l and r+1
        for (auto &b : boosts) {
            int l = b[0];
            int r = b[1];
            int v = b[2];

            diff[l] += v;
            if (r + 1 < n)
                diff[r + 1] -= v;
        }

        // Prefix -> bonus at every index
        vector<long long> bonus(n);

        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            bonus[i] = cur;
        }

        long long lo = 0;
        long long hi = 0;

        for (int x : monsters)
            hi += x;          // Always sufficient

        while (lo < hi) {

            long long mid = lo + (hi - lo) / 2;

            if (can(mid, monsters, bonus))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};