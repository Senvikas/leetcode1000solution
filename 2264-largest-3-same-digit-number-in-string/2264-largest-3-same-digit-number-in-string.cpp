class Solution {
public:
    string largestGoodInteger(string num) {
        int val = 0;
        string ans = "";
        for(int i=1; i<num.size()-1; i++){
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                if(val <= num[i] - '0')
                {
                    ans = num.substr(i-1, 3);
                    val = num[i] - '0';
                }
                i+=2;
            }
        }
        
        return ans;
    }
};