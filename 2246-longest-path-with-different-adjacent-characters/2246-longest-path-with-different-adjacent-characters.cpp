class Solution
{
    public:
       	// variable to store the maximum length of the path
        int max_length = 1;
   	// array to store the distance from the starting node to each node
    int distances[(int) 1e5];
   	// function to perform DFS and calculate the max length of path and distances
    void dfs(int starting_node, string &word, vector<int> adjacent_nodes[])
    {
       	// set distance of the starting node to 1
        distances[starting_node] = 1;
       	// iterate through the adjacent nodes
        for (auto node: adjacent_nodes[starting_node])
        {
           	// recursively call the dfs function for the adjacent node
            dfs(node, word, adjacent_nodes);
           	// check if the characters of the current node and adjacent node are different
            if (word[starting_node] != word[node])
            {
               	// update the max_length
                max_length = max(max_length, distances[starting_node] + distances[node]);
               	// update the distance of the current node
                distances[starting_node] = max(distances[starting_node], distances[node] + 1);
            }
        }
        return;
    }
   	// main function to find the longest path
    int longestPath(vector<int> &parent_nodes, string word)
    {
       	// get the number of nodes
        int number_of_nodes = parent_nodes.size();
       	// create an array to store the adjacent nodes
        vector<int> adjacent_nodes[number_of_nodes];
       	// iterate through the parent nodes
        for (int i = 1; i < number_of_nodes; i++)
        {
           	// add the child nodes to the adjacent nodes array
            adjacent_nodes[parent_nodes[i]].push_back(i);
        }
       	// call the dfs function starting from node 0
        dfs(0, word, adjacent_nodes);
       	// return the max length
        return max_length;
    }
};