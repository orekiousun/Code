# coding:utf-8

import os


"""
    内置函数： # 只有字符串类型才能使用
    1.capitalize:首字母大写
        newstr=string.capitalize()
        ·只对第一个字母有效
        ·只对字母有效
        ·已经大写则无效
    2.casefold/lower:将字符串全体小写
        newstr=string.casefold()
        newstr=string.lower()
        ·casefold与lower几乎没有区别,casefold适用于更多语种
    3.upper:将字符串全体大写
        newstr=string.upper()
    4.swapcase:大小写互换
        newstr=string.swapcase()
        ·只对字符串中字母有效
    5.zfill:为字符串定义长度，缺少的部分用0补足
        newstr=string.zfill(width) # width新字符串的长度
        ·zfill与字符串的字符无关
        ·如果定义长度小于当前字符串长度，则不会发生变化
    6.count:返回当前字符串中某个成员（元素）的个数
        newstr=string.count(item) # item表示元素的个数
        ·如果查询成员不存在，则会返回0
    7.startswith/endswith 判断字符串最开始/结束位置是否是某成员（元素）
        string.startswith(item) -> 返回布尔值 
        string.endswith(item) -> 返回布尔值
        ·可以测试开头/结束的多个字符，甚至整个字符串
    8.find和index：返回想寻找的成员位置
        string.find(item) 返回整型，找不到返回-1
        string.index(item) 返回整型，找不到报错
    8.strip:去掉字符串左右两边的指定元素，默认为空格
      lstrip/rstrip:去掉字符串开头/结尾的指定元素/空格
        newstr=string.strip(item) # item不填去掉空格
    9.replace:将旧的元素替换为新的元素
        newstr=string.replace(old,new,max)
        old:被替换的元素
        new:替换old的元素
        max:可选，代表替换几个，默认全部替换
    10.isspace:判断字符串是否是空格组成的字符串
        booltype=string.isspace() -> 返回布尔值
    11.istitle:判断字符串是否是标题类型 # 标题类型：每个单词首字母是大写，全大写也不为title类型 
        booltype=string.istitle() -> 返回布尔值
    12.isupper:判断字符串是否全为大写
        booltype=string.isupper() -> 返回布尔值
    13.islower:判断字符串是否全为小写
        booltype=string.islower() -> 返回布尔值
"""
name='Xiao Ai'
# 测试capitalize：
newname_01=name.capitalize()
print(newname_01)
# 测试casefold/lower
newname_02=name.casefold()
print(newname_02)
newname_03=name.lower()
print(newname_03)
# 测试upper
newname_04=name.upper()
print(newname_04)
# 测试swapcase
newname_05=name.swapcase()
print(newname_05)
# 测试zfill
newname_06=name.zfill(10)
print(newname_06)
# 测试count
newname_07=name.count('i')
print(newname_07)
# 测试startswith/endswith
print(name.startswith('X'))
print(name.startswith('Xiao'))
print(name.endswith('Ai')) 
print(name.endswith('x'))
# 测试find/index
print(name.find('o'))
print(name.find('l'))
# 测试strip
newname_08=name.strip('X')
print(newname_08)
name_01='  xiao ai x '
name_02='xiao ai x'
newname_09=name_01.strip()
newname_10=name_02.strip('x')
print(newname_09)
print(newname_10)
# 测试replace
name_03='hello my name is xxx,nice to meet you,I`m xxx'
newname_11=name_03.replace('xxx','***')
print(newname_11)
newname_12=name_03.replace('xxx','***').replace('i','#')
print(newname_12)
# 测试isspace,istitle,isupper,islower
name_04='HELLO WORLD'
print(name_04.isspace())
print(name_04.istitle()) 
print(name_04.isupper())
print(name_04.islower())