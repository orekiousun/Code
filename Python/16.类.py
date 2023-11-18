# coding:utf-8

"""
    1.面向对象:
    ·利用面向对象的属性与方法去进行编程的过程
    ·自定义对象数据类型就是面向对象中的类（class）的概念
    类的关键字class:class来声明类，类的名称首字母大写，多单词情况下每个单词首字母大写
    
    2.类的定义：
        class Name(object):
            attr=something
            def func(self):
                do
    
    3.类的使用：
        class Person(object):
            name='xiaomu'
            def dump(self):
                print(f'{self.name} is dumping')
        xiaomu=Person()     # 类的实例化
        print(xiaomu.name)  # 通过实例化进行属性调用
        xiaomu.dump()       # 通过实例化进行函数调用
    
    4.类的参数self:
    ·self是必传的参数，必须放在第一个参数位置
    ·self是一个对象，他代表实例化变量本身
    ·self可以直接通过点来定义一个类变量
    ·self中的变量与含有self参数的函数可以在类中的任何一个函数内随意调用
    ·非函数中定义的变量在定义的时候不用self
    
    5.类的构造函数：类中的一种默认函数，用来将类实例化的同时，将参数传入类中
    构造函数的创建方法
        def __init__(self,a,b):  # 注意init前后是两个下划线
            self.a=a
            self.b=b
        例子：
        class Test(object):
            def _init_(self,a):
                self.a=a
            def run(self):
                print(self.a)
        t=Test(1)
        t.run()
    
    6.私有函数与私有变量：
    ·无法通过被实例化后的对象调用的类中的函数与变量
    ·类内部可以调用私有函数与变量
    ·只希望类内部业务调用，不希望被使用者调用
    私有函数与变量的定义方法：在变量或函数前添加两个下横向，后边无需添加
    
    7.封装:将不对外的私有属性或方法通过可对外使用的函数而使用，保护隐私，明确区分内外
    
    8.装饰器：
        ·也是一种函数
        ·可以接受函数作为参数
        ·可以返回函数
        ·接收一个函数，内部对其进行处理，然后返回一个新函数，动态的增强函数功能
        ·将c函数在a函数中执行，在a函数中可以选择执行或不执行c函数，也可以对c函数的结果进行二次加工
            def out(func_args): 外围函数
                def inter(*args,**kwargs): 内嵌函数
                    return func_args(*args,**kwargs)
                return inter 外围函数返回内嵌函数
      装饰器的用法：
        ·将被调用的函数直接作为参数传入装饰器的外围函数括弧
        ·将装饰器与被调用函数绑定在一起 
        ·通过@符号+装饰器函数放在被调用函数的上一行，被调用函数正常定义，只需要直接调用被执行函数即可
    
    9.类的常用装饰器
        1-classmethod:将类函数可以不经过实例化而被直接调用
            @classmethod
            def func(cls...):
                do
            # cls替代类函数中的self，变为cls代表当前操作是类
        2-staticmethod:将类函数可以不经过实例化而直接被调用，被该装饰器调用的函数不许传递self或cls，且无法在该函数内调用其他类函数或变量
            @staticmethod
            def func(...):
                do
            # 函数体内无cls或self
        3-property:将类函数的执行免去括弧，类似于调用属性（变量）
            @property
            def func(self):
                do
            # 调用时直接t.func,免去括弧
            # @func.setter
            # def name(self,value): # value为传入的新参数
            #     self.a(某私有变量)=value # 可通过此方式强制传参
    
    10.类的继承:
        1-继承:
        ·通过继承基类来得到基类的功能
        ·把继承的类称为父类或基类，继承者被称作子类
        ·代码的重用
        2-父类与子类的关系:
        ·子类拥有父类的所有属性和方法
        ·父类不具备子类自有的属性和方法
        3-类的继承使用方法:
        ·定义子类时，将父类传入子类参数内
        ·子类实例化可以调用自己与父类的函数与变量
            class Parent(object):
                def func:
                    do
            class Child(Parent):
                def func2:
                    do
            # 其实object就是一个通用的父类
    
    11.super:python子类继承父类的方法使用的关键字，当子类继承父类后，就可以使用父类的方法
        class Parent(object):
            def __init__(self):
                print('i am parent')
        class Child(Parent):
            def __init__(self):
                print('i am child')
                super(Child,self).__init__()
    
    12.类的多重继承:子类可以同时继承多个父类
        clss Child(Parent1,Parent2,Parent3)
        ·将被继承的类放入子类中，用逗号隔开
        ·从左到右依次继承
    
    13.__setattr__:拦截当前类中不存在的属性与值
        def __setattr__(self,key,value):
            self.__dict__[key]=value
        # key当前的属性名
        # value当前的参数对应值
        举例:
        class Test(object):
            def __setattr__(self,key,value):
                if key not in self.__dict__:
                    self.__dict__[key]=value
        t=Test()
        t.name='dewei'
        print(t.name) # 自动为dewei添加了key值

    14.__call__:本质是将一个类变成一个函数
        def __call__(self,*args,**kwargs):
            print('call will start')
        举例:
        class Test(object):
            def __call__(self,**kwargs):
                print('args is {}'.format(kwargs))
        t=Test()
        t(name='dewei') # 直接把t作为函数使用
"""
# 测试类的使用
class Person(object):
    # name=None
    # age=None
    # 通过构造函数定义name和age
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def run(self):
        print(self.name,'在奔跑')
    def jump(self):
        print(self.name,'在跳跃')
    def work(self):
        self.run()
        self.jump()
if __name__=='__main__':
    xiaomu=Person(name='xiaomu',age=18)
    xiaomu.run()
    xiaomu.jump()
    dewei=Person(name='dewei',age=18)
    dewei.jump()   # 赋值给xiaomu只改变xiaomu这个类
    dewei.top=174  # 可以通过此方式直接为类添加属性
    print(dewei.top)
    dewei.work()
    xiaobai=Person(name='xiaobai',age=10)
    xiaobai.jump()
    xiaobai.age=17
    print(xiaobai.age)  # 也可以通过此方式强制修改值

# 测试私有函数与私有变量
class Cat(object):
    __cat_type='cat' # 私有属性，类中的函数可以调用，但是不能从外部直接调用
    def __init__(self,name,sex):
        self.name=name
        self.__sex=sex
    def run(self):
        result=self.__run()
        print(result)
        # pass # 占位关键字,空函数会报错
    def __run(self):
        return f'{self.__cat_type},xiaomao{self.name}{self.__sex}开心的奔跑着'
    def jump(self):
        result=self.__jump()
        print(result)
    def __jump(self):
        return f'{self.__cat_type},xiaomao{self.name}{self.__sex}开心的跳跃着'
if __name__=='__main__':
    cat=Cat(name='xiaomao',sex='girl')
    cat.run()
    cat.jump()
    # cat.__jump() # 无法调用私有函数
    print(cat._Cat__jump()) # 可通过此方法强制调用私有函数
    # print(cat.__sex) # 无法调用私有属性
    print(cat._Cat__sex) # 可通过此方法强制调用私有属性

# 测试装饰器
def check_str(func):
    print('func:',func)
    def inner(*args,**kwargs):
        print('args:',args,kwargs)
        result=func(*args,**kwargs)
        if result=='ok':
            return 'result is %s' % result
        else:
            return 'result is failed:%s' % result
    return inner
@check_str
def test(data):
    return data
if __name__=='__main__':
    result=test('no')
    print(result)

class Test(object): 
    def __init__(self,a):
        self.a=a
# 测试property
    @property
    def run(self): # 不使用classmethod时
        print('run')

# 测试property强制传参
    @property
    def name(self):
        return self.a
    @name.setter
    def name(self,value): 
        self.a=value # 可通过此方式强制传参
    
# 测试classmethod
    @classmethod 
    def jump(cls): # 使用classmethod时
        print('jump')

# 测试staticmethod
    @staticmethod
    def sleep(): 
        print('i want sleep')
if __name__=='__main__':
    t=Test('a')
    Test.jump() # 不需要进行实例化，直接调用函数即可
    # 不能在classmethod的装饰器中调用self的函数，因为没有实例化过后的参数，但是可以在未被装饰过的函数中调用被classmethod装饰后的函数
    Test.sleep() # 测试staticmethod
    t.run # 不用写括弧
    t.name='xiaomu'
    print(t.name)
    t.sleep() # staticmethod，classmethod也可在实例化后调用

# 测试类的继承
class Parent(object):
    def __init__(self,name,sex):
        self.name=name
        self.sex=sex
    def talk(self):
        return f'{self.name} are walking'
    def sex(self):
        if self.sex=='boy':
            return f'{self.name} is a boy'
        else:
            return f'{self.name} is a girl'
class Child(Parent):
    def football(self):
        return f'{self.name} are playing football'
if __name__=='__main__':
    child=Child('xiaomu','boy')
    print(child.talk())
    print(child.football())

# 测试super以及传参方法
class Parent_2(object):
    def __init__(self,p):
        print('i am  %s' % p)
class Child_2(Parent_2):
    def __init__(self,c,p):
        print('i am  %s' % c)
        super(Child_2,self).__init__(p) # 在这里传入父类的参数
if __name__=='__main__':
    c=Child_2(c='Child',p='Parent')

# 测试多重继承
class Tool(object):
    def work(self):
        return 'tool work'
    def car(self):
        return 'cai will run'
class Food(object):
    def work(self):
        return 'food work'
    def cake(self):
        return 'i like cake'
class Person(Tool,Food):
    pass
if __name__=='__main__':
    p=Person()
    p_car=p.car()
    p_cake=p.cake()    
    print(p_car)
    print(p_cake)
    print(p.work()) # 两个父类同时有一样的函数时，左边的类会先被继承，函数先发挥作用

# 测试__setattr__,__call__
class Test2(object):
    name='None'
    def __setattr__(self,key,value):
        print(key,value)
        if key not in self.__dict__:
            self.__dict__[key]=value
        print(self.__dict__)
    def __call__(self,a):
        print('call will start')
        print(a)
if __name__=='__main__':
    t=Test2()
    t.name='xiaomu' 
    t('dewei')

