class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int n = people.size();
        int sum = 0;
        int numBoats = 0;

        int left = 0, right = n - 1;
        while (left < right)
        {
            if (people[left] + people[right] <= limit)
                left++;
            right--;
            numBoats++;
        }

        if (left == right)
            numBoats++;

        return numBoats;
    }
};