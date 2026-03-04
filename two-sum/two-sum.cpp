#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> freq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq.find(nums[i]) != freq.end())
            {
                auto it = freq.find(nums[i]);
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
            else
            {
                freq[target - nums[i]] = i;
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    if (result.size() == 2)
    {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    }
    else
    {
        cout << "No pair found" << endl;
    }

    return 0;
}