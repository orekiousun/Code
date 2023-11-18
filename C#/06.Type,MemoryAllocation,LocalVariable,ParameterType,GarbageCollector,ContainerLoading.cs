using System;
using System.Text;

/*
    1.类型分类
        值类型（结构，枚举）：   --  对应确定字节大小的数据类型 int，bool，char等
            --  声明在栈中，数据存储在栈中
        引用类型（接口，类）：存储数据的引用（内存地址）  --  对应不确定字节大小的数据类型 string，Array等
            --  声明在栈中，数据存储在堆中，栈中保存该数据的引用
    2.内存分配
        程序运行时，CLR将申请的内存空间从逻辑上划分
    栈区：空间小，读取速度快
        ·用于存储正在执行的方法，分配的空间叫栈帧
        ·栈帧中存储方法的参数以及变量等数据
        ·方法执行完毕后，对应的栈帧将被删除
        -- 无论是值类型还是引用类型，只要是在方法中（包括main函数）声明的变量（无论是值类型还是引用类型），都放在栈中（但数据不一定保存在栈中）
    堆区：空间大，读取速度慢
        用于存储引用类型的数据
    3.局部变量：在方法内部申明的变量
    特点：
        没有默认值，必须自己设定初值，不然无法使用
        方法被调用时，存在栈中，方法调用结束时从栈中清除
    4.参数类型
        ·值参数：按值传递
        ·引用参数：按引用传递 -- 传递实参变量自身的地址 -- 关键字ref(reference)
        ·输出参数：按引用传递 -- 传递实参变量自身的地址 -- 关键字out，用于返回结果
    5.垃圾回收器GC（Garbage Collection）：用于回收堆中的栈上没有数据使用的内存
    当方法执行完毕时，方法内的所有存放在栈上的值类型和引用类型会被释放掉
    但是释放引用类型时，只会释放引用类型记录的引用地址，不会释放对用堆区的内存
    这个对应的内存就是通过垃圾回收器GC来释放的
    -- 日常开发时尽量不要产生垃圾，同时可以提供代码建议垃圾回收的时机
    -- 当内存会不够时，垃圾回收器GC才会工作
    // 注意与C++的不同点
    6.拆装箱 - 比较消耗性能
    当将栈区的数值赋值到引用类型中时，会在堆区开辟一个集装箱
    拆装箱 = 数据 + 同步块索引 + 类型对象指针
    ·装箱操作box：值类型到object类型的隐式转换  -- 比起拆箱更消耗性能
    内部机制：
        1）在堆区开辟内存空间
        2)将值类型的数据赋值到堆中
        3)返回堆中新分配对象的地址
        int a = 1;
        object o  = a;
    ·拆箱操作unbox:object类型到值类型的显示转换
    内部机制：
        1）判断给定类似是否时装箱时的类型
        2）返回已装箱实例中属于原值类型字段的地址，同时赋值数据
        int b = (int)o;
    如果函数中参数的类型为object就会发生拆装箱，尽量通过重载或泛型方法避免
    int num = 100;
    string str = "" + num; -- 会发生拆装箱
    内部代码为string str02 = string.Concat("", num);   // concat内部参数数据类型为object
    为避免发生拆装箱，可以：
    string str = "" + num.ToString();   // ToString不会发生拆装箱
    -- 对性能损失不大，但是面试常考
    7.字符串池 -- 提高字符串利用率
    在创建字符串时，会在字符串池中找是否有相同的字符串，如果有会直接返回该相同字符串的引用
    字符串的不可变性：
        ·在开辟内存时，字符串的大小已经被确定
        ·如果一旦修改，当传入一个更大的字符串时，有可能会将其他对象的内存破坏
        ·每次修改都是重新开辟新的空间，替换引用
    字符串常用方法：ToArray Insert Contains ToLower ToUpper IndexOf Substring  Trim Split Replace Join
    
*/
namespace Day06
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("--------------- test01 ---------------");
            // 交错数组
            // 交错数组就是一个数组，数组中每一个元素都是一个数组
            // 每一行的数据可能不同，不规则的表格
            int[][] array = new int[4][];   // 定义交错数组，不能定义每个子数组上的维度，因为每一行维度不同
            array[0] = new int[3];          // 创建一维数组，赋值给交错数组的第一元素
            array[1] = new int[5];
            array[2] = new int[4];
            array[3] = new int[1];
            array[0][2] = 1;
            array[1][4] = 1; 
            array[2][3] = 1;
            array[3][0] = 1;
            printInterArray(array);
            // 通过for循环访问 -- 不能写在函数中
            for (int i = 0; i < array.Length; i++)
            {
                for (int j = 0; j < array[i].Length; j++)
                {
                    Console.Write(array[i][j] + " ");
                }
                Console.WriteLine();
            }
            

            // 参数数组
            Console.WriteLine("--------------- test02 ---------------");
            int addResult = myAdd(1, 2, 3, 4, 5 );
            Console.WriteLine("addResult = " + addResult);

            // 数据类型
            int a = 1;
            int b = a;
            a = 2;
            Console.WriteLine(b);         // 返回结果为1
            // 值类型直接存储数据，所以数据存储在栈中 -- a在栈中，1在栈中

            int[] arr = new int[] {1};    // arr存的是一个地址
            int[] arr2 = arr;             // 相当于赋值了一个地址
            arr[0] = 2;                   // 改变堆区该地址上的数据
            // 这里有中括号，所以arr[0]代表的是一个数据，修改的是数据不是地址
            Console.WriteLine(arr2[0]);   // 返回结果为2
            arr = new int[] {3};          // 为arr赋值了一个新的地址
            Console.WriteLine(arr2[0]);   // 返回结果为2
            // 数据存储在堆中，栈中保存该数据的引用 -- arr在栈中，1在堆中，a为1的引用（内存地址）

            string s1 = "男";
            string s2 = s1;
            s1 = "女";                    // 修改的栈中存储的引用
            // 注意此时s1代表一个地址，修改了地址即重新开辟了一块空间
            Console.WriteLine(s2);
            // string重新赋值的时候会在堆区重新分配一块内存，为s1重新赋值时改的是地址不是数据，相当于new了一块新的空间
            // 所以此时s2保存的仍为“男”，string中分配的数据是只读的，具有不可变性

            object o1 = 1;                // object为引用类型 不知道字节大小 1存在堆中 o1在栈中
            // 注意此时o1是一个地址
            Object o2 = o1;               // o2得到的是数据1的地址
            o1 = 2;                       // 修改的是栈中o1存储的引用
            // 修改o1的值，只有给他赋予一个新的地址，该地址存放了2
            Console.WriteLine(o2);        // 返回结果为1

            // 关键点在于看有没有中括号
            //  ·如果有中括号，修改的就是数据
            //  ·如果没有中括号，修改的就是地址 -- 在堆区新开辟了一块内存

            Console.WriteLine("--------------- test03 ---------------");
            // 结合方法/函数理解
            int intA = 1;
            func1(intA);
            Console.WriteLine(intA);   // 输出结果为1，只进行了值传递

            int[] intArr = new int[]{1};
            func2(intArr);
            Console.WriteLine(intArr[0]);   // 输出结果为2，进行了地址传递
            func5(intArr);
            Console.WriteLine(intArr[0]);

            string strA = "Lisa";
            func3(strA);
            Console.WriteLine(strA);   // 输出结果为Lisa，进行了地址传递
            // 但是传入func3中的a为一个地址，修改了a的值即修改了地址，所以相当于在堆区新开辟了一块内存存取Aimer
            // 如果需要使strA = "Aimer"，需要返回a，重新定义函数
            strA = func4(strA);
            Console.WriteLine(strA);

            int num01 = 1, num02 = 1;   // 存的数据，相同
            bool r1 = num01 == num02;
            Console.WriteLine("r1 = " + r1.ToString());
            
            int[] arr01 = new int[] { 1 }, arr02 = new int[] { 1 };   // 存的地址不同
            bool r2 = arr01 == arr02;
            Console.WriteLine("r2 = " + r2.ToString());
            bool r3 = arr01[0] == arr02[0];   // 取出来值，相同
            Console.WriteLine("r3 = " + r3.ToString());
            // 总结：只有传入数组并通过[]修改值才能实现C++中地址传递，同步改变数组中的值，其他均不行(值类型和引用类型的原因不相同)




            Console.WriteLine("--------------- test04 ---------------");
            // 值参数：按值传递
            // 引用参数：按引用传递 -- 传递实参变量自身的地址 -- 关键字ref(reference)
            // 输出参数：按引用传递 -- 传递实参变量自身的地址 -- 关键字out
            // 输出参数的作用：返回结果
            /*
                区别：
                    ·方法内部必须为输出参数赋值
                    ·引用参数必须有初始值，而输出参数传递之前可以不复制 -- 因为方法内部一定会为输出参数赋值
             */

            int num03 = 1;
            fun6(ref num03);   // 这样传递进来的num的引用，可以同步修改num的值
            // 类似于C++中传入的引用
            Console.WriteLine("num03 = " + num03.ToString());

            int num04;   // 传递之前可以不赋值，用于接收方法的结果
            fun7(out num04);   
            Console.WriteLine("num04 = " + num04.ToString());
            int num05 = 1, num06 = 2;
            Console.WriteLine("交换前：");
            Console.WriteLine("num05 = " + num05.ToString());
            Console.WriteLine("num06 = " + num06.ToString());
            swap(ref num05, ref num06);
            Console.WriteLine("交换后：");
            Console.WriteLine("num05 = " + num05.ToString());
            Console.WriteLine("num06 = " + num06.ToString());
            int S, C;
            getSAndC(out S, out C, num05, num06);
            Console.WriteLine("S = " + S.ToString());
            Console.WriteLine("C = " + C.ToString());
            // TryParse
            int tryResult;
            bool boolResult = int.TryParse("250+", out tryResult);   // out返回转换后的数值，而函数返回值返回是否可以转换
            Console.WriteLine("boolResult = " + boolResult);
            
            // 拆装箱
            Console.WriteLine("--------------- test04 ---------------");
            // 装箱操作
            int num07 = 0;
            object o3 = num07;   // 此时会在堆中新分配一块内存用于保存1，同时将该地址赋值给o3
            // 拆箱操作
            int num08 = (int)o3;

            // string 
            string s3 = "Lisa";
            string s4 = "Lisa";
            bool r4 = ReferenceEquals(s3, s4);
            Console.WriteLine("r4 = " + r4.ToString());
            // 发现返回的结果为True，说明s1,s2是同一个引用
            // 字符串池：在创建字符串时，会在字符串池中找是否有相同的字符串，如果有会直接返回该相同字符串的引用 -- 可以提高内存利用率

            string s5 = new string("Lisa");
            string s6 = new string("Lisa");
            bool r5 = ReferenceEquals(s5, s6);
            Console.WriteLine("r5 = " + r5.ToString());
            s3 = "Aimer";   // 不是将Lisa改为了Aimer，而是重新开辟了空间，存储新的字符串，替换栈中引用
            // 而new开辟的数据为在堆区新开辟了一块地址


            object o4 = 1;
            o4 = 2.0;
            o4 = "ok";
            o4 = true;
            // 每次修改都是重新开辟新的空间，替换引用

            string[] strArray = new string[2] ;
            strArray[0] = "Lisa";
            strArray[1] = "Aimer";    
            // 堆区有一个引用指向栈区的一个str数组
            // 同时栈区str数组内保存的也是引用，因为string是引用类型
            // 该引用指向栈区的另外一块空间，分别保存Lisa和Aimer

            string strNumber = "";
            for (int i = 0; i < 10; i++)
            {
                strNumber = strNumber + i.ToString();   // 会频繁地重新申请空间，同时生成大量垃圾
            }
            Console.WriteLine(strNumber);

            // 替换方案 -- 利用可变字符串StringBuilder  --  需要包含头文件using System.Text;
            StringBuilder builder = new StringBuilder(10);   // 也可以指定开辟的空间大小，通过new StringBuilder(size)指定
            for (int i = 0; i < 10; i++)
            {
                builder.Append(i);
            }
            Console.WriteLine(builder);   // StringBuilder会开辟一个较大的空间，每次拼接都是在原有字符串上进行的，不会生成大量垃圾
            // 可以提前指定该空间的大小，如果录入的数据超过了指定空间的大小，就会开辟一块更大的新的空间，这样同样会生成垃圾
            //builder.Insert()
            //builder.Replace()
            //builder.Replace()
            s5 = s5.Insert(0, s5);   // string实现插入是利用返回值接收了该结果，同时原来时s5保存的"Lisa"会变为垃圾


            // ToArray Insert Contains ToLower ToUpper IndexOf Substring Trim Split Replace Join
            string s7 = "Lisa";
            char[] c1 = s7.ToCharArray();
            Console.WriteLine(c1[0].ToString() + " " + c1[1].ToString() + " " + c1[2].ToString() + " " + c1[3].ToString());
            s7 = s7.Insert(0, "i");
            Console.WriteLine("s7.Insert(0, \"i\") = " + s7);
            bool b1 = s7.Contains('i');  // 确实是都包含i
            Console.WriteLine("s7.Contains('i') = " + b1.ToString());
            Console.WriteLine("s7.ToLower() = " + s7.ToLower());   // 改为小写字母
            Console.WriteLine("s7.ToUpper() = " + s7.ToUpper());   // 改为大写字母
            Console.WriteLine("s7.IndexOf('s') = " + s7.IndexOf('s').ToString());
            Console.WriteLine("s7.Substring(3) = " + s7.Substring(3));   // 返回一个子串
            string s8 = "     Hello World ! ! !     ";
            Console.WriteLine("s8.Trim() = " + s8.Trim());   // 删除字符串开头和结尾的空白
            string[] s9 = s7.Split("i");   // 通过指定子字符串分割字符串，返回一个字符串数组
            Console.WriteLine("s9[2] = " + s9[2]);
            Console.WriteLine("s7.Replace('i', 'x') = " + s7.Replace('i', 'x'));   // 利用指定字符替换原来的指定字符
            Console.WriteLine(string.Join(" ", 1,2,3));
            string strInverse = InverseStr("How are you");
            Console.WriteLine(strInverse);
            strInverse = InverseStr2("How are you");
            Console.WriteLine(strInverse);
            string strDelete = deleteRepeat("Lxxixxsxxa");
            Console.WriteLine(strDelete);
        }

        private static void printArray(Array arr)
        {
            foreach (var item in arr)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }

        private static void printInterArray(Array[] arr)
        {
            foreach (int[] item in arr)
            {
                foreach (int itemInside in item)
                {
                    Console.Write(itemInside + " ");
                }
                Console.WriteLine();
            }
        }

        // 整数相加的方法
        // 当类型确定 个数不确定的清晰，调用数组
        // 参数数组：对于方法内部而言，就是一个普通数组
        // 对于调用者（方法尾部）而言，参数数组可以传递数组，也可直接传递参数（即数据类型相同的变量的集合，数组元素），甚至可以不传递参数
        // 作用：：传参更方便，简化调用者调用方法的代码
        // 本质上还是传入了一个数组，只是编译器帮忙提供了数组的定义，只用传入数组内的参数即可
        private static int myAdd(params int[] arr)
        {
            int sum = 0;
            foreach (var item in arr)
            {
                sum += item;
            }
            return sum;
        }



        // 值类型和引用类型
        private static void func1(int a)
        {
            a = 2;
        }
        private static void func2(int[] a)
        {
            a[0] = 2;
        }
        private static void func5(int[] a)
        {
            a = new int[] { 3 };
            // 这样只修改了a的指向，在堆区重新开辟了一块地址用于存放3这个数据，并没有修改传进来参数的指向地址
        }
        private static void func3(string a)
        {
            a = "Aimer";
        }
        private static string func4(string a)
        {
            a = "Aimer";
            return a;
        }
        


        // 引用参数
        private static void fun6(ref int a)   // 利用ref传入引用，实质上就是在修改实参变量
        {
            a = 2;
        }
        // 输出参数
        private static void fun7(out int a)   // 利用out传入引用，实质上就是在修改实参变量
        {
            a = 2;
        }
        private static void swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }   // 利用引用参数实现交换
        private static void getSAndC(out int S, out int C, int a, int b)
        {
            S = a * b;
            C = 2 * (a + b);  
        }   // 利用输出参数输出面积和周长


        private static string InverseStr(string str)
        {
            StringBuilder strReturn = new StringBuilder();
            string[] strNew = str.Split(" ");
            for (int i = 0; i < strNew.Length; i++)
            {
                strReturn.Append(strNew[strNew.Length - 1 - i]);
                strReturn.Append(" ");
            }
            string strReturn2 = strReturn.ToString();
            strReturn2 = strReturn2.Trim();
            return strReturn2;
        }

        private static string InverseStr2(string str)
        {
            StringBuilder strReturn = new StringBuilder();
            string[] strNew = str.Split(" ");
            for (int i = strNew.Length - 1; i >= 0; i--)
            {
                StringBuilder strChar = new StringBuilder();
                char[] charArr = strNew[i].ToCharArray();
                for (int j = 0; j < charArr.Length; j++)
                {
                    strChar.Append(charArr[charArr.Length - j - 1]);
                }
                strReturn.Append(strChar);
                strReturn.Append(" ");
            }
            string strReturn2 = strReturn.ToString();
            strReturn2 = strReturn2.Trim();
            return strReturn2;
        }

        private static string deleteRepeat(string str)
        {
            StringBuilder strReturn = new StringBuilder();
            char[] charArr = str.ToCharArray();
            for (int i = charArr.Length - 1; i > 0; i--)
            {
                if (i != str.IndexOf(str[i]))
                {
                    charArr[i] = ' ';
                }
            }
            for (int i = 0; i < charArr.Length; i++)
            {
                if (charArr[i] != ' ')
                {
                    strReturn.Append(charArr[i]);
                }
            }
            string strReturn2 = strReturn.ToString();
            strReturn2 = strReturn2.Trim();
            return strReturn2;
        }
    }

}
