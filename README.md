# InterviewCode
此仓库是本人在准备秋招面试过程中的刷题总结和感悟

## 刷题技巧感悟



## C++ 语法技巧
> 1.C++ 中不同类型混合运算的规则
* 参与运算的类型不同, 则先转换成同一类型, 然后再进行运算。(这个是总原则)
* 转换成同一类型时, 转换按数据长度增加的方向进行。
    * 对于类型中只有整数的运算: 两种类型字节数不同，转换成字节数高的类型。若字节数相同，一种有符号，一种无符号，转换成无符号。
    * 对于类型中有浮点数的运算: 若最高的是 `float`, 那所有数据类型先转换成 `float` 然后再进行运算; 若最高类型是 `double`, 那所有类型先转换为`double` 再进行运算。
* 有两个比较特殊的情况:
    * 所有的浮点运算，都是以双精度进行的, 即使是两个 `float` 单精度运算的表达式, 也要先转换为 `double` 再做运算。
    * `char` 型和 `short` 型参与运算时，必须先转换成 `int` 型。

```C++
#include <vector>
#include <iostream>

int main(){
    std::vector<int> nums {1};
    int i=1, k=1;
    std::cout << std::boolalpha << (i<nums.size()-k-1) << std::endl;
    return 0;
}
```
在以上的这个例子中, 可能会认为输出为 false (1<-1肯定是真>), 其实真正的输出为 true。这是因为运算的类型不同, 要先转换成同一类型再进行运算。
比如，`i<nums.size()-k-1` 中 `i` , `k` , `1` 都是 `int` 类型, `nums.size()` 是 `unsigned long long` 类型, 所以所有都要先转换为 `unsigned long long`, 再进行运算。(这个也提示我们，以后调用 `vector.size()` 时, 必须要注意其是无符号整数类型)

> 2.C++ 中 `vector` 的辨析 
* C++ 中的 `vector` 在 `RAII` 机制析构之前, 会逐个调用其内部元素的析造函数(如果存在析构函数的话), 然后再析构自己。所以如果元素是指针, 但这个指针指向的是堆上的内存空间, 就必须手动 `delete` 其中的每一个元素。

```C++
#include <iostream>
#include <vector>

int main() {
    // 创建一个存储整数指针的 vector
    std::vector<int*> ptrVector;

    // 动态分配一些整数
    int* ptr1 = new int(5);
    int* ptr2 = new int(10);

    // 将指针添加到 vector 中
    ptrVector.push_back(ptr1);
    ptrVector.push_back(ptr2);

    // 以上四行还能写做, 能写成这样的原因是 new 的返回值其实就是一个指向已经分配空间首地址的指针
    // ptrVector.push_back(new int(5));
    // ptrVector.push_back(new int(10));

    // 不要忘记释放动态分配的内存
    for (int* ptr : ptrVector) {
        delete ptr;
    }

    return 0;
}
```
在上面的例子中, `vector` 中每个元素是一个指针, 而且这个指针指向了堆上的内存, 所以要手动释放。如果含有的这个指针，指向的是栈上的内存空间, 那不需要手动释放。C++ 中的容器对放入其中的类对象, 会调用其拷贝构造函数来创建一个新的副本, 并将该副本储存在容器中。注意容器中存放的是指针时, 他们在只会复制指针的值。当容器在析构前, 也会逐一调用该类对象的析构函数。

## 待解决的问题
* 链表 8
* 字符串 6
* 二叉树 18