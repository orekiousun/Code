# coding:utf-8

import os


"""
    赋值运算符：
        1.=：等于运算符 c=a+b
        2.+=:加法运算符：c+=a -> c=c+a
        3.-=:减法运算符：c-=a -> c=c-a
        4.*=:乘法运算符：c*=a -> c=c*a
        5./=:除法运算符：c/=a -> c=c/a
        6.%=:取模运算符：c%=a -> c=c%a
        7.**=:幂运算符：c**=a -> c=c**a
        8.//=:整除运算符：c//=a -> c=c//a
    比较运算符：
        1.==:判断是否等于 a==b
        2.!=:判断是否不等 a!=b
        3.>:判断是否大于 a>b
        4.<:判断是否小于 a<b
        5.>=:判断是否大于等于 a>=b
        6.<=:判断是否小于等于 a<=b
        2.<>:判断是否不等 a<>b # 老版本
    身份运算符：
        1.is:判断两个对象存储单元是否相同 a is b
        2.is not:判断两个对象存储单元是否不同 a is not b
    身份与比较运算符返回的都是布尔类型
"""
a=1
b=2
c=3
d=a+b+c
d+=c
print(d)
d-=a
print(d)
d*=b
print(d)
d/=b
d//=c
print(d)
c%=1
print(c)
x=10
x**=2
print(x)
list_01=[1,2,3]
print(list_01*2)
tuple_01=(1,2,3)
print(tuple_01) # 字典类型不支持乘法
m=4
n=5
m_01=4
print(a==b)
print(a!=b)
print(a>b)
print(a<b)
print(a>=b)
print(a<=b)
print(m is m_01)
print(m is not m_01) # python会把0-255范围内的数字从已有的内存中直接拿出来