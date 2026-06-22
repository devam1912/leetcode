class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> fs(26, 0), ft(26, 0);

        for (char c : s) fs[c - 'a']++;
        for (char c : target) ft[c - 'a']++;

        int ans = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (ft[i] > 0) {
                ans = min(ans, fs[i] / ft[i]);
            }
        }

        return ans;
    }
};  