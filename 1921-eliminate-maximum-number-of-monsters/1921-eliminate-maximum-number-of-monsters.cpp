class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = speed.size();
        vector<double>MonstersTime(n);
        
        for(int i=0; i<n; i++){
            MonstersTime[i] = (double)dist[i]/(double)speed[i];
            
        }
        
        sort(MonstersTime.begin(), MonstersTime.end());
        
        int ans = 0, time = 0;
        for(auto mt : MonstersTime){
            if(mt <= time) break;
            else{
                ans++; time++;
            }
        }
        return ans;
    }
};