class Solution {
public:
    vector<string> buildArray(vector<int>& arr, int n) {
        vector<string> ans;
        int count = 0;
        for(int i = 1;i<=n;i++){
            if(arr[count]==i){
                ans.push_back("Push");
                count++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(count>arr.size()-1) break;
        }
        return ans;
    }
};