#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0, length = 0;
        vector<char> st;

        for (char ch : s)
        {
            auto it = find(st.begin(), st.end(), ch);
            while (it != st.end())
            {
                cout << "Before erasing" << endl;
                printVector(st);
                st.erase(st.begin());
                cout << "after erasing" << endl;
                printVector(st);
                length--;
                it = find(st.begin(), st.end(), ch);
            }
            st.push_back(ch);
            printVector(st);
            length++;
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }

private:
    void printVector(vector<char> st)
    {
        for (char ch : st)
            cout << ch;
        cout << endl;
    }
};

int main()
{
    Solution obj;
    string s;

    s = "pwwkew";

    int result = obj.lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}