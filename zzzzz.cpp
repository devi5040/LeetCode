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
        for (vector<bool> n : v)
        {
            for (bool m : n)
                cout << m << " ";
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
    vector<int> merge(vector<int> leftArray, vector<int> rightArray)
    {
        int left_size = leftArray.size(), right_size = rightArray.size();
        int left_cursor = 0, right_cursor = 0;
        vector<int> merged_array;
        while (left_cursor < left_size && right_cursor < right_size)
        {
            if (leftArray[left_cursor] < rightArray[right_cursor])
            {
                merged_array.push_back(leftArray[left_cursor]);
                left_cursor++;
            }
            else
            {
                merged_array.push_back(rightArray[right_cursor]);
                right_cursor++;
            }
        }
        while (left_cursor < left_size)
        {
            merged_array.push_back(leftArray[left_cursor]);
            left_cursor++;
        }
        while (right_cursor < right_size)
        {
            merged_array.push_back(rightArray[right_cursor]);
            right_cursor++;
        }
        cout << "Merged array is: " << endl;
        printVector(merged_array);
        return merged_array;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return nums;
        int mid = n / 2;
        vector<int> righta(nums.begin() + 2, nums.begin() + 4);
        printVector(righta);
        vector<int> left(nums.begin(), nums.begin() + mid);
        cout << "The left array is" << endl;
        printVector(left);
        vector<int> left_array = sortArray(left);
        vector<int> right(nums.begin() + mid, nums.begin() + (n - 1));
        cout << "The right array is: " << endl;
        printVector(right);
        vector<int> right_array = sortArray(right);
        return merge(left_array, right_array);
    }
};

int main()
{
    Solution sol;

    vector<int> position = {1, 5, 4, 2, 3};
    vector<int> speed = {20, 4, 5};
    string text = "eccbbbbdec";
    string text2 = "pqhgxgdofcvmr";
    vector<vector<char>> v = {{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
    vector<string> patterns = {"a"};
    vector<vector<int>> q = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> nums = {5, 2, 3, 1};
    sol.sortArray(nums);
    // int subsets = sol.countMajoritySubarrays(position, 2);
    cout << "The solution is: " << endl;
    // cout << result;
    cout << endl
         << endl;
    return 0;
}