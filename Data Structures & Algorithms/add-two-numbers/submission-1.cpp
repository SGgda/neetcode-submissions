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
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* copy = dummy;
        int sum = 0;
        int carry = 0;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr && list2 != nullptr) {
                int total = (carry + list2->val);
                sum = total % 10;
                carry = total / 10;
                dummy->next = new ListNode(sum);
                dummy = dummy->next;
                list2=list2->next;

            } else if (list2 == nullptr && list1 != nullptr) {
                int total = (carry + list1->val);
                sum = total % 10;
                carry = total / 10;
                dummy->next = new ListNode(sum);
                dummy = dummy->next;
                list1=list1->next;
            } else {
                int total = list1->val + list2->val + carry;
                sum = total % 10;
                carry = total / 10;

                dummy->next = new ListNode(sum);
                dummy = dummy->next;

                list1 = list1->next;
                list2 = list2->next;
            }
        }
        if(carry!=0){
            dummy->next=new ListNode(carry);
        }
        return copy->next;
    }
};
