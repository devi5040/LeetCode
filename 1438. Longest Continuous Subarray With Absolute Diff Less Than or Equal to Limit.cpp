class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        int start = 0;
        int max_size = 0;

        deque<int> maxDeque;
        deque<int> minDeque;

        for (int end = 0; end < n; end++)
        {

            while (!maxDeque.empty() &&
                   nums[maxDeque.back()] < nums[end])
            {
                maxDeque.pop_back();
            }
            maxDeque.push_back(end);

            while (!minDeque.empty() &&
                   nums[minDeque.back()] > nums[end])
            {
                minDeque.pop_back();
            }
            minDeque.push_back(end);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit)
            {

                if (maxDeque.front() == start)
                    maxDeque.pop_front();

                if (minDeque.front() == start)
                    minDeque.pop_front();

                start++;
            }

            max_size = max(max_size, end - start + 1);
        }

        return max_size;
    }
};