#pragma once
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <vector>

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

    namespace Solution06{
        class Solution{
        // 这里维护一个单调队列
        private:
            class MyDeque
            {
            public:
                std::deque<int> deq;  // 使用双向队列的原因是两边都要拉元素出去
                // 加入滑动窗口中的元素也加入这个单调队列中, 从入口处开始, 小于加入的值都弹出
                // 这个相当于保存了滑动窗口中的最大值, 弹出最大值之后的最大值, ...
                void push(int value)
                {
                    while(!deq.empty() && deq.back() < value)
                    {
                        deq.pop_back();
                    }
                    deq.push_back(value);
                }

                // 删除滑动窗口中的元素, 如果删除的值等于 front 的值, 那么就将其删除, 否则就不删除
                void pop(int value)
                {
                    if(!deq.empty() && value==deq.front())  // 注意这里使用 if, 上面使用 while
                    {
                        deq.pop_front();
                    }
                }

                // 经过这样一维, 其实 front 就是当前框中的最大值
                int get_max_value()
                {
                    return deq.empty() ? 0 : deq.front();
                }
            };

        public:
            static std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
        };
    }

    namespace Solution07{
        class Solution{
        public:
            class Func{
            public:
                bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b)
                {
                    return a.second > b.second;
                }
            };
        
        public:
            static std::vector<int> topKFrequent(std::vector<int>& nums, int k);
        };
    }
}