# Sort List (Merge Sort, Two pointers)

> If we see below keywords
>
> Sort a linked list
>
> Required time: O(n log n)
>
> Space: O(1)
>
> - Merge sort on linked list

### Break the Problem Into 3 Subproblems

1. Find Middle
2. Recursively Sort Left and Right
3. Merge Two Sorted Lists

### Solution

```cpp
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
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *second, *slow=head, *fast=head;
        if(head==NULL || head->next==NULL)
            return head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        second = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        second = sortList(second);
        return merge(head, second);
    }

    ListNode* merge(ListNode* firstList, ListNode* secondList)
    {
        ListNode dummy;
        ListNode* head = &dummy;
        while(firstList != NULL && secondList != NULL)
        {
            if(firstList->val<=secondList->val)
            {
                head->next = firstList;
                firstList = firstList->next;
            }
            else
            {
                head->next = secondList;
                secondList = secondList->next;
            }
            head = head->next;
        }
        head->next = (firstList!=NULL)?firstList:secondList;
        return dummy.next;
    }
};
```
