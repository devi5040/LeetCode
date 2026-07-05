class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> stone_q;
        for (int num : stones)
            stone_q.push(num);
        while (stone_q.size() >= 2)
        {
            int y = stone_q.top();
            stone_q.pop();
            int x = stone_q.top();
            stone_q.pop();
            if (x == y)
                continue;
            stone_q.push(y - x);
        }
        return !stone_q.empty() ? stone_q.top() : 0;
    }
};