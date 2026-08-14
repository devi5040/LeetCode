class Solution
{
public:
    bool search(vector<vector<int>> &matrix, int rstart, int rend, int cstart, int cend, int target)
    {
        if (rstart < 0 || rend > matrix.size() || cstart < 0 || cend > matrix[0].size() || rstart > rend || cstart > cend)
            return false;
        if (rend == rstart && cend == cstart)
            return target == matrix[rstart][cstart];
        int pivot_r = (rend + rstart) / 2;
        int pivot_c = (cend + cstart) / 2;
        int mid = matrix[pivot_r][pivot_c];
        if (mid == target)
            return true;
        else if (mid > target)
            return search(matrix, rstart, pivot_r - 1, cstart, pivot_c - 1, target) || search(matrix, rstart, pivot_r - 1, pivot_c, cend, target) || search(matrix, pivot_r, rend, cstart, pivot_c - 1, target);
        else
            return search(matrix, pivot_r + 1, rend, pivot_c + 1, cend, target) || search(matrix, rstart, pivot_r, pivot_c + 1, cend, target) || search(matrix, pivot_r + 1, rend, cstart, pivot_c, target);
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        return search(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
    }
};

// removing 2 squares
class Solution
{
public:
    bool search(vector<vector<int>> &matrix, int rstart, int rend, int cstart, int cend, int target)
    {
        if (rstart < 0 || rend >= matrix.size() || cstart < 0 || cend >= matrix[0].size() || cstart > cend || rstart > rend)
            return false;
        if (rend == rstart)
        {
            for (int i = cstart; i <= cend; i++)
                if (matrix[rstart][i] == target)
                    return true;
            return false;
        }

        if (cend == cstart)
        {
            for (int i = rstart; i <= rend; i++)
                if (matrix[i][cstart] == target)
                    return true;
            return false;
        }

        int mid = cstart + (cend - cstart) / 2;
        int start = rstart;
        while (start < rend && matrix[start][mid] < target)
            start++;
        if (matrix[start][mid] == target)
            return true;

        // Entire middle column is smaller than target
        if (start == rend && matrix[start][mid] < target)
            return search(matrix, rstart, rend, mid + 1, cend, target);

        // Otherwise matrix[start][mid] > target,
        // so split into bottom-left and top-right.
        return search(matrix, start, rend, cstart, mid - 1, target) ||
               search(matrix, rstart, start - 1, mid + 1, cend, target);
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;
        return search(matrix, 0, m - 1, 0, n - 1, target);
    }
};