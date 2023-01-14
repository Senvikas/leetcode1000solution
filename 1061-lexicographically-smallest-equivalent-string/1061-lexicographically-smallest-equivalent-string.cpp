class Solution
{
    public:
       	// findParent function finds the parent of a given node in a union-find data structure.
       	// The function takes in an integer node and a vector of integers parent, which represents the parent of each node.
       	// The function starts with the current node being the input node.
       	// It then loops through the parent vector until it finds the parent of the current node, which is the node that has itself as its parent.
       	// It then returns the parent node.
        int findParent(int node, vector<int> &parent)
        {
            int curr = node;
            while (parent[curr] != curr) curr = parent[curr];
            return curr;
        }
   	// merge function merges two nodes in a union-find data structure.
   	// The function takes in two integer nodes (node1, node2) and a vector of integers parent, which represents the parent of each node.
   	// It first finds the parent of each node using the findParent function. 
   	// If the parents are the same, the function returns without doing anything.
   	// Otherwise, it sets the parent of the node with the larger parent value to the parent of the node with the smaller parent value.
   	// This is done so that the parent of the larger group points to the parent of the smaller group.
    void merge(int node1, int node2, vector<int> &parent)
    {
        int parent1 = findParent(node1, parent);
        int parent2 = findParent(node2, parent);
        if (parent1 == parent2) return;

        int minParent = min(parent1, parent2);
        int maxParent = max(parent1, parent2);
        parent[maxParent] = minParent;
    }

   	// smallestEquivalentString function finds the smallest equivalent string given two strings s1 and s2, and a base string baseStr.
   	// It first creates a union-find data structure using the nodes of the s1 and s2 strings.
   	// Then it creates an empty string ans and loops through the base string.
   	// For each character in the base string, it finds the smallest equivalent character using the findParent function.
   	// It then appends this character to the ans string and returns ans at the end.
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.size();
        vector<int> parent(26);
        for (int i = 0; i < 26; i++) parent[i] = i;
        for (int i = 0; i < n; i++) merge(s1[i] - 'a', s2[i] - 'a', parent);

        string ans = "";
        for (int i = 0; i < baseStr.size(); i++)
        {
            int minParentIdx = findParent(baseStr[i] - 'a', parent);
            char minParent = minParentIdx + 'a';
            ans.push_back(minParent);
        }
        return ans;
    }
};