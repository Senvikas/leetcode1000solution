class Solution {
public:
    vector<int> solve(string expression){
        vector<int> ans;
        for(int i=0; i<expression.length(); i++){
            if(expression[i] == '+' || expression[i] == '-' ||
              expression[i] == '*'){
                vector<int> ans1 = solve(expression.substr(0,i));
                vector<int> ans2 = solve(expression.substr(i+1));
                
                for(int k=0; k<ans1.size(); k++){
                    for(int j=0; j<ans2.size(); j++){
                        if(expression[i] == '+') 
                            ans.push_back(ans1[k]+ans2[j]);
                        else if(expression[i] == '-') 
                            ans.push_back(ans1[k]-ans2[j]);
                        else if(expression[i] == '*') 
                            ans.push_back(ans1[k]*ans2[j]); 
                    }
                }
            }
        }
        
        // Base case: If no operator is found, it is a single number
        if(ans.empty()) ans.push_back(stoi(expression));
        
        return ans;
    }
    
    vector<int> diffWaysToCompute(string expression) {
       return solve(expression); 
    }
};
