using System;

namespace Day02
{
    class Program
    {
        static void Main(string[] args)
        {
            string gunName = "AK47";
            int size = 42;
            int current = 32;


            // 输出方式
            // 在字符串中插入变量
            Console.WriteLine("--------------- 变量 ---------------");
            Console.WriteLine("枪的名称：" + gunName + " 弹夹容量：" + size + " 子弹数量：" + current);
            // 占位符{位置的编号} 如果编号大于参数列表长度，则异常
            string str = string.Format("枪的名称为：{0}，容量为：{1}，子弹数为：{2}",gunName, size, current);
            Console.WriteLine(str);
            // 也可以直接这么写，但是有很强的局限性
            Console.WriteLine("枪的名称为：{0}，容量为：{1}，子弹数为：{2}", gunName, size, current);
            Console.WriteLine("金额：{0:c}", 10);   // 接后缀:c显示货币符号
            // 取有效数字
            Console.WriteLine("{0:d3}", 5);    // 接后缀:dn只显示n位
            Console.WriteLine("{0:d3}", 15);   // 接后缀:dn只显示n位
            // 选择小数精度
            Console.WriteLine("{0:f3}", 0.1564);   // 接后缀:fn只显示n位小数精度
            Console.WriteLine("{0:f3}", 15);       // 接后缀:fn只显示n位小数精度
            // 百分比显示
            Console.WriteLine("{0:p}", 0.15);       // 接后缀:p以百分比显示
            Console.WriteLine("{0:p4}", 0.15);       // 接后缀:pn只显示n位百分比
            // 转义字符\：显示引号
            Console.WriteLine("这是\"Unity\"");
            char c = '\'';     // 单引号'
            char c3 = '\0';    // 空字符
            string s = "";     // 空字符串
            Console.WriteLine(c);
            Console.WriteLine(c3);
            Console.WriteLine(s);
            Console.WriteLine("hello\nhello");   // 换行
            Console.WriteLine("hello\thello");   // 制表符




            // 运算符
            Console.WriteLine("--------------- 运算符 ---------------");
            // 赋值运算符
            int n1 = 5, n2 = 2;   // 同时声明赋值多个
            // 计算符
            int r1 = n1 + n2;
            int r2 = 5 / 2;
            float r3 = n1 / n2;
            int r4 = n1 % n2;   // 取模 -> 用于判断能否被整除，或获取个位数字
            bool r5 = n1 % 2 == 0;
            Console.WriteLine(r1 + " " + r2 + " " + r3 + " " + r4 + " " + r5);
            // 比较运算符> < >= <= == !=
            bool r6 = n1 == n2;
            string s1 = "我", s2 = "你";
            bool r7 = s1 == s2;
            bool r8 = !true;
            bool r9 = true && false;
            bool r10 = true || false;
            Console.WriteLine(r6 + " " + r7 + " " + r8 + " " + r9 + " " + r10);
            // 逻辑运算符 && || ！ 且或非
            // 且 一假全假     或 一真全真
            // 快捷运算符
            int num01 = 1;
            num01 += 5;
            // 一元运算符++ --
            int num02 = 1, num03 = 2, num04 = 0;
            num02++;   // 后加之后再使用
            --num03;   // 先减之后再使用
            Console.WriteLine(num01 + " " + num02 + " " + num03 + " " + num04++ + " " + ++num04);
            // 三元运算符 - 三目运算符
            string m = 1 > 2 ? "yes" : "no";
            Console.WriteLine(m);
            // 优先级：满足运算规律
            int r11 = 1 + 2 * 4;
            Console.WriteLine(r11);



            // 数据类型转换
            Console.WriteLine("--------------- 数据类型转换 ---------------");
            // 1.Parse转换：将string转换为其他数据类型，代转数必须像该数据类型
            string strNumber = "18";
            int num001 = int.Parse(strNumber);
            float num002 = float.Parse(strNumber);

            // 2.ToString转换：任意类型转化为string
            int number = 18;
            string str01 = number.ToString();

            // 输入一个四位整数，计算每位相加和
            // 法一 数学方法
            Console.WriteLine("输入一个四位数数字：");
            string input = Console.ReadLine();
            int intInput = int.Parse(input);
            int strNum01 = intInput % 10;
            int strNum02 = intInput % 100 / 10;
            int strNum03 = intInput % 1000 / 100;
            int strNum04 = intInput / 1000;
            int strResult = strNum01 + strNum02 + strNum03 + strNum04;
            Console.WriteLine(strResult);
            // 法二 先取每个位转换为char，再将char->string，string->int
            int strResult02 = int.Parse(input[0].ToString());
            strResult02 += int.Parse(input[1].ToString());
            strResult02 += int.Parse(input[2].ToString());
            strResult02 += int.Parse(input[3].ToString());
            Console.WriteLine(strResult02);


            Console.WriteLine("--------------- 类型转换 ---------------");
            // 隐式类型转换
            byte b3 = 100;
            int i3 = b3;   // 可以将byte转换为int
            // 显式类型转换 / 强制类型转换
            int i4 = 100;
            byte b4 = (byte)i4;   // byte不能自动转化为int
            // byte只有一个字节8位，int有4个字节32位，所以int一定能够表示byte的数据，但是byte不一定可以表示int的数据，使用强制类型转换可以，但是有可能出现问题
            short result = (short)(i4 + b4);
            Console.WriteLine(result);
            int a = 1;
            a = a + 1;
            a += 3;
            byte b = 1;
            b += 3;   // 快捷运算符不做类型提示
            b = (byte)(b + 3);   // 有可能越界，需要在外部进行强制类型转换


            Console.WriteLine("--------------- 选择语句 ---------------");
            // 语句
            // 选择语句
            int flag = 1;
            if(flag == 1)
            {
                Console.WriteLine("flag = 1");
            }
            else if( flag == 2)
            {
                Console.WriteLine("falg = 2");
            }
            else
            {
                Console.WriteLine("flag != 1 && flag != 2");
            }
            Console.WriteLine("输入数字：");
            string strNumerOne = Console.ReadLine();
            int numberOne = int.Parse(strNumerOne);   // Console.ReadLine()只能读取string类型的数据，需要进行一次数据转换
            Console.WriteLine("输入数字：");
            string strNumerTwo = Console.ReadLine();
            int numberTwo = int.Parse(strNumerTwo);
            Console.WriteLine("请输入运算符：");
            string calculate;
            calculate = Console.ReadLine();
            float calResult;
            if(calculate == "+")
            {
                calResult = numberOne + numberTwo;
            }
            else if (calculate == "-")
            {
                calResult = numberOne - numberTwo;
            }
            else if (calculate == "*")
            {
                calResult = numberOne * numberTwo;
            }
            else if (calculate == "/")
            {
                calResult = numberOne / numberTwo;
            }
            else
            {
                Console.WriteLine("运算符输入有误");
                calResult = 0;
            }
            Console.WriteLine(calResult);
            Console.WriteLine("再次输入运算符：");
            calculate = Console.ReadLine();
            switch (calculate)
            {
                case "+":
                    calResult = numberOne + numberTwo;
                    break;
                case "-":
                    calResult = numberOne - numberTwo;
                    break;
                case "*":
                    calResult = numberOne * numberTwo;
                    break;
                case "/":
                    calResult = numberOne / numberTwo;
                    break;
                default:
                    calResult = 0;
                    break;
            }
            Console.WriteLine(calResult);


            Console.ReadLine();
        }
    }
}
