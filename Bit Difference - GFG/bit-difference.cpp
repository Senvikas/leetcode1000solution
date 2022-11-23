//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int n, long long int arr[])
    {
        long long ans = 0, mod = 1e9+7;
    for(long long i=0; i<31; i++)
    {
        long long z=0, o=0;
        for(long long j=0; j<n; j++)
        {
            if((arr[j]>>i)%2 == 1) o++;
            else z++;
        }
        ans = (ans + (z*o)%mod )%mod;
    }
    return (int)(2*ans)%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends