class DetectSquares
{
public:
    map<pair<int, int>, int> freq;
    vector<pair<int, int>> points;

    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        freq[{point[0], point[1]}]++;
        points.push_back({point[0], point[1]});
    }

    int count(vector<int> point)
    {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        for (auto &[px, py] : points)
        {

            // Must be on a diagonal
            if (abs(px - x) != abs(py - y))
                continue;

            if (px == x || py == y)
                continue;

            ans += freq[{px, y}] * freq[{x, py}];
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */