# coding:utf-8

import os


"""
    1.[]处理法
        ·字典没有索引
        ·dict['name']='dewei'
        ·添加或修改，根据key是否存在决定
    2.update:添加新的字典，如新的字典中有和原字典相同的key，则key的value会被新字典的value覆盖
        dict.update(new_dict) # new_dict为新的字典
    3.setdefault:获取某个key的value，若key不存在在字典中，则会添加key并将value设为默认值
        dict.setdefault(key,value) # 返回的是key对应的value值，若key存在则value不会有任何作用
    4.keys:获取当前字典中所有的key值
        dict.keys() # 返回一个key集合的伪列表，伪列表不具有列表的所有功能
        key_list=list(my_dict.keys()) # 这样可以把伪列表变成真列表
    5.values:获取当前字典中所有的value值
        dict.values() # 返回一个values的伪列表
        values_list=list(my_dict.value()) # 这样可以把伪列表变成真列表
    6.items():以列表返回可遍历的(键, 值)元组数组,可以用于for来循环遍历
        dict = {1:2,'a':'b','hello':'world'}
        print(dict.items())
        <<输出结果dict_items([(1, 2), ('a', 'b'), ('hello', 'world')])
        for循环使用时：
            for key,value in dict.items():        
    7.字典key的获取
        ·[]的获取方法
            name=my_dict['name'] # name为字典中一个key
        ·get的获取方法
            name=dict.get(key,default) # default默认为None
        ·两者区别
            ·[]获取不到数据报错
            ·get获取不到数据会返回默认值
    8.clear:清空当前字典中所有数据
        dict.clear() # 无参数，无返回值
    9.pop:删除字典指定key
        dict.pop(key) # 返回这个key对应的值(value)
    10.del:删除指定的key或整个字典
        del dict['key']
        del dict
    12.copy:将当前字典复制出一个新的字典
        new_dict=old_dict.copy()
    12.成员运算符 # 只能判断key值
    ·in/not in:'key'in dict
    ·get:dict.get('key')
    13.popitem:删除字典里末尾一组键值对并返回
        dict.popitem() # 返回被删除的键值对，返回一个元组，0索引是key，1索引是value
"""
# 测试[]处理法
user={'username':'dewei','age':33}
user['top']=174
print(user)
user['username']='xiaomu'
print(user)
# 测试update
xiaomu={'username':'xioamu','age':18,'top':160}
user.update(xiaomu)
print(user)
# 测试setdefault
value_01=user.setdefault('username','xiaoyun')
value_02=user.setdefault('birthday','2020-1-1')
print(user,value_01,value_02)
# 测试keys
project={'id':1,'name':'ipad','price':2200,'count':1000}
project_keys=project.keys()
key_list=list(project.keys())
print(type(key_list))
print(key_list)
print(key_list[0])
# 测试values
project_values=project.values()
values_list=list(project.values())
print(type(values_list))
print(values_list)
print(values_list[0])
print('{} | {} | {} | {} '.format(key_list[0],key_list[1],key_list[2],key_list[3]))
print('{} | {} | {} | {} '.format(values_list[0],values_list[1],values_list[2],values_list[3]))
# 测试[]与get
info={'name':'xiaomu','id':1,'password':123456}
print('name:',info['name'])
print('id:',info.get('id')) 
# 测试clear
dict_clear={'name':'xiaomu','id':1,'password':123456}
dict_clear.clear()
# print(dict_clear) 无法输出，已经被清除
# 测试pop
dict_pop={'name':'xiaomu','id':1,'password':123456}
print('id:',dict_pop.pop('id'))
print(dict_pop)
# 测试del
dict_del={'name':'xiaomu','id':1,'password':123456}
del dict_del['id']
print(dict_del)
del dict_del
# print(dict_del) 无法输出，已经被清除
# 测试copy
old_dict={'name':'xiaomu','id':1,'password':123456}
new_dict=old_dict.copy()
print(new_dict)
print(id(old_dict)==id(new_dict))
# 测试成员运算符
test_dict={'a':1,'b':2,'c':3}
print('a' in test_dict)
print(bool(test_dict.get('a')))
print('a' not in test_dict)
# 测试popitem
print(test_dict.popitem())
# 测试bool
a_1=1
a_2=0
print(bool(a_1))
print(bool(a_2))
print(bool(not a_2))
 