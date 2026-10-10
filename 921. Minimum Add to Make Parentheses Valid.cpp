class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int count = 0;
        stack<char> st;

        for (char ch : s)
        {
            if (ch == '(' || st.empty())
                st.push(ch);
            else if (ch == ')' && st.top() == '(')
                st.pop();
            else
                st.push(ch);
        }

        return st.size();
    }
};