class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
        
        while (getline(ss, token, '/')) {
            if (token.empty() || token == ".") {
                continue; // skip empty or current dir
            } else if (token == "..") {
                if (!stack.empty()) stack.pop_back(); // go up one dir
            } else {
                stack.push_back(token); // valid directory name
            }
        }
        
        string ans = "/";
        for (int i = 0; i < stack.size(); i++) {
            ans += stack[i];
            if (i != stack.size() - 1) ans += "/";
        }
        return ans;
    }
};