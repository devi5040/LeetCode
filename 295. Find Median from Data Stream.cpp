class MedianFinder
{
public:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (low.empty())
            low.push(num);
        else
        {
            if (num > low.top())
            {
                high.push(num);
                if (high.size() > low.size())
                {
                    low.push(high.top());
                    high.pop();
                }
            }
            else
            {
                low.push(num);
                if (low.size() > high.size() + 1)
                {
                    high.push(low.top());
                    low.pop();
                }
            }
        }
    }

    double findMedian()
    {
        if (high.size() == low.size())
            return (double)(high.top() + low.top()) / 2;
        return (double)low.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */