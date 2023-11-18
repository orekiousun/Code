# coding:utf-8

import os
from typing import cast


"""
    1.+=,*=对列表/元组也适用
    2.内置函数
        1.append:将一个元素添加到当前列表中 # 只用于列表
            list.append(new_item) # new_item添加进去的新元素
            ·被添加的元素只会添加到末尾
            ·是在原有列表基础上添加，不额外添加新变量
            ·append可以添加字符串，元组，字典，整型
            ·append后方只能添加一个元素
        2.insert:将一个元素添加到当前列表指定位置中 # 只用于列表
            list.insert(index,new_item) # idex代表位置，new_item代表新的成员
            ·append只能添加到列表末尾，insert可以添加到任意位置
            ·如果insert传入的位置列表中存在，则将新元素添加到列表末尾
            ·字符串，元组，列表的位置都是从0开始计算的
        3.count:返回当前列表种某个成员的个数 # 用于列表/元组
            list.count(item) # item需要查询个数的成员
            ·如果查询成员不存在，则返回0
            ·只会查找完整的成员
        4.remove:删除列表中的某个元素 # 适用于列表
            list.remove(item) # item表示要删除的元素
            ·若不存在这个成员，程序会直接报错
            ·若要删除的元素有多个，则只会删除从左到右第一个元素
            ·删除后列表地址不变，没有创建新的列表
          del:把变量完全删除
            del drinks 
        5.reverse:将当前的列表顺序反转 # 适用于列表
            list.reverse()
        6.sort:把当前列表按照一定规律进行排序 # 适用于列表
            list.sort(key=None,reverse=True)
                key-参数比较
                reverse-为True时降序，False时升序（默认）
            ·列表中的元素类型必须相同，否则无法排序
        7.clear:把当前列表中所有的数据清空 # 适用于列表
            list.clear()
        8.copy:将当前的列表复制一份相同的列表，新列表与旧列表相同，但内存空间不同 # 适用于列表
            new_list=list.copy()
            浅拷贝-拷贝出新的列表后，改变其中一个列表，相互之间也受到影响
            深拷贝-不仅对第一层数据进行了copy，对深层的数据也进行了copy，原始变量与新变量完全不共享数据
        9.extend:将其他列表或元组中的函数一次性导入到当前列表中 # 适用于列表
            list.extend(iterable) # iterable代表要添加的列表或元组
            ·可以导入列表，元组，字符串，字典（只会出现key）
"""
# 测试append
books_a=[]
print(id(books_a))
books_a.append('python')
print(books_a)
print(id(books_a))
number_a=1
tuple_a=(1,2)
dict_a={'name':'dewei'}
books_a.append(number_a)
books_a.append(dict_a)
books_a.append(tuple_a)
print(books_a)
# 测试insert
students_i=[{'name':'dewei','age':33,'id':1},{'name':'xioamu','age':18,'id':2}]
xiaoai={'name':'xiaoai','age':21,'id':3}
xiaogao={'name':'xiaogao','age':19,'id':4}
students_i.insert(1,xiaoai)
students_i.insert(8,xiaogao)
print(students_i)
# 测试count
animals_c1=['cat','dog','tiger','rabbit','cat']
print(animals_c1.count('cat'))
animals_c2=('cat','dog','tiger','rabbit','cat')
print(animals_c1.count('cat'))
animals_dict=[{'name':'cat'},{'name':'dog'},{'name':'tiger'},{'name':'rabbit'},{'name':'cat'}]
print(animals_dict.count({'name':'cat'}))
# 测试remove
drinks_remove=['cola','water','cola','milk','tea']
drinks_remove.remove('cola')
print(drinks_remove)
# 测试reverse
drinks_reverse=['cola','water','cola','milk','tea']
drinks_reverse.reverse()
print(drinks_reverse)
# 测试sort
number_sort=[3,5,2,6,9,1,7,4,8]
number_sort.sort()
print(number_sort)
number_sort.sort(key=None,reverse=True)
print(number_sort)
# 测试clear
target_list=[1,2,3,4,5,6,'haha',{'name':'xiaoming'},(1,2,3)]
target_list.clear()
print(target_list)
# 测试copy
old_list=[1,2,3,4,5,6,'haha',{'name':'xiaoming'},(1,2,3)]
new_list_01=old_list # 此方法为浅拷贝
new_list_01.append('chorm')
print(old_list,id(old_list))
print(new_list_01,id(new_list_01)) 
new_list_02=old_list.copy() # 此方法为深拷贝
new_list_02.append('code')
print(old_list,id(old_list))
print(new_list_02,id(new_list_02))
# 测试extend
books_e=['a','b','c']
books_e_01=['d','e']
books_e.extend(books_e_01)
print(books_e)
books_e.extend({'name':'ousun','age':19}) # 只会出现key
print(books_e)


