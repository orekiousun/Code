# coding:utf-8

import os


"""
    转义字符:字符要转成其他含义的功能
        1.\n 换行
        2.\t 横向制表符
        3.\v 纵向制表符
        4.\a 响铃
        5.\b 退格符，将光标前移，删除前一个
        6.\r 回车
        7.\f 翻页
        8.\' 转义字符串中的单引号
        9.\" 转义字符串中的双引号
        10.\\ 转义字符串中的斜杠
    转义无效符：在当前字符串前加r使当前转义字符无效化,对格式化中的%s没有效果
"""
info_n='my name \nis dewei'
print(info_n)
info_t1='my name\tis dewei' # 出现一个空格
info_t2='my name \tis dewei' # 出现多个空格
print(info_t1)
print(info_t2)
info_v='my name\vis dewei'
print(info_v)
info_b='my name is dewei\b'
print(info_b)
info_r='my name is dewei\r'
print(info_r,info_b) # \r会吞掉后面一行的字符串
info_f='my name is dewei\f'
print(info_f) # 底下多了一个空行
print('my name is \'dewei\'') # 能在工作区体现出单引号
print('my name is \"dewei\"') # 能在工作区体现出双引号
print('my name is \ dewei') # 显示不出效果
print('my name is \\ dewei') # 显示一个斜杠
print(r'my name is dewei\r')