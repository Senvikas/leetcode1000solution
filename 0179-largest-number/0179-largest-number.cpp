class Solution {
public:
    static bool comp(string &s1, string &s2){

        if (s1 == "0") return false;
    if (s2 == "0") return true;
        int i;
        for( i=0; i<min(s1.size(), s2.size()); i++){
            if(s1[i] == s2[i]) continue;
            else return s1[i] > s2[i];
        }
        i--;
        auto s1ps2 =  s1 + s2;
        auto s2ps1 = s2 + s1;

        if(s2ps1 > s1ps2) return false;
        return true;
        return s1.back() > s2.back();
    }

    bool allZeros(const vector<int>& nums) {
    for (int num : nums) {
        if (num != 0) return false;
    }
    return true;
}


    string largestNumber(vector<int>& nums) {

        if(allZeros(nums)) return "0";
        string ans = "";

        vector<string> numsStr;

        for(auto num: nums){
            numsStr.push_back(to_string(num));
        }

        sort(numsStr.begin(), numsStr.end(), comp);

        // for(auto num: numsStr) cout << num << " ";
        // cout << endl;
        // reverse(numsStr.begin(), numsStr.end());

        for(auto num: numsStr) ans += num;
        ans.erase(0, ans.find_first_not_of('0'));
        if(!ans.size()) {
            // cout << " Hi " << endl;
            ans = "0";
        }
        return ans;
    }
};