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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)  return nullptr;
        queue<ListNode*> q;
        for(auto &i: lists) q.push(i);
        while(!q.empty() && q.size()>1){
            ListNode *l1,*l2;
            l1 = q.front(); q.pop();
            l2 = q.front(); q.pop();
            q.push(sortedMerge(l1, l2));
        }
        return q.front();
    }
    ListNode* sortedMerge(ListNode* head1, ListNode* head2)  
    {  
        ListNode *tail, *head;
        tail = new ListNode(NULL);
        head = tail;
        while(head1 && head2){
            if(head1 -> val < head2 -> val){
                tail -> next = head1;  //joda
                tail = head1;          //ans wali k last ele p aee
                head1 = head1 -> next; //bachi hui k head p aae
            }
            else{
                tail-> next = head2;
                tail = head2;
                head2 = head2 -> next;
            }
            tail -> next = NULL; //tod dia
        }
        if(head1) tail -> next = head1;
        if(head2) tail -> next = head2;

        return head->next;
    }  
};