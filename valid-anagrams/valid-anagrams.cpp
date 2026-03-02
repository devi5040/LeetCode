#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> freq(26, 0);

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int count : freq)
        {
            if (count != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    string s, t;
    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (sol.isAnagram(s, t))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are NOT anagrams." << endl;

    return 0;
}