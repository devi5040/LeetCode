class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &inPath, int i)
    {
        visited[i] = true;
        inPath[i] = true;
        for (int next : graph[i])
        {
            if (inPath[next])
                return true;
            else if (!visited[next])
                if (dfs(graph, visited, inPath, next))
                    return true;
        }
        inPath[i] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> mp(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> inPath(numCourses, false);
        for (vector<int> &num : prerequisites)
            mp[num[1]].push_back(num[0]);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
                if (dfs(mp, visited, inPath, i))
                    return false;
        }
        return true;
    }
};