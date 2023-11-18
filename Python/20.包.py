# coding:utf-8


"""
    1.强大的第三方包
    ·其他程序员写好的功能发布到网上
    ·提高开发效率
    ·利用pip与easy_install获取第三方包
        pip install 包名 # 安装
        pip uninstall 包名 # 删除
        pip install --trusted-host http://pypi.douban.com/simple/ ipython # 通过国内特定网站安装ipython
        easy_install 包名 # 使用easy_install安装
    ·第一个第三方包ipython(一般还是用于调试环境，正常执行还是可以用解释器)
        1-python的交互式shell，支持变量自动补全，自动缩进
        2-在终端中输入pip install ipython
        3-import导入时输入import按住tab键可以显示后方可以出现的函数，按住tab也可以自动补齐
    2.datetime
    ·日期与时间结合体
    ·获取当前时间
    ·获取时间间隔
    ·将时间对象转化成字符串
    ·将字符串转化成时间类型
        1-获取当前时间
            ·导入包与模块
                from datetime import datetime
                import datetime
            ·使用方法
                第一种方法导入的：datetime.now()
                第二种方法导入的：datetime.datetime.now()
        2-获取时间间隔
            ·导入包与模块
                from datetime import datetime
                from datetime import timedelta
            ·使用方法
                timeobj=timedelta(days=0,seconds=0,microseconds=0,milliseconds=0,minutes=0,hours=0,week=0)
        3-strftime:时间对象转字符串
            date_str=now.strftime(format) # format使用一般的时间规格为'%Y-%m-%d %H:%M:%S'
            举例：
            from datetime import datetime
            date=datetime.now()
            str_date=date.strftime('%Y-%m-%d %H:%M:%S')
            print(str_date)
        4-strptime:时间字符串转时间
            datetime.strptime(tt,format)
            # tt符合时间格式的字符串
            # format:tt时间字符串匹配规则
            from datetime import datetime
            str_date='2021-10-10 13:13:13'
            date_obj=datetime.strptime(str_date,'%Y-%m-%d %H:%M:%S')
            print(date_obj)
            %Y年份  %m月份  %d月中的某一天  %H一天中的第几个小时（24h制）
            %i一天中的第几个小时（12h制度）  %M当前的第几分  %S当前分的第几秒  %f当前秒的第几毫秒
            %a简化的星期，如星期三Wen  %A完整的星期，如星期三Wednesday  %b简化的月份，如二月Feb  %B完整的月份，如二月February
            %c本地日期和时间，如Web Feb 5 10:14:49 2020  %p显示上午还是下午，AM上午，PM下午 %j一年中的第几天  %U一年中的星期数
            

"""


from datetime import datetime # 内置包，被安装在指定目录下，可以直接获取
from datetime import timedelta
date=datetime.now()
before_one_day=timedelta(days=1)
yesterday=date-before_one_day
str_date=date.strftime('%Y-%m-%d %H:%M:%S')
str_date2='2021-10-10 13:13:13'
date_obj=datetime.strptime(str_date2,'%Y-%m-%d %H:%M:%S')
print(date_obj,type(date_obj))
print(str_date,type(str_date))
print(datetime.now(),type(datetime.now()))
print(yesterday)