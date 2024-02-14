class Solution {
public:
    
    bool pal(string word){
        int n = word.size();
        int i=0, j=n-1;
        while(i<=j){
            if(word[i++] != word[j--]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {

        
        for(auto word: words){
            if(pal(word)) return word;
        }
        return "";
    }
};