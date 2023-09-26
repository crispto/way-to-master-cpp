
## demo 的输出

```bash
size of Foo is 32
size of FooStatic is 32
size of FooWithFunc is 32
size of FooWithVirtual is 40
size of FooWithTwoVirtual is 40
```

显然是不会，而且增加一个函数也不会因为 static 虽然声明在类之内，但是它实际上存储在静态存储区内，不占用对象内存空间。因此它不需要实例化一个对象就可以直接使用。另外 static 方法也不需要实例化类就可以使用。

存储空间分为以下几个部分

- 栈区stack （执行时系统自动分配和回收的内存）

- 堆区heap （用 new\delete 来手动管理的内存）

- 代码区（程序的二进制代码）

- 数据区 (存储static变量,const变量，全局变量)，


数据区其实分为三部分
一、只读区，存储const 修饰的不可改变量，
二、已初始化的可读写段，包含了 static 变量，全局变量，文字常亮
三、未初始化的读写段，和二相同，不过这块区域的值都是默认值0，int类型就是0，string 就是空字符串

类的大小由
1. 成员变量（静态数据除外）、
2. 内存对齐
3. 如果有虚函数，则有一个虚表指针，这里存储的只是指针，所以不论虚函数有多少，大小都不变
4. 如果有虚继承的话，还有基类虚指针


### 内存对齐的一个例子

需要注意，内存对齐是对每一个元素做的，而不是在整个类后面，因此变量的声明顺序会影响类的大小，比如下面两个成员变量完全相同的类，因为其变量的顺序不同，大小也不同。

```cpp
// 这个类大小为 4 +4 +24 = 32
class Foo {
public:
private:
    int age_{10};
    int age_2{10};
    string name_{"mark"};
};
```

```cpp
// 这个类大小为 4+ 4(align)+24 + 4 + 4(align) = 40
class Foo {
public:
private:
    int age_{10};
    string name_{"mark"};
    int age_2{10};
};
```
