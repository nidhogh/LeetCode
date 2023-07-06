#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string addStrings(string num1, string num2) {
    bool equal = num1.length() == num2.length();
    bool big1 = true;
    if (num1.length() < num2.length()) {
        big1 = false;
    }
    string tmp = big1 ? num1 : num2;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string num3 = big1 ? num2 : num1;
    int minLen = min(num1.length(), num2.length());
    bool add1 = false;
    for (int i = 0; i < minLen; i++) {
        int n1 = num1.at(i) - '0';
        int n2 = num2.at(i) - '0';
        int n3 = n1 + n2;
        if (add1) {
            n3 += 1;
        }
        if (n3 > 9) {
            add1 = true;
            n3 = n3 - 10;
        } else {
            add1 = false;
        }
        char c = '0' + n3;
        num3[i] = c;
    }
    cout << "num3: " << num3 << endl;
    reverse(num3.begin(), num3.end());

    if (!equal) {
        int subLen = max(num1.length(), num2.length()) - minLen;
        string substr = tmp.substr(0, subLen);
        num3 = substr + num3;
        cout << "substr: " << substr << endl;
        if (add1) {
            for (int i = subLen - 1; i >= 0; i--) {
                if (num3[i] == '9') {
                    add1 = true;
                    num3[i] = '0';
                } else {
                    add1 = false;
                    num3[i] = num3[i] + 1;
                    break;
                }
            }
        }
    }
    if (add1) {
        num3 = '1' + num3;
    }
    //先拼上之前多出的部分，再在多出的部分加1，该进一位就进一位
    cout << "num3: " << num3 << endl;
    return num3;
}

int main() {
    addStrings("0", "0");
    return 0;
}
