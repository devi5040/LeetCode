class Solution
{
public:
    int nearestDrone(vector<vector<int>> &drones, vector<int> &target)
    {
        int min_index = -1, min_distance = INT_MAX;
        int n = drones.size();

        for (int i = 0; i < n; i++)
        {
            int distance = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if (distance <= drones[i][2] && distance < min_distance)
            {
                min_distance = distance;
                min_index = i;
            }
        }

        return min_index;
    }
};