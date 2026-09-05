class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        int sum = 0;

        if (nums1.size() == 1)
            return true;
        int mini = *min_element(nums1.begin(), nums1.end());
        bool isEven = mini % 2 == 0;

        for (int num : nums1)
        {
            bool isNumModEven = num % 2 == 0;
            if (num == mini || isEven == isNumModEven)
                continue;
            isNumModEven = (num - mini) % 2 == 0;
            if (isEven == isNumModEven)
                continue;
            return false;
        }
        return true;
    }
};