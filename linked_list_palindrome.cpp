/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        /* Run time 20ms, beats 97% CPP Submissions with O(1) space and O(n)*/
        int len = 0;
        ListNode *curr =head;
        
        while(curr)
        {
            len++;
            curr = curr->next;
        }
        
        curr = head;
        ListNode *start_2 = NULL;
        ListNode *last_1 = NULL;
        int i = 1;
        while(curr){
             
            if(i == len/2){
                last_1 = curr;
                start_2 = curr->next;
                curr->next = NULL;
                break;
            }
            i++;
            curr = curr->next;
        }
        
        curr = start_2;
        
        ListNode *prev =NULL;
        ListNode *next =NULL;
        
        while(curr){
              next = curr->next;
              curr ->next = prev;
              prev = curr;
              curr = next;
        }
        start_2 = prev;
        
         while(start_2 && head){
            if(start_2->val != head->val){
                return false;
            }
            start_2 = start_2->next;
            head = head->next;
        }
        
        return true;
        /* Run time 20ms, beats 97% CPP Submissions 
        
        vector<int> v;
        
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        
        int i = 0;
        int j = v.size()-1;
        
        while(i < j){
            if(v[i] != v[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true; */
    }
}
