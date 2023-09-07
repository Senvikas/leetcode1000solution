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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        ListNode* temp1 = NULL;
        ListNode* last = head;
        ListNode* f = head;
        ListNode* m = head;

        int l = left, r = left, n = right;
        int i = 0, count = 0;
        vector<int> arr;

        if(left==right){
            return head;
        }

        while(last!=NULL){
            count++;
            last = last -> next;
        }

        while(n>0){
            m = m -> next;
            n--;
        }

        while(l>1){
            temp = temp -> next;
            l--;
        }

        while(r<=right){
            arr.push_back(temp->val);
            temp = temp -> next;
            r++;
        }

        reverse(arr.begin(), arr.end());

        while(left>1){
            ListNode* newNode = new ListNode(f->val);
            newNode -> next = temp1;
            temp1 = newNode;
            f = f -> next;
            left--;
        }

        while(i<arr.size()){
            ListNode* newNode = new ListNode(arr[i]);
            newNode -> next = temp1;
            temp1 = newNode;
            i++;
        }

        while(right<count){
            ListNode* newNode = new ListNode(m->val);
            newNode -> next = temp1;
            temp1 = newNode;
            m = m -> next;
            right++;
        }

        vector<int> reverse_arr;

        while(temp1!=NULL){
            reverse_arr.push_back(temp1->val);
            temp1 = temp1 -> next;
        }

        ListNode* temp2 = NULL;
        int j = 0;

        while(j<reverse_arr.size()){
            ListNode* newNode = new ListNode(reverse_arr[j]);
            newNode -> next = temp2;
            temp2 = newNode;
            j++;
        }

        return temp2;
    }
};