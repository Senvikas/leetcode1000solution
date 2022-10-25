
/*
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int l=0, mid=0, r=n-1;
        int cnt=0, cnt1=0, cnt2=0;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] == 0)
                cnt++;
            else if(arr[i] == 1)
                cnt1++;
            else
                cnt2++;
        }
        for(int i=0; i<cnt; i++)
            arr[i] = 0;
        for(int i=cnt; i<cnt+cnt1; i++)
            arr[i] = 1;
        for(int i=cnt+cnt1; i<n; i++)
            arr[i] = 2;
        
        return;
    }
};

*/
    //[2,0,2,1,1,0,2,2,2,1,1,1,0,0,2,2,0,1,1,1,1,2,2,2]

//this will solve the question in two passes
/*
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int l=0, mid=0, r=n-1;
        
        while(l<=r)
        {
            if(arr[r]==2)
                r--;
            else if(arr[l] == 2)
            {
                swap(arr[l], arr[r]);
                l++; r--;
            }
            if(arr[l] != 2)
                l++;
        }
        while(mid<=r)
        {
            if(arr[r] == 1)
                r--;
            else if(arr[mid] == 0)
                mid++;
            else
                swap(arr[mid++], arr[r--]);
        }
        
        
        return;
    }
};  
*/

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int l=0, mid=0, r=n-1;
        while(mid<=r)
        {
            if(arr[mid] == 0)
                swap(arr[l++], arr[mid++]);
            else if(arr[mid] == 1)
                mid++;
            else
                swap(arr[mid], arr[r--]);
            
        }
        return ;
    }
};