using System;

namespace Day04
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("--------------- test01 --------------");
            int mulResult = multiply(5);
            Console.WriteLine("multiply(5) = " + mulResult);
            int calResult = calculate(5);
            Console.WriteLine("calculate(5) = " + calResult);


            // 数组
            // 从Array类派生，一组数据类型相同的变量组合
            // 一种空间连续的数据结构
            // 元素通过索引（位置的序号）进行操作
            Console.WriteLine("--------------- test02 --------------");
            int[] a;                // 声明
            a = new int[4];         // 初始化
            float[] b = new float[5];   // 一步完成
            a[0] = 1;
            a[1] = 2;
            a[2] = 3;               // 存数据，默认值为0
            for (int i = 0; i < 4; i++)
            {
                Console.WriteLine("a["+ i + "] = " + a[i]);    // 拿数据
            }
            // float[] scoreArray = createScoreArray();           // 返回值为数组时的调用方式
            float max1 = getMax(new float[] { 2,4,6,8,10});
            Console.WriteLine("getMax(b) = " + max1);
            string[] strArrray = new string[] { "a", "b" };    // 利用数值初始化数组
            bool[] boolArraay = { true, false, false };        // 直接初始化数组
            // float max2 = getMax({ 2, 4, 5, 6, 7});          // 不能这样写，会报错
            int dayCount = getDay(2002, 6, 19);
            Console.WriteLine("getDay(2002, 6, 19) = " + dayCount);


            // foreach循环：从头到位一次读取数组元素
            /*
                foreach(元素类型 变量名 in 数组名称)
                {

                }
                优点：使用简单，但是更消耗性能，同时有很多限制
            */
            Console.WriteLine("--------------- test03 --------------");
            foreach (int item in a)
            {
                Console.Write(item + " ");
                // item = 0;   // 报错，item无法修改，只读
            }
            Console.Write("\n");
            // var推断类型，会根据后面的定义的数据类型自动推断自己的数据类型
            // 适用性：用于数据类型过长时偷懒，同时可以用于foreach中
            var v1 = 1;
            var v2 = "1";
            var v3 = '1';
            var v4 = true;
            var v5 = 1.0f;
            // 也可以声明父类类型，赋值子类对象 -- 多态
            Array arr01 = new int[2];
            Array arr02 = new double[2];
            printElement(new int[4] { 1, 5, 6, 9 });  // 可以利用此特性传参
            // object是所有类的父类，可以传入任意类型
            object o1 = 1;
            object o2 = true;
            object o3 = new int[3];


            // 数组常用方法及属性
            Console.WriteLine("--------------- test04 --------------");
            Console.WriteLine("Array.IndexOf(a, 1) = " + Array.IndexOf(a, 2));
            Console.WriteLine("a.Length = " + a.Length);
            int[] sortArray = new int[] { 5, 1, 6, 3 };
            Array.Sort(sortArray);                               // 排序
            printElement(sortArray);
            int[] desArray = new int[4];
            Array.Copy(sortArray, desArray, 2);                  // 复制
            printElement(desArray);
            int[] cloneArray = (int[])sortArray.Clone();         // 克隆
            printElement(cloneArray);

            // 双色球
            // 红球01-33不重复
            // 篮球01-16
            // 7个数全中即中奖
            int[] myLottery = purLottery();
            Console.Write("您购买的双色球为：");
            printElement(myLottery);
            int[] trueLottery = setLottery();
            Console.Write("奖池的双色球为：");
            printElement(trueLottery);
            getAward(myLottery, trueLottery);

        }
        // 方法重载：名称相同，参数列表不同
        // 在不同条件下，解决同一类问题，让调用者仅仅记忆1个方法
        // 仅仅out和ref的区别不能构成重载

        // 递归 计算阶乘
        // 能不用递归最好不用递归，递归比起循环更消耗性能，但有时候递归可以把复杂问题简单化
        private static int multiply(int num)
        {
            if(num == 1) return num;
            else return num * multiply(num - 1);
        }

        private static int calculate(int num)
        {
            if (num == 1) return num;
            else if (num % 2 == 0) return -num + calculate(num - 1);
            else return num + calculate(num - 1);   
        }

        private static float[] createScoreArray()   // 返回数组
        {
            Console.WriteLine("请输入学生总数：");
            int count = int.Parse(Console.ReadLine());
            float[] scoreArray = new float[count];
            for (int i = 0; i < count; )
            {
                Console.WriteLine("请输入第{0}个学生成绩", i + 1);
                float score = int.Parse(Console.ReadLine());
                if (score >= 0 && score <= 100)
                {
                    scoreArray[i++] = score;   // 只有加入成绩成功时i才会++
                }
                else
                {
                    Console.WriteLine("输入有误");
                }
            }
            return scoreArray;
        }

        private static float getMax(float[] array)
        {
            float max = array[0];
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] >= max) max = array[i];
            }
            return max;
        }

        private static int getDay(int year, int month, int day)
        {
            int[] monthDay;
            if (year % 4 == 0) monthDay = new int[] { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            else monthDay = new int[] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            int dayCount = 0;
            for (int i = 0; i < month - 1; i++)
            {
                dayCount = dayCount + monthDay[i];
            }
            dayCount += day;
            return dayCount;
        }

        private static void printElement(Array arr)
        {
            foreach (var item in arr)
            {
                Console.Write(item + " ");
            }
            Console.Write("\n");
        }

        private static int[] purLottery()
        {
            int[] lottery = new int[7];
            for (int i = 0; i < 6; )
            {
                Console.Write("请输入第{0}个红球，范围为01-33：", i + 1);
                int temp = int.Parse(Console.ReadLine());
                if (Array.IndexOf(lottery, temp) != -1) 
                    Console.WriteLine("该号码已存在，请重新输入");
                else if(temp < 1 || temp > 33) 
                    Console.WriteLine("选择的号码越界，请重新输入");
                else lottery[i++] = temp;
            }
            Console.Write("请输入蓝球，范围为01-16：");
            while(true)
            {
                int temp = int.Parse(Console.ReadLine());
                if (temp >= 1 && temp <= 16)
                {
                    lottery[6] = temp;
                    break;
                }
                else Console.WriteLine("选择的号码越界，请重新输入");
            }
            return lottery;
        }

        static Random random = new Random();   // 创建一个随机数工具
        private static int[] setLottery()
        {
            int[] lottery = new int[7];
            for (int i = 0; i < 6; )
            {
                int number = random.Next(1, 34);   // 左闭右开
                if (Array.IndexOf(lottery, number) == -1) 
                    lottery[i++] = number;
            }
            int number7 = random.Next(1, 17);
            lottery[6] = number7;
            Array.Sort(lottery, 0, 6);   // 部分排序，Sort函数的重载
            return lottery;
        }

        private static void getAward(int[] myLottery, int[] trueLottery)
        {
            int countRed = 0;
            int CountBlue = 0;
            for (int i = 0; i < 6; i++)
            {
                if (Array.IndexOf(trueLottery, myLottery[i], 0, 6) != -1) // 利用IndexOf的一个重载实现
                    countRed++;
            }
            if(myLottery[6] == trueLottery[6]) 
                CountBlue++;
            if (countRed == 6 && CountBlue == 1) 
                Console.WriteLine("恭喜获得一等奖");
            else if(countRed == 6 && CountBlue == 0) 
                Console.WriteLine("恭喜获得二等奖");
            else if (countRed == 5 && CountBlue == 1) 
                Console.WriteLine("恭喜获得三等奖");
            else if (countRed == 5 && CountBlue == 0) 
                Console.WriteLine("恭喜获得四等奖");
            else if (countRed == 4 && CountBlue == 1) 
                Console.WriteLine("恭喜获得四等奖");
            else if (countRed == 3 && CountBlue == 1) 
                Console.WriteLine("恭喜获得五等奖");
            else if (countRed == 4 && CountBlue == 0) 
                Console.WriteLine("恭喜获得五等奖");
            else if (countRed == 2 && CountBlue == 1) 
                Console.WriteLine("恭喜获得六等奖");
            else if (countRed == 1 && CountBlue == 1) 
                Console.WriteLine("恭喜获得六等奖");
            else if (countRed == 0 && CountBlue == 1) 
                Console.WriteLine("恭喜获得六等奖");
            else Console.WriteLine("很可惜，没中奖");
        }
    }
}
