class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       set<int> s1 ,s2 ; map<int,int>mp ;vector<int>result ;
       for(int i=0 ;i<nums1.size();i++){
           s1.insert(nums1[i]) ;
       }
            for(int i=0 ;i<nums2.size();i++){
           s2.insert(nums2[i]) ;
       }
       for(auto & i:s1){
           mp[i]++ ;
       }
        for(auto & i:s2){
           mp[i]++ ;
       }
       for(auto & i:mp){
           if(i.second>1){
               result.push_back(i.first) ;
           }
       }
       return result ;
    }
};