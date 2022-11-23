//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    Node* findStart(int start, Node* root)
    {
        if(!root) return NULL;
        if(root -> data == start) return root;
        auto left = findStart(start, root->left);
        auto right = findStart(start, root->right);
        if(!left && right) return right;
        if(!right && left) return left;
        return NULL;
    }
    void findParenNodes(Node*root, Node* target, unordered_map<Node*,Node*>&parentNodes)
    {
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            auto curr_node = q.front(); q.pop();
            if(curr_node->left)
            {
                parentNodes[curr_node->left] = curr_node;
                q.push(curr_node->left);
            }
            if(curr_node->right)
            {
                parentNodes[curr_node->right] = curr_node;
                q.push(curr_node->right);
            }
        }
    }
  public:
    int minTime(Node* root, int target) 
    {
        auto start_node = findStart(target, root);
        unordered_map<Node*, Node*>parentNodes;
        findParenNodes(root, start_node, parentNodes);

        unordered_map<Node*, bool>vis;
        queue<Node*>q;
        q.push(start_node);
        vis[start_node] = 1;
        //main course
        int minTime = 0;
        while(!q.empty())
        {
            int size = q.size();
            int flag = 0;
            for(int i=0; i<size; i++)
            {
                auto curr_node = q.front(); q.pop();
                if(curr_node->left && !vis[curr_node->left])
                {
                    flag = 1;
                    vis[curr_node->left] = 1;
                    q.push(curr_node->left);
                }
                if(curr_node->right && !vis[curr_node->right])
                {
                    flag = 1;
                    vis[curr_node->right] = 1;
                    q.push(curr_node->right);
                }
                if(parentNodes[curr_node] && !vis[parentNodes[curr_node]])
                {
                    flag = 1;
                    vis[parentNodes[curr_node]] = 1;
                    q.push(parentNodes[curr_node]);
                }
            }
            if(flag) minTime++;
        }
        return minTime;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends