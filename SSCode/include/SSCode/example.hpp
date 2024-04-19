#pragma once
#include <vector>
#include <string>

namespace SSCode{
    namespace Solution01{
        class Solution{
        public:
            static void reverseString(std::vector<char>& s);
            static void changeChar(char & c1, char & c2);
        };
    }

    namespace Solution02{
        class Solution{
        public:
          static std::string reverseStr(std::string s, int k);
        };
    }

    namespace Solution03{
        class Solution{
        public:
            static std::string replaceStr(std::string s);
        };
    }

    namespace Solution04{
        class Solution{
        public:
            static std::string reverseWords(std::string s);
        };
    }

    namespace Solution05{
        class Solution{
        public:
            static std::string rightShiftStr(std::string s, int n);
        };
    }


    namespace Solution06{
        class Solution{
        public:
            static int strStr(std::string haystack, std::string needle);
        };
    }
    
    namespace Solution07{
        class Solution{
        public:
            static bool repeatedSubstringPattern(std::string s);
        };
    }
}