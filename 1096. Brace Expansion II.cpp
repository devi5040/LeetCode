class Solution
{
public:
    string expression;
    int pos;

    set<string> parseExpression()
    {
        set<string> result = parseTerm();

        while (pos < expression.size() && expression[pos] == ',')
        {
            pos++; // skip ','

            set<string> right = parseTerm();

            result.insert(right.begin(), right.end());
        }

        return result;
    }

    set<string> parseTerm()
    {
        set<string> result = {""};

        while (pos < expression.size() &&
               expression[pos] != '}' &&
               expression[pos] != ',')
        {

            set<string> factor = parseFactor();

            set<string> next;

            for (const string &a : result)
            {
                for (const string &b : factor)
                {
                    next.insert(a + b);
                }
            }

            result = next;
        }

        return result;
    }

    set<string> parseFactor()
    {
        if (expression[pos] == '{')
        {
            pos++; // skip '{'

            set<string> result = parseExpression();

            pos++; // skip '}'

            return result;
        }

        // Normal character
        string s(1, expression[pos]);
        pos++;

        return {s};
    }

public:
    vector<string> braceExpansionII(string expression)
    {
        this->expression = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};