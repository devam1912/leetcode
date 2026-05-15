class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {

        // Step 1: concatenate all chunks
        string s = "";

        for (string &part : chunks) {
            s += part;
        }

        unordered_map<string, int> freq;

        string curr = "";
        int n = s.size();

        // Step 2: extract words
        for (int i = 0; i < n; i++) {

            char c = s[i];

            bool valid = false;

            // lowercase letter
            if (c >= 'a' && c <= 'z') {
                valid = true;
            }

            // check joiner hyphen
            else if (c == '-') {

                if (i > 0 && i < n - 1 &&
                    s[i - 1] >= 'a' && s[i - 1] <= 'z' &&
                    s[i + 1] >= 'a' && s[i + 1] <= 'z') {

                    valid = true;
                }
            }

            // build current word
            if (valid) {
                curr += c;
            }
            else {
                // separator found
                if (!curr.empty()) {
                    freq[curr]++;
                    curr = "";
                }
            }
        }

        // last word
        if (!curr.empty()) {
            freq[curr]++;
        }

        // Step 3: answer queries
        vector<int> ans;

        for (string &q : queries) {
            ans.push_back(freq[q]);
        }

        return ans;
    }
};