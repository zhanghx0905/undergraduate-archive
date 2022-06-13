# PA2-2 Circuit Report

2018011365 张鹤潇

#### 算法简述

用Trie树维护[i-k-1,i+k+1]区间内的节点，查找时按高位贪心，即：尽可能沿着当前数按位取反后对应的路径下行查找。

在叶子节点中维护了一个队列，查找到该节点时，如果队首元素不是自己，就返回队首元素的下标；否则，就返回队列中下一个元素的下标。

#### 困难及其解决

本题最大的困难在于内存不够。在最坏情况下，即n=500000，树从某一层之后全部退化成一条链时，要在Trie树中维护超过2200万个内部节点。

为了尽可能压缩内存，我做了以下尝试：

- 考虑到在64位机上一个指针占8 byte，我不使用指针，用结构体数组来模拟Trie树；
- 将内部节点和叶子节点分开。内部节点中，用一个表示该节点是否存在的bool变量，替代表示该节点对应子树大小的int变量；
- 为了避免初始化全局结构体数组消耗太多时间，我用get方法替代了结构体的构造函数。

最后开出了2000万个内部节点.

#### 复杂度分析

每个节点被加入Tire树一次，删除一次，对应查找一次，时间复杂度$O(3*64n)=O(n)$.

Tires树中要同时维护不超过2k+3个节点，空间复杂度$O(64kn)$.

在本题背景下，空间复杂度的常系数不能忽略。