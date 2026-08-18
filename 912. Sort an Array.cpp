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

// Heap Sort
class Solution
{
public:
    void heapify(vector<int> &nums, int n, int i)
    {
        int largest = i;

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && nums[largest] < nums[l])
            largest = l;

        if (r < n && nums[largest] < nums[r])
            largest = r;

        if (largest != i)
        {
            swap(nums[largest], nums[i]);

            heapify(nums, n, largest);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();

        // build heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[i], nums[0]);

            heapify(nums, i, 0);
        }

        return nums;
    }
};