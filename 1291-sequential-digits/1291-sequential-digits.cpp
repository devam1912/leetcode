class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string s = "123456789";
        vector<int> ans;

        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();

        // Try every possible length
        for (int len = lowLen; len <= highLen; len++) {

            // Sliding window all the subtrings
            for (int i = 0; i + len <= 9; i++) {

                int num = stoi(s.substr(i, len));

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};