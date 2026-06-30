#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> freq;
        for (int num : nums)
        {
            if (freq.find(num) != freq.end())
                return true;
            freq.insert(num);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    bool result = sol.containsDuplicate(nums);

    if (result)
        cout << "Contains Duplicate: True" << endl;
    else
        cout << "Contains Duplicate: False" << endl;

    return 0;
}