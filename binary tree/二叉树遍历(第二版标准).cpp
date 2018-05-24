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


/*----中序方法
先把左边都压栈，这时不能访问，弹栈后再访问，然后指向右边，下次就从右边开始了
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *>s;
        
        while(root||!s.empty())
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                root=s.top();
                s.pop();
                result.push_back(root->val);
                root=root->right;   //访问完左边直接访问右边，注意中间是先访问过
            }
        }
        return result;
    }
};

