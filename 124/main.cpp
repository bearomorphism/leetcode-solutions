/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct Node
{
  int val;
  Node *left, *right;
  int maxChildrenPathSum;
  Node() : val(0), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
  Node *dfs(TreeNode *root)
  {
    if (!root)
      return nullptr;
    Node *ret = new Node();
    ret->val = root->val;
    ret->left = dfs(root->left);
    ret->right = dfs(root->right);
    int l = getChildrenPathSum(ret->left);
    int r = getChildrenPathSum(ret->right);
    ret->maxChildrenPathSum = ret->val + max(l, r);
    return ret;
  }

  int getChildrenPathSum(Node *n)
  {
    return n ? max(n->maxChildrenPathSum, 0) : 0;
  }

  int dfsSum(Node *root)
  {
    if (!root)
      return 0;
    int l = getChildrenPathSum(root->left);
    int r = getChildrenPathSum(root->right);
    int ret = root->val + l + r;
    if (root->left) ret = max(ret, dfsSum(root->left));
    if (root->right) ret = max(ret, dfsSum(root->right));
    return ret;
  }

public:
  int maxPathSum(TreeNode *root)
  {
    Node *newRoot = dfs(root);
    return dfsSum(newRoot);
  }
};