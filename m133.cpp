/*
第一次寫的，居然只贏 10%，好爛
看了一下討論區，有人是直接用到了 node 的值在 [0, 100] 之間，對應起來比較快
*/

class Solution {
    map<Node*, Node*> m;
    map<Node*, bool> visited;
public:
    Node *old2New(Node* oldNode) {
        if(m.find(oldNode) != m.end())
            return m[oldNode];
        else {
            Node *newNode = new Node(oldNode->val);
            m[oldNode] = newNode;
            return newNode;
        }
    }
    Node *cloneGraph(Node* node) {
        queue<Node*> q;
        Node *oldNode, *newNode;
        
        if(!node)
            return NULL;
        
        oldNode = node;
        newNode = old2New(oldNode);
        visited[node] = true;
        q.push(node);
        
        while(!q.empty()) {
            oldNode = q.front();
            newNode = m[oldNode];
            q.pop();
            for(int i = 0; i < oldNode->neighbors.size(); i++) {
                if(visited.find(oldNode->neighbors[i]) == visited.end()) {
                    q.push(oldNode->neighbors[i]);
                    visited[oldNode->neighbors[i]] = true;
                }
                newNode->neighbors.push_back(old2New(oldNode->neighbors[i]));
            }
        }
        return m[node];
    }
};

/*
Runtime: 10 ms, faster than 14.96% of C++ online submissions for Clone Graph.
Memory Usage: 8.7 MB, less than 55.69% of C++ online submissions for Clone Graph.
*/

//***************************************************************************//
// 換成 unordered_map 變慢

class Solution {
    unordered_map<Node*, Node*> m;
    unordered_map<Node*, bool> visited;
public:
    Node *old2New(Node* oldNode) {
        if(m.find(oldNode) != m.end())
            return m[oldNode];
        else {
            Node *newNode = new Node(oldNode->val);
            m[oldNode] = newNode;
            return newNode;
        }
    }
    Node *cloneGraph(Node* node) {
        queue<Node*> q;
        Node *oldNode, *newNode;
        
        if(!node)
            return NULL;
        
        oldNode = node;
        newNode = old2New(oldNode);
        visited[node] = true;
        q.push(node);
        
        while(!q.empty()) {
            oldNode = q.front();
            newNode = m[oldNode];
            q.pop();
            for(int i = 0; i < oldNode->neighbors.size(); i++) {
                if(visited.find(oldNode->neighbors[i]) == visited.end()) {
                    q.push(oldNode->neighbors[i]);
                    visited[oldNode->neighbors[i]] = true;
                }
                newNode->neighbors.push_back(old2New(oldNode->neighbors[i]));
            }
        }
        return m[node];
    }
};

/*
Runtime: 12 ms, faster than 10.57% of C++ online submissions for Clone Graph.
Memory Usage: 8.6 MB, less than 81.25% of C++ online submissions for Clone Graph.
*/
