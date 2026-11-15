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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {

        ListNode* middle = middleNode(head);
       
        ListNode* curr = head;
        
        ListNode* rev = reverseList(middle->next);
         middle->next=NULL;
       middle->next = NULL;

while (rev != NULL) {
    ListNode* next1 = curr->next;
    ListNode* next2 = rev->next;

    curr->next = rev;
    rev->next = next1;

    curr = next1;
    rev = next2;
}
    }
};