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
        ListNode* retNode = new ListNode();
        ListNode* cur = retNode;
        int carr = 0;
        while (l1 != nullptr || l2 != nullptr || carr) {
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            int sum = x + y + carr;
            carr = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        return retNode->next;
    }
};
