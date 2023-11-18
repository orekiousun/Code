# coding:utf-8

import os


"""
    1.字符串与数字之间的转换
    原始类型  目标类型  函数  举例
    整型      字符串   str   new_str=str(123456)
    浮点型    字符串   str   new_str=str(3.14)
    字符串     整型    int   new_int=int('12')
    字符串    浮点型  float  new_float=float('1.2')
    2.字符串与列表的转换
    ·split:将字符串以一定规则将字符串切割为列表
        string.split(sep,maxsplit) 
        # sep:切割的规则符号，不填写，默认空格，如字符串无空格则不分割生成列表
        # maxsplit:根据切割符号切割的次数，默认-1无限制切割
        # 返回值为一个列表 
    ·join:将列表以一定规则转为字符串
        'sep'.join(iterable)
        # sep:生成字符串用来分割列表每个元素的符号
        # iterable:非数字类型的列表或元组组合
        # 返回值为一个字符串
    3.比特类型bytes:二进制数据流，是一种特殊字符串，在字符串前添加一个b的标记即为比特类型
        bt=b'my name is dewei'
        # 比特类型可以用字符串的所有元素，但是传入的参数必须是比特类型
    4.encode:字符串转比特的函数
        string.encode(encoding,errors)
        # encoding:转换成的编码格式，如ascii，gbk，默认为utf-8
        # errors:出错时的处理方式，默认为strict
            直接抛出错误，也可选择ignore忽略
        # 返回值为一个比特（bytes）类型
    5.decode:比特转化为字符串的函数
        bytes.decode(encoding,errors)
        # encoding:转换成的编码格式，如ascii，gbk，默认为utf-8
        # errors:出错时的处理方式，默认为strict
            直接抛出错误，也可选择ignore忽略
        # 返回值为一个字符串类型
    6.列表元组集合间转换的函数
    原始类型 目标类型 函数   举例
    列表     集合     set   new_set=set([1,2,3,4,5])
    列表     元组    tuple  new_tuple=tuple([1,2,3,4,5])
    元组     集合     set   new_set=set((1,2,3,4,5))
    元组     列表     list  new_list=list((1,2,3,4,5))
    集合     列表     list  new_list=list({1,2,3,4,5})
    集合     元组     tuple new_tuple=tuple({1,2,3,4,5})
"""
# 测试数字转字符串
int_data=12
float_data=-3.14
str_int_data=str(int_data)
str_float_data=str(float_data)
print(str_int_data,type(str_int_data))
print(str_float_data,type(str_float_data))
# 测试字符串转数字
str_int='123456'
str_float='3.14'
real_int=int(str_int)
real_float=float(str_float)
print(real_int,type(real_int))
print(real_float,type(real_float)) 
# float不能转换为int，int可以转换为float
# 测试字符串转列表
a='abc'
print(a.split())
b='a b c'
print(b.split(','))
c='a|b|c|d'
print(c.split('|',1))
print(c.split('|',3))
# split中sep参数不能传入空字符串
# 测试列表转字符串
test=['a','b','c']
test_str='|'.join(test)
print(test_str)
# 只有字符串类型的列表才能转换为字符串
# 利用分割实现字符串内部排序
sort_str='f c a d i j l n'
sort_list=sort_str.split(' ') # 分割
print(sort_list)
sort_list.sort() # 利用列表内置函数sort排序
print(sort_list)
sort_str=' '.join(sort_list) # 排序成功后再次合并
print(sort_str)
# 内置函数sorted可以对任何类型进行排序处理
sort_str_new='fcadijln'
res=sorted(sort_str_new) # 使用sort后默认转化为了列表
print(res)
print(''.join(res))
# 创建比特类型
bytes_1=b'my name is dewei'
print(bytes_1,type(bytes_1))
# print(dir(b)) # 通过dir函数可以打印出有的函数
str='hello 小慕'
bytes_2=str.encode('utf-8')
print(bytes_2)
bytes_2=bytes_2.decode('utf-8')
print(bytes_2)


