#pragma once
#include <vector>


namespace BinaryTree {
    // 依据 vector 来产生二叉树 (vector)
    struct TreeNode 
    {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(): val(0), left(nullptr), right(nullptr){}
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
        TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
    };

    // 递归的方法进行遍历
    namespace Solution01{
        class Solution{
        public:
            static void preTraversal(TreeNode *root, std::vector<int> vec);
            static std::vector<int> preorderTraversal(TreeNode* root);
        };
    }

    // 迭代的方法进行遍历
    namespace Solution02{
        class Solution{
        public:
            static std::vector<int> preorderTraversal(TreeNode* root);
        };
    }

    namespace Solution03{
        class Solution{
        public:
            static std::vector<int> inorderTraversal(TreeNode* root);
        };
    }

    namespace Solution04{
        class Solution{
        public:
            static std::vector<int> postorderTraversal(TreeNode* root);
        };
    }

    namespace Solution05{
        class Solution{
        public:
            static std::vector<std::vector<int>> levelOrder(TreeNode* root);
        };
    }

    namespace Solution06{
        class Solution{
        public:
            static std::vector<std::vector<int>> levelOrderBottom(TreeNode* root);
        };
    }

    namespace Solution07{
        class Solution{
        public:
            static std::vector<int> rightSideView(TreeNode* root);
        };
    }

    namespace Solution08{
        class Solution{
        public:
            static std::vector<double> averageOfLevels(TreeNode* root);
        };
    }

    namespace Solution09{
        class Solution{
        public:
            class Node
            {
            public:
                int val;
                std::vector<Node *> children;

                Node() {}

                Node(int _val)
                {
                    val = _val;
                }

                Node(int _val, std::vector<Node *> _children)
                {
                    val = _val;
                    children = _children;
                }
            };
            static std::vector<std::vector<int>> levelOrderNTree(Node* root);
        };
    }

    namespace Solution10{
        class Solution{
        public:
            static std::vector<int> largestValues(TreeNode* root);
        };
    }

    namespace Solution11{
        class Solution{
            static int maxDepth(TreeNode* root);
        };
    }

    namespace Solution12{
        class Solution{
            static int minDepth(TreeNode* root);
        };
    }

    namespace Solution13{
        class Solution{
            static TreeNode* invertTree(TreeNode* root);
        };
    }

    namespace Solution14{
        class Solution{
            static bool isSymmetric(TreeNode* root);
        };
    }

    namespace Solution15{
        class Solution{
            static int countNodes(TreeNode* root);
        };
    }

    namespace Solution16{
        class Solution{
            static int findBottomLeftValue(TreeNode* root);
        };
    }

    namespace Solution17{
        class Solution{
            static std::vector<int> PathSum(TreeNode* root);
            static bool hasPathSum(TreeNode* root, int targetSum);
        };
    }
}