using System;
// 引入命名空间

// 定义命名空间：对类进行逻辑上的划分，避免重名
namespace Day01
{
    // 定义一个类
    class Program
    {
        // 程序的入口函数
        static void Main(string[] args)
        {
            // 在控制台输出和输入
            Console.Title = "My Code";
            Console.WriteLine("input your name: ");
            string name = Console.ReadLine();
            Console.WriteLine("hello: " + name);
            // Console是一个类，WriteLine/ReadLine是成员函数，Title是成员属性
            // Ctrl + A 全选
            // Ctrl + K + F 自动对齐
            // Ctrl + K + C 注释选中代码
            // Ctrl + K + U 取消注释选中代码
            // 1Byte = 8bit, 1KB = 1024B...
            // 网速10M指的是Mbps，指bit每秒，所以换算为字节应该/8
            
            
            
            // float num01 = 1.0f;
            // float num02 = 0.9f;
            // float result = num01 - num02;
            // bool b1 = result == 0.1f;
            // Console.WriteLine(b1);
            // 不会返回true，因为计算机二进制格式下无法准确表示小数，存在舍入误差
            // 1.0f-0.9f结果不为0.1f，建议使用decimal
            
            decimal num01 = 3.0m;
            decimal num02 = 2.9m;
            decimal result = num01 - num02;
            bool b1 = result == 0.1m;
            Console.WriteLine(b1);
            // 使用decimal就不存在舍入误差
            Console.ReadLine();
            // 调试：F5运行程序，F11逐语句执行（如果有断点的话）

            Console.WriteLine("请输入枪的名称：");
            string gunName = Console.ReadLine();
            Console.WriteLine("请输入弹夹容量：");
            string size = Console.ReadLine();
            Console.WriteLine("请输入子弹数量：");
            string current = Console.ReadLine();

            int n1 = 1;
            float n2 = 0.1f;
            double n3 = 0.1d;
            char c4 = 'a';
            string s1 = "hello";
            bool b = false;

            Console.WriteLine("枪的名称：" + gunName + " 弹夹容量：" + size + " 子弹数量：" + current);
            Console.ReadLine();
        }
    }
}
