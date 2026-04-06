class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                // skip duplicate
                curr->next = curr->next->next;
            } else {
                curr = curr->next; // move forward
            }
        }

        return head;
    }
};