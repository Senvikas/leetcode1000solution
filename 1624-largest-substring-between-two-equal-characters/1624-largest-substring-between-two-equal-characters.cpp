class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> v;
        for(int i=0;i<s.size();i++)
        {
            char temp=s[i];
            for(int j=i+1;j<s.size();j++)
            {
                if(s[j]==temp)
                {
                    v.push_back(j-i-1);
                }
            }
        }
        if(v.size()==0)
        return -1;
        int maxi=*max_element(v.begin(),v.end());
        return maxi;
    }
};