//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] S1 = br.readLine().trim().split(" ");
            int n = Integer.parseInt(S1[0]);
            int m = Integer.parseInt(S1[1]);
            int[][] image =  new int[n][m];
            for(int i = 0; i < n; i++){
                String[] S2 = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++)
                    image[i][j] = Integer.parseInt(S2[j]);
            }
            String[] S3 = br.readLine().trim().split(" ");
            int sr = Integer.parseInt(S3[0]);
            int sc = Integer.parseInt(S3[1]);
            int newColor = Integer.parseInt(S3[2]);
            Solution obj = new Solution();
            int[][] ans = obj.floodFill(image, sr, sc, newColor);
            for(int i = 0; i < ans.length; i++){
                for(int j = 0; j < ans[i].length; j++)
                    System.out.print(ans[i][j] + " ");
                System.out.println();
            }
        }
    }
}

// } Driver Code Ends


class Solution {
    public void dfs(int[][] image, int sr, int sc, int newc, int[][] vis, int originalColor) {
        if (vis[sr][sc] == 0) {
            vis[sr][sc] = 1;
            image[sr][sc] = newc;

            int[] delrow = {-1, 0, 1, 0};
            int[] delcol = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = sr + delrow[i];
                int ncol = sc + delcol[i];

                if (nrow >= 0 && nrow < image.length && ncol >= 0 && ncol < image[0].length &&
                    vis[nrow][ncol] == 0 && image[nrow][ncol] == originalColor) {
                    dfs(image, nrow, ncol, newc, vis, originalColor);
                }
            }
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int n = image.length;
        int m = image[0].length;
        int[][] vis = new int[n][m];

        int originalColor = image[sr][sc]; // Store the original color.
        dfs(image, sr, sc, newColor, vis, originalColor);
        return image;
    }
}
