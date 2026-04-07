class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()) st.push(s[i]);
            else if(st.top()=='c' && s[i]=='b')
            {
                st.push(s[i]);
            } 
            else if(st.top()=='b' && s[i]=='a')
            {
                char temp = st.top();
                st.pop();
                if(!st.empty() && st.top()=='c') st.pop();
                else
                {
                    st.push(temp);
                    st.push(s[i]);
                } 
            }
            else
            {
                st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        return false;
    }
};