class Solution {
public:
    set<string> st; // Declare a set to store unique binary strings
    string ans = ""; // Initialize a string to store the answer

    // Depth-First Search (DFS) function to generate binary strings
    void dfs(string s, int n) {
        // Base case: If the size of the generated string equals n
        if (s.size() == n) {
            // Check if the generated string is not in the set and if the answer is empty
            if (st.find(s) == st.end() && ans == "") {
                ans = s; // Update the answer with the generated string
            }
            return; // Return from the function
        }

        // Recursive calls to generate binary strings by appending '0' and '1'
        dfs(s + '0', n);
        dfs(s + '1', n);

        return; // Return from the function
    }

    // Main function to find a different binary string from the given vector of strings
    string findDifferentBinaryString(vector<string>& nums) {
        // Store the input strings into the set for quick lookup of existing strings
        for (auto a : nums) {
            st.insert(a);
        }

        int n = nums[0].size(); // Determine the length of the binary strings

        dfs("", n); // Start DFS from an empty string

        return ans; // Return the resulting answer
    }
};