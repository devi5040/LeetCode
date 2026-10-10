#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *prev, *nextNode = head->next;
        vector<int> criticals;
        int step = 1;
        prev = head;
        head = head->next;
        nextNode = nextNode->next;

        if (!nextNode)
            return {-1, -1};

        while (nextNode)
        {
            step++;

            cout << "prev: " << prev->val << ", cur: " << head->val << ", next: " << nextNode->val << endl;
            if ((prev->val < head->val && nextNode->val < head->val) ||
                (prev->val > head->val && nextNode->val > head->val))
            {
                criticals.push_back(step);
            }
            prev = head;
            head = nextNode;
            nextNode = nextNode->next;
            for (int num : criticals)
                cout << num << " ";
            cout << endl;
        }

        if (criticals.size() < 2)
            return {-1, -1};

        int n = criticals.size();

        return {
            criticals[n - 1] - criticals[n - 2],
            criticals[n - 1] - criticals[0]};
    }
};

int main()
{

    // Example:
    // [5, 3, 1, 2, 5, 1, 2]

    ListNode *head = new ListNode(6);
    head->next = new ListNode(8);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next->next->next->next = new ListNode(6);

    Solution solution;

    vector<int> result = solution.nodesBetweenCriticalPoints(head);

    cout << "Result: ";

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}