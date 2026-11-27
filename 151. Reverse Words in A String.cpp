class Solution
{
public:
    string reverseWords(string s)
    {
        // Step 1: Remove extra spaces
        int n = s.size();
        string temp;

        int i = 0;
        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++; // skip spaces
            if (i >= n)
                break;

            if (!temp.empty())
                temp += ' ';

            int j = i;
            while (j < n && s[j] != ' ')
                j++;

            temp += s.substr(i, j - i);
            i = j;
        }

        // Step 2: Reverse whole string
        reverse(temp.begin(), temp.end());

        // Step 3: Reverse each word
        int start = 0;
        for (int end = 0; end <= temp.size(); end++)
        {
            if (end == temp.size() || temp[end] == ' ')
            {
                reverse(temp.begin() + start, temp.begin() + end);
                start = end + 1;
            }
        }

        return temp;
    }
};

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        stringstream ss(s);
        string word;
        string res;

        while (ss >> word)
            st.push(word);

        while (!st.empty())
        {
            res += st.top();
            st.pop();
            if (!st.empty())
                res += ' ';
        }

        return res;
    }
};