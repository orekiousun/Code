# coding:utf-8

"""
    1.索引:列表，字符串，元组存在索引，从最左边开始记录的位置就是索引
        索引用数字表示，从0开始，最大索引就是他们的长度-1
        numbers[5]
    2.切片:对一定范围内元素进行访问
        切片通过冒号在中括号内把相隔的两个索引查找出来
        numbers[0:10]
        ·切片规则为左含右不含，即访问0:10就会访问0-9的索引
        ·通过索引生成的列表是一个新的列表
        ·-1也可代表最后一个元素，-2倒数第二个，依次类推
    3.列表的索引获取与修改
        list[index]=new_item
        ·数据的修改只能在存在的范围内
        ·列表无法通过添加新的索引的方式赋值
    4.index函数：返回元素所在的索引位置
        numbers.index('number')
    5.pop函数：通过索引删除并获取列表元素，索引不存在报错
        numbers.pop(index) # 返回被删除的值
    6.del函数：删除索引，直接删除，没有返回值，索引不存在报错
        numbers.pop(index)
    7.索引切片在元组中的特殊性
    ·可以和列表一样获取索引和索引切片
    ·元组函数index和；列表用法完全一致
    ·无法通过索引修改与删除元素    
    8.字符串的索引与获取：字符串每个字符对应一个索引
    ·字符串无法通过索引切片修改
    ·find/index函数：获取元素的索引位置
        string.index(item)
        string.find(item)
        区别：find找不到返回-1，index找不到报错
"""
# 测试列表索引
numbers=[1,2,3,4,5,6,7,8,9,10]
print('获取列表完整数据：',numbers[:])
print('获取列表完整数据：',numbers[0:])
print('获取列表除最后一个元素所有元素：',numbers[:-1]) # -1表示为最大索引，右不含丢失最后一位数
print('获取列表部分数据：',numbers[0:8])
print('列表的反序：',numbers[::-1])
print('列表的反向获取：',numbers[-3:-1])
print('步长获取切片:',numbers[0:8:2]) # 表示范围是0-8，每次跳跃两个
print('切片生成空列表：',numbers[0:0])
numbers[3]='#'
print(numbers)
numbers[2:5]=['#','#','#'] # 修改2-4，左右数值量要相同
print(numbers)
print(numbers.index('#')) # 只会返回第一个位置
print(numbers.pop(8))
print(numbers)
del(numbers[6])
print(numbers)
# 测试字符串
name='my name is dewei'
print(name.find('dewei')) # 获取第一个位置
new_name=name[::-1] # 字符串反序
print(new_name)