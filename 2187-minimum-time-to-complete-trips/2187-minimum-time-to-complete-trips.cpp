typedef long long ll;
class Solution {
public:
    long long minimumTime(vector<int>& time, int tt) {
        ll l = 0, h = 1e14, ans = h;
        sort(time.begin(), time.end());
        
        while(l < h)
        {
            ll mid = (l + h)/2, cnt = 0;
            for(int i=0; i<time.size(); i++)
            {
                cnt += (mid/time[i]);
            }
            
            if(cnt >= tt){
                ans = min(ans, mid);
                h = mid;
            }
            else l = mid + 1;
        }
        return ans;
    }
};