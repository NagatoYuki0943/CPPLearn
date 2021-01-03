#include <iostream>
#include <deque>

using namespace std;

/**
 * deque基本概念
 * 功能:
 *  双端数组,可以对头端进行插入删除操作
 * deque和vector区别:
 *  vector对于头部插入删除效率低,数据量越大,效率越低
 *  deque相对而言,对头部的插入删除速度比vctor快
 *  vector访问元素的速度比deque快,这和两者的内部实现有关
 *
 * begin()和end()返回iterator迭代器,begin()代表第一个,end()代表最后一个的下一个
 *
 * front()和back()代表第一个和最后一个数据
 * push_back()和pop_back()对尾部数据进行操作
 * push_front()和poop_back()对头部数据进行操作
 *
 * deque内部工作原理:
 * deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
 * 中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
 *
 * deque容器的迭代器也是支持随机访问的
 *
 * deque构造函数
 * 函数原型：
 *  deque<T> deqT;                  //默认构造形式
 *  deque(iterator beg, iterator end); //构造函数将[beg, end)区间中的元素拷贝给本身。
 *  deque(n, elem);                 //构造函数将n个elem拷贝给本身。
 *  deque(const deque &deq);        //拷贝构造函数
 *
 *
 * deque容器和vector容器的构造方式几乎一致，灵活使用即可
 */

void prinfDeque(const deque<int> &d) {
    //两个写法效果相同
//    for (int i = 0; i < d.size(); ++i) {
//        cout << d[i] << " ";
//    }
    //上面修改为只读之后这里要改为 const_iterator
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    deque<int> d1;
    d1.push_back(2);
    d1.push_front(1);
    prinfDeque(d1); //1 2

    deque<int> d2{1, 2, 3, 4, 5, 6, 7};
    deque<int> d3(d2.begin() + 1, d2.end() - 1);
    prinfDeque(d3); //2 3 4 5 6

    deque<int> d4(5, 6);
    prinfDeque(d4); //6 6 6 6 6

    deque<int> d5(d3);
    prinfDeque(d5); //2 3 4 5 6

}

int main() {
    test01();
    return 0;
}
