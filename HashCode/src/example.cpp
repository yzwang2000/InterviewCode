#include <HashCode/example.hpp>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>

namespace HashCode
{
    namespace Solution01
    {
        // 初始化一个数组存放 26 个小写的英文字母
        // 这里注意一个问题, 'A' 比 'a' 的ASCII码更小, 而且 大写字母小写字母不是连续的 
        bool Solution::isAnagram(std::string s, std::string t)
        {
            if (s.size() != t.size())
                return false;
            if (!s.size())
                return true;

            int hashTable[26] {0}; // 存放每个字符的次数
            auto hashFunc = [](char tmp) -> int
            {
                return tmp - 'a';
            };

            for (int i = 0; i < s.size(); ++i)
            {
                ++hashTable[hashFunc(s[i])];
            }

            for (int i = 0; i < t.size(); ++i)
            {
                int hashIdx = hashFunc(t[i]);
                if (hashTable[hashFunc(t[i])])
                {
                    --hashTable[hashFunc(t[i])];
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    }

    namespace Solution02
    {
        // 注意不要忽略了使用内置的数据结构
        std::vector<int> Solution::intersection(std::vector<int> &nums1, std::vector<int> &nums2)
        {
            if(!nums1.size() || !nums2.size())
                return std::vector<int>{};

            // 去重的作用
            std::unordered_set<int> nums1_set {nums1.begin(), nums1.end()};
            std::unordered_set<int> result;
            for(int tmp: nums2){
                if(nums1_set.find(tmp) != nums1_set.end()){
                    result.insert(tmp);
                }
            }
            return {result.begin(), result.end()};
        }
    }

    namespace Solution03{
        // 题解说是无限循环, 就应该假设是求和的结果会重复出现(这点很重要, 注意无限循环和无限不循环)
        // 还有就是取各个单位上的数字的方法
        // bool Solution::isHappy(int n){
        //     static int count = 0;
        
        //     if(count > 20)
        //         return false;

        //     ++count;
        //     std::stringstream ss;
        //     ss << std::to_string(n);
        //     int result = 0;
        //     bool happy = true;
        //     char tmp;
        //     while (ss.get(tmp))
        //     {
        //         if(tmp-'0' != 0 && tmp-'0' != 1){
        //             happy = false;
        //         }
        //         result += (tmp-'0')*(tmp-'0');
        //     }
        //     if(happy){
        //         return true;
        //     }else{
        //         return isHappy(result);
        //     }
        // }

        // 这个是对一个整数, 求取各个位的数字的方式
        int getSum(int n){
            int tmp = n, sum {0};
            while (tmp)
            {
                sum += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
            return sum;
        }

        bool Solution::isHappy(int n){
            std::unordered_set<int> sumSet;
            int sum {0};
            while (1)
            {
                sum = getSum(n);
                if(sum==1){
                    return true;
                }else{
                    if(sumSet.find(sum) != sumSet.end()){
                        return false;
                    }else{
                        sumSet.insert(sum);
                    }
                }
                n = sum;
            }
        }
    }

    namespace Solution04{
        // 这里还能改进一下, 就是只用一个 for 循环就解决, 就是在生成 map 的过程中看
        // map 中是否有元素能与当前的结果对应, 有的话就返回对应的 vector
        // std::vector<int> Solution::twoSum(std::vector<int>& nums, int target){
        //     std::unordered_multimap<int, int> numMap;  // 先是 数组元素, 然后是 数组下标
        //     std::vector<int> result;
        //     for(int i=0; i<nums.size(); ++i){
        //         numMap.insert(std::pair<int, int> {nums[i], i});
        //     }
        //     for(auto tmp = numMap.begin(); tmp != numMap.end(); ++tmp){
        //         // 余下的值
        //         int resValue = target - tmp->first;
        //         if(numMap.find(resValue) != numMap.end()){
        //             if(resValue != target-resValue){
        //                 result.push_back(tmp->second);
        //                 result.push_back(numMap.find(resValue)->second);
        //                 return result;
        //             }else{
        //                 if(numMap.count(resValue)==2)
        //                 {
        //                     result.push_back(tmp->second);
        //                     numMap.erase(tmp);
        //                     result.push_back(numMap.find(resValue)->second);
        //                     return result;
        //                 }
        //             }
        //         }
        //     }
        //     return result;
        // }

        std::vector<int> Solution::twoSum(std::vector<int>& nums, int target){
            std::unordered_multimap<int, int> numMap;  // 先是 数组元素, 然后是 数组下标
            std::vector<int> result;
            for(int i=0; i<nums.size(); ++i){
                int resValue = target - nums[i];
                if(numMap.find(resValue) != numMap.end()){
                    result.insert(result.end(), {i, numMap.find(resValue)->second});
                }else{
                    numMap.insert(std::pair<int, int> {nums[i], i});
                }
            }
            return result;
        }
    }

    namespace Solution05{
        // 这道题给的启发是, 一个字典能够统计两个数组相加相减一共有多少种结果, 每种结果出现多少次
        int Solution::fourSumCout(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4){
            // 这题的思路是, 用一个 map 统计 nums1 和 nums2 相加的和, key 存储和, value 存储这个和出现的次数 
            std::unordered_map<int, int> sumAB;
            for(int i=0; i<nums1.size(); ++i){
                for(int j=0; j<nums2.size(); ++j){
                    sumAB[nums1[i]+nums2[j]]++; // 这里进行统计
                }
            } 
            int count = 0;
            for(int i=0; i<nums3.size(); ++i){
                for(int j=0; j<nums4.size(); ++j){
                    if(sumAB.count(0-(nums3[i]+nums4[j]))!=0){
                        count += sumAB[0-(nums3[i]+nums4[j])];
                    } 
                }
            }
            return count;
        } 
    }

    namespace Solution06{
        bool Solution::canConstruct(std::string ransomNote, std::string magazine){
            // 这里的第一种方法思路是对的, 但是有个问题, 就是可以不使用 map, 直接用数组就可以, 因为维护 map 和哈希函数的成本也是比较高的
            // if(ransomNote.size() > magazine.size() || !magazine.size()){
            //     return false;
            // }

            // std::unordered_map<char, int> magSet; // key magazine 中的字符, value 是字符在 magazine 中出现的次数
            // for(int i=0; i<magazine.size(); ++i){
            //     magSet[magazine[i]]++;
            // }

            // for(int i=0; i<ransomNote.size(); ++i){
            //     if(magSet.count(ransomNote[i])==0) // 缺少这个字符, 肯定不能构成
            //         return false;
            //     if(magSet[ransomNote[i]] <= 0){  // 这个字符不够用, 也不能构成
            //         return false;
            //     }else{
            //         --magSet[ransomNote[i]];
            //     }
            // }
            // return true;
            
            // 这里得第二种方法就是直接构造一个数组
            if(ransomNote.size() > magazine.size() || !magazine.size()){
                return false;
            }

            int magVec[26] {0};
            for(int i=0; i<magazine.size(); ++i){
                magVec[magazine[i]-'a'] ++;
            } 
            
            for(int j=0; j<ransomNote.size(); ++j){
                if(magVec[ransomNote[j]-'a']<=0)
                    return false;
                else{
                    --magVec[ransomNote[j]-'a'];
                }
            }
            
            return true;
        }
    }

    namespace Solution07{
        // 首先是它只关心三元组的搭配, 而不关心下标, 所以我们可以进行排序简化运算
        // 我们可以使用三指针的方法, 第一个指针进行遍历操作, 2 和 3 指针取得其余位置, 获得结果
        // 期间也需要去重操作, 去重主要在 第一个指针的重复 和 2 和 3指针变化过程中相邻位置的重复 
        // 这样的三指针方法, 其实是相当于每次都是把第一个指针所值位置的值的所有情况都遍历完全, 相当于每次都规定了一个最小的值的所有情况
        std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums){
            std::vector<std::vector<int>> result; // 存放结果
            std::sort(nums.begin(), nums.end());

            for(int i=0; i<nums.size()-2; ++i)
            {
                if(i>0 && nums[i]==nums[i-1]) // 最小值不能重复
                    continue;
                
                int left = i+1, right = nums.size() -1; // 初始化, 保证 i 代表的是最小值 
                while (left < right)
                {
                    if(nums[i]+nums[left]+nums[right]<0)
                    {
                        left++;
                    }
                    else if(nums[i]+nums[left]+nums[right]>0)
                    {
                        right--;
                    }
                    else{
                        result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                        while(left < right && nums[left]==nums[left+1])
                        {
                            left++;
                        }
                        while (left < right && nums[right]==nums[right-1])
                        {
                            right--;
                        }
                        
                        left++;
                        right--;
                    }
                }
            }

            return result;
        }
    }

    namespace Solution08{
        // 这道题目与3数之和的思想是一样的, 先确定两个最小的数, 然后其余两个指针开始遍历
        // 这里要注意一个问题, 就是指溢出的问题, 解决的办法是使用 long
        std::vector<std::vector<int>> Solution::fourSum(std::vector<int>& nums, int target){
            std::vector<std::vector<int>> result;  // 存放所有可能的结果
            std::sort(nums.begin(), nums.end());

            if(nums.size() < 4)
                return result;

            for(int i=0; i<nums.size()-3; ++i)
            {
                if(i > 0 && nums[i]==nums[i-1])
                    continue;
                for(int j=i+1; j<nums.size()-2; ++j)
                {
                    if(j > i+1 && nums[j]==nums[j-1])
                        continue;
                     
                    int left = j+1, right = nums.size() -1; // 初始化, 保证 i 代表的是最小值 
                    while (left < right)
                    {
                        // 这里变为 long 来解决溢出的问题
                        if((long)nums[i]+nums[j]+nums[left]+nums[right]<target)
                        {
                            left++;
                        }
                        else if((long)nums[i]+nums[j]+nums[left]+nums[right]>target)
                        {
                            right--;
                        }
                        else{
                            result.push_back(std::vector<int>{nums[i], nums[j], nums[left], nums[right]});
                            while(left < right && nums[left]==nums[left+1])
                            {
                                left++;
                            }
                            while (left < right && nums[right]==nums[right-1])
                            {
                                right--;
                            }
                            
                            left++;
                            right--;
                        }
                        
                    }
                }
            }

            return result;
        }
    }
}