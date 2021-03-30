//Leetcode practice

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        stack<int> s;
        int TOS;
        
        ListNode * ptr = head;
        
        while(ptr->next!=NULL)
        {
            if(s.size()!=0)
            {
                if(TOS == ptr->val)
                {
                    s.pop();
                }
                else
                {
                    s.push(ptr->val);
                }
            }
            else
            {
                s.push(ptr->val);
                TOS = ptr->val;
            }
            ptr=ptr->next;
        }
        
        if(s.size()==0)
        {
            return true;
        }
        else
            return false;
        
        
    }
};