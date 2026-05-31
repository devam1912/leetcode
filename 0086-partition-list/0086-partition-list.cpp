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
    ListNode* partition(ListNode* head, int x) {

        vector<int> v;
        ListNode* temp = head;

        while(temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> s, b;

        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] < x)
                s.push_back(v[i]);
            else
                b.push_back(v[i]);
        }

        ListNode* temp2 = head;

        for(int i = 0; i < s.size(); i++)
        {
            temp2->val = s[i];
            temp2 = temp2->next;
        }

        for(int i = 0; i < b.size(); i++)
        {
            temp2->val = b[i];
            temp2 = temp2->next;
        }

        return head;
    }
};