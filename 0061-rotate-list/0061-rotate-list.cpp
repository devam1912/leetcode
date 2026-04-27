class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0)
            return head;
        int n = 0;
        ListNode* t = head;
        while (t) {
            n++;
            t = t->next;
        }
        k = k % n;
        if (k == 0) return head;

        for (int i = 0; i < k; i++) {

            ListNode* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }

            ListNode* last = temp->next;
            temp->next = nullptr;
            last->next = head;
            head = last;
        }

        return head;
    }
};
