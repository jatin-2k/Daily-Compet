class Solution {
private:

ListNode* reverse(ListNode* &head,ListNode* refptr){
    ListNode *prev=NULL,*curr=head,*nextptr;
    while(curr!=refptr)      
	// assume refptr as NULL ..reversing will stop if its  NULL  or that means we have reached the RIGHT value
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
     }
    
    return prev;
}
public:
ListNode* reverseBetween(ListNode* head, int left, int right) {

	if(!head->next) return head;
    ListNode *start=head,*refptr;
     ListNode *temp=new ListNode(-1);
   
     temp->next=head;
    int count=1;
    while(count<left) {
        start=start->next;  //start pointer will point to the starting point which has                                 //to be reversed
        temp=temp->next;    //temp will always be before start
        count++;
        }
    refptr=start;            // initializing the end pointer
    
    while(count<right && refptr->next) //will always stop before reaching NULL
    {
        
        refptr=refptr->next;
          count++;
    }           //at the end of this loop refptr will be at the RIGHT value position
    
    refptr=refptr->next;  // doing this will make it 1 step ahead CAN REACH NULL NOW
    
    if(start==head && refptr==NULL) 
        return reverse(start,refptr); //if left is 1 and refptr has reached NULL
                            // i.e RIGHT was SIZE OF LIST and refptr is just after that
    
if(start==head) //edge case as our start is HEAD but RIGHT was not end
{
    ListNode* node=reverse(start,refptr);
    start->next=refptr;
    return node;
}
    
    temp->next=reverse(start,refptr); // anycase of start and right within SIZE LIMIT
    
    start->next=refptr;
                     
    return head;
}
};