class Solution {
public:
    using ll = long long;
    long long maximumSumOfHeights(vector<int>& m) {
        int n=m.size();
        stack<int>st;
        st.push(-1);
        st.push(0);
        vector<ll> pre(n);
        pre[0]=0;
        ll sum=0;
        for(int i=1;i<n;i++){
            if(m[i]>=m[i-1]){
                sum+=1ll*m[i-1];
            }else{
                ll temp=0;
                while(st.size()>1 && m[st.top()]>m[i]){
                    st.pop();
                }
                if(st.top()!=-1){
                    temp+=1ll*(i-st.top()-1)*1ll*m[i];
                }else{
                    temp+=1ll*i*1ll*m[i];
                }
                if(st.size()>1) temp+=1ll*pre[st.top()+1];
                sum=temp;
            }
            pre[i]=sum;
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<pre[i]<<endl;
        // }
        st= stack<int>();
        st.push(-1);
        st.push(n-1);
        vector<ll> suf(n);
        suf[n-1]=0;
        sum=0;
        for(int i=n-2;i>=0;i--){
            if(m[i]>=m[i+1]){
                sum+=1ll*m[i+1];
            }else{
                ll temp=0;
                while(st.size()>1 && m[st.top()]>m[i]){
                    st.pop();
                }
                if(st.top()!=-1){
                    temp+=1ll*(st.top()-i-1)*1ll*m[i];
                }else{
                    temp+=1ll*(n-i-1)*1ll*m[i];
                }
                if(st.size()>1) temp+=1ll*suf[st.top()-1];
                sum=temp;
            }
            suf[i]=sum;
            st.push(i);
        }
        // for(int i=n-1;i>=0;i--){
        //     cout<<suf[i]<<endl;
        // }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans=max(1ll*(pre[i]+suf[i]+m[i]),ans);
        }
        return ans;
    }
};