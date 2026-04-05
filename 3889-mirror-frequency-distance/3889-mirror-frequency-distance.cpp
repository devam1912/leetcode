class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> fc;

        // Step 1: count frequency
        for (char c : s) {
            fc[c]++;
        }

        int total = 0;
        unordered_set<char> visited;

        // Step 2: process each unique character
        for (auto &[c, freqc] : fc) {

            if (visited.count(c)) continue;

            char mirror;

            if (isalpha(c)) {
                mirror = 'z' - (c - 'a');
            } else {
                mirror = '0' + (9 - (c - '0'));
            }

            int freqm = fc.count(mirror) ? fc[mirror] : 0;

            total += abs(freqc - freqm);

            // mark both as visited to avoid double counting
            visited.insert(c);
            visited.insert(mirror);
        }

        return total;
    }
};