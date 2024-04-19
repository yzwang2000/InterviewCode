#pragma once

#include <string>
#include <vector>

namespace HashCode
{
    namespace Solution01
    {
        class Solution
        {
        public:
            static bool isAnagram(std::string s, std::string t);
        };

    }

    namespace Solution02
    {
        class Solution {
        public:
            static std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);
        };
    }

    namespace Solution03
    {
        class Solution {
        public:
            static bool isHappy(int n);
        };
    }

    namespace Solution04
    {
        class Solution {
        public:
            static std::vector<int> twoSum(std::vector<int>& nums, int target);
        };
    }


    namespace Solution05
    {
        class Solution {
        public:
            static int fourSumCout(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4); 
        };
    }

    namespace Solution06
    {
        class Solution {
        public:
            static bool canConstruct(std::string ransomNote, std::string magazine);
        };
    }


    namespace Solution07
    {
        class Solution {
        public:
            static std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
        };
    }


    namespace Solution08
    {
        class Solution {
        public:
            static std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);
        };
    }
}