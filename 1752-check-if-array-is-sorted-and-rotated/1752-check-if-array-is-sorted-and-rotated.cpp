class Solution {
public:
    bool check(vector<int>& arr) {
        int rot = 0;
        int n = arr.size();
        if(n<=2) return true;
        int s = -1;
        
        for(int i=1; i<n; i++){
            if(rot == 0){
               s = (s == -1) ? arr[i-1] : s;
                if(arr[i-1] > arr[i]){
                    rot++;
                    if(i == n-1 && arr[i] > arr[0]) return false; 
                }
                
            }else{
                if(arr[i-1] > arr[i] || s < arr[i-1] || s<arr[i]) return false;
            }
        }
        

        
        return true;
    }
};