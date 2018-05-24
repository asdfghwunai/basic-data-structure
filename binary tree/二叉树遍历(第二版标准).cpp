/*---前序遍历方法
先依次遍历左边，并把节点压入栈,左边为空时转右边
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        while(root||!s.empty())
        {
            if(root)
            {
                result.push_back(root->val);   
                s.push(root);
                root=root->left;
            }
            else
            {
                root=s.top();
                s.pop();
                root=root->right; //如果这里为空,下次循环if不会执行的,正好啊
            }
        }
        return result;
    }
};
