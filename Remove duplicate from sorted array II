class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(-1);  // Dummy node to handle edge cases
        ListNode* prev = dummy;
        prev->next = head;
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                while (curr->next != nullptr && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;  // Skip duplicates
            } else {
                prev = prev->next;  // Move prev forward if no duplicates
            }
            curr = curr->next;  // Move current forward
        }

        return dummy->next;
    }
};
