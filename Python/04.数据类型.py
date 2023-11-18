# coding:utf-8

import os


"""
数据类型：
    1.数字类型
        a.整型 int
            count_100_01=int(100)
            count_100_02=100（简化语法，系统自动加上int）
        b.浮点型 float
            pi_01=3.14
            pi_02=3.14（简化语法，系统自动加上float）
    2.字符串类型 # 用""或''包裹的都是字符串类型
        用str函数定义
            weather=str('sunny')
            weather='sunny'（简化语法，系统自动加上str）
        # 字符串内部不能用同样的引号，若要在字符串内引用，则要用不同的引号
    3.布尔类型 # 真假判断类型
        固定值true->真 false->假
        int 0->false,not 0->true
        float 0->false,not 0->true
        str ''->false,not ''->true
        计算机中 0->false,1->ture
            result=bool('mu'in'xioami')
    4.空类型 # 不属于任何类型，没有任何特色就是空类型，属于false范畴
        固定值 None
        不确定数据类型时，可以先赋值一个空类型
    5.列表类型 # 队列，多种数据集合，一种数据结构，可以重名
        list定义列表
            list_01=list(['a','b','a'])
            list_02=['a','b','c']
        列表可以定义字符串，整型，浮点型，bool类型，空类型,混合类型
        列表中可以嵌套列表
            list_03=[['a','b'],['b','c']]
        列表中也可以用in,max,min
            1 in [1,2,3,4]
            max([1,2,3,4])
            min([1,2,3,4]) # max&min中元素数据类型一定要统一
        也可以用过len返回列表长度
            len([1,2,3,4])
    6.元组类型
        tuple定义元祖，用()
            tuple_02=tuple(('a','b','c'))
            tuple_01=('a','b','c')
        元组与列表的区别
            元组具有不可变性，列表可以增加删除修改
        元组的使用方法与列表除了符号几乎完全一致
        可以在列表中创建元组，也可以在元组中创建列表，元组中列表一旦创建也无法改变
    7.字典类型
        dict定义字典,用{}将key与value存入字典中
            person=dict({'name':'dewei', 'age':33})
            person={{'name':'dewei', 'age':33}}
        字典支持的数据类型：
            key：字符串，数组，元组
            value：所有数据类型
        列表与元组中的字典：
            dict_array=[{1:1,2:2},{'one':1,'two':2}]
            dict_tuple=({1:1,2:2},{'one':1,'two':2})
        字典也可以进行修改和添加，元组一旦创建，就不能修改了
        字典中每一个key一定是唯一的，每一个key与value一定一一对应
内置函数：
    1.type：   # 返回数据类型
        count=100
        print(type(count))
        print(type(3.1415926))
    2.id：     # 返回变量的内存地址
        name='ousun'
        id(name)
        name='xiaomu'
        id(name)
    3.len      # 返回字符串长度
        name='xiaomu'
        len(name)
    4.in       # 成员运算符,判断是否是子字符串
        name='xioamu'
        result='mu'in name
    5.max      # 返回数据中最大的成员
        max(1,2,3)
        max('weather')
    6.min      # 返回数据中心最小的成员
        min(1,2,3)
        min('weather')
    7.字符串拼接，用+  # 字符串不是数字，不能做减法和乘除法
        a='123'
        b='456'
        c=a+b

"""
count=int(100) # count=100
pi=float(3.1415926) # pi=3.1415926
name='xioamu'
result_01=bool('mu' in name) # bool类型
result_02='um' in name
weather=str('sunny') # weather='sunny'
a='123'
b='456'
c=a+b
a=0
b=1
c=0.0
d=1.1
e=''
f='None'
g=None
test_01=bool(a)
test_02=g # 测试bool
list_01=list(['a','b','a'])
tuple_02=('a','b','c')
list_03=[['a','b'],['b','c']]
list_in=1 in [1,2,3,4]
list_max=max([1,2,3,4])
tuple_min=min((1,2,3,4)) # 测试列表和元组
user_info={'name':'xioamu','age':18}
result_03='name'in user_info
if __name__=='__main__':
    print(type(count))
    print(type(pi))
    print('count=',count,'元') # 可以直接通过此方式链接打印内容
    print(result_01)
    print(result_02) # 测试in
    print(id(weather))
    print(len(weather))
    print(max(1,2,3))
    print(max('weather'))
    print(min(1,2,3))
    print(min('weather')) # 测试max&min
    print(c)                   
    print(a+b) # 测试拼接
    print(bool(a))
    print(bool(b))
    print(bool(c))
    print(bool(d))
    print(bool(e))
    print(bool(f))
    print(bool(g))             
    print(type(test_01))
    print(type(test_02)) # 测试bool和None
    print(list_in)
    print(list_max)
    print(tuple_min)
    print(max(list_01))
    print(min(tuple_02))
    print(type(list_01)) 
    print(type(tuple_02))
    print(len(list_01))
    print(len(tuple_02)) #测试列表和元组
    print(result_03)
    print(type(user_info))