class Solution {
public:
    bool isPossible(vector<int> &dist, double hour, int speed){

        double time = 0.0;
        int n = dist.size();

        for(int i=0; i<n-1; i++){

            time += ceil((double)dist[i]/speed);
        }
        time += (double)dist[n-1]/speed;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int low = 1, high = 1e7;
        int ans = -1;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(isPossible(dist,hour,mid)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }

        return ans;
    }
};