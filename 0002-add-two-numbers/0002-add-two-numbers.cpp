/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0, carry = 0;
    ListNode* dummy = new ListNode(); // A dummy node to simplify the code
    ListNode* current = dummy;

    while (l1 || l2 || carry) {
      int x = l1 ? l1->val : 0;
      int y = l2 ? l2->val : 0;
              
      sum = x + y + carry;
      carry = sum / 10; // Calculate carry for the next iteration
      sum %= 10;

      current->next = new ListNode(sum);
      current = current->next;

      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }

    return dummy->next; // Skip the dummy node
  }
};
