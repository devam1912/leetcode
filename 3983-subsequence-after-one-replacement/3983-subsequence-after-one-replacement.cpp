class Solution {
public:
    bool canMakeSubsequence(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<int> left(n, -1);
        vector<int> right(n, -1);

        // Prefix matching
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;

            if (j == m) break;

            left[i] = j;
            j++;
        }

        // Already a subsequence
        if (left[n - 1] != -1)
            return true;

        // Suffix matching
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;

            if (j < 0) break;

            right[i] = j;
            j--;
        }

        // Try replacing every position
        for (int i = 0; i < n; i++) {

            int L = -1;
            int R = m;

            if (i > 0) {
                if (left[i - 1] == -1) continue;
                L = left[i - 1];
            }

            if (i < n - 1) {
                if (right[i + 1] == -1) continue;
                R = right[i + 1];
            }

            if (R - L >= 2)
                return true;
        }

        return false;
    }
};