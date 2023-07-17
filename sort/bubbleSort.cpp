#include <iostream>
#include <vector>

using namespace std;

/*
 * 具体来说，冒泡排序的过程如下：
 * 从序列的第一个元素开始，依次比较每一对相邻的元素，如果前面的元素大于后面的元素，则交换它们的位置。
 * 继续比较序列中的下一对相邻元素，重复执行上述步骤，直到序列的最后一个元素。
 * 重复上述步骤，直到整个序列有序。
 * 冒泡排序的核心在于不断地交换相邻元素，通过每一轮比较和交换，将序列中最大（或最小）的元素逐渐“浮”到序列的顶端，然后继续对剩余的元素进行排序，直到整个序列有序。
 * 冒泡排序的时间复杂度为 O(n^2)，其中 n 是待排序的元素个数，因此在实际应用中，冒泡排序效率较低，但它是一种容易理解和实现的排序算法。
 */

// 冒泡排序 从小到大排序
void bubbleSort(vector<int> &vec)
{
    size_t len = vec.size();
    for (size_t i = len - 1; i > 0; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                int tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    vector<int> vec{59, 77, 70, 75, 84, 23, 23, 88, 88, 36};
    bubbleSort(vec);
    for (auto it : vec)
        cout << it << " ";
    return 0;
}