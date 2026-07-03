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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second =slow->next;
        slow->next=nullptr;

        ListNode* curr=second;
        ListNode* prev=nullptr;
        ListNode* next;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        //merging both the lists now
        ListNode* first=head;
        ListNode* secondhalf=prev;
        while(first!=nullptr && secondhalf!=nullptr){
            ListNode* next1=first->next;
            ListNode* next2=secondhalf->next;

            first->next=secondhalf;
            secondhalf->next=next1;

            first=next1;
            secondhalf=next2;
        }
        



    }
};
