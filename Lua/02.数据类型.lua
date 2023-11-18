--[[
    1.nil:������
        1)λ������ֵ��nil�൱��ɾ������������
            x = nil
        2)nil���Ƚ�ʱӦ�ü���˫����
            print(type(X)=="nil")

    2.boolean:��������
        1)ֻ��true/false,lua��false��nil����false�����ࣨ��������0������true

    3��number:��������
        2)luaĬ��ֻ��һ�� number ���� -- double��˫���ȣ�����

    4.string:�ַ���
        1)�ַ�����һ��˫���Ż���������ʾ��Ҳ����������˫���ű�ʾһ���ַ���<���·�>
            string1 = "this is string1"
            string2 = 'this is string2'
        2)�������ַ����Ͻ�����������ʱ��Lua �᳢�Խ���������ַ���ת��һ������
            print("2" + 6)
        3)����..ƴ���ַ���
            string4 = "a" .. "b"
        4)���ַ���֮ǰ��#�����ַ�������
            len = #string3

    5.table:��
        1)table �Ĵ�����ͨ��"������ʽ"����ɣ���򵥹�����ʽ��{}����������һ���ձ�Ҳ�����ڱ������һЩ���ݣ�ֱ�ӳ�ʼ����
            local tbl1 = {}   --����һ���ձ�
            local tbl2 = {"apple", "pear", "orange", "grape"}   --ֱ�ӳ�ʼ����
        2)lua��������Ĭ��������1��ʼ
        3)table ����̶����ȴ�С�������������ʱ table ���Ȼ��Զ�������û��ʼ�� table ���� nil
       
    6.function:����
        1)�� Lua �У������Ǳ�������"��һ��ֵ��First-Class Value��"���������Դ��ڱ�����
            function myfun(val)
                ...
                ...
                return xx
            end
            ���ã�
                print(myfun(x))
                myfun_copy = myfun
                print(myfun_copy(x))
        2)function ����������������anonymous function���ķ�ʽͨ����������

]]

--����nil
print("------------------------------------------------")
print("nil test")
print(X)
print(type(X)==nil)   -- �����÷�
print(type(X)=="nil")

--����boolean
print("------------------------------------------------")
print("boolean test")
print(type(true))
print(type(false))
print(type(nil))
if false or nil then
    print("������һ���� true")
else
    print("false �� nil ��Ϊ false")
end
if 0 then
    print("���� 0 �� true")
else
    print("���� 0 Ϊ false")
end

--����number
print("------------------------------------------------")
print("number test")
print(type(2e+1))

--����string
print("------------------------------------------------")
print("string test")
string1 = "this is string1"
print(string1)
string2 = 'this is string2'
print(string2)
string3 = [[
    line1
    line2
    line3
]]
print(string3)
print("2" + 6)
print("2" + "6")   -- �ַ����Զ�ת��Ϊ��������
string4 = "a" .. "b"
print(string4)
len = #string3
print(len)

--����table
print("------------------------------------------------")
print("table test")
a = {}
a["key"] = "value"   --��ֵ��
key = 10
a[key] = 22
a[key] = a[key] + 11
for k, v in pairs(a) do
    print(k .. " : " .. v)
end

tbl = {"apple", "pear", "orange", "grape"}
for key, val in pairs(tbl) do
    print("Key", key)
end

a3 = {}
for i = 1, 10 do
    a3[i] = i
end
a3["key"] = "val"
print(a3["key"])
print(a3["none"])
print(#a3)

--����function
print("------------------------------------------------")
print("function test")

function factorial1(n)   -- ʹ�õݹ�ʵ�ֽ׳�
    if n == 0 then
        return 1
    else
        return n * factorial1(n - 1)
    end
end   
print(factorial1(5))
factorial2 = factorial1
print(factorial2(5))

--������������
function testFun(tab,fun)
    for k ,v in pairs(tab) do
            print(fun(k,v));
    end
end

tab={key1="val1",key2="val2"};
testFun(tab,
function(key,val)   -- ��������<����˼�壬û�����֣�ֱ�ӵ���>
    return key.."="..val;
end
);
