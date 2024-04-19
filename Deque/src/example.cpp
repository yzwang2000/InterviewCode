#include <Deque/example.hpp>
#include <stack>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

namespace Deque{
    // 整体思路是对的, 但是还能够改进一下；
    // push 的时候直接放入输入栈就可以啦, pop 的时候先判断是否还有元素, 没有的话就将 push 全都拿过来
    // 我原来的思路是每次 push 和每次 pop 都进行转移一次
    namespace Solution01{
        // MyQueue::MyQueue(){           
        // }

        // void MyQueue::push(int x){
        //     if(_master_stack.size()==0 && _assist_stack.size()==0)
        //     {
        //         _master_stack.push(x);
        //     }
        //     else if(_master_stack.size())
        //     {
        //         _master_stack.push(x);
        //     }
        //     else{
        //         while (!_assist_stack.empty())
        //         {
        //             _master_stack.push(_assist_stack.top());
        //             _assist_stack.pop();
        //         }
        //         _master_stack.push(x);
        //     }
        // }

        // int MyQueue::pop(){
        //     int result;
        //     if(_master_stack.size()==0 && _assist_stack.size()==0)
        //     {
        //         std::cout << "元素为 0, 不能再返回元素" << std::endl;
        //     }
        //     else if(_master_stack.size()==0 && _assist_stack.size())
        //     {
        //         result = _assist_stack.top();  // 先返回栈顶元素
        //         _assist_stack.pop();  // 移除栈顶元素
        //     }else if(_master_stack.size() && _assist_stack.size()==0)
        //     {
        //         while (!_master_stack.empty())
        //         {
        //             _assist_stack.push(_master_stack.top());
        //             _master_stack.pop();
        //         }
                
        //         result = _assist_stack.top();  // 先返回栈顶元素
        //         _assist_stack.pop();  // 移除栈顶元素
        //     }else{
        //         std::cout << "检查语法错误" << std::endl;
        //     }
        //     return result;
        // }

        // int MyQueue::peek(){
        //     int result;
        //     if(_master_stack.size()==0 && _assist_stack.size()==0)
        //     {
        //         std::cout << "元素为 0, 不能再返回元素" << std::endl;
        //     }
        //     else if(_master_stack.size()==0 && _assist_stack.size())
        //     {
        //         result = _assist_stack.top();  // 先返回栈顶元素
        //     }else if(_master_stack.size() && _assist_stack.size()==0)
        //     {
        //         while (!_master_stack.empty())
        //         {
        //             _assist_stack.push(_master_stack.top());
        //             _master_stack.pop();
        //         }
                
        //         result = _assist_stack.top();  // 先返回栈顶元素
        //     }else{
        //         std::cout << "检查语法错误" << std::endl;
        //     }
        //     return result;      
        // }

        // bool MyQueue::empty(){
        //     if (_master_stack.size() || _assist_stack.size())
        //     {
        //         return false;
        //     }
        //     else{
        //         return true;
        //     }
        // }

        MyQueue::MyQueue(){           
        }

        void MyQueue::push(int x){
            _master_stack.push(x);
        }

        int MyQueue::pop(){
            int result;
            if(_master_stack.size()==0 && _assist_stack.size()==0)
            {
                std::cout << "元素为 0, 不能再返回元素" << std::endl;
            }
            else{
                result = peek();            
                _assist_stack.pop();
            }

            return result;
        }

        int MyQueue::peek(){
            int result;
            if(_master_stack.size()==0 && _assist_stack.size()==0)
            {
                std::cout << "元素为 0, 不能再返回元素" << std::endl;
            }
            else if(_assist_stack.size())
            {
                result = _assist_stack.top();  // 先返回栈顶元素
            }else if(_master_stack.size())
            {
                while (!_master_stack.empty())
                {
                    _assist_stack.push(_master_stack.top());
                    _master_stack.pop();
                }
                
                result = _assist_stack.top();  // 先返回栈顶元素
            }else{
                std::cout << "检查语法错误" << std::endl;
            }
            return result;      
        }

        bool MyQueue::empty(){
            if (_master_stack.size() || _assist_stack.size())
            {
                return false;
            }
            else{
                return true;
            }
        }
    }

    namespace Solution02{
        MyStack::MyStack(){
        }
        
        // 整体思路就是, 那个队列不空就往那个队列存放数据; 都空的话, 就往 que1 存放数据
        void MyStack::push(int x)
        {
            if(!que1.size() && !que2.size())    
            {
                que1.push(x);
            }else if(que1.size())
            {
                que1.push(x);
            }else{
                que2.push(x);
            }
        }

        // 将为非空的队列取出来, 放到空的队列中, 这样就能找到最后一个元素
        int MyStack::pop()
        {
            int result;
            if(!que1.size() && !que2.size())
            {
                std::cout << "元素为空, 不能pop" << std::endl;
            }else if(que1.size())
            {
                while (true)
                {
                   int tmp = que1.front();
                   que1.pop();
                   if(que1.empty()) 
                   {
                        result = tmp;
                        break;
                   }else{
                        que2.push(tmp);
                   }
                }
            }else{
                while (true)
                {
                   int tmp = que2.front();
                   que2.pop();
                   if(que2.empty()) 
                   {
                        result = tmp;
                        break;
                   }else{
                        que1.push(tmp);
                   }
                }
            }
            return result;
        }

        int MyStack::top(){
            int result;
            if(!que1.size() && !que2.size())
            {
                std::cout << "元素为空, 不能top" << std::endl;
            }else if(que1.size())
            {
                while (true)
                {
                   int tmp = que1.front();
                   que1.pop();
                   que2.push(tmp);
                   if(que1.empty()) 
                   {
                        result = tmp;
                        break;
                   }
                }
            }else{
                while (true)
                {
                   int tmp = que2.front();
                   que2.pop();
                   que1.push(tmp);
                   if(que2.empty()) 
                   {
                        result = tmp;
                        break;
                   }
                }
            }
            return result;
        }

        bool MyStack::empty(){
            if(que1.size() || que2.size())
            {
                return false;
            }
            else{
                return true;
            }
        }
    }

    namespace Solution03{
        // 遇到左括号就放到栈中, 遇到右括号, 就弹出栈顶的符号, 如果匹配, 则是对应的
        // std::vector<char> left_brackets {'(', '{', '['};  // 左括号用数组存放
        bool Solution::isVaid(std::string s)
        {
            std::unordered_map<char, char> brackets_match {{'(', ')'}, {'{', '}'}, {'[', ']'}};
            std::stack<char> bracket_stack;
            for(int i=0; i<s.size(); ++i) 
            {
                if(brackets_match.find(s.at(i)) != brackets_match.end())
                {
                   bracket_stack.push(s.at(i)); 
                }
                else{
                    if(bracket_stack.empty())
                        return false;
                    
                    if (s.at(i) == brackets_match[bracket_stack.top()])
                    {
                        bracket_stack.pop();  // 弹出栈顶的匹配
                    }
                    else{
                        return false;
                    } 
                }
            }
            return bracket_stack.empty() ? true : false;
        }
    }

    namespace Solution04{
        // 初始化一个 std::string 充当栈
        std::string Solution::removeDuplicates(std::string s){
            std::string result;  // 充当栈来使用
            for(int i=0; i<s.size(); ++i)
            {
                if(!result.size())
                {
                    result.push_back(s.at(i));
                }
                else{
                    if(result.back()==s.at(i))
                    {
                        // result.erase(result.size()-1);
                        result.pop_back();  // 移除最后一个元素, 这里有现成的方法
                    }
                    else{
                        result.push_back(s.at(i));
                    }
                }
            }
            return result;
        }
    }

    namespace Solution05{
        int Solution::evalRPN(std::vector<std::string>& tokens)
        {
            std::stack<std::string> tk_stack;
            std::unordered_set<std::string> op_set {"+", "-", "*", "/"};  // 存放运算符

            auto str2int = [](const std::string & ss)->int{
                int result = 0;
                for(int i=0; i<ss.size(); ++i)
                {
                    if(ss.at(i)=='-')
                        continue;
                    result += (ss.at(i) - '0') * std::pow(10, ss.size()-i-1);
                }
                return ss.at(0)=='-' ? static_cast<int>(-1*result):result;
            };

            auto calOp = [](const int a, const int b, const char op)->int
            {
                switch (op)
                {
                    case '+':
                        return a + b;
                        break;
                    case '-':
                        return a - b;
                        break;
                    case '*':
                        return a * b;
                        break;
                    case '/':
                        return a / b;
                        break;
                }
            };

            for(int i=0; i<tokens.size(); ++i) 
            {
                if(!tk_stack.size() || op_set.find(tokens.at(i))==op_set.end())                
                {
                    tk_stack.push(tokens.at(i));
                }
                else{
                    int tmp1 = str2int(tk_stack.top());
                    tk_stack.pop();
                    int tmp2 = str2int(tk_stack.top());
                    tk_stack.pop();
                    tk_stack.push(std::to_string(calOp(tmp2, tmp1, tokens.at(i)[0])));
                }
            }

            return str2int(tk_stack.top());
        }
    }
}