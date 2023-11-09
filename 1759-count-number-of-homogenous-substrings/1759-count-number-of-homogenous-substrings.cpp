class Solution {
public:
    int countHomogenous(string s) {
        int count = 0, temp = 0;
        for(int i=0; i < s.size(); i++){
            temp++;
            if(temp > 1000000007) temp = temp%(1000000007);
            count+=temp;
            if(count > 1000000007) count = count%(1000000007);
            if(s[i]!=s[i+1]) temp = 0;
        }
        return count;
    }
};