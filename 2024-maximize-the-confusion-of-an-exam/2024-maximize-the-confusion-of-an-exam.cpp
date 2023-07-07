class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(), max_true = 0, max_false = 0, l, r ,ch;
        // consider the maximum consecutive true
        l = 0, r = 0, ch = 0;
        while(r < n){
            if(answerKey[r] == 'T') r++;
            else r++, ch++;
            while(ch > k && l < r){
                if(answerKey[l] == 'T') l++;
                else l++, ch--;
            }
            max_true = max(max_true, r-l);
        }
        // consider the maximum consecutive false
        l = 0, r = 0, ch = 0;
        while(r < n){
            if(answerKey[r] == 'F') r++;
            else r++, ch++;
            while(ch > k && l < r){
                if(answerKey[l] == 'F') l++;
                else l++, ch--;
            }
            max_false = max(max_false, r-l);
        }
        // the answer is the maximum of the above cases
        return max(max_true, max_false);
    }
};