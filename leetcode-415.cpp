#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

//add-strings
string addStrings(string num1, string num2) {
    //字符串相加前先反转
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    //保证num1到长度大于等于num2，否则交换
    if (num1.length() < num2.length()) {
        string tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
    int len1 = num1.length();
    int len2 = num2.length();
    //num2如果比num1短，要补0
    if (len1 != len2) {
        for (int i = 0; i < len1 - len2; i++) {
            num2 += '0';
        }
    }
    //依次相加
    int add = 0;     //是否进一位
    for (int i = 0; i < len1; i++) {
        int n1 = num1.at(i) - '0';
        int n2 = num2.at(i) - '0';
        num1[i] = '0' + (n1 + n2 + add) % 10;
        add = (n1 + n2 + add) > 9 ? 1 : 0;
    }

    if (add) {
        num1 += '1';
    }
    
    //反转num1
    reverse(num1.begin(), num1.end());
    
    return num1;
}

int main()
{
    addStrings("9", "99");
    std::cout << "hello world!\n";
}