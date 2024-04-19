#pragma once
#include <deque>
#include <stack>
#include <queue>
#include <string>

namespace Deque{
    namespace Solution01{
        class MyQueue{
        private:
            std::stack<int> _master_stack;  // 正常的栈, 存放的元素先入先出
            std::stack<int> _assist_stack;  // 将 _master_stack 中的栈反向存储, 给人一种先入后出的感觉
        public:
            MyQueue();
            void push(int x); 
            int pop();
            int peek();
            bool empty();
        };
    }

    namespace Solution02{
        class MyStack{
        private:
            std::queue<int> que1;
            std::queue<int> que2;
        public:
            MyStack();
            void push(int x); 
            int pop();
            int top();
            bool empty();
        };
    }
    
    namespace Solution03{
        class Solution{
        public:
           static bool isVaid(std::string s);
        };
    }

    namespace Solution04{
        class Solution{
        public:
            static std::string removeDuplicates(std::string s);
        };
    }
    
    namespace Solution05{
        class Solution{
        public:
            static int evalRPN(std::vector<std::string>& tokens);
        };
    }
}