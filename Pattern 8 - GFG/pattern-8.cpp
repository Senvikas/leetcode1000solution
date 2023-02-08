//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    for(int i=n; i>=1; i--)
        {
            for(int j=1; j<=2*n-1; j++)
            {
                if(j <= n-i) cout << " " ;
                else if(j >= n+i) continue;
                else cout << "*" ;
            }
            cout << endl;
        }
        return ;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends