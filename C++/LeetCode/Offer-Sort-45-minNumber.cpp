#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

/*
    输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

    先把int数组转化为string数组，再对数组进行排序，排序方法需要自定义，可以利用lambda表达式
    注意字符串也可以直接作比较，会逐位比较
    [](string& x, string& y){return x + y < y + x; } -- 该lambda表达式是该题的核心
*/

class MyCompare {
public:
    bool operator()(string str1, string str2) {
        return str1 + str2 < str2 + str1;
    }
};

string minNumber(vector<int>& nums) {
    vector<string> strs(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        strs[i] = to_string(nums[i]);
    }
    sort(strs.begin(), strs.end(), [](string& x, string& y){return x + y < y + x; });
    // 直接使用C++的Lambda表达式
    // sort(strs.begin(), strs.end(), MyCompare());
    string ans;
    for (string str : strs) {
        ans.append(str);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{3,30,34,5,9};
    cout << minNumber(nums) << endl;
    return 0;
}


// "101410891272160316131630210921162264230423624362439258126232709278828693288339334023513700372338663910394639639764088428943453245424555466247104787482250415137521352245228544154905526556556385731575258175828590660286145631063256406678768046822683686171007107219726572727440751975277584771781378805281618274830883083748382859185978701871877588238902898589959051952595569579632964298549959"
// "101410891272160316131630210921162264230423624362439258126232709278828693288339334023513700372338663910394639639764088428943453245424555466247104787482250415137521352245228544154905526556556385731575258175828590660286145631063256406678768046822683686171007107219726572727440751975277584771781378805281618274830830883748382859185978701871877588238902898589959051952595569579632964298549959"