--[[
    1.字符串表示
        ·单引号间的一串字符
        ·双引号间的一串字符
        ·双方括号间的一串字符

    2.转义字符
        \a   响铃(BEL)
        \b   退格(BS) ，将当前位置移到前一列
        \f   换页(FF)，将当前位置移到下页开头
        \n   换行(LF) ，将当前位置移到下一行开头
        \r   回车(CR) ，将当前位置移到本行开头
        \t   水平制表(HT) （跳到下一个TAB位置）
        \v   垂直制表(VT)
        \\   代表一个反斜线字符''\'
        \'   代表一个单引号（撇号）字符
        \"   代表一个双引号字符
        \0   空字符(NULL)
        \ddd 1到3位八进制数所代表的任意字符
        \xhh 1到2位十六进制所代表的任意字符

    3.字符串操作
        1)string.sub(s, i [, j])
            ·s -- 要截取的字符串
            ·i -- 截取开始位置
            ·j -- 截取结束位置，默认为 -1，最后一个字符
        2)string.upper(argument)   字符串全部转为大写字母
        3)string.lower(argument)   字符串全部转为小写字母
        4)string.reverse(arg)   字符串反转
        5)string.len(arg)   计算字符串长度
        6)string.rep(string, n)   返回字符串string的n个拷贝
        7)..   连接两个字符串
        
    4.格式化 string.format(...)   返回一个类似printf的格式化字符串
        %c -- 接受一个数字, 并将其转化为ASCII码表中对应的字符
        %d, %i -- 接受一个数字并将其转化为有符号的整数格式
        %o -- 接受一个数字并将其转化为八进制数格式
        %u -- 接受一个数字并将其转化为无符号整数格式
        %x -- 接受一个数字并将其转化为十六进制数格式, 使用小写字母
        %X -- 接受一个数字并将其转化为十六进制数格式, 使用大写字母
        %e -- 接受一个数字并将其转化为科学记数法格式, 使用小写字母e
        %E -- 接受一个数字并将其转化为科学记数法格式, 使用大写字母E
        %f -- 接受一个数字并将其转化为浮点数格式
        %g(%G) -- 接受一个数字并将其转化为%e(%E, 对应%G)及%f中较短的一种格式
        %q -- 接受一个字符串并将其转化为可安全被Lua编译器读入的格式
        %s -- 接受一个字符串并按照给定的参数格式化该字符串
        细化格式，可以在%号后添加参数. 参数将以如下的顺序读入
        (1) 符号: 一个+号表示其后的数字转义符将让正数显示正号. 默认情况下只有负数显示符号
        (2) 占位符: 一个0, 在后面指定了字串宽度时占位用. 不填时的默认占位符是空格<如果字符串达不到宽度就用0/空格占位>
            date = 2; month = 1; year = 2014
            print(string.format("日期格式化 %02d/%02d/%03d", date, month, year))
        (3) 对齐标识: 在指定了字串宽度时, 默认为右对齐, 增加-号可以改为左对齐
        (4) 宽度数值
        (5) 小数位数/字串裁切: 在宽度数值后增加的小数部分n, 若后接f(浮点数转义符, 如%6.3f)则设定该浮点数的小数只保留n位, 若后接s(字符串转义符, 如%5.3s)则设定该字符串只显示前n位
    
    5.字符串与整数相互转换
        string.char(arg)   将整型数字转成字符并连接，对应askii码
        string.byte(arg[,int])    byte 转换字符为整数值(可以指定某个字符，默认第一个字符)

    6.匹配模式
        1)string.find(str, substr, [init, end])   在一个指定的目标字符串 str 中搜索指定的内容 substr，如果找到了一个匹配的子串，就会返回这个子串的起始索引和结束索引，不存在则返回 nil
        2)string.gmatch(str, pattern)   回一个迭代器函数，每一次调用这个函数，返回一个在字符串 str 找到的下一个符合 pattern 描述的子串。如果参数 pattern 描述的字符串没有找到，迭代函数返回nil
        3)string.gsub(mainString,findString,replaceString,num)   在字符串中替换
            mainString -- 要操作的字符串
            findString -- 被替换的字符
            replaceString -- 要替换的字符
            num -- 替换次数（可以忽略，则全部替换）
        4)string.match(str, pattern, init)   只寻找源字串str中的第一个配对. 参数init可选, 指定搜寻过程的起点, 默认为1
           在成功配对时, 函数将返回配对表达式中的所有捕获结果; 如果没有设置捕获标记, 则返回整个配对字符串. 当没有成功的配对时, 返回nil
        .(点): 与任何字符配对
        %a: 与任何字母配对
        %c: 与任何控制符配对(例如\n)
        %d: 与任何数字配对
        %l: 与任何小写字母配对
        %p: 与任何标点(punctuation)配对
        %s: 与空白字符配对
        %u: 与任何大写字母配对
        %w: 与任何字母/数字配对
        %x: 与任何十六进制数配对
        %z: 与任何代表0的字符配对
        %x(此处x是非字母非数字字符): 与字符x配对. 主要用来处理表达式中有功能的字符(^$()%.[]*+-?)的配对问题, 例如%%与%配对
        [数个字符类]: 与任何[]中包含的字符类配对. 例如[%w_]与任何字母/数字, 或下划线符号(_)配对
        [^数个字符类]: 与任何不包含在[]中的字符类配对. 例如[^%s]与任何非空白字符配对

]]

-- 字符串表示
print("------------------------------------------------")
string1 = "Lua"
print("\"字符串 1 是\"",string1)
string2 = 'runoob.com'
print("字符串 2 是",string2)
string3 = [["Lua 教程"]]
print("字符串 3 是",string3)

-- 字符串操作
print("------------------------------------------------")
print(string.sub("Lua",2,3))
print(string.upper("Lua"))
print(string.lower("Lua"))
print(string.reverse("Lua"))
print(string.len("Hello Lua user"))
print(string.rep("Lua", 5))

-- 格式化
print("------------------------------------------------")
print(string.format("the value is %d",4))
date = 1; month = 1; year = 2014
print(string.format("日期格式化 %02d/%02d/%03d", date, month, year))   
print(string.format("%.4f",1/3))
print(string.format("%08f",13))   -- 浮点数会将0补充在小数点后
print(string.format("%8s","Lua"))   -- 字符串会将space补充在前方，表示有8为，用空格填充
print(string.format("%08s","Lua"))   -- 浮点数会将0补充在小数点后
print(string.format("%6.3f", 13))   -- 输出13.000，小数点前表示总体的位数
print(string.format("%5.3s", "monkey"))   -- 输出  mon, 小数点后表示位数，因为总体为5位，所以占据两位空格

-- 字符串与整数相互转化
print("------------------------------------------------")
print(string.byte("Lua"))   -- 转换第一个字符
print(string.byte("Lua",3))   -- 转换第三个字符
print(string.byte("Lua",-1))   -- 转换末尾第一个字符，-表示从末尾开始
print(string.byte("Lua",2))   -- 转换第二个字符
print(string.byte("Lua",-2))   -- 转换末尾第二个字符
print(string.char(97))   -- 整数 ASCII 码转换为字符

-- 匹配模式
print("------------------------------------------------")
print(string.find("Hello Lua user", "Lua", 1))
print(string.gsub("aaaa","a","z",3))
for word in string.gmatch("Hello Lua user", "%a+") do 
    print(word) 
end
string.match("I have 2 questions for you.", "%d+ %a+")





