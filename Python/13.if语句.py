# coding:utf-8


"""
    if语句功能:判断一个命题的真实性，如果命题为真则执行if的逻辑语句
        if bool_result: # 语法块
            do          # 业务代码块，注意缩进
        # bool_result:判断结果的真假，bool类型
        # do:如果bool_result为true时执行任意python代码
        # 返回值：if属于关键字，没有返回值
        dewei_status='hunger'
        if dewei_status=='hunger':
            print('xioamu invites dewei to dinner')
    else语句功能:if条件不满足时执行另一个代码块的入口
        if bool_result:
            do        
        else:
            elsedo # else语法块需要缩进，缩进等级与if一致，一样没有返回值
    elif语句功能:（或者如果）对于命题的非第一次的多种判断，每一种判断条件对应一组业务代码
        if bool_result:
            do        
        elif bool_result:
            do
        elif bool_result:
            do
        else:
            do
        

"""
info='my name is xiaomu'
info_list=info.split()
if info_list[3]=='xiaomu':
    info_list[3]='dewei'
print(info_list)
info=' '.join(info_list)
print(info)
info='my name is dewei i am a pythoner i love python'
info_list=info.split()
if info_list[0]=='python'or info_list[0]=='i': # or表示或
    info_list[0]='*'
if info_list[1]=='python'or info_list[1]=='i':
    info_list[1]='*'
if info_list[2]=='python'or info_list[2]=='i':
    info_list[2]='*'
if info_list[3]=='python'or info_list[3]=='i':
    info_list[3]='*'
if info_list[4]=='python'or info_list[4]=='i':
    info_list[4]='*'
if info_list[5]=='python'or info_list[5]=='i':
    info_list[5]='*'
if info_list[6]=='python'or info_list[6]=='i':
    info_list[6]='*'
if info_list[7]=='python'or info_list[7]=='i':
    info_list[7]='*'
if info_list[8]=='python'or info_list[8]=='i':
    info_list[8]='*'
if info_list[9]=='python'or info_list[9]=='i':
    info_list[9]='*'
if info_list[10]=='python'or info_list[10]=='i':
    info_list[10]='*'
print(' '.join(info_list))
info='my name is dewei'
print(len(info))
if len(info)>10 and len(info)!=16: # and表示且
    print(info.replace('dewei','xioamu'))
url='https://www.imooc.com'
if 'www.imooc.com' in url:
    print('true')
else:
    print('false')
name='dewei'
if name=='xiaomu':
    print('第一次判断正确')
elif name=='xiaoming':
    print('第二次判断正确')
elif name=='dewei':
    print('第三次判断正确')
number=10
if number>10:
    print('number>10')
elif 5<number<10:
    print('5<number<10')
elif number==10:
    print('number=10')
