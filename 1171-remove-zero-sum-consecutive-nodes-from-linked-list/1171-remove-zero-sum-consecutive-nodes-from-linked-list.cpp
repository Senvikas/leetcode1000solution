class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr ; 

        ListNode* temp = head; 

        while(temp != nullptr) {
            arr.push_back(temp -> val); 
            temp = temp-> next; 
        }

        for(int i = 0 ; i<arr.size() ; i++) {
            
                int j = i-1;
                int sum = arr[i]; 
                while(j>=0) {
                    sum += arr[j]; 
                    if(sum == 0) break; 
                    j--; 
                }
                if(sum == 0 && j >-1) {
                    for(int k = j ; k<=i ; k++) {
                        arr[k] = 0; 
                    }
                }
            
        }
        ListNode * ans = new ListNode(10); 
        ListNode * tail = ans; 
        for(int i = 0 ; i < arr.size() ; i++) {
            if(arr[i] != 0) {
                //create new Node 
                ListNode * now = new ListNode(arr[i]);
                tail -> next = now ; 
                tail = tail -> next; 
            }
        }

        return ans -> next; 
    }
};