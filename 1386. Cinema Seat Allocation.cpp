class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        int count = 2 * n;

        unordered_map<int, vector<int>> reserved;

        for (int i = 0; i < reservedSeats.size(); i++)
            reserved[reservedSeats[i][0]].push_back(reservedSeats[i][1]);

        for (auto &[rows, seats] : reserved)
        {
            int mask = 0;

            for (int seat : seats)
                mask |= (1 << seat);

            int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
            int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
            int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight)
                continue;
            else if (canLeft || canRight || canMiddle)
                count -= 1;
            else
                count -= 2;
        }

        return count;
    }
};