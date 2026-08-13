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