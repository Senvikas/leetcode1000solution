class Solution
{
    public:
       	// This function uses depth-first search to count the number of subtrees with a given label
        void dfs(int currentNode, string &labels, vector<vector < int>> &adjacencyList, int labelCount[], vector<int> &result)
        {
           	// If the result for the current node has not been calculated yet
            if (result[currentNode] == 0)
            {
               	// Mark the current node as visited
                result[currentNode] = 1;
               	// Iterate through all the children of the current node
                for (auto child: adjacencyList[currentNode])
                {
                   	// Initialize a new count array for the child
                    int childLabelCount[26] = {};
                   	// Recursively call the function for the child
                    dfs(child, labels, adjacencyList, childLabelCount, result);
                   	// Add the count from the child to the current count array
                    for (auto i = 0; i < 26; ++i)
                        labelCount[i] += childLabelCount[i];
                }
               	// Store the final count for the current node's label in the result array
                result[currentNode] = ++labelCount[labels[currentNode] - 'a'];
            }
        }
   	// This function returns an array with the count of subtrees with a given label for each node
    vector<int> countSubTrees(int numNodes, vector<vector < int>> &edges, string labels)
    {
       	// Initialize the result and count arrays
        vector<int> result(numNodes);
        int labelCount[26] = {};
       	// Create an adjacency list representation of the tree
        vector<vector < int>> adjacencyList(numNodes);
        for (auto &edge: edges)
        {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
       	// Start the depth-first search from the root node (node 0)
        dfs(0, labels, adjacencyList, labelCount, result);
        return result;
    }
};