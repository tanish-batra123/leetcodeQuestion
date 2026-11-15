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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode*temp=head;
        if(head==NULL)return NULL;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        temp=head;
        int idx=len-n;
        if(idx==0){
            ListNode*prevhead=head;
            head=head->next;
            delete(prevhead);
            return head;
        }
        for(int i=1;i<idx;i++){
           temp=temp->next;
        }
        ListNode*deletdNode=temp->next;
        temp->next=deletdNode->next;
        delete(deletdNode);
        return head;
        
    }
};