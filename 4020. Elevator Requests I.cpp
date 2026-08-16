class Solution
{
public:
    int elevatorRequests(int n, vector<int> &requests)
    {
        int totalTime = requests[0];

        for (int i = 1; i < requests.size(); i++)
            totalTime += abs(requests[i] - requests[i - 1]);

        return totalTime;
    }
};