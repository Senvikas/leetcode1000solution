class Solution {
public:
    bool isvowel(char c) {
  
        char lowercase_c = std::tolower(static_cast<unsigned char>(c));
        // Check if it's a vowel
        return (lowercase_c == 'a' || lowercase_c == 'e' || lowercase_c == 'i' || lowercase_c == 'o' || lowercase_c == 'u');
    return false;
}
    
    string sortVowels(string s) {
        string vow = "";
        for(auto ch : s){
            if(isvowel(ch)){
                vow.push_back(ch);
            }
        }
        sort(vow.begin(), vow.end());
        //cout << vow << endl;
        int i = 0;
        for(int j=0; j<s.size(); j++){
            char ch = s[j];
            if(isvowel(ch)){
                s[j] = (vow[i]); i++;
            }
        }
        return s;
        
    }
};