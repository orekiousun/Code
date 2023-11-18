# coding:utf-8

import os

name=input('你的名字是：')
age=input('你的年龄是：')
username='lisa'
userage=20
a,b,c=1,2,3 # 也可以这样连续定义
if __name__=='__main__':
    print('你的名字是%s，年龄是%s' %(name,age)) # 格式化内容用%
    print(username)
    print(userage)
    print(a,b,c)