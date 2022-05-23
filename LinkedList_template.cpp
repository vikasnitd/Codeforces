#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    
    int val;
    ListNode *next;
    ListNode(): val(0), next(NULL){}
    ListNode(int _val): val(_val), next(NULL){}
    ListNode(int _val, ListNode *_next): val(_val), next(_next){}
};

class solution {
public:
    void printLinkedList(ListNode *head) {

        while(head) {

            cout<<head->val<<"\n";
            head = head->next;
        }
    }
};
int main() {
  
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ListNode *secondNode = new ListNode(5);
    ListNode *firstNode = new ListNode(11, secondNode);

    solution solutionObj;
    solutionObj.printLinkedList(firstNode);

    return 0;
}