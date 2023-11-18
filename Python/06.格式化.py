# coding:utf-8

import os
from typing import AsyncGenerator


"""
    1.字符串格式化用操作符%来实现,右边对应元组
     'my name is %s,my age is %s' % ('xiaomu',19)
    2.format函数:格式化字符串
        string.format(data,data,data)
        ·使用format的字符串主体使用大括号{}来替代格式符
    3.用f-string的方法格式化
        ·定义一个变量
        ·字符串前加f符号
        ·需要格式化的位置使用变量名
    4.格式化常用字符
        ·%c 字符类型
        ·%d 整型
        ·%f 浮点型
        ·%u 无符号整
        型
        ·%s 通用类型
        ·%o 格式化无符号的8进制数
        ·%x 格式化无符号的16进制数
        ·%e 科学计数法格式化浮点数
        print('%d' % 4)
        # 使用format时%要替换为:.%u与%s在format中不适用
        print('{:d}'.format(3))
        
"""
# 测试%的格式化方法
name_01=('a',12)
name_02=('b',18)
info='my name is %s,my age is %s'
print('my name is %s,my age is %s' % ('xiaomu',19))
print('my name is %s,my age is %s' % name_01)
print('my name is %s,my age is %s' % name_02)
print(info % name_01)
print(info) # 不进行关联就不会出现问题
books=['python','java','html']
dict={'a':'a','b':'b'}
print('my name is %s,my age is %s,my books are %s' % ('xiaomu',18,books))
# 测试format函数
info_01='my name is {},my age is {},my books are {}'
print(info_01.format('xiaomu',18,books))
# 测试f-string
name_03='xioamu'
age=19
info_02=f'my name is {name_03},my age is {age},my books are {books}'
print(info_02)
# 测试格式化常用字符
print('%o' % 9)
number=int('123ab',16) # 在后方传入16说明要生成16进制的数字
print(number)
print('%x' % number) # 说明number确实是16进制字符
