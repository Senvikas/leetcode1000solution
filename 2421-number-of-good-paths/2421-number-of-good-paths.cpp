class Solution
{
    public:
        int numberOfGoodPaths(vector<int> &nodeValues, vector<vector< int>> &edges)
        {
            const unsigned int numNodes = nodeValues.size();
            int numGoodPaths = numNodes;
            int currentNode, previousNode;
            map<pair<int, int>, int> pathPairs;
            vector<int> parentNodes(numNodes, -1), highestParentNodes(numNodes, -1);
            vector<bool> visited(numNodes, 0);
            highestParentNodes[0] = 0;
            visited[0] = 1;
            for (const auto &edge: edges)
            {
                if (visited[edge[0]])
                {
                    parentNodes[edge[1]] = edge[0];
                }
                else
                {
                    parentNodes[edge[0]] = edge[1];
                }
                visited[edge[1]] = 1;
                visited[edge[0]] = 1;
            }
            for (int i = 1; i < numNodes; i++)
            {
                currentNode = i;
                previousNode = parentNodes[i];
                while ((currentNode != previousNode) && (currentNode != 0) && (previousNode != -1) && (nodeValues[previousNode] <= nodeValues[i]))
                {
                    currentNode = previousNode;
                    previousNode = highestParentNodes[currentNode];
                }
                previousNode = parentNodes[currentNode];
                while ((previousNode != -1) && (nodeValues[previousNode] <= nodeValues[i]))
                {
                    currentNode = previousNode;
                    previousNode = parentNodes[currentNode];
                }
                highestParentNodes[i] = currentNode;
            }
            for (int i = 0; i < numNodes; i++)
            {
                pathPairs[
                {
                    nodeValues[i],
                    highestParentNodes[i]
                }]++;
            }
            for (auto path: pathPairs)
            {
                numGoodPaths += ((path.second *(path.second - 1)) >> 1);
            }
            return numGoodPaths;
        }
};