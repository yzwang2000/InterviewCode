#include <ArrayCode/example.hpp>
#include <stack>
#include <cmath>
#include <numeric>
#include <iostream>

namespace ArrayCode
{

    namespace Solution01
    {
        // 时间复杂度 O(log n) 空间复杂度 O(1)
        int Solution::search(std::vector<int> &nums, int target)
        {
            int low = 0, high = nums.size() - 1;
            while (low <= high)
            {
                int middle = (low + high) / 2;
                // note1: 这里能做些修改, 防止溢出
                // int middle = low + (low - high) /2;
                if (target == nums[middle])
                {
                    return middle;
                }
                else if (target < nums[middle])
                {
                    high = middle - 1;
                }
                else
                {
                    low = middle + 1;
                }
            }
            return -1;
        }
    };

    namespace Solution02{
        // int Solution::removeElement(std::vector<int>& nums, int val){
        //     int num_ele = nums.size(); // 数组最原始的长度
        //     for(int i=0; i<num_ele; ++i){
        //         if(nums[i]==val){
        //             for(int j=0; j<num_ele-i-1; ++j){
        //                 nums[i+j] = nums[i+j+1];
        //             }
        //             num_ele --;
        //             i--;
        //         }
        //     }
        //     return num_ele;
        // }

        // 双指针法能够更加快速
        int Solution::removeElement(std::vector<int>& nums, int val){
            int slowIndex = 0;
            for(int fastIndex=0; fastIndex < nums.size(); ++fastIndex){
                if(nums[fastIndex] != val){
                    nums[slowIndex++] = nums[fastIndex];
                }
            }
            return slowIndex;
        }
    }

    namespace Solution03{
        // 这个是使用栈做了一个辅助
        // std::vector<int> Solution::sortedSquares(std::vector<int>& nums){
        //     std::stack<int> stack_nega;
        //     int slowIndex = 0;
        //     for(int fastIndex=0; fastIndex< nums.size(); ++fastIndex){
        //         if(nums[fastIndex] < 0){
        //             stack_nega.push(nums[fastIndex]);
        //         }else{
        //             if(stack_nega.empty()){
        //                 nums[slowIndex++] = nums[fastIndex] * nums[fastIndex];
        //             }else{
        //                 while(-stack_nega.top() < nums[fastIndex]){
        //                     nums[slowIndex++] = stack_nega.top() * stack_nega.top();
        //                     stack_nega.pop();
        //                     if (stack_nega.empty()) break;
        //                 }
        //                 nums[slowIndex++] = nums[fastIndex] * nums[fastIndex];
        //             }
        //         }
        //     }
        //     while (!stack_nega.empty())
        //     {
        //         nums[slowIndex++] = stack_nega.top() * stack_nega.top();
        //         stack_nega.pop();
        //     }
        // return nums;
        // }

        // 双指针的写法
        std::vector<int> Solution::sortedSquares(std::vector<int>& nums){
            std::vector<int> result; result.resize(nums.size());
            int low = 0, high = nums.size()-1;
            for(int cur = nums.size()-1; cur >=0; --cur){
                if(nums[low] * nums[low] > nums[high] * nums[high]){
                    result[cur] = nums[low] * nums[low];
                    ++low;
                }else{
                    result[cur] = nums[high] * nums[high];
                    --high;
                }
            }
            return result;
        }
    }
    
    namespace Solution04{
        // 这种是暴力求解法, 时间复杂度为 O(n^2)
        // int Solution::minSubArrayLen(int target, std::vector<int>& nums){
        //     for(int i=1; i<=nums.size(); ++i){  // 数组中连续数字的个数
        //         for(int j=0; j<= nums.size()-i; ++j){
        //             int temp = std::accumulate(nums.begin()+j, nums.begin()+i+j, 0);
        //             if (temp >= target){
        //                 std::cout << i << " " << j << std::endl;
        //                 return i;
        //             }
        //         }
        //     }
        //     return 0;
        // }

        // 滑动窗口法(双指针法的一种)
        int Solution::minSubArrayLen(int target, std::vector<int>& nums){
            int minSub = nums.size();  // 记录最小的数组长度
            int numSub = 0;
            int sum = 0;  // 记录当前的和
            for(int j=0; j<nums.size(); ++j){
                ++numSub;
                sum += nums[j];
                while(sum >= target){
                    sum -= nums[j-(numSub-1)];
                    minSub = std::min(numSub, minSub);
                    --numSub;
                }
            }
            return numSub==nums.size() && sum < target ? 0 : minSub;
        }
    }

    namespace Solution05{
        std::vector<std::vector<int>> Solution::generateMatrix(int n){
            std::vector<std::vector<int>> res (n, std::vector<int>(n, 0));
            // 每一圈的起点
            int startx = 0;
            int starty = 0;

            // 每一圈的偏移量
            int offset = 0;

            // 多少圈
            int loop = n / 2;
            int count = 1;  // 开始计数

            while (loop--)
            {
                int i=startx;  // 控制着行
                int j=starty;  // 控制着列

                // 从左到右
                for(int k=starty; k<n-offset; ++k){
                    res[startx][k] = count++;
                }

                // 从上到下
                for(int k=startx+1; k<n-offset; ++k){
                    res[k][n-1-offset] = count++;
                }

                // 从右到左
                for(int k=n-1-offset-1; k>=starty; --k){
                    res[n-1-offset][k] = count++;
                }

                // 从下到上
                for(int k=n-1-offset-1; k>startx; --k){
                    res[k][starty] = count++;
                }

                ++offset;
                ++startx;
                ++starty;
            }

            if(n%2==1){
                res[n/2][n/2] = count;
            }

            return res;
        }
    }
    
}
