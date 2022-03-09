#include<iostream>
using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
        cout << "无参构造函数调用" << endl;
    }
    ListNode(int x) : val(x), next(nullptr) {
        cout << "有参 val 构造函数调用" << endl;
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
        cout << "有参 val , *next 构造函数调用" << endl;
    }
};


 
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {

//     }
// };
void printList(ListNode* n)
{
    while (n != NULL) {
        cout << n->val << " ";
        n = n->next;
    }
}

int main()
{
    ListNode *m;
    
    m = new ListNode(3);
    
    //m->val = 5;
    // printList(m);

    delete m;
    return 0;
}