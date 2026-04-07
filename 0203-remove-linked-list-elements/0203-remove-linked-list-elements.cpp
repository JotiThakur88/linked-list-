class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Step 1: Create dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        // Step 2: Traverse
        while (curr->next != NULL) {
            if (curr->next->val == val) {
                curr->next = curr->next->next; // remove node
            } else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};