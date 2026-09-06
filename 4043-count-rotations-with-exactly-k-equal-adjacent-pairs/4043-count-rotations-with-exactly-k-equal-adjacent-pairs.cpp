class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();

        string temp = s + s;

        int ans = 0;

        for (int start = 0; start < n; start++) {
            int score = 0;

            for (int i = start; i < start + n - 1; i++) {
                if (temp[i] == temp[i + 1]) {
                    score++;
                }
            }

            if (score == k) {
                ans++;
            }
        }

        return ans;
    }
};