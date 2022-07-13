class Solution
{
public:
  bool helper(TreeNode *r1, TreeNode *r2)
  {
    if (!r1 && !r2)
      return true;
    if (!r1 && r2 || r1 && !r2 || r1->val != r2->val)
      return false;
    return helper(r1->left, r2->right) && helper(r1->right, r2->left);
  }
  bool isSymmetric(TreeNode *root)
  {

    if (!root)
      return true;
    return helper(root, root);
  }
};