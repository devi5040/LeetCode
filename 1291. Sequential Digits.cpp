class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int lowDigits = 0, highDigits = 0, temp_l = low, temp_h = high;
        vector<int> result;
        while (temp_l > 0)
        {
            lowDigits++;
            temp_l /= 10;
        }
        while (temp_h > 0)
        {
            highDigits++;
            temp_h /= 10;
        }
        string s = "123456789";
        for (int i = lowDigits; i <= highDigits; i++)
        {
            int start = 0;
            while (start < 10 - i)
            {
                string sub = s.substr(start, i);
                if (stoi(sub) >= low && stoi(sub) <= high)
                    result.push_back(stoi(sub));
                if (stoi(sub) > high)
                    break;
                start++;
            }
        }
        return result;
    }
};