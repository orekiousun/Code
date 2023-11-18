# coding:utf-8


"""
    1.os包下可直接调用的函数
    getcwd 无参数 返回当前的路径 os.getcwd() 返回一个字符串
    listdir 参数为一个路径path 返回指定路径下所有的文件或文件夹 os.listdir('c://windows') 返回一个列表
    makedirs 参数为path，mode 创建多级文件夹 os.makedirs('d://imooc/py') 没有返回值
    removedirs 参数为path 删除多级文件夹 os.removedirs('d://immoc/py') 没有返回值
    rename 参数为oldname和newname os.rename('d://imooc','d://imoc') 没有返回值
    rmdir 参数为path 只能删除空文件夹 os.rmdir('d://imooc') 没有返回值
    2.os.path包下函数
    exists 参数为path 判断文件或路径是否存在 os.path.exists('d://') 返回bool类型
    isdir 参数为path 判断是否是路径 os.path.isdir('d://') 返回bool类型
    isabs 参数为path  判断是否是绝对路径 os.path.isabs('test') 返回bool类型
    isfile 参数为path 判断是否是文件 os.path.isfile('d://a.py') 返回bool类型
    join 参数为path，path* 路径与字符串合并 os.path.join('d://','test') 返回字符串
    split 参数为path 以最后一层路径为基准切割 os.path.split('d://test') 返回列表
    3.sys模块
    modules 无参数 py启动时加载的模块 sys.modules 返回列表 #没有括号,是属性不是函数
    path 无参数 返回当前py的环境路径 sys.path 返回列表 #没有括号,是属性不是函数
    exit arg(默认值为0) 退出程序 sys.exit() 没有返回值 
    getdefaultencoding 无参数 获取系统编码 sys.getdefaultencoding() 返回字符串
    platform 无参数 获取当前系统平台 sys.platform 返回字符串 #没有括号,是属性不是函数
    version 无参数 获取python平台 sys.version 返回字符串
    argv *args 获取外部程序参数 sys.argv 返回列表
"""
import os
import os.path
import sys
# 测试getcwd
current_path=os.getcwd()
print(current_path)
# 测试makedirs
new_path='%s/test1' % current_path
#os.makedirs(new_path)
# 测试listdir
data=os.listdir(current_path)
print(data)
#os.remove(new_path)
#os.rename('test1','test1_new') # 同级类文件夹可以不用书写完整路径
#os.rmdir('test1_new')
# 测试exists
if os.path.exists(new_path):
    print('new_path exists')
else:
    print('new_path do not exists')
# 测试isabs
print(os.path.isabs(current_path)) # 说明curren_path是一个绝对路径
# 测试join
new_path2=os.path.join(current_path,'test2')
print(new_path2)
# 测试split
print(os.path.split(new_path2))
new_path3=current_path+'/22.os包.py'
print(new_path3)
print(os.path.split(new_path3))
# 测试isfile
print(os.path.isfile(new_path3))
# 测试isdir
print(os.path.isdir(current_path)) 
# 测试modules
modules=sys.modules
print(modules)
# 测试path
path=sys.path
print(path)
# 测试exit
# 脚本结束后会自动触发sys.exit(),后面的程序不会执行
# 测试getdefaultencoding
code=sys.getdefaultencoding()
print(code)
# 测试platfrom
platform=sys.platform
print(platform)
# 测试version
version=sys.version
print(version)
# 测试argv
print(sys.argv)