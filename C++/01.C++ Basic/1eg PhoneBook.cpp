#include<iostream>
using namespace std;
#include<string>
#define Max 100

struct Contacts
{
    string name;
    int sex;
    int age;
    string phone;
};

struct AddressBook
{
    Contacts contacts[Max];
    int size;   // 存储当前电话本大小
};




void showMeau()
{
    cout<<"---------------选择功能---------------"<< endl;
    cout<<"-------------1-添加联系人-------------"<< endl;
    cout<<"-------------2-显示联系人-------------"<< endl;
    cout<<"-------------3-删除联系人-------------"<< endl;
    cout<<"-------------4-查找联系人-------------"<< endl;
    cout<<"-------------5-修改联系人-------------"<< endl;
    cout<<"-------------6-清空联系人-------------"<< endl;
    cout<<"-------------0-退出通讯录-------------"<< endl;
}
void addContacts(Contacts contacts[], int * count)
{
    cout << "输入姓名：";
    cin >> contacts[*count].name;
    int newsex;
    cout << "输入性别（男为0，女为1）：";
    while(1)
    {
        cin >> newsex;
        if (newsex == 1 || newsex == 0)
        {
            contacts[*count].sex = newsex;
            break;
        }
        else
        {
            cout << "输入错误" << endl;
        }
    }
    cout << "输入年龄：";
    cin >> contacts[*count].age;
    cout << "输入电话：";
    cin >> contacts[*count].phone;
    *count = *count + 1;
    cout << "添加成功" << endl;
    showMeau();
}

void showContacts(Contacts contacts[], int * count)
{
    if (*count == 0)
    {
        cout << "当前没有联系人" << endl;
    }
    else
    {
        cout << "test" << endl;
        for (int i = 0; i < *count; i++)
        {
            string truesex;
            if (contacts[i].sex == 0) truesex = "男";
            if (contacts[i].sex == 1) truesex = "女";
            cout << "姓名：" << contacts[i].name << "\t性别：" << truesex << "\t年龄：" << contacts[i].age << "\t电话：" << contacts[i].phone << endl;
        }
        cout << "显示成功" << endl;
    }
    showMeau();
}

void deleteContacts(Contacts contacts[], int * count, string name)
{
    int target = 0;
    for (int i = 0; i < *count; i++)
    {
        if (contacts[i].name == name)
        {
            target = 1;
            for (int j = i; j < *count; j++)
            {
                contacts[j] = contacts[j+1];
            }
            *count = *count - 1;
            break;
        }
    }
    if(target == 1)
    {
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "未找到该联系人" << endl;
    }
    showMeau();
}

void searchContacts(Contacts contacts[], int * count, string name)
{
    for (int i = 0; i < *count; i++)
    {
        if (contacts[i].name == name)
        {
            cout << "姓名：" << contacts[i].name << "，性别：" << contacts[i].sex << "，年龄：" << contacts[i].age << "，电话：" << contacts[i].phone << endl;
            break;
        }
    }
    cout << "查找成功" << endl;
    showMeau();
}

void changeContacts(Contacts contacts[], int * count, string name, int option)
{
    if (option == 1)
    {
        for (int i = 0; i < *count; i++)
        {
            if (contacts[i].name == name)
            {
                string newname;
                cout << "输入新的姓名：";
                cin >> newname;
                contacts[i].name = newname;
                break;
            }
            else
            {
                cout << "未找到该联系人" << endl;
            }
        }
    }
    else if (option == 2)
    {
        for (int i = 0; i < *count; i++)
        {
            if (contacts[i].name == name)
            {
                int newsex;
                cout << "输入新的性别：";
                cin >> newsex;
                contacts[i].sex = newsex;
                break;
            }
            else
            {
                cout << "未找到该联系人" << endl;
            }
        }
    }
    else if (option == 3)
    {
        for (int i = 0; i < *count; i++)
        {
            if (contacts[i].name == name)
            {
                int newage;
                cout << "输入新的年龄：";
                cin >> newage;
                contacts[i].age = newage;
                break;
            }
            else
            {
                cout << "未找到该联系人" << endl;
            }
        }
    }
    else if (option == 4)
    {
        for (int i = 0; i < *count; i++)
        {
            if (contacts[i].name == name)
            {
                string newphone;
                cout << "输入新的电话：";
                cin >> newphone;
                contacts[i].phone = newphone;
                break;
            }
            else
            {
                cout << "未找到该联系人" << endl;
            }
        }
    }
    else
    {
        cout << "输入错误" << endl;
    }
    cout << "修改成功" << endl;
    showMeau();
}

void clearContacts(Contacts contacts[], int * count)
{
    *count = 0;
    cout << "清除成功" << endl;
}

int main()
{
    AddressBook addressBook;
    addressBook.size = 0;
    showMeau();
    while (1)
    {
        cout << "选择要执行的功能：";
        int i;
        cin >> i;
        if (i == 1)
        {
            if (addressBook.size > Max)
            {
                cout << "通讯录已满" << endl;
            }
            else
            {
                addContacts(addressBook.contacts, &addressBook.size);
            }
        }
        else if (i == 2)
        {
            showContacts(addressBook.contacts, &addressBook.size);
        }
        else if (i == 3)
        {
            string name;
            cout << "输入需要删除的联系人的姓名：";
            cin >> name;
            deleteContacts(addressBook.contacts, &addressBook.size, name);
        }
        else if (i == 4)
        {
            string name;
            cout << "输入需要查找的联系人的姓名：";
            cin >> name;
            searchContacts(addressBook.contacts, &addressBook.size, name);
        }
        else if (i == 5)
        {
            string name;
            cout << "输入需要修改的联系人的姓名：";
            cin >> name;
            int option;
            cout << "输入需要修改的选项，修改姓名输入1，修改性别输入2，修改年龄输入3，修改电话输入4：";
            cin >> option;
            changeContacts(addressBook.contacts, &addressBook.size, name, option);
        }
        else if (i == 6)
        {
            clearContacts(addressBook.contacts, &addressBook.size );
        }
        else if (i == 0)
        {
            break;
        }
        else
        {
            cout << "输入错误" << endl;
        }
    }
    system("pause");
    return 0;
}
