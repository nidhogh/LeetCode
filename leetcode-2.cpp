#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int i = 0, add = 0;
    ListNode* ret = new ListNode();
    ListNode* node = ret;
    do {
        int val_1 = (l1) ? l1->val : 0;
        int val_2 = (l2) ? l2->val : 0;
        node->val = (val_1 + val_2 + add) % 10;     //val相加
        add = (val_1 + val_2 + add) > 9 ? 1 : 0;    //是否需要进一位

        node->next = new ListNode();

        if ((nullptr == l1 || nullptr == l1->next) && (nullptr == l2 || nullptr == l2->next)) {
            if (1 == add) {
                node->next->val = 1;
            } else {
                node->next = nullptr;
            }
            break;
        } else {
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            node = node->next;
        }
    } while (true);

    //打印返回值（链表）
    ListNode* tmp = ret;
    do {
        cout << " val: " << tmp->val;
        tmp = tmp->next;
    } while (tmp->next);

    return ret;
}

int main()
{
    vector<ListNode*> vec;
    for (int i = 0; i < 7; i++) {
        vec.push_back(new ListNode(9));
        if (i > 0) {
            vec[i]->next = vec[i - 1];
        }
    }
    vector<ListNode*> vec2;
    for (int i = 0; i < 4; i++) {
        vec2.push_back(new ListNode(9));
        if (i > 0) {
            vec2[i]->next = vec2[i - 1];
        }
    }
    addTwoNumbers(vec[6], vec2[3]);
    return 0;
}