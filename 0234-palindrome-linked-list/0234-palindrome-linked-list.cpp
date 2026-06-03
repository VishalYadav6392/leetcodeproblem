class Solution {
    ListNode* Reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* secondHalf = Reverse(slow->next);

        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;

        // Compare
        while(temp)
        {
            if(firstHalf->val != temp->val)
            {
                return false;
            }

            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        // Restore list
        slow->next = Reverse(secondHalf);

        return true;
    }
};