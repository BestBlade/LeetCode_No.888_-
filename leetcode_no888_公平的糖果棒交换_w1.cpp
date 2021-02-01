/* ------------------------------------------------------------------|
爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j] 是鲍勃拥有的第 j 根糖果棒的大小。

因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。

 

示例 1：

输入：A = [1,1], B = [2,2]
输出：[1,2]
示例 2：

输入：A = [1,2], B = [2,3]
输出：[1,2]
示例 3：

输入：A = [2], B = [1,3]
输出：[2,3]
示例 4：

输入：A = [1,2,5], B = [2,4]
输出：[5,4]
 

提示：

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
保证爱丽丝与鲍勃的糖果总量不同。
答案肯定存在。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fair-candy-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：88 ms, 在所有 C++ 提交中击败了98.26%的用户
*	内存消耗：42.7 MB, 在所有 C++ 提交中击败了70.75%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    //直接构造要节省很多内存
    unordered_set<int> setb(B.begin(), B.end());
    //int diff = accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0);
    int diff = 0;
    for (int& i : A) {
        diff += i;
    }
    for (int& i : B) {
        diff -= i;
    }

    diff /= 2;
    vector<int> res;
    for (int& iter : A) {
        if (setb.find(iter - diff) != setb.end()) {
            res = { iter,iter - diff };
            break;
        }
    }
    return res;
}