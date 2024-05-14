#include <omp.h>
#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <ArrayCode/example.hpp>
#include <ListCode/example.hpp>
#include <HashCode/example.hpp>
#include <SSCode/example.hpp>
#include <Deque/example.hpp>
#include <BinaryTree/example.hpp>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

namespace std
{
    template <typename _T>
    std::ostream& operator<<(std::ostream& os, const std::vector<_T> &container)
    {
        for (const auto& ele : container)
        {
            os << ele << ", ";
        }
        os << std::endl;
        return os;
    }
}

int main(int argc, char ** argv){

    std::vector<int> okk {1, 2, 3, 4};
    auto max_iter = std::max_element(okk.begin(), okk.end());
    std::vector<int> {okk.begin(), max_iter};
    std::unordered_set<int> ook;
    
    return 0;
}


















// 对于可变形模板的展开, 通常有三种方式
// 1) 递归调用, 通常通过递归函数, 逐步分解形参包
// 2) 通过逗号表达式展开形参包, 这个比较蠢, 需要定义数组
// 3) 折叠表达式 一元左折叠 一元右折叠 
// 二元折叠存在的意义其实就在一元的基础上提供了初始值(同时也解决了一元折叠表达式不能接受空参数包的问题)
// 只有 op 是 && || , 的一元表达式是能够接受空参数包

// 这要注意表达式的返回值还能否传入下个表达式 E 中包含了形参包
// 一元右折叠 (E op ...)         E1 op (... (En-2 op (En-1 op En)))
// 一元左折叠 (... op E)         (((E1 op E2) op E3) ... ) op En
// 二元右折叠 (E op ... op I)    E1 op (... (En-1 op (En op I)))
// 二元左折叠 (I op ... op E)    ((I op E1) op E2) ...) En

// 待决名是指在模板中的名称, 其解析取决于模板参数的具体实例化, 即依赖于模板参数的类型。
// 非待决名是指在模板中的名称, 其解析不依赖于模板参数的具体实例化, 在模板定义的时候就能确定其含义。
// 在模板中, 依赖于某个模板类型的非当前实例化成员的名字都不会被认为是类型。用 typename 消除
// 在模板中, 依赖于某个模板类型的非当前实例化成员的名字都不会被认为是模板类型。用 template 消除
// 绑定规则 对于待决名, 是从实例化后开始查找。对于非待决名, 是从模板定义时开始查找。
// 对于有继承, 父类依赖于模板参数的时候。对于待决名, 从实例化后开始查找, 也就是能查找到父类。
// 对于非待决名, 定义时查找, 不能在父类中查找。

// 类成员指针 类成员指针就是指向类的非静态成员变量和非静态成员函数的指针
// 因为静态成员函数和静态成员变量用普通的指针就可以指向
// 指向非静态成员变量的指针, 只是记录了成员相对于类对象的偏移量, 不指向具体的地址           *p 这是非法   // 必须要类对象调用
// 指向非静态成员函数的指针, 确实是指向了成员函数的地址, 但是成员函数也必须要类对象进行调用   p() 非法    // 必须类对象进行调用



// template <typename T1, typename T2>
// std::common_type_t<T1, T2> sum_two(T1 a, T2 b)
// {
//     return a + b;
// }

// template<>
// int sum_two<int, int>(int, int){
//     std::cout << "。。。。。" << std::endl;
// }

// template<typename T>
// class is_void{
//     public:
//         inline static bool value = false;
// };

// template<>
// class is_void<void>{
//     public:
//         inline static bool value = true;
// };

// template<>
// class is_void<char>{
// };

// template<typename T>
// const bool is_void_v = is_void<T>::value;

// template<typename T>
// constexpr T PI = static_cast<T>(3.1415926);

// template<>
// double PI<int> = 2;

// // 对于不完整类型, 只能用到其指针和引用
// void printArraySize(int arr[]){
//     // std::cout << sizeof(arr) << std::endl;
//     std::cout << "......" << std::endl;
// }

// // void printArraySize(int arr[2]){
// //     std::cout << sizeof(arr) << std::endl;
// // }


// int main(int argc, char ** argv)
// {
//     // std::cout << is_void<void>::value << std::endl;
//     // std::cout << is_void_v<void> << std::endl;
//     // std::cout << PI<double> << std::endl;
//     // std::cout << PI<int> << std::endl;

//     int a[] {1, 2, 3, 4};  // 这里只是语法糖, 其实是 int a[4] = {1, 2, 3, 4}; 因为不允许不完整类型定义对象的
//     std::cout << std::is_same_v<int[2], int[4]> <<std::endl;
//     printArraySize(a);

//     return 0;
// }


// // template<typename T>
// // void ffff(T && t){
// //     std::cout << "调用" << std::endl;
// // }

// // decltype 的推到规则
// // decltype(exp) 如果 exp 是一个普通变量或者类的成员变量, 那就是直接把其类型拿回来
// // 如果 exp 是一个函数的调用形式, 注意这里是调用的形式, 就直接把返回类型拿回来
// // 如果 exp 是一个表达式, 如果是左值, 那就是左值的引用, 如果是右值, 就不是引用类型, 是正常的类型
// // exp 被表达式括起来是情况单独考虑。

// // template<typename... Args>
// // void printInfo(Args... args){
// //     int _[]{(std::cout << args << std::endl, 0)...};
// // }

// // template<typename T, size_t N, typename... Args>
// // void print_multi_ele(const T(&arr)[N], Args... Index){
// //     std::cout << "the length of arr" << " " << N << std::endl;
// //     printInfo(arr[Index]...);
// // }

// template<typename... Args, typename RT=std::common_type_t<Args...>>
// RT sum_multi(Args... args){
//     RT _[] {static_cast<RT>(args)...};
//     RT result {};
//     for(int i=0; i< sizeof...(args); ++i){
//         result += _[i];
//     }
//     return result;
// }

// template<size_t... N>
// void test_test(){
//     size_t _[] {N...};
//     for(size_t ele: _){
//         std::cout << ele << std::endl;
//     }
// }

// // 类模板与函数模板是没有什么大的差别的

// template<typename T, size_t N>
// class array{
//     public:
//         T _arr[N];
// };

// // 具体的类型推导不需要指定模板, 直接写就可以了
// // 某一个类的类型推导需要指定模板
// // 注意这里的推导方式, 前面的 array 是指放到 array 中的形式
// // 后面的 array<> 是指具体的推导类型
// array(int, int) -> ::array<int, 2>;  // 具体的推导

// template<typename T, typename... Args>
// array(T, Args... args) -> array<T, sizeof...(args)+1>;

// // 都是直接把模板的参数复制过来, template<typename T, size_t N> 
// // 其实就是一个类型, 其中的 T 和 N 都是不可以用的
// template<typename Ty, template<typename T, size_t N> class C>
// class NewClass{
//     public:
//     C<Ty, 3> okk;
// };

// template<typename... Args>
// class test_tuple{
//     public:
//     test_tuple(Args... args):
//     value(args...)
//     {

//     }

//     std::tuple<Args...> value;
// };

// // 函数模板和类模板要先确定要推导的参数是什么, 然后再进行实例化
// // 推导的这个参数, 其实就是其可以泛化的部分, 能够泛化 类型, 整数, 模板
// // 实例化完成以后, 才能进行后面步骤
// // 而这个泛化的部分可以通过 函数的实参 默认参数 用户指定 类的构造函数 用户指定推导 

// // template<typename T>
// // constexpr T PI = static_cast<T>(3.1415926);

// // template<size_t N>
// // constexpr size_t okk = N;

// // template<size_t... N>
// // constexpr std::common_type_t<decltype(N)...> const_array[] {N...};

// // C++ 中的不完全类型 void 未声明长度的数组 未给出声明的结构体和类
// // 不完全类型的作用：
// // 1) 对于未声明长度的数组, 可以在 .hpp 文件中先声明, 再在 .cpp 中定义。
// // 2) 结构体或者类的成员中指针的相互指向, 一定是需要不完整类型。
// // 3) 不完整类型可以起到隐藏代码的作用, 较少暴露信息给外界。

// extern int aaa[];  // 这个就是不完全类型

// 全特化这里, 对类模板和变量的全特化, 相当于是能够任意写一个新的定义方式
// 而对函数的全特化, 要保持其形参和返回类型是与模板特化后一致的

// 模板代换失败不是错误 SFINAE 这个本质上其实就是增加了编译时期的检查功能
// 如果没有这个检查的话, 那么就会对模板进行实例化, 实例化再出错的话, 就会直接报错
// SFINAE 代换失败的化就会丢弃这个特化, 转而去找其他的函数, 没有的话, 会说没有合适的函数重载
// C++ 20 之前都是 typename SFINAE = 如果是逻辑值的, 就用 std::enable_if_t, 如果仅仅是多个并列的, 就使用 std::void_t
// 将任意类型 T 转换成引用类型, 使得在decltype说明符的操作数中不必经过构造函数就能够使用成员函数 std::declval



// 概念与约束
// concept 是 C++20 为模板引入的新的语法  
// 概念的基本形式是
// template<形参列表>
// concept 概念名 = 可以在编译期确定bool值的表达式
// 概念可以用于约束中, 可以将 typename 替换掉
// requires 子句和 requires 表达式 
// requires 子句 是期待子句是一个能够产生一个编译时确定 bool 的表达式
// requires 表达式是检查语法, 返回一个纯右值的表达式(符合语法就返回 true, 否则返回 false)
// requires 正好是符合 concept 和 requires 子句中, 在编译时确定 bool 的要求