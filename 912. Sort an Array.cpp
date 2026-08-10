class Solution
{
public:
    vector<int> merge(vector<int> leftArray, vector<int> rightArray)
    {
        int left_size = leftArray.size(), right_size = rightArray.size();
        int left_cursor = 0, right_cursor = 0;
        vector<int> merged_array;
        while (left_cursor < left_size && right_cursor < right_size)
        {
            if (leftArray[left_cursor] < rightArray[right_cursor])
            {
                merged_array.push_back(leftArray[left_cursor]);
                left_cursor++;
            }
            else
            {
                merged_array.push_back(rightArray[right_cursor]);
                right_cursor++;
            }
        }
        while (left_cursor < left_size)
        {
            merged_array.push_back(leftArray[left_cursor]);
            left_cursor++;
        }
        while (right_cursor < right_size)
        {
            merged_array.push_back(rightArray[right_cursor]);
            right_cursor++;
        }

        return merged_array;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return nums;
        int mid = n / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> left_array = sortArray(left);
        vector<int> right(nums.begin() + mid, nums.begin() + n);
        vector<int> right_array = sortArray(right);
        return merge(left_array, right_array);
    }
};