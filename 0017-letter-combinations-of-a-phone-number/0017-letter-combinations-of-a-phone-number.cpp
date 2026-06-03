class Solution {
private:
    void solve(string &digits, string &output, int index, vector<string> &ans, vector<string> &mapping)
    {
        if(index == digits.size())
        {
            ans.push_back(output);
            return;
        }

        int num = digits[index] - '0';
        string &letters = mapping[num];

        for(char ch : letters)
        {
            output.push_back(ch);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if(digits.empty())
            return ans;

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        string output = "";

        solve(digits, output, 0, ans, mapping);

        return ans;
    }
};