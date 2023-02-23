class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> projects;
        for(int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        } 
        sort(projects.begin(), projects.end());
        priority_queue<int> maxH;
        int i = 0;
        while(i<projects.size() && k>0) {
            if(projects[i].first <= w) {
                maxH.push(projects[i].second);
                i++;
            }
            else {
                if(maxH.empty()) break;
                k--;
                w += maxH.top();
                maxH.pop();
            }
        }
        while(!maxH.empty() && k>0) {
            k--;
            w += maxH.top();
            maxH.pop();
        }
        return w;
    }
};