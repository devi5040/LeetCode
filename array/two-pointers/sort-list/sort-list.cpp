#include <iostream>
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
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head, *fast = head;

        // Find middle
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split
        ListNode *second = slow->next;
        slow->next = nullptr;

        // Recursively sort
        head = sortList(head);
        second = sortList(second);

        // Merge
        return merge(head, second);
    }

    ListNode *merge(ListNode *firstList, ListNode *secondList)
    {
        ListNode dummy;
        ListNode *tail = &dummy;

        while (firstList != NULL && secondList != NULL)
        {
            if (firstList->val <= secondList->val)
            {
                tail->next = firstList;
                firstList = firstList->next;
            }
            else
            {
                tail->next = secondList;
                secondList = secondList->next;
            }
            tail = tail->next;
        }

        tail->next = (firstList != NULL) ? firstList : secondList;

        return dummy.next;
    }
};

// Utility: Insert at end
ListNode *insert(ListNode *head, int val)
{
    if (head == NULL)
        return new ListNode(val);

    ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

// Utility: Print list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = NULL;

    // Example: 4 -> 2 -> 1 -> 3
    head = insert(head, 4);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 3);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}