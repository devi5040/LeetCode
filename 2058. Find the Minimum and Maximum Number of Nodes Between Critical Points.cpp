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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *prev = NULL;
        vector<int> criticals;
        int step = 1;

        while (head != NULL)
        {
            if (prev == NULL || head->next == NULL)
            {
                prev = head;
                head = head->next;
                continue;
            }

            if (head->val > prev->val && head->val > head->next->val)
                criticals.push_back(step);
            else if (head->val < prev->val && head->val < head->next->val)
                criticals.push_back(step);

            prev = head;
            head = head->next;
            step++;
        }

        if (criticals.size() < 2)
            return {-1, -1};

        int n = criticals.size();
        int minDistance = INT_MAX;
        for (int i = 1; i < n; i++)
            minDistance = min(minDistance, criticals[i] - criticals[i - 1]);

        return {
            minDistance,
            criticals[n - 1] - criticals[0]};
    }
};