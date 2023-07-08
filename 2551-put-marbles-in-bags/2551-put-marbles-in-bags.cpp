class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        int n = w.size();
        long long mx = w[0] + w[n-1]; // maximum val
        long long mn= w[0] + w[n-1]; // min val

        // we'll be storing the adjacent sums in priority queue
        vector<long long> adjSum; 

        for(int i=0; i<n-1; i++){
            adjSum.push_back(w[i] + w[i+1]);
        }

        sort(adjSum.begin(), adjSum.end(), greater<int>()); // sorting in decending order

        for(int i=0; i<k-1; i++){
            mx += (long long) adjSum[i];
            mn += (long long) adjSum[n-i-2];
        }
        return (mx-mn);

    }
};