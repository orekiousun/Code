using System;

namespace Day03
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
                短路逻辑：
                    ·对于&&运算符，当第一个操作数为false时，不会判断第二个操作数
                    ·对于||运算符，当第一个操作数为true时，不会判断第二个操作数
                开发中可以将运算量小的判断放在前面，用于提高性能
            */
            Console.WriteLine("--------------- test01 ---------------");
            int n1 = 1, n2 = 2;
            bool re1 = n1 > n2 && n1++ > 1;
            // n1 > n2 为假，已经可以判定re1为假，后面的语句不执行，n1++不执行，n1 = 1
            Console.WriteLine("n1 = " + n1);
            bool re2 = n1 < n2 || n2++ < 1;
            // n1 < n2 为真，已经可以判定re2为真，后面的语句不执行，n2++不执行，n2 = 2
            Console.WriteLine("n2 = " + n2);



            // 循环语句 -- 打一个for按两个tab会自动补全代码结构
            /*
                跳转语句：
                    continue 跳出当前循环，执行下一循环
                    break 跳出当前循环/判断语句
                    return
            */
            Console.WriteLine("--------------- test02 ---------------");
            int i;
            Console.WriteLine("for 循环：");
            for(i = 0; i < 5; i++)
            {
                // continue 跳转语句 结束本次循环，继续下次循环
                if (i % 2 == 0) continue;
                Console.WriteLine(i);
            }
            i = 0;
            Console.WriteLine("while 循环：");
            while (i < 5)
            {
                Console.WriteLine(i);
                i++;
            }
            i = 0;
            Console.WriteLine("do while 循环：");
            do
            {
                Console.WriteLine(i);
                i++;
            } while (i < 5);
            // 猜数字
            // guessNumber();



            // 方法/函数 -- 提高代码的可重用性和可维护性
            /*
                [访问修饰符][可选修饰符] 返回类型 方法名称(参数列表)
                {
                    // 方法体
                    return 结果;
                }
                方法名称(参数);

                返回值类型：void int double float string ...
                返回数据必须与返回值类型兼容(可以隐式类型转换)
            */
            Console.WriteLine("--------------- test03 ---------------");
            func1();
            Console.WriteLine("myAdd(1, 2) = " + myAdd(1, 2));   // 实参与形参一一对应 
            string str = "my";
            str = str.Insert(2, "Insert");
            Console.WriteLine("str = " + str);
            int index = str.IndexOf("m");   // 查找指定字符在字符串中的位置
            Console.WriteLine("index = " + index);
            str = str.Remove(1, 3);
            Console.WriteLine("str = " + str);
            str = str.Replace("m", "x");
            Console.WriteLine("str = " + str);
            bool judge = str.StartsWith('x');
            Console.WriteLine("str.StartsWith('x') = " + judge);
            judge = str.Contains("xx");
            Console.WriteLine("str.str.Contains(\"xx\") = " + judge);



            Console.WriteLine("--------------- test04 ---------------");
            // 显示日期
            printYearCalender(1995);
        }

        private static void func1()
        {
            Console.WriteLine("fun1 执行");
        }

        private static void guessNumber()
        {
            Random random = new Random();   // 创建一个随机数工具
            int number = random.Next(1, 101);   // 左闭右开
            int intNumber;
            do
            {
                Console.WriteLine("请输入猜测的数字：");
                intNumber = int.Parse(Console.ReadLine());
                if (intNumber > number) Console.WriteLine("猜测过大");
                else if (intNumber < number) Console.WriteLine("猜测过小");
                else
                {
                    Console.WriteLine("猜测正确");
                    break;
                }
            } while (intNumber != number);
        }

        private static int myAdd(int a, int b)
        {
            return a + b;
        }

        private static void printMonthCalender(int year, int month)
        {
            int week = getWeekByDay(year, month, 1);
            int dayCount = getDayByMonthAndYear(year, month);
            Console.WriteLine(year + "年" + month + "月");
            Console.WriteLine("日\t一\t二\t三\t四\t五\t六");
            for (int i = 0; i < week; i++)
            {
                Console.Write("\t");
            }
            for (int i = 1; i <= dayCount; i++)
            {
                Console.Write(i + "\t");
                if (getWeekByDay(year, month, i) == 6)
                {
                    Console.Write("\n");
                }
            }
        }

        private static void printYearCalender(int year)
        {
            Console.WriteLine(year + "年");
            for (int i = 1; i <= 12; i++)
            {
                printMonthCalender(year, i);
                Console.Write("\n");
            }
        }

        private static int getWeekByDay(int year, int month, int day)
        {
            DateTime dt = new DateTime(year, month, day);
            return (int)dt.DayOfWeek;
        }

        private static int getDayByMonthAndYear(int year, int month)
        {
            int flag;
            if (year % 4 != 0) flag = 0;   // 代表不为闰年
            else flag = 1;   // 代表为闰年
            if (month < 1 || month > 12) return 0;
            switch (month)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    return 31;   
                case 2:
                    if (flag == 0) return 28;
                    else return 29;
                default:
                    return 30;
            }
        }
    }
}
