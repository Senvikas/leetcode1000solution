class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        int[][] isPal = new int[n][n];
        int ans = 0;
        for(int i=0; i<n; i++) { ans++; isPal[i][i] = 1;}
        
        for(int len=2; len<=n; len++)
            for(int i=0; i<=n-len; i++){
                int j = i + len - 1;
                if(len == 2){
                    isPal[i][j] = (s.charAt(i) == s.charAt(j) ? 1 : 0);    
                }else if(s.charAt(i) == s.charAt(j)){
                    if(i+1<n) isPal[i][j] = isPal[i+1][j-1];
                }
            if(isPal[i][j] == 1) ans++;
        }
        
        return ans;
    }
}