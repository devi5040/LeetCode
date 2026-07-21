class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq, fr;
        for (int n : arr)
            freq[n]++;

        for (auto [key, value] : freq)
        {
            if (fr.find(value) != fr.end())
                return false;
            fr[value] = key;
        }

        return true;
    }
};