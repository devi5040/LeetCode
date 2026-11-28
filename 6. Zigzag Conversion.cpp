class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.size();
        int step = 2 * (numRows - 1);

        if (numRows == 1 || n <= numRows)
            return s;

        string result(n, ' ');
        int index = 0;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = i; j < n; j += step)
            {
                result[index++] = s[j];

                if (i != 0 && i != numRows - 1)
                {
                    int mid = j + step - (2 * i);
                    if (mid < n)
                        result[index++] = s[mid];
                }
            }
        }

        return result;
    }
};