class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);

        for (char c : chars) {
            freq[c - 'a']++;
        }

        int ans = 0;

        for (string word : words) {
            vector<int> subf(26, 0);

            for (char c : word) {
                subf[c - 'a']++;
            }

            bool check = true;

            for (int i = 0; i < 26; i++) {
                if (subf[i] > freq[i]) {
                    check = false;
                    break;
                }
            }

            if (check) {
                ans += word.size();
            }
        }

        return ans;
    }
};