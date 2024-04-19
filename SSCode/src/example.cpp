#include <SSCode/example.hpp>

namespace SSCode{
    namespace Solution01{
        // 定义交换字符的函数
        void Solution::changeChar(char & c1, char & c2){
            char tmp = c1;
            c1 = c2;
            c2 = tmp;
        }

        // 使用双指针的方法, 分别指向两个首位, 然后每次进行移动, 交换两个指针所指向的字符值
        void Solution::reverseString(std::vector<char>& s){
            // if(s.size() <=1){
            //     return;
            // }
            // 接下来判断字符串的个数是奇数还是偶数
            // if(s.size() % 2)  // 这个是奇数
            // {
            //     int left = 0, right = s.size()-1;
            //     while (left!=right)
            //     {
            //         changeChar(s[left], s[right]);
            //         ++left;
            //         --right;
            //     }
            // }
            // else{  // 这个是偶数
            //     int left = 0, right = s.size()-1;
            //     while (left!=right+1)
            //     {
            //         changeChar(s[left], s[right]);
            //         ++left;
            //         --right;
            //     }
            // }
            // return;
            
            // 以上的代码的问题是分了元素个数是奇数还是偶数, 其实不需要分
            // 只需要管双指针中的一个指针是否超够了一半, 如果超过了就不再交换了
            if(s.size() <=1){
                return;
            }

            for(int i=0, j=s.size()-1; i<s.size() / 2; ++i, --j){
                changeChar(s[i], s[j]);
            }
        }
    }

    namespace Solution02{
        std::string Solution::reverseStr(std::string s, int k){
           int sLen = s.size();  // 字符串的长度 
           for(int i=0; (2*i+1)*k-1< sLen; ++i)
           {
                for(int j=(2*i)*k, z = (2*i+1)*k-1; j<2*i*k+k/2; ++j, --z)
                {
                    char tmp = s[j];
                    s[j] = s[z];
                    s[z] = tmp;
                }
           }

            int resLen = sLen % (2*k);  // 2k 为一组, 除去之外剩余的字符长度
            int numGroup = sLen / (2*k);
            int preLen = numGroup * 2 * k;
            if(resLen<k){
                for(int i=0, j=resLen-1; i<resLen/2; ++i, --j)
                {
                    char tmp = s[preLen + i];
                    s[preLen+i] = s[preLen+j];
                    s[preLen+j] = tmp;
                }
            }
            return s;
        }
    }

    namespace Solution03{
        // 这里可以用双指针的方法, 相比于自己写的方法, 可以充分的利用空间
        // 首先也是统计出扩容后数组的大小, 然后一个指针指向旧数组的结尾, 一个指向扩容后的数组的结尾
        // 每次向后移动元素, 其实就是调转了一个方向来做这个题目
        std::string Solution::replaceStr(std::string s){
            // std::string fillStr = "number";  // 填充的字符串
            // int numberCount = 0;
            // for(char c_: s)
            // {
            //     if(c_>'0' && c_<'9')
            //         ++numberCount;
            // }

            // std::string newStr;
            // newStr.reserve(s.size()+(fillStr.size()-1)*numberCount);  // 依据填充的字符首先分配字符串容量
            // for(char c_:s)
            // {
            //     if(c_>'0' && c_<'9')
            //     {
            //         newStr.append(fillStr);
            //     }else{
            //         newStr.push_back(c_);
            //     }
            // }
            // return newStr; 

            int numberCount = 0;
            for(char c_: s)
            {
                if(c_>='0' && c_<='9')
                    ++numberCount;
            }

            int left = s.size()-1;
            s.resize(s.size() + 5*numberCount);  // 首先将原始字符串进行扩容
            int right = s.size()-1;
            while (left>=0)
            {
                if(s[left] >= '0' && s[left] <= '9'){
                    s[right--] = 'r';
                    s[right--] = 'e';
                    s[right--] = 'b';
                    s[right--] = 'm';
                    s[right--] = 'u';
                    s[right--] = 'n';
                }else{
                    s[right--] = s[left];
                }
                --left;
            }
            return s;        
    }
    }

    namespace Solution04{
        // 这种方法是一个 o(n) 的时间复杂度, o(n) 的空间复杂度
        // 但是这种方法利用了辅助空间, 即重新定义了一个字符串
        // 也可以分成三部做, 把空间复杂度也降低到 o(1) 删除空格, 反转所有字符串, 反转单词字符串
        std::string Solution::reverseWords(std::string s){
            std::string newStr;
            newStr.reserve(s.size());    

            int right = s.size()-1;
            int left = 0;

            while (right>=0)
            {
                while (right>=0 && s.at(right)==' ')
                {
                    --right;
                }
                if(right<0)
                    break;
                
                int j = right;
                while (j>0 && !(s.at(j) != ' ' && s.at(j-1) == ' '))
                {
                    --j;
                }
                newStr.append(s.begin()+j, s.begin()+right+1);
                newStr.push_back(' ');
                right = j-1;
            }

            if(newStr.back()==' ')
                newStr.resize(newStr.size()-1);
            
            return newStr;
        }
    }
    
    namespace Solution05{
        // 这道题目我这样做, 时间复杂度是 o(n), 空间复杂度是 o(n)
        // 有一个新的方法是, 先将整体进行一个倒序, 然后再将两个局部分别进行倒序
        std::string Solution::rightShiftStr(std::string s, int n){
            // if(!s.size())
            // {
            //     return s;
            // }

            // int sLen = s.size();
            // int realShift = n % sLen;  // 相当于进行了取余的操作
            // std::string newStr;
            // newStr.resize(sLen);
            
            // for(int i=0; i<realShift; ++i)     // 先填充旋转过来的
            // {
            //     newStr.at(i) = s.at(sLen-realShift+i);   
            // }

            // for(int i=realShift; i<sLen; ++i)  // 再填充补充的
            // {
            //     newStr.at(i) = s.at(i-realShift);
            // }
            // return newStr;


            if(!s.size())
            {
                return s;
            }

            int sLen = s.size();
            int realShift = n % sLen;  // 相当于进行了取余的操作
            std::reverse(s.begin(), s.end());
            std::reverse(s.begin(), s.begin()+n);
            std::reverse(s.begin()+n, s.end());
            return s;
        }
    }

    namespace Solution06{
        int Solution::strStr(std::string haystack, std::string needle){
            if(!haystack.size() || needle.size() > haystack.size())
                return -1;

            int count;
            int i = 0;
            for(; i<=haystack.size()-needle.size(); ++i)
            {
                count = 0;
                for(int j=0; j<needle.size(); ++j)
                {
                    if(haystack[i+j]==needle[j]) 
                    {
                        ++count;
                    }
                }
                if (count==needle.size())
                    break;
            }
            if (count==needle.size())
            {
                return i;
            }else{
                return -1;
            } 
        }
    }

    namespace Solution07{
        bool Solution::repeatedSubstringPattern(std::string s){
            int sLen = s.size();

            bool isMatch = true; // 默认情况下是匹配的
            for(int numPattern=1; numPattern <= sLen/2; ++numPattern)  // 遍历匹配字符的长度
            {
                if(sLen % numPattern)
                    continue;
                
                bool isMatch = true;
                for(int j=0; j<sLen-numPattern; j+=numPattern)
                {
                    int k = 0;
                    while(k < numPattern && s[j+k]==s[j+numPattern+k])
                    {
                        ++k;
                    }
                    if(k<numPattern)
                    {
                        isMatch = false;
                        break;
                    }
                }
                if(isMatch)
                {
                    return true;
                }
            }
            return false;
        }
    }
}

 