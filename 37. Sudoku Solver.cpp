class Solution
{
public:
    bool place_candidate(vector<vector<char>> &board, int row, int col, int current)
    {
        char cur = '0' + current;

        for (int i = 0; i < 9; i++)
            if (board[row][i] == cur || board[i][col] == cur)
                return false;

        int r = row - row % 3, c = col - col % 3;

        for (int i = r; i < r + 3; i++)
            for (int j = c; j < c + 3; j++)
                if (board[i][j] == cur)
                    return false;

        board[row][col] = cur;
        return true;
    }

    bool backtrack(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] != '.')
                    continue;

                for (int current = 1; current <= 9; current++)
                {
                    if (place_candidate(board, row, col, current))
                    {
                        if (backtrack(board))
                            return true;
                        board[row][col] = '.';
                    }
                }

                if (board[row][col] == '.')
                    return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        backtrack(board);
    }
};