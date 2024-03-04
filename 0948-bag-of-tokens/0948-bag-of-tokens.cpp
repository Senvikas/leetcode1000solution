class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        
        int i=0, n = tokens.size(), j = n-1;
        
        int maxi = 0;
        while(i<=j){
            if(power >= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
            }else if(score >= 1){
                score--;
                power += tokens[j];
                j--;
            }
            else
                i++;
            
            maxi = max(score, maxi);
        }
        
        return maxi;
    }
};