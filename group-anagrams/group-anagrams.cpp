#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> vec_freq;
        string temp;

        for (string str : strs)
        {
            temp = str;
            sort(temp.begin(), temp.end());

            auto it = vec_freq.find(temp);

            if (it != vec_freq.end())
                it->second.push_back(str);
            else
                vec_freq[temp].push_back(str);
        }

        for (auto &p : vec_freq)
            res.push_back(p.second);

        return res;
    }
};

int main()
{

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution sol;
    vector<vector<string>> result = sol.groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";

    for (auto &group : result)
    {
        cout << "[ ";
        for (string word : group)
        {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}