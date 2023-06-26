#include<bits/stdc++.h>
class Solution {
    
    
public:
   
    long long totalCost(vector<int>& costs, int k, int c) {
        long cost = 0;
        priority_queue <int, vector<int>, greater<int> >leftpq;
        priority_queue <int, vector<int>, greater<int> >rightpq;
        
        int j = costs.size()-1;
        int i = 0;
        for(i = 0; i<c; i++)
        {
            leftpq.push(costs[i]);
        }
       
        int count = 0;
        if(c > costs.size()-c) c = costs.size() - c;
        
        while(count < c)
        {
            rightpq.push(costs[j]);
            count++; j--;
        }
        
        while(k--){
            if(leftpq.size() == 0){
                cost += rightpq.top();
                rightpq.pop();
                if(i<=j){
                    rightpq.push({costs[j]});
                    j--;
                }
            }
            
            else if(rightpq.size() == 0) {
                cost += leftpq.top();
                leftpq.pop();
                if(i<=j){
                    leftpq.push(costs[i]);
                    i++;
                }
            }
            
            
            else if(leftpq.top()<= rightpq.top())
            {
                cost += leftpq.top();
                leftpq.pop();
                if(i<=j){
                    leftpq.push(costs[i]);
                    i++;
                }
            }
            
            
            else{
                cost += rightpq.top();
                rightpq.pop();
                if(i<=j){
                    rightpq.push({costs[j]});
                    j--;
                }
            }  
            
        }
        
        
        return cost;
    }
};