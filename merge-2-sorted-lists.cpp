/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *head = list1, *nextNode, *prev = nullptr;
        while (list1 != nullptr && list2 != nullptr && list2->val < list1->val)
        {
            nextNode = list2->next;
            if (prev == nullptr)
            {
                head = list2;
                prev = list2;
            }
            else
            {
                prev->next = list2;
                prev = prev->next;
            }
            list2->next = list1;
            list2 = nextNode;
        }
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val > list2->val)
            {
                nextNode = list2->next;
                prev->next = list2;
                list2->next = list1;
                prev = list2;
                list2 = nextNode;
            }
            else
            {
                prev = list1;
                list1 = list1->next;
            }
        }
        if (list2 != nullptr)
            prev->next = list2;
        return head;
    }
};