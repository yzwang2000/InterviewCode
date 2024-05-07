#include <BinaryTree/example.hpp>
#include <stack>
#include <queue>

namespace BinaryTree{
    namespace Solution01{
        // 递归函数的三个注意事项, 参数(递归过程需要的参数, 就在递归函数中加上), 返回值(明确每次递归的返回值是什么), 终止条件
        void Solution::preTraversal(TreeNode *root, std::vector<int> vec)
        {
            // 终止条件
            if(root==nullptr)
                return;
            
            vec.push_back(root->val);
            preTraversal(root->left, vec);
            preTraversal(root->right, vec);
        }

        std::vector<int> Solution::preorderTraversal(TreeNode *root)
        {
            std::vector<int> vec;
            preTraversal(root, vec);
            return vec;
        }
    }
    
    namespace Solution02{
        std::vector<int> Solution::preorderTraversal(TreeNode *root){
            std::vector<int> vec;
            if(root==nullptr)
                return vec; 

            std::stack<TreeNode *> st;
            st.push(root);
            while (!st.empty())
            {
                TreeNode * tmp = st.top();  // 这里是浅拷贝, 但是没关系, 结构体没并没有维护堆上的东西
                st.pop();  // 释放了结构体指针
                vec.push_back(tmp->val);
                if(tmp->right) st.push(tmp->right); 
                if(tmp->left) st.push(tmp->left); 
            }
        }
    }

    namespace Solution03{
        std::vector<int> Solution::inorderTraversal(TreeNode* root){
            std::vector<int> vec;
            std::stack<TreeNode*> st;
            TreeNode *node = root;

            while (node!=nullptr || !st.empty())  // || 前的用于判定初始就不为 nullptr, || 用于后续遍历完所有的判定
            {
                if(node!=nullptr)
                {
                    st.push(node);
                    node = node->left;
                }
                else{
                    node = st.top();
                    st.pop();
                    vec.push_back(node->val);
                    node = node->right;
                }
            }

            return vec; 
        }
    }

    namespace Solution04{
        std::vector<int> Solution::postorderTraversal(TreeNode* root){
            std::vector<int> vec;
            std::stack<TreeNode*> st;
            TreeNode* prev = root; // 用于跟踪上一个访问过的节点
            TreeNode *node = root;

            while (node!=nullptr || !st.empty())  // || 前的用于判定初始就不为 nullptr, || 用于后续遍历完所有的判定
            {
                if(node!=nullptr)
                {
                    st.push(node);
                    node = node->left;
                }
                else{
                    node = st.top();
                    if(node->right && node->right != prev)
                    {
                        node = node->right;
                    }
                    else{
                        st.pop();
                        vec.push_back(node->val);
                        prev = node;
                        node = nullptr;
                    }
                }
            }

            return vec;
        }
    }

    namespace Solution05{
        // 层序遍历感觉可以使用队列, 从队头取元素, 每取一次就将其左右节点放入其中
        std::vector<std::vector<int>> Solution::levelOrder(TreeNode* root)
        {
            std::queue<TreeNode *> que;
            std::vector<std::vector<int>> result;
            if(!root) return result;

            que.push(root);
            while (!que.empty())
            {
                int size = que.size();           // 这个用来区分每个层的大小, 保留了当前层的元素个数
                for(int i=0; i<size; ++i)
                {
                    if(!i) result.push_back(std::vector<int>{});
                    TreeNode *tmp = que.front();
                    result.back().push_back(tmp->val);
                    que.pop();
                    if(tmp->left) que.push(tmp->left);
                    if(tmp->right) que.push(tmp->right);
                }
            }

            return result;
        }
    }

    namespace Solution06{
        // 打个标记隔绝开来, 其实反转下数组就对了, 数组的反转只会管其元素顺序的反转, 不会再管其元素元素顺序的反转了
        std::vector<std::vector<int>> Solution::levelOrderBottom(TreeNode* root)
        {
            std::queue<TreeNode*> que;
            std::stack<TreeNode*> assit_st;
            std::vector<std::vector<int>> result;
            if(!root) return result;
            
            que.push(root);
            while (!que.empty())
            {
                int size = que.size();
                for(int i=0; i<size; ++i)
                {
                    TreeNode *tmp = que.front();
                    assit_st.push(tmp);
                    que.pop();
                    if(tmp->right) que.push(tmp->right);
                    if(tmp->left) que.push(tmp->left);
                    if(i==size-1) assit_st.push(nullptr);
                }
            }
            
            while (!assit_st.empty())
            {
                TreeNode * tmp = assit_st.top();
                assit_st.pop();
                if(tmp)
                {
                    result.back().push_back(tmp->val);
                }
                else{
                    result.push_back(std::vector<int>{});
                }
            }

            return result;
        }
    }

    namespace Solution07{
        std::vector<int> Solution::rightSideView(TreeNode* root)
        {
            std::vector<int> result;
            if(!root) return result;

            std::queue<TreeNode*> que;
            que.push(root);
            while (!que.empty())
            {
                int size = que.size();
                for(int i=0; i<size; ++i)
                {
                    TreeNode *tmp = que.front();
                    que.pop();
                    if(i==size-1) result.push_back(tmp->val);
                    if(tmp->left) que.push(tmp->left);
                    if(tmp->right) que.push(tmp->right);
                }
            }

            return result;
        }
    }

    namespace Solution08{
        std::vector<double> Solution::averageOfLevels(TreeNode *root)
        {
            std::queue<TreeNode *> que;
            std::vector<double> result;
            if(!root) return result;

            que.push(root);
            while (!que.empty())
            {
                int size = que.size();           // 这个用来区分每个层的大小, 保留了当前层的元素个数
                double layerSum = 0.;
                for(int i=0; i<size; ++i)
                {
                    TreeNode *tmp = que.front();
                    que.pop();
                    layerSum += tmp->val;
                    if(tmp->left) que.push(tmp->left);
                    if(tmp->right) que.push(tmp->right);
                    if(i==size-1) result.push_back(layerSum/size);
                }
            }

            return result;
        }
    }

    namespace Solution09{
        std::vector<std::vector<int>> Solution::levelOrderNTree(Node* root)
        {
            std::queue<Node*> que;
            std::vector<std::vector<int>> result;
            if(!root) return result;

            que.push(root);
            while (!que.empty())
            {
                int size = que.size();
                std::vector<int> vec;
                for(int i=0; i<size; ++i)
                {
                    Node * tmp = que.front();
                    vec.push_back(tmp->val);
                    que.pop();
                    for(int j=0; j<tmp->children.size(); ++j) 
                    {
                        if(tmp->children[j]) que.push(tmp->children[j]);
                    }
                }
                result.push_back(vec);
            }
            
            return result;
        }
    }

    namespace Solution10
    {
        std::vector<int> Solution::largestValues(TreeNode* root)
        {
            std::queue<TreeNode*> que;
            std::vector<int> result;
            if(!root) return result;
           
            que.push(root);
            while (!que.empty())
            {
                int layerSize = que.size();  // 每一层个数
                int layerMax = que.front()->val;
                for(int i=0; i<layerSize; ++i)
                {
                    TreeNode *tmp = que.front();
                    que.pop();
                    if(tmp->val>layerMax) layerMax=tmp->val;
                    if(tmp->left) que.push(tmp->left);
                    if(tmp->right) que.push(tmp->right);
                }
                result.push_back(layerMax);
            }

            return result;
        }
    }
    
    namespace Solution11{
        int Solution::maxDepth(TreeNode* root)
        {
            std::queue<TreeNode*> que;
            if(!root) return 0;

            int height {0};
            que.push(root);
            while (!que.empty())
            {
                ++height;
                int layerSize = que.size();
                for(int i=0; i<layerSize; ++i)
                {
                    TreeNode *tmp = que.front();
                    que.pop();
                    if(tmp->left) que.push(tmp->left);
                    if(tmp->right) que.push(tmp->right);
                }
            }

            return height;
        }
    }

    namespace Solution12{
        int Solution::minDepth(TreeNode* root)
        {
            std::queue<TreeNode*> que;
            if(!root) return 0;

            int height {0};
            bool isFind {false};
            que.push(root);
            while (!que.empty())
            {
                ++height;
                int layerSize = que.size();
                for(int i=0; i<layerSize; ++i)
                {
                    TreeNode *tmp = que.front();
                    que.pop();
                    if(tmp->left) que.push(tmp->left);
                    if(tmp->right) que.push(tmp->right);
                    if(!tmp->left && !tmp->right) 
                    {
                        isFind = true;
                        break;
                    }
                }

                if(isFind) break;
            }

            return height;
        }
    }

    namespace Solution13{
        TreeNode* Solution::invertTree(TreeNode* root)
        {
            if(!root) return root;
            
            std::swap(root->right, root->left);
            invertTree(root->right);
            invertTree(root->left);

            return root;
        }
    }

    namespace Solution14{
        bool Solution::isSymmetric(TreeNode *root)
        {
            if(!root) return true;
            std::queue<TreeNode *> que;
            que.push(root->left);
            que.push(root->right);

            while (!que.empty())
            {
                TreeNode *leftnode = que.front(); que.pop();
                TreeNode *rightnode = que.front(); que.pop();
                if(!leftnode && !rightnode) continue;  // 左右均为空

                if(leftnode==nullptr || rightnode==nullptr || (rightnode->val != leftnode->val)) return false;

                que.push(leftnode->left);
                que.push(rightnode->right);
                que.push(leftnode->right);
                que.push(rightnode->left);
            }

            return true;
        }
    }

    namespace Solution15{
        int Solution::countNodes(TreeNode* root)
        {
            if(!root) return 0;
            std::queue<TreeNode*> que;
            int nodeNum {0};

            que.push(root);
            while (!que.empty())
            {
                int layerSize = que.size();
                nodeNum += layerSize;
                for(int i=0; i<layerSize; ++i)
                {
                    TreeNode *tmp = que.front();
                    que.pop();
                    if(tmp->left) que.push(tmp->left);
                    if(tmp->right) que.push(tmp->right);
                }
            }

            return nodeNum;
        }
    }
}