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
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // > makes it a min-heap
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
       for(ListNode* node:lists)
            if(node)
                pq.push(node);
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(!pq.empty())
        {
            ListNode *current = pq.top();
            ListNode *nextNode = current->next;
            current->next = nullptr;
            cur->next = current;
            cur = current;
            pq.pop();
            if(nextNode)pq.push(nextNode);
        }
        return dummy->next;
    }
};
