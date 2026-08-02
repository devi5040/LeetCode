class Solution
{
public:
    vector<int> countTasks(vector<int> &tasks, vector<int> &shifts)
    {
        int m = tasks.size(), n = shifts.size();
        long long task_comp = 0, rem_time = 0;
        vector<int> result;
        long long taskSum = 0;
        for (int task : tasks)
            taskSum += (long long)task;

        for (int i = 0; i < n; i++)
        {
            if (shifts[i] >= taskSum)
            {
                result.push_back(0);
                task_comp = 0;
                rem_time = 0;
                continue;
            }
            rem_time += shifts[i];
            for (int j = task_comp; j < m; j++)
            {
                if (tasks[j] <= rem_time)
                {
                    task_comp++;
                    rem_time -= (long long)tasks[j];
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (task_comp == m)
            {
                result.push_back(0);
                task_comp = 0;
                rem_time = 0;
            }
            else
            {
                result.push_back(m - (int)task_comp);
            }
        }

        return result;
    }
};