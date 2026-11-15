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
    bool isPalindrome(ListNode* head) {
       stack<ListNode*>st;
       if(head==NULL){
            return true;
        }
       ListNode*temp=head;
       while(temp!=NULL){
        st.push(temp);
        temp=temp->next;
       }

       temp=head;
        while(temp!=NULL){
        ListNode*node=st.top();
        if (node->val != temp->val)
    return false;
        else st.pop();
        temp=temp->next;
       }
       return true;


        
    }
};