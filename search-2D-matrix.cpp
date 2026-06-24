class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = (m * n) - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            int mid_r = mid / n, mid_c = mid % n;
            if (target == matrix[mid_r][mid_c])
                return true;
            if (target > matrix[mid_r][mid_c])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};