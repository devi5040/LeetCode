# Reorder List (Two Pointers)

> To solve this problem, we can use the two-pointer technique to find the middle of the linked list, reverse the second half of the list, and then merge the two halves together.

### How to recognize the pattern

Signal 1: "Reorder" a Linked List

> Whenever the problem says:
>
> Reorder
>
> Rearrange
>
> Interleave
>
> Alternate
>
> Zigzag

Think: Pointer manipulation problem

Signal 2: Uses First and Last Elements Together
So we need access to the end of the list efficiently.
But singly linked lists cannot access last node in O(1). So we can reverse linked list, use stack,convert to array or 2 pointer technique.

Signal 3: In-place requirement
So we need to follow below pattern

1. Find middle (Fast & Slow pointer)
2. Reverse second half
3. Merge alternately

### Here are the steps to implement the solution:

1. Use two pointers, slow and fast, to find the middle of the linked list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the middle.
2. Reverse the second half of the linked list starting from the node after the slow pointer(Use 3 pointer technique to reverse the list).
3. Merge the two halves of the linked list together. We can use two pointers, one for each half, to alternate nodes from each half until we reach the end of one of the halves.

#### Solution

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
        slow->next = NULL;
        ListNode *l1 = head, *l2 = prev;
        next = NULL;
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
```
