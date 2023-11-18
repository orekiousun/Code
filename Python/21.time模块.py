# coding:utf-8


"""
    1.时间戳:1970年1月1日至今的总毫秒数
    ·用timestamp表示时间戳
    2.time模块及其函数
        1-时间处理，转换时间格式
        2-time:生成时间戳函数
            导入包:import time
            time.time
            # 返回一个秒级别的时间戳（浮点类型）
        2-localtime:获取本地时间函数
            导入包:import time
            time.localtime(timestamp)
            # timestamp:时间戳(可以不传)
            # tm_year四位年数 tm_mon月 tm_mday日 ...
        3-sleep:暂停函数
            导入包:import time
            time.sleep(second)
            # second代表希望程序性暂停的秒数
        4-time中的strftime:时间对象转字符串
            导入包:import time 
            time.strftime(format,t)
            # format:格式化规范
            # t:time.localtime对应的时间类型 实质是转换localtime的变量类型为标准时间标准
            # str_time=time.localtime('%Y-%m-%d %H:%M:%S',time.localtime())
        5-time中的strptime:时间字符串转时间
            导入包:import time
            time.strptime(time_str,format)
            # time_str:符合时间标准的字符串
            # format:确保与time_str一致的格式化标准
            # time.strptime('2020-12-12','%Y-%m-%d')
    3.datetime包：
        1-timestamp:时间戳
            导入包:import datetime
            now=datetime.datetime.now()
            datetime.datetime.timestamp(now) # timestamp是时间戳的意思
            # now:datetime的时间对象
        2-fromtimestamp:时间戳转时间对象，会返回一个datetime日期对象
            导入包:import datetime
            datetime.datetime.fromtimestamp(timestamp)
            # timestamp:时间戳
"""
import time
import datetime

# 测试time
now=time.time()
print(now,type(now))
# 测试localtime
time_obj=time.localtime(now)
print(time_obj,type(time_obj))
current_time=time.localtime() # 也可以不用传入参数
print(current_time,type(current_time))
before=now-100000
before_time=time.localtime(before)
print(before_time)
# 测试sleep
# for i in range(10):
#     print(i)
#     time.sleep(0.5) # 每循环一次暂停0.5s
# 测试datetime
now=datetime.datetime.now()
datetime_now=datetime.datetime.timestamp(now)
print(datetime_now)
datetime_time=datetime.datetime.fromtimestamp(datetime_now)
print(datetime_time)