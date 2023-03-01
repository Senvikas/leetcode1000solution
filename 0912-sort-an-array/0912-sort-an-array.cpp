class Solution {
public:

    void merge(vector<int>&v, int l , int mid, int r){
        int i=l;
        int j=mid+1;
        int k=l;
        int b[r+1];
       
        while(i<=mid && j<=r){
            if(v[i]<v[j]){
                b[k]=v[i];
                i++;
            }
            else{
               b[k]=v[j];
                j++;
            }
            k++;
        }
        while(j<=r){
           b[k++]=v[j++];
        }
        while(i<=mid){
            b[k++]=v[i++];
        }
        for(int p=l;p<=r;p++){
            v[p]=b[p];
        }
    }

    void mergesort(vector<int>&v, int l , int r){
        if(l<r){                                                        
            int m=l+(r-l)/2;
            mergesort(v,l,m);
            mergesort(v,m+1,r);
            merge(v,l,m,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
        
    }
};