#include <iostream>
#include <map>
using namespace std;
/**
 * map/ multimap容器
 * 简介：
 *  map中所有元素都是pair
 *  pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
 *  所有元素都会根据元素的键值自动排序
 *
 * 本质：
 *  map/multimap属于关联式容器，底层结构是用二叉树实现。set底层也是二叉树
 *
 * 优点：
 *  可以根据key值快速找到value值,使用数组的方式 my_map[key] 获取value
 *
 * map和multimap区别：
 *  map不允许容器中有重复key值元素
 *  multimap允许容器中有重复key值元素
 *
 * map构造和赋值
 *  对map容器进行构造和赋值操作
 *  函数原型：
 * 构造：
 *  map<T1, T2> mp;                    //map默认构造函数:
 *  map<T1, T2> mp = {pair<T1,T2>(值1,值2),pair<T1,T2>(值1,值2),pair<T1,T2>(值1,值2),...};    ={}初始化
 *  map(const map &mp);                //拷贝构造函数
 *  map(operator beg ,operator end);   //拷贝区间构造  beg和end可以使用 ++ -- ,不能使用 +1 -1   set和map不支持随机访问
 *
 * 赋值：
 *  map& operator=(const map &mp);    //重载等号操作符
 *  没有assign()方法赋值
 *  也没有push和pop方法,要使用insert插入,erase clear删除
 */
void printMap(const map<int,int> &m) {
    for (map<int,int>::const_iterator i =m.begin(); i !=m.end() ; ++i) {
        cout << i->first << " " << i->second << " | ";
    }
    cout << endl;
}
void test01(){
    // = {pair<类型1,类型2>(值1,值2),pair<类型1,类型2>(值1,值2),pair<类型1,类型2>(值1,值2),...}
    map<int,int> m0{pair<int,int>(1,10),pair<int,int>(1,20),pair<int,int>(4,40)};

    //通过key值可以获取value值
    cout << m0[4] << endl;  //40

    printMap(m0);   //1 10 | 4 40 |

    //默认构造
    map<int,int> m1;

    //插入方式
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(1,20));
    m1.insert(pair<int,int>(4,40));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(2,20));


    printMap(m1);   //1 10 | 2 20 | 3 30 | 4 40 |

    //拷贝构造
    map<int,int> m2(m1);
    printMap(m2);   //1 10 | 2 20 | 3 30 | 4 40 |

    map<int,int> m3(++m1.begin(),--m1.end());
    printMap(m3);   //2 20 | 3 30 |

    // = 赋值
    map<int,int> m4 = m3;
    printMap(m4);   //2 20 | 3 30 |

    //使用 [键值] 查看的是数据
    cout << m4[1] << endl;  //0
    cout << m4[2] << endl;  //20
    cout << m4[3] << endl;  //30
}
int main() {
    test01();
    return 0;
}
