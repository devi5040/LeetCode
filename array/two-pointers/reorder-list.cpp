#include <iostream>
using namespace std;

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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        // Find the middle of linked list
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // the slow pointer will be the middle
        // Next we need to reverse the second part of the list
        ListNode *prev = NULL, *cur = slow->next, *next;
        while (cur != NULL)
        {
            next = cur->next; // temporary to store next node
            cur->next = prev; // reverse pointer
            prev = cur;       // move prev forward
            cur = next;       // move cur forward
        }
        slow->next = prev;
        ListNode *l1 = head, *l2 = prev;
        while (l1 != NULL && l2 != NULL)
        {
            next = l2->next;
            cur = l1->next;
            l1->next = l2;
            l1 = cur;
            l2->next = l1;
            l2 = next;
        }
    }
};

// Helper: build linked list from array
ListNode *build(initializer_list<int> vals)
{
    ListNode dummy;
    ListNode *cur = &dummy;
    for (int v : vals)
    {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    return dummy.next;
}

// Helper: print linked list
void print(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution sol;

    ListNode *head = build({1, 2, 3, 4});
    cout << "Before: ";
    print(head);
    sol.reorderList(head);
    cout << "After:  ";
    print(head);

    return 0;
}