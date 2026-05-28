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
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> nums;

        // Convert linked list to array
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();

        vector<int> ans(n, 0);

        stack<int> st;

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {

            // Remove smaller/equal elements
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // Next greater element
            if(!st.empty()) {
                ans[i] = st.top();
            }

            // Push current element
            st.push(nums[i]);
        }

        return ans;
    }
};