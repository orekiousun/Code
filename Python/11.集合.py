# coding:utf-8

import os


"""
    集合：
        ·无序的不重复的元素序列
        ·常用来对两个列表进行交并差处理
        ·集合与列表一样，支持所有不可变的数据类型
    集合与列表区别：
                列表                   集合
        顺序     有序                  无序
        内容    可重复               不可重复
        功能 用于数据的使用  用于数据的交集并集差集的获取
        索引    有索引                 无索引
        符号    [][1,2,3]            {}{1,2,3}
    集合的创建方法：
        通过set函数创建，不能使用{}来创建空集合，但可以通过{}创建有值的集合
        a_set=set()    ->空集合
        b_set=set([1,2,3])    ->传入列表或元组
        c_set={1,2,3}    ->传入元素
        d_set={}    ->错误
    ·集合无法通过索引获取元素
    ·集合无获取元素的方法
    ·集合只是用来处理列表或元组的一种1临时类型，不适合存储与传输
    函数：
    1.add:用于集合中添加一个函数，如果集合中已经存在了这个函数就无效
        set.add(item) # set是当前操作的集合
    2.update:将一个新的元素加入集合中，若存在则会被忽略
        set.update(itarable) # iterable代表集合，元组，列表或字符串
    3.remove:将集合中某个元素删除，若不存在则报错
        set.remove(item) # item指集合中的成员
    4.clear:清空集合中所有元素 
        set.clear()
    5.del:删除集合
        set.clear()
    6.difference:求集合的差集
        a_set.difference(b_set)
    7.intersection:求集合交集
        a_set.intersection(b_set)
    8.union:求集合并集
        a_set.union(b_set,c_set) # 支持多个集合传入
    9.isdisjoint:判断两个集合是否有相同的元素，如果没有返回true，有返回false
        a_set.isdisjoint(b_set) # b_set与当前集合用于判断的集合，返回bool类型
"""

#测试set
a=set()
print(a)
print(type(a))
b=set([1,2,3])
print(b)
# c={1,'python',[1,2,3],{'name':2},(1,2,3)}
c={1,'python',(1,2,3)}
print(c)
# 测试通过{}创建空集合
d={}
print(d,type(d)) # 只能创建字典
e={1,1,2,3,4}
print(e) # 去掉了a中重复的内容
# 测试set
a_set=set()
a_set.add(0)
a_set.add(0)
a_set.add(1)
a_set.add(2)
print(a_set)
# 测试update
b_set=set()
b_set.update((1,2,3),'python',[4,5,6])
print(b_set)
# 测试remove
c_set={1,2,3,4,5}
c_set.remove(1)
print(c_set)
c_set.clear()
print(c_set)
# 测试difference
d_list=[1,2,3,4,5]
e_set=[4,5,6,7,8]
d_set=set(d_list)
e_set=set(e_set)
f_set=d_set.difference(e_set)
print(f_set)
# 测试intersection
print(d_set.intersection(e_set))
# 测试union
print(d_set.union(e_set))
# 侧视isdisjoint
print(d_set.isdisjoint(e_set))
g_set={1,2}
h_set={3,4}
print(g_set.isdisjoint(h_set))