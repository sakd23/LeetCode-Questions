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
        
        int carry=0;
        
        int sum=l1->val+l2->val;
        
        if(sum>9)
        {
            carry=1;
            sum=sum%10;
        }
        
        ListNode *head=new ListNode(sum);
        l1=l1->next;
        l2=l2->next;
        
        ListNode *temp=head;
        while(l1!=NULL and l2!=NULL)
        {
        
        int sum=l1->val+l2->val+carry;
        
        if(sum>9)
        {
            carry=1;
            sum=sum%10;
        }
            
            else
            {
                carry=0;
            }
        
            ListNode *newdigit=new ListNode(sum);
            temp->next=newdigit;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1==NULL and l2!=NULL)
        {
          int sum=l2->val+carry;
        
        if(sum>9)
        {
            carry=1;
            sum=sum%10;
        }
            
            else
            {
                carry=0;
            }
        
            ListNode *newdigit=new ListNode(sum);
            temp->next=newdigit;
            temp=temp->next;
            
            l2=l2->next;  
        }
        
        while(l2==NULL and l1!=NULL)
        {
          int sum=l1->val+carry;
        
        if(sum>9)
        {
            carry=1;
            sum=sum%10;
        }
            
            else
            {
                carry=0;
            }
        
            ListNode *newdigit=new ListNode(sum);
            temp->next=newdigit;
            temp=temp->next;
            
            l1=l1->next;  
        }
        if(carry!=0)
        {
           ListNode *newdigit=new ListNode(carry);
            temp->next=newdigit; 
        }
        return head;
    }
};