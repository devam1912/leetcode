class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int target = n / 4;

        vector<int> count(128, 0);

        for (char c : s) count[c]++;

        if (count['Q'] == target &&
            count['W'] == target &&
            count['E'] == target &&
            count['R'] == target)
            return 0;

        int l = 0, r = 0;
        int ans = n;

        while (r < n) {
            count[s[r]]--;

            while (l <= r &&
                   count['Q'] <= target &&
                   count['W'] <= target &&
                   count['E'] <= target &&
                   count['R'] <= target) {

                ans = min(ans, r - l + 1);

                count[s[l]]++;
                l++;
            }

            r++;
        }

        return ans;
    }
};