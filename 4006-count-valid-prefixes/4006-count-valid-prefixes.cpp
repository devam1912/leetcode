class Solution {
public:
    int countValidPrefixes(string s) {
        int c0 = 0, c1 = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '0')
                c0++;
            else
                c1++;

            if (abs(c0 - c1) <= 1)
                ans++;
        }

        return ans;
    }
};