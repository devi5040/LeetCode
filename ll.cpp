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

// Paste your Solution class here

ListNode *createList(int arr[], int n)
{
    if (n == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;

    for (int i = 1; i < n; i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    void listNode(Node *head)
    {
        Node *tmp = head;
        while (tmp)
        {
            cout << tmp << ", ";
            tmp = tmp->next;
        }
        cout << endl;
        while (head)
        {
            cout << "[" << head->val << ", " << head->random << "] -> ";
            head = head->next;
        }
        cout << endl;
    }
    void printNode(Node *head)
    {
        cout << head->val << endl;
        cout << "next: " << head->next << endl;
        cout << "random: " << head->random << endl;
    }
    void printVector(vector<ListNode *> v)
    {
        for (ListNode *list : v)
        {
            cout << list->val << " ";
        }
        cout << endl;
    }
    vector<ListNode *> reverseLists(ListNode *head)
    {
        ListNode *tail = head;

        ListNode *prev = nullptr;
        ListNode *cur = head;

        while (cur)
        {
            ListNode *next = cur->next;

            cur->next = prev;

            prev = cur;
            cur = next;
        }

        return {prev, tail};
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        cout << "current list is: " << endl;
        printList(head);
        int count = 0;
        ListNode *cur = head;
        ListNode *prev = new ListNode();
        prev->next = cur;
        ListNode *dummy = prev;
        vector<ListNode *> nodes;
        cout << "cur is: " << cur->val << endl;
        cout << "prev is: " << prev->val << endl;
        cout << "dummy is: " << dummy->val << endl;
        while (count <= k && cur)
        {
            cout << "cur is: " << cur->val << endl;
            cout << "prev is: " << prev->val << endl;
            cout << "dummy is: " << dummy->val << endl;
            cout << "current list is: " << endl;
            printList(dummy->next);
            if (count != k)
            {
                cur = cur->next;
                count++;
                continue;
            }
            ListNode *temp = cur;
            cur->next = nullptr;
            nodes = reverseLists(prev->next);
            printVector(nodes);
            prev->next = nodes[0];
            nodes[1]->next = temp;
            prev = temp;
            cur = temp;
            count = 0;
            cout << "cur is: " << cur->val << endl;
            cout << "prev is: " << prev->val << endl;
        }
        printList(dummy->next);
        return dummy->next;
    }
};

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;
    Solution obj;

    obj.reverseKGroup(n1, 2);
    // Node *ans = obj.copyRandomList(n1);

    // cout << "\nCopied List:\n";
    // obj.listNode(ans);

    return 0;
}
/*
int main()
{
    int a[] = {5};
    int b[] = {1, 2, 4};

    // int a[] = {2};
    // int b[] = {1};

    ListNode *list1 = createList(a, 1);
    ListNode *list2 = createList(b, 3);

    Node *list = createNode(a, )

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Solution obj;
    Node *ans = obj.copyRandomList(list1);

    cout << "Merged: ";
    printList(ans);

    return 0;
}
    */