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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == nullptr || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode *prevGroupTail = &dummy;

        while (true)
        {

            ListNode *kth = prevGroupTail;

            for (int i = 0; i < k && kth; i++)
                kth = kth->next;

            if (kth == nullptr)
                break;

            ListNode *groupStart = prevGroupTail->next;
            ListNode *nextGroup = kth->next;

            ListNode *prev = nextGroup;
            ListNode *curr = groupStart;

            while (curr != nextGroup)
            {
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            prevGroupTail->next = kth;

            prevGroupTail = groupStart;
        }

        return dummy.next;
    }
};