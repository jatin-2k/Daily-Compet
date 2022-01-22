class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *i1 = l1, *i2 = l2, *curr = dummyHead;
        int carry = 0;
        while(i1 or i2){
            int x = (i1)? i1->val : 0;
            int y = (i2)? i2->val : 0;
            int sum = x+y+carry;
            carry = sum / 10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            if(i1) i1 = i1 -> next;
            if(i2) i2 = i2 -> next;
        }
        if(carry) curr -> next = new ListNode(carry);
        return dummyHead -> next;
    }
};