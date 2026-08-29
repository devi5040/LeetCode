class Solution
{
public:
    vector<string> largestString(vector<int> &nums)
    {
        vector<string> result;

        for (int num : nums)
        {
            int step = 0;
            string str = "";
            while (num)
            {
                if (num & 1)
                {
                    if (step < 26)
                        str = char('a' + step) + str;
                    else
                        str = "zz" + str;
                }
                num >>= 1;
                step++;
            }
            result.push_back(str);
        }

        return result;
    }
};