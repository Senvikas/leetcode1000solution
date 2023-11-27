vector<vector<int>>dial(4,vector<int>(3,0));
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={-2,-1,1,2,2,1,-1,-2};
#define mod 1000000007
int help(int x,int y,int n,vector<vector<vector<int>>>&dp){
if(n==0){
    return 1;
}
if(dp[n][x][y]!=-1){
    return dp[n][x][y];
}
int sum=0;
for(int i=0;i<8;i++){
    int new_x=x+dy[i];
    int new_y=y+dx[i];
    if(new_x>=0 && new_x<=3 && new_y>=0 && new_y<3 && dial[new_x][new_y]!=10){
          sum+=(help(new_x,new_y,n-1,dp));
          sum%=mod;
    }
}
return dp[n][x][y]=sum;
}

class Solution {
public:
    int knightDialer(int n) {
          dial[0] = {1, 2, 3};
        dial[1] = {4, 5, 6};
        dial[2] = {7, 8, 9};
        dial[3] = {10, 0, 10}; 
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(4,vector<int>(3,-1)));
        int sum=0;
        for(int i=0;i<4;i++){
           for(int j=0;j<3;j++){
               if(dial[i][j]!=10 ){
                   sum+=(help(i,j,n-1,dp));
                   sum%=mod;
               }
           }
        }
        return sum;

    }
};