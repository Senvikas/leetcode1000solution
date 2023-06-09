class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int beg=0, end=letters.size()-1;

        if(letters[0] > target)
            return letters[0];
        else if(target >= letters[letters.size()-1])
            return letters[0];  

        char ans;
        int mid;
        while(beg<=end){
            mid = (end-beg)/2+beg;
            if(letters[mid]>target){
                ans = letters[mid];
                end = mid-1;
            }
            else
                beg = mid+1;
        }

        return ans;

    }
};