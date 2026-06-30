class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string s : tokens)
        {
            if (s != "+" && s != "-" && s != "*" && s != "/")
                st.push(stoi(s));
            else
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                char ch = s[0];
                switch (ch)
                {
                case '+':
                    st.push(num2 + num1);
                    break;
                case '-':
                    st.push(num2 - num1);
                    break;
                case '*':
                    st.push(num2 * num1);
                    break;
                default:
                    st.push(num2 / num1);
                    break;
                }
            }
        }
        return st.top();
    }
};