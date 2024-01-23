class Solution {
public:
    bool hasDup(string &s1, string &s2){
        int arr[26]={0};
        for(char &ch:s1){
            if(arr[ch-'a']>0) return true;

            arr[ch-'a']++;
        }
        for(char &ch:s2){
            if(arr[ch-'a']>0) return true;
        }
        return false;
    }

    int solve(int i, vector<string>&arr, string temp, int n){
        if(i>=n) return temp.length();
        int exclude=0;
        int include=0;

        if(hasDup(arr[i], temp)){
            exclude=solve(i+1, arr, temp, n);
        }
        else{
            include=solve(i+1, arr, temp+arr[i], n);
            exclude=solve(i+1, arr, temp, n);
        }
        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        int n=arr.size();
        int i=0;
        return solve(i, arr, temp, n);
    }
};