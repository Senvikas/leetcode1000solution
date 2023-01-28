class SummaryRanges {
public:
    vector<vector<int>> arr;
    SummaryRanges() {
        arr.resize(0);
    }
    int bin(int x){
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int m=(s+e)/2;
            if(arr[m][0]<=x && arr[m][1]>=x) return -1;
            if(arr[m][0]>x) e=m-1;
            else s=m+1;
        }
        return s;
    }
    
    void addNum(int value) {
         int ind=bin(value);
         cout<<value<< " "<<ind<<endl;
         if(ind==-1) return ;
         int n=arr.size();
         if(n==0){
            arr.insert(arr.begin()+ind,{value,value});
            return;  
         }
         if(ind!=n){
             if(value+1==arr[ind][0]) arr[ind][0]--;
         }
         if(ind!=0){
             if(arr[ind-1][1]+1==value) arr[ind-1][1]++;
         }
         if( ind!=0 && ind != n){
             if(arr[ind-1][1]==arr[ind][0]){
                 arr[ind-1][1]=arr[ind][1];
                 arr.erase(arr.begin()+ind);
             }
             else if(arr[ind][0]!=value && arr[ind-1][1]!=value){
                 arr.insert(arr.begin()+ind,{value,value});
             }
             return;
         }
         if(ind==0){
            if(arr[0][0]==value) return;
            arr.insert(arr.begin()+ind,{value,value});
            return;
         }
         if(ind==n){
             if(arr[ind-1][1]==value) return;
             arr.insert(arr.begin()+ind,{value,value});
             return;
         }    
    }
    
    vector<vector<int>> getIntervals() {
        return arr;
    }
};