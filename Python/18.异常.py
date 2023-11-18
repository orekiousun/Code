# coding:utf-8

"""
    1.异常与异常处理
    ·异常就是错误
    ·异常会导致程序崩溃并停止运行
    ·能监控并捕获到异常，将异常部位的程序进行修理使得程序继续正常运行

    2.异常的语法
        try:
            <代码块1>被try关键字检查并保护的业务代码
        except<异常的类型>:
            <代码块2>代码块1出现错误后执行的代码块
        举例：
        try:
            1/0
        except:
            print('0不能被1整除')
            print('程序将继续执行')

    3.捕获通用异常:
    ·无法确定是哪种异常的情况下使用的捕获方法
        try:
            <代码块>
        except Exception as e:
            <异常代码块>

    4.捕获具体异常
    ·确定哪种异常的情况下使用的捕获方法
        try:
            <代码块>
        except <具体异常类型> as e:
            <异常代码块>
        举例：
        try:
            1/0
        except ZeroDivisionError as e:
            print(e)

    5.捕获多种异常
        solution1:
        try:
            print('try start')
            res=1/0
            print('try finish')
        except ZeroDivisionError as e:
            print(e)
        except Exception as e: # 可以有多个except
            print('this is a public except ,bug is: %s' % e)
        ·当ecxept代码块有多个的时候，当捕获到第一个后，不会继续往下捕获
        solution2:
        try:
            print('try start')
            res=1/0
            print('try finish')
        except (ZeroDivisionError,Exception) as e:
            print(e)
        ·当except代码后边的异常类型使用元组包裹起来，捕获到哪种抛哪种

    6.常见异常类型
    Excption                  通用异常类型
    ZeroDivisionError         不能整除0
    AttributeError            对象没有这个属性
    IOError                   输入输出操作失败
    IndexError                没有当前索引
    KeyError                  没有这个键值（key）
    NameError                 没有这个变量（未初始化对象）
    SynataxError              phython语法错误
    SystemError               解释器的系统错误 
    ValueError                传入的参数错误
    TypeError                 调用函数时传参错误或者没有传参

    7.finally
    ·无论是否发生异常，一定会执行的代码块
    ·在函数中，即使在try或except中进行了return也依然会执行finally语法块
    ·try语法至少要伴随except或finally中的一个
        try:
            <语法块>
        except:
            <语法块>
        finally:
            <语法块>

    8.抛出异常
    raise:将信息以报错的形式抛出
        raise 异常类型(message)
        # message:错误信息
    raise ValueError('主动抛出一个异常')

    9.自定义异常
    ·继承基类--Exception
    ·在构造函数中定义错误信息
    class NewError(Exception):
        def __init__(self,message):
            self.message=message
    def test():
        raise NewError('this is a bug')
    try:
        test()
    except Exception as e:
        print(e)
    >>result:this is a bug

"""
# 测试通用异常
def upper(str_data):
    new_str=''
    try:
        new_str=str_data.upper()
    except Exception as e:
        print('程序出错{}'.format(e))
    return new_str
result=upper(1)
print('result=',result)

# 测试具体异常
def test():
    try:
        print('try test')
        1/0
        print('hello')
    except ZeroDivisionError as e:
        print(e)
test()

# 测试多个异常
def test2():
    try:
        print('try test')
        print(name)
    except (ZeroDivisionError,NameError) as e:
        print(e)
        print(type(e))
test2()

# 测试常见异常类型
# AttributeError
class Test(object):
    pass
t=Test()
try:
    t.name
except AttributeError as e:
    print(e)

# KeyError
d={'name':'xiaomu'}
try:
    d['age']
except KeyError as e:
    print('没有对应的key:',e)

# IndexError
l=[1,2,3,4]
try:
    l[5]
except IndexError as e:
    print(e)

# ValueError
name='dewei'
try:
    int(name)
except ValueError as e:
    print(e)

# TypeError
def test2(a):
    return a
try:
    test2()
except TypeError as e:
    print(e)

# 测试finally
def test3():
    try:
        1/0
    except Exception as e:
        print(e)
    finally:
        return 'finally'

result=test3()
print(result)
def test4():
    try:
        1/0
    except Exception as e:
        return e
    finally:
        print('finally') # 这里即使前面返回了finally依然执行

result=test4() # 由于test4先执行，所以先打印出finally
print(result)
def test5():
    try:
        1/0
    except Exception as e:
        print('1')
        return e
    finally:
        print('2')
        return 'finally'

result=test5()
print(result) # 最终返回了finally中的return
def test6():
    try:
        1/0
        return 'try'
    except Exception as e:
        print('1')
        return e
    finally:
        print('2')
        return 'finally'

result=test6()
print(result) # 最终返回了finally中的return
def test7():
    try:
        print('0')
        1/0
        return 'try'
    except Exception as e:
        print('1')
        return e
    finally:
        print('2')

result=test7()
print(result) # 最终返回了finally中的return
# 最终得出解过，函数的返回值取决于函数最后执行的语句的返回值
# try语法块一旦出现错误，就停止执行

# 测试抛出异常
def test8(number):
    if number==100:
        raise ValueError('number!=100')
    return number

# result=test8(100)
# print(result)
def test9(number):
    try:
        return test8(number) # 发现异常
    except ValueError as e:
        return e

result=test9(100)
print(result)
def test10(name):
    if name=='dewei':
        raise Exception('dewei不可以被填写')
    return name

# test10('dewei')

# 测试自定义异常
class NumberLimitError(Exception):
    def __init__(self,message):
        self.message=message

class NameLimitError(Exception):
    def __init__(self,message):
        self.message=message

def test11(number):
    if number>100:
        raise NumberLimitError('this is a number bug')
    return number

def test12(name):
    if name=='dewei':
        raise NameLimitError('this is a name bug')
    return name

try:
    test11(101)
except NumberLimitError as e:
    print(e)
try:
    test12('dewei')
except NameLimitError as e:
    print(e)
# test12('dewei')

