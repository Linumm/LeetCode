/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> um; // {origin, copied}
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* new_one = new Node(node->val);
        um[node] = new_one;

        // BFS with 'node'
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            for (auto neighbor: current->neighbors) {
                if (um.find(neighbor) == um.end()) { // if not found in hash table
                    um[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                um[current]->neighbors.push_back(um[neighbor]); // copied_current->neighbors.push_back(copied_neighbor)
            }
        }

        return new_one;
    }
};