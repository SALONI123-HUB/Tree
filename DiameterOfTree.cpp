#include <iostream>
#include <algorithm> // For max
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int p1 = diameterOfBinaryTree(root->left);
        int p2 = diameterOfBinaryTree(root->right);
        int p3 = height(root->left) + height(root->right);
        
        return max(max(p1, p2), p3);
    }
};

int main() {
    // Creating a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the Binary Tree: " << diameter << endl;

    // Free the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
