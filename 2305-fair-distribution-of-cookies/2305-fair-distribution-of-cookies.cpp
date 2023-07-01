class Solution {
public:
int n;
int result=INT_MAX  ;
void sol(int idx,vector<int>& cook,vector<int>& cookies, int k){
    if(idx>=n){
        int unfair=*max_element(begin(cook),end(cook));
        result=min(result,unfair);
        return;
    }
    int cookie=cookies[idx];
    for(int i=0;i<k;i++){
        cook[i]+=cookie;
        sol(idx+1,cook,cookies,k);
        cook[i]-=cookie;
    }
}

    int distributeCookies(vector<int>& cookies, int k) {
         n=cookies.size();
        vector<int> cook(k,0);
        sol(0,cook,cookies,k);
        return result;
    }
};