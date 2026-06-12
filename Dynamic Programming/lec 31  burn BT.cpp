#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // BFS to build parent mapping
    TreeNode* bfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int nmbr) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if(current->val==nmbr){
                node= current;
            }
            if (current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
        return node;
    }

public:
    int BURN_distance(TreeNode* root, int  nmbr) {

        unordered_map<TreeNode*, TreeNode*> parent;  // child -> parent mapping
        TreeNode* target=  bfs(root, parent,nmbr); 

        unordered_map<TreeNode*, bool> vis; 

        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;

        int cnt = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool p=false;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Check left child
                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                    p=true;
                }
                // Check right child
                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                    p=true;
                }
                // Check parent
                if (parent.count(node) && !vis[parent[node]]) {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                    p=true;
                }
            }

            if(p){
                cnt++;}
            
        }
        return cnt;
    }
};

// Example usage:
int main() {
    /*
        Example tree:
              3
             / \
            5   1
           / \ / \
          6  2 0  8
            / \
           7   4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution sol;
    int result = sol.BURN_distance(root, 7);

    cout << "Nodes at distance 2 from target 5: "<< result<<endl;
    

    return 0;
}
