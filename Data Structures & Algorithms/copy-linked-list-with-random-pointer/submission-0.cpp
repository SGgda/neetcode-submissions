/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        Node* curr1 = head;
        while (curr != nullptr) {
            mp[curr] = new Node(curr->val) ;
            curr = curr->next;
        }
        mp[nullptr] = nullptr;
        while (curr1 != nullptr) {
            mp[curr1]->next = mp[curr1->next];

            mp[curr1]->random = mp[curr1->random];

            curr1 = curr1->next;
        }
        return mp[head];
    }
};
