class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string prefix = "";

        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            if (freq[x] > 0) {
                //  common prefix
                prefix += target[i];
                freq[x]--;

                // Move to the next position
                continue;
            }


            // Now try to make the answer GREATER
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = prefix;

                    // Put the smallest character greater
                    ans += char('a' + c);

                    // Use that character.
                    freq[c]--;

                    //  Make the remaining suffix

                    for (int j = 0; j < 26; j++) {

                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }

            break;
        }

        // We could not make the answer greater at the current position
        // So go backwards through the common prefix
        for (int i = prefix.size() - 1; i >= 0; i--) {

            int x = target[i] - 'a';

            // Put back the character that was part of the common prefix.
            freq[x]++;

            prefix.pop_back();

            // Try to make the answer GREATER here
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = prefix;

                    // Put the smallest character greater
                    ans += char('a' + c);

                    // Use that character.
                    freq[c]--;

                    //  Make the remaining suffix

                    for (int j = 0; j < 26; j++) {

                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};