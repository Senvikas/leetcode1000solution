/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    void deepClone(Node node, Node res, Node[] nodes) {
        if(node == null || nodes[node.val] != null) return;
        nodes[node.val] = res;
        for(Node n : node.neighbors) {
            if(res.neighbors.isEmpty()) res.neighbors = new ArrayList<>();
            if(nodes[n.val] == null) {
                res.neighbors.add(new Node(n.val));
                deepClone(n, res.neighbors.get(res.neighbors.size() - 1), nodes);
            } else {
                res.neighbors.add(nodes[n.val]);
            }
        } 
    }

    public Node cloneGraph(Node node) {
        if(node == null) return null;
        Node res = new Node(node.val);
        deepClone(node, res, new Node[101]);
        return res;
    }
}