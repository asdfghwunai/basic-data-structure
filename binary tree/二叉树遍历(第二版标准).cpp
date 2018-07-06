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


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*----后序方法
先把左边都压栈，这时不能访问，弹栈后再访问，然后指向右边，下次就从右边开始了
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *pre=NULL;
        if(root==NULL)
            return result;
        s.push(root);
        while(!s.empty())
        {
            root=s.top();
            if((root->left==NULL&&root->right==NULL)||((pre!=NULL)&&(pre==root->left||pre==root->right)))  //情况1直接输出
            {
                    result.push_back(root->val);
                    s.pop();
                    pre=root;
                    //root=NULL; //来让下一个结点出栈 这里改root没事，当成副本和实体指向同一个地址，现在副本不指向了,实体还指向
            }
            else
            {
                if(root->right)
                    s.push(root->right);
                if(root->left)
                    s.push(root->left);   //迷在root怎么向下走
            }
       
        }
        return result;
    }
};

