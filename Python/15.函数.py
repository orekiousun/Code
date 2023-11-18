# coding:utf-8


"""
    1.通过关键字def定义函数
        def name(args...):
            todo something...
            返回值
    2.函数的返回return：
        ·将函数结果返回
        ·return只能在函数体内使用
        ·return可以支持返回所有的python类型
        ·有返回值的函数可以直接用于赋值
    3.函数的调用：
        name((args=)...) # args可以省略
    4.函数的参数
        1-必传参数：在定义很熟时，没有默认值且必须在函数执行时传递进去的参数，且顺序与参数顺序相同，就是必传参数
            ·函数中定义的参数没有默认值，在调用时不传入则会报错
            ·在定义函数时，参数后面没有等号和默认值
                def func(a,b):
        2-默认参数：
            ·在定义函数时，定义的参数含有默认值，通过赋值语句给他一个默认的值
            ·如果默认参数在调用函数的时候给与了新的值，函数将优先使用后传入的值进行工作
                def func(a,b=1):
        3-可变参数：
            ·没有固定参数名和数量
                def func(*args,**kwargs):
                func(1,2,3,name='dewei',age='33')
                # 1,2,3对应*args，代表将无参数的值合并为元组
                # name='dewei',age='33'对应**kwargs，代表将有参数与默认值的赋值语句合并为字典
            ·传入参数时可以在参数前加*或**确定对应的函数中函数时args还是kwargs
        4-参数规则
            def add(a,b=1,*args,**args)
            ·参数的定义从左到右依次是必传参数，默认参数，(可变元组参数)，可变字典参数
            ·函数的参数传递非常灵活
            ·必传参数与默认参数的传参多样化
            ·特例:对默认参数要进行传参时要把元组提前（一般不用）
        5-函数参数类型定义:参数名+冒号+类型函数（+等号+默认值）
            def person(name:str,age:int=33)
            ·函数不会对参数类型进行验证,只是单纯肉眼认知
    5.局部变量与全局变量
        1-全局变量:在python脚本最上层代码块
            ·函数体内使用全局变量时只能使用，不能修改
        2-局部变量:在函数体内定义的变量，只能在函数体内使用
        ·当在函数体内定义了和全局变量一样的名字是，将优先使用局部变量，全局变量不变
        ·将全局变量传入函数也不会该表全局变量的值
    6.global:内资关键字，可以将全局变量在函数内更改
        name='dewei'
        def test():
            global name
            name='xiaomu'
        ·工作中不建议用global对全局变量修改，global仅仅支持数字，字符串，空，bool
        ·局部可以直接使用以及改变字典，列表
    7.递归：一个函数不停地反复执行
        ·通过返回值，直接执行自身函数
    8.lambda:定义轻量化函数，即用即删除，此功能只在一处使用
        f=lambda:value # 无参数，执行时用f()
        f=lambda x,y:x*y  # 有参数，执行时用f(1,4)
        ·lambda后面不能写return
    9.对*args和**kwargs的理解
        1.*args:args本质是一个元组，*args本质是若干个单独的数据，将*args写在函数定义后的括弧内，可以自动这若干个数据保存在args的元组中
        2.**kwargs:kwargs本质是一个字典，**kwargs本质是若干个键值对，通过**kwargs写在函数定义的括弧内，可以将这个若干个键值对保存在kwargs的字典中
"""
# 测试函数
def capitalize(data):
    index=0
    temp=''
    for item in data:
        if index==0:
            temp=item.upper()
        else:
            temp+=item
        index+=1
    return temp
def message(message,messagetype):
    newmessage='[%s]%s' % (messagetype,message)
    print(newmessage)
def add(a,b,c=1):
    return a+b+c
result=capitalize('hello')
print(result)
message('what a nice day','info')
# 测试默认参数
print(add(a=1,b=2))
print(add(1,2,6))
print(add(b=2,a=2)) # 这种形式可以交换顺序
# 测试可变参数
def test_args(*args,**kwargs):
    print(args,type(args))
    print(kwargs,type(kwargs))
test_args(1,2,3,4,5,6,name='dewei',age='33')
test_args(*(1,2,3,4,5,[1,2,3],{'name':'dewei'}),**{'name':'xioamu','age':18})
def test(a,b=1,*args):
    print(a,b,args)
s=(1,2)
test(1,2,*s)
def test2(a,b=1,**kwargs):
    print(a,b,kwargs)
test2(1,2,name='dewei')
test2(a=1,b=2,name='dewei')
test2(name='dewei',age=33,a=1,b=2)
d={'name':'xiaomu'}
test2(a=1,b=2,**d)
test2(**d,a=1,b=2)
# 测试定义参数类型
def func(a:int,b:int=3):
    print(a+b)
func(1)
# 测试局部以及全局变量
a=1
def test3(a):
    a=10
test3(a)
print(a)  # a的值并没有改变
# 测试global
def test4():
    global a
    a=10
test4()
print(a)
new_list=[]
def test5():
    new_list.append('2')
test5()
print(new_list)
# 测试递归
count=0
def test6():
    global count
    count+=1
    if count!=5:
        print('error')
        return test6()
    else:
        print(count)
test6()
# 测试lambda
f1=lambda:1
print(f1())
f2=lambda x,y:x*y
print(f2(5,6))
f2=lambda x,y=3:x*y
print(f2(2))
users=[
    {'name':'dewei'},
    {'name':'xiaomu'}
]
users.sort(key=lambda x:x['name'])
print(users)