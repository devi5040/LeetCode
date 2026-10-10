#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <map>

using namespace std;

class Solution
{
public:
    void printVector(vector<int> v)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
    void printVector(vector<pair<int, int>> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << "{" << v[i].first << ", " << v[i].second << "}";
        }
        cout << endl;
    }
    void printVector(vector<pair<string, int>> v)
    {
        for (int i = 0; i < v.size(); i++)
            cout << "{'" << v[i].first << "', " << v[i].second << "}";
        cout << endl;
    }
    void printVector(vector<bool> v)
    {
        for (bool n : v)
            cout << n << " ";
        cout << endl;
    }

    void printVector(vector<float> v)
    {
        for (float n : v)
            cout << n << " ";
        cout << endl;
    }
    void printVector(vector<vector<int>> v)
    {
        for (vector<int> n : v)
        {
            for (int m : n)
                cout << m << " ";
            cout << endl;
        }
    }
    void printVector(vector<vector<bool>> v)
    {
        int idx = 0;
        for (vector<bool> n : v)
        {
            cout << idx << "::::::";
            for (bool m : n)
            {
                string val = m ? "True" : "False";
                cout << val << " ";
            }
            cout << endl;
            idx++;
        }
        cout << endl;
    }
    void printVector(vector<vector<char>> v)
    {
        int idx = 0;
        for (vector<char> n : v)
        {
            for (char m : n)
                cout << m << " ";
            cout << endl;
        }
        cout << endl;
    }
    void printVector(vector<unordered_map<int, int>> v)
    {
        for (unordered_map<int, int> n : v)
        {
            for (auto it : n)
                cout << "{" << it.first << ": " << it.second << "}, ";
            cout << endl;
        }
        cout << endl;
    }
    void printQueue(deque<int> pq)
    {
        int n = pq.size();
        while (n--)
        {
            cout << pq.back() << " ";
            pq.pop_back();
        }
        cout << endl;
    }
    void printStack(stack<int> st)
    {
        int n = st.size();
        while (n--)
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    void printStack(stack<float> st)
    {
        int n = st.size();
        while (n--)
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    void printStack(stack<char> st)
    {
        int n = st.size();
        while (n--)
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    void printStack(stack<string> st)
    {
        int n = st.size();
        while (n--)
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    void printMap(unordered_map<string, int> mp)
    {
        for (auto it : mp)
        {
            cout << "{" << it.first << ", " << it.second << "}, ";
        }
        cout << endl;
    }
    void printMap(unordered_map<int, pair<int, pair<int, int>>> mp)
    {
        for (auto it : mp)
        {
            cout << "{" << it.first
                 << ", " << it.second.first
                 << ", {" << it.second.second.first
                 << ", " << it.second.second.second
                 << "}}, ";
        }
        cout << endl;
    }
    void printMap(unordered_map<int, int> mp)
    {
        for (auto it : mp)
        {
            cout << "{" << it.first << ", " << it.second << "}, ";
        }
        cout << endl;
    }
    void printMap(unordered_map<char, int> mp)
    {
        for (auto it : mp)
        {
            cout << "{" << it.first << ", " << it.second << "}, ";
        }
        cout << endl;
    }
    void printMap(unordered_map<string, string> mp)
    {
        for (auto it : mp)
        {
            cout << "{" << it.first << ", " << it.second << "}, ";
        }
        cout << endl;
    }

    void printPQ(priority_queue<int> pq)
    {
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }

    void printPQ(priority_queue<int, vector<int>, greater<int>> pq)
    {
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }

    int minAddToMakeValid(string s)
    {
        int count = 0;
        stack<char> st;

        for (char ch : s)
        {
            if (ch == '(' || st.empty())
                st.push(ch);
            else if (ch == ')' && st.top() == '(')
                st.pop();
            else
                st.push(ch);
            printStack(st);
        }

        return st.size();
    }
};

int main()
{
    Solution sol;

    vector<int> position = {1, 5, 4, 2, 3};
    vector<int> speed = {20, 4, 5};
    string text = "abcbddddd";
    string text2 = "abcd";
    vector<vector<char>> v = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    vector<string> patterns = {"LS", "RL"};
    vector<vector<int>> q = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}};

    vector<int> nums = {5, 2, 3, 1, 1};
    vector<vector<string>> st = {{"a", "yes"}};
    sol.minAddToMakeValid("())");
    // int subsets = sol.countMajoritySubarrays(position, 2);
    cout << endl
         << endl;
    return 0;
}