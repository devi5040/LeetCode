class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> counts;
        stack<string> strings;

        string current;
        int number = 0;

        for (char ch : s)
        {
            if (isdigit(ch))
            {
                number = number * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                counts.push(number);
                strings.push(current);

                number = 0;
                current.clear();
            }
            else if (ch == ']')
            {
                string temp = current;

                current = strings.top();
                strings.pop();

                int repeat = counts.top();
                counts.pop();

                while (repeat--)
                {
                    current += temp;
                }
            }
            else
            {
                current += ch;
            }
        }

        return current;
    }
};