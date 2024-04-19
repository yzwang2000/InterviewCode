#pragma once
#include <vector>

namespace ArrayCode
{

    namespace Solution01
    {
        class Solution
        {
        public:
            static int search(std::vector<int> &nums, int target);
        };
    }

    namespace Solution02{
        class Solution{
        public:
            static int removeElement(std::vector<int>& nums, int val);
        };
    }

    namespace Solution03{
        class Solution{
        public:
            static std::vector<int> sortedSquares(std::vector<int>& nums);
        };
    }
    
    namespace Solution04{
        class Solution{
        public:
            static int minSubArrayLen(int target, std::vector<int>& nums);
        };
    }

    namespace Solution05{
        class Solution{
        public:
            static std::vector<std::vector<int>> generateMatrix(int n);
        };
    }

}