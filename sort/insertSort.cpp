#include <iostream>
#include <vector>

using namespace std;

/*
 * 插入排序是一种简单直观的排序算法，其基本思想是将待排序的元素分为已排序和未排序两部分。初始时，将第一个元素视为已排序的部分，剩余元素视为未排序的部分。然后逐一将未排序部分的元素插入到已排序部分的适当位置，直到所有元素都被插入到已排序部分为止。
 * 具体来说，假设要将一组元素按从小到大的顺序进行排序，插入排序的过程如下：
 * 从第二个元素开始，将其与已排序部分的最后一个元素进行比较。
 * 如果待插入元素比已排序部分的最后一个元素小（或等于），则将其插入到已排序部分的合适位置，否则将其插入到已排序部分的下一个位置。
 * 重复上述步骤，直到所有元素都被插入到已排序部分为止。
 * 插入排序的时间复杂度为O(n^2)，其中n为待排序元素的个数。尽管其时间复杂度较高，但是在实际应用中，插入排序的常数项较小，对小规模数据的排序效率较高。此外，插入排序也是稳定排序算法，即相等元素的相对位置不会改变。
 */

// 插入排序 从小到大
void insertSort(vector<int> &vec)
{
    size_t len = vec.size();
    for (size_t i = 1; i < len; i++)
    {
        if (vec[i] < vec[i - 1])
        {
            for (size_t j = 0; j < i; j++)
            {
                if (vec[i] < vec[0])
                {
                    vec.insert(vec.begin(), vec[i]);
                    break;
                }
                else if (vec[j] <= vec[i] && vec[i] <= vec[j + 1])
                {
                    vec.insert(vec.begin() + j + 1, vec[i]);
                    break;
                }
            }
            vec.erase(vec.begin() + i + 1);
        }
        cout << "i = " << i << endl;
        for (auto it : vec) {
            cout << it << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<int> vec{59, 77, 70, 75, 84, 23, 23, 88, 88, 36};
    insertSort(vec);
    return 0;
}