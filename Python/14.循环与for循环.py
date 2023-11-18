# coding:utf-8


"""
    1.for循环
        for item in iterable: # for循环语法块
            print(item)       # 每次循环对应代码块，需要缩进
        # iterable:可循环的数据类型 如列表 元组 字符串 字典
        # item:iterable中的每一个元素（成员）
        # for循环是语句，没有返回值，但在特定情况下有返回值
    2.字典利用items函数进行for循环
        for key,value in dict,items():
            print(key,value)
        # items 无参数
        # key:for循环中获取的字典当前元素的key
        # value:for循环中对应当前key的value值
        # for循环是语句，没有返回值，items返回一个伪列表
    3.range:返回一个一定范围的可迭代对象，元素为整型，不是列表，无法打印信息，但可循环
        for item in range(start,stop,step=1):
            print(item)
        # start:开始的数组，类似索引左边，左闭
        # stop:结束的数字，类似索引右边，右开
        # step:跳步，类似索引中的第三个参数
        # 返回值为一个可循环的以整型为主的对象
    4.else在for循环中的使用:else语句只有在for循环正常退出后执行，循环不报错，中途不停止
    5.嵌套for循环
    6.while循环:以一定条件为基础的循环，条件满足则无限循环，条件不满足退出循环
        while bool_result:
            do
        # bool_result:布尔类型，此处与if语法完全一致
        # do:while循环体的代码块，需要缩进
        # while循环是语句，没有返回值
    7.continue:将循环遇到continue时停止本循环，进入下一个循环
        while bool:
            continue
        for item in itrable:
            continue
            print(item)
        # continue是语法，不需要加(),没有参数，没有返回值
    8.break:使循环正常停止，若配合else语句，else将不执行
        while bool:
            break
        for item in iterable:
            print(item)
            break
        # break是语法，不需要加(),没有参数，没有返回值
            
            
"""
# 测试for循环
l=['xiaomu','xiaoman','xiaoming']
for i in l: # i从0索引位置开始循环直至结束
    print(i)
print('finish')
for i in 'python':
    print(i)
users=('xiaomu','xiaoman','xiaoming')
for name in users:
    if name=='xiaomu':
        print('hello xiaomu')
    else:
        print('you are not xiaomu ,your name is %s' % (name))
info={'name':'dewei','age':24}
for key,value in info.items():
    print(key,value)
# 测试else
users_list=[
    {'username':'dewei'},
    {'username':'xiaomu'}
]
for user in users_list:
    print(user['username'])
    print(user.get('username'))
else:
    print('循环结束')
l=range(6) # 相当于有(0:6)个索引，左开右闭
print(l)
for i in l:
    print(i)
else:
    print('循环结束')
# 测试嵌套
a=[1,2,3]
b=[4,5,6]
for i in a:
    for j in b:
        print('a=%s,b=%s,a+b=%s' % (i,j,i+j))
# 测试while
count=0
total=0
while count<=100:
    total+=count
    count+=1
print(total)
# 测试continue
for name in users:
    if name=='xiaomu':
        continue
    print(name)
# 测试break
numbers=range(100)
for number in numbers:
    if number==77:
        break
    print(number)
# 乘法表
n=range(1,10)
for i in n:
    for j in range(1,i+1):
        print('%s*%s=%s'%(i,j,i*j),end=' ')
    print('')