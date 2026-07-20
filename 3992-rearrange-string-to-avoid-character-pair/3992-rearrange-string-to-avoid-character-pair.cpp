class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        string others = "";
        int cntX = 0, cntY = 0;

        for (char ch : s) {
            if (ch == x)
                cntX++;
            else if (ch == y)
                cntY++;
            else
                others += ch;
        }

        return string(cntY, y) + others + string(cntX, x);
    }
};