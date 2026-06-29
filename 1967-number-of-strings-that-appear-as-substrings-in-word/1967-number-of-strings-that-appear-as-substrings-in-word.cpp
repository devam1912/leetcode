class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string &p : patterns) {
            if (word.find(p) != -1)
                count++;
        }

        return count;
    }
};