class Solution {
public:
    int clumsy(int n) {
       stack<int> st;
        st.push(n);
        int oprInd = 0;
        vector<char> opr = {'*', '/', '+', '-'};
        for(int num = n-1; num>0; num--){
            
            if(opr[oprInd] == '*'){
                int pick = st.top();
                st.pop();
                pick *= num;
                st.push(pick);
            }
            
            else if(opr[oprInd] == '/'){
                int pick = st.top();
                st.pop();
                pick /= num;
                st.push(pick);
            }
            
            else if(opr[oprInd] == '+'){
                st.push(num);
            }
            
            else st.push(-num);
            oprInd = (oprInd + 1)%4;
        }
        
        int ans = 0;
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        return ans;
    }
};