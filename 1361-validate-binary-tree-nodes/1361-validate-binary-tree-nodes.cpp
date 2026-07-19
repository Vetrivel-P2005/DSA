class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (++inDegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                if (++inDegree[rightChild[i]] > 1) return false;
            }
        }
        
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                if (root != -1) return false; 
                root = i;
            }
        }
        
        if (root == -1) return false; 
        
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(root);
        visited[root] = true;
        int visitedCount = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visitedCount++;
            
            if (leftChild[curr] != -1) {
                if (visited[leftChild[curr]]) return false; 
                visited[leftChild[curr]] = true;
                q.push(leftChild[curr]);
            }
            if (rightChild[curr] != -1) {
                if (visited[rightChild[curr]]) return false;
                visited[rightChild[curr]] = true;
                q.push(rightChild[curr]);
            }
        }
        
         return visitedCount == n;
    }
};