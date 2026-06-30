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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while(l1&&l2)
        {
            int sum = l1->val+l2->val;
            int q = (sum+carry)/10;
            int rem = (sum+carry)%10;
            carry = 0;
            ListNode* temp = new ListNode(rem);
            carry += q;
            res->next = temp;
            res = res->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            int q = (l1->val+carry)/10;
            int rem = (l1->val+carry)%10;
            carry = 0;
            ListNode* temp = new ListNode(rem);
            carry += q;
            res->next = temp;
            res=res->next;
            l1=l1->next;
        }
        while(l2)
        {
            int q = (l2->val+carry)/10;
            int rem = (l2->val+carry)%10;
            carry = 0;
            ListNode* temp = new ListNode(rem);
            carry += q;
            res->next = temp;
            res=res->next;
            l2 = l2->next;
        }
        if(carry)
        {
            ListNode* car = new ListNode(carry);
            res->next = car;
        }

        return head->next;
    }
};
