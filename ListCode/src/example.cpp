#include <ListCode/example.hpp>

namespace ListCode
{
    namespace Solution01{
        ListNode *Solution::removeElements(ListNode *head, int val)
        {   
            // 不需要两个指针的
            // if (!head)
            //     return head;

            // ListNode *curNode = head, *preNode = head;
            // while (true)
            // {
            //     if (curNode->val != val)
            //     {
            //         preNode = curNode;       // 指向这个节点
            //         curNode = curNode->next; // 指向当前的下一个节点
            //     }
            //     else
            //     {
            //         ListNode * delNode = preNode->next;
            //         preNode->next = curNode->next;
            //         curNode = curNode->next;
            //         delete delNode;
                    
            //     }
            //     if (!(preNode->next))
            //         break;
            // }
            // if(head->val==val) {
            //     ListNode * delNode = head;
            //     head = head->next;
            //     delete delNode;
            // };
            // return head;

            // 更好的方法 1 (不带空头节点的)
            // 对头节点特殊处理 这里是 while 先将头节点处理干净
            // while(head != nullptr && head->val==val){
            //     ListNode * tmp = head;
            //     head = head->next;
            //     delete tmp;
            // }

            // // 删除非头节点
            // ListNode * cur = head;
            // while(cur != nullptr && cur->next != nullptr){
            //     if(cur->next->val == val){
            //         ListNode *tmp = cur->next;
            //         cur->next = cur->next->next;
            //         delete tmp;
            //     }else{
            //         cur = cur->next;
            //     }
            // }

            // return head;

            // 更好的方法2(带头节点的)
            ListNode *dummyNode = new ListNode(val-1);
            dummyNode->next = head;

            ListNode *cur = dummyNode;
            while (cur->next!=nullptr)
            {
                if(cur->next->val==val){
                    ListNode *tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                }else{
                    cur = cur->next;
                }
            }

            head = dummyNode->next;
            delete dummyNode;

            return head;
        }
    }

    namespace Solution02{
        MyLinkedList::MyLinkedList():
        _dummyNode(new ListNode(0)), _numNode(0)
        {
        }

        int MyLinkedList::get(int index) const {
            if(index >= _numNode)
                return -1;
            
            ListNode *cur = _dummyNode;
            for(int i=0; i<=index; ++i){
                cur = cur->next;
            }

            return cur->val;
        }

        void MyLinkedList::addAtHead(int val){
            ListNode *tmp = _dummyNode->next;
            _dummyNode->next = new ListNode(val);
            _dummyNode->next->next = tmp;
            ++_numNode;
        }

        void MyLinkedList::addAtTail(int val){
            ListNode *cur = _dummyNode;
            for(int i=0; i<_numNode; ++i){
                cur = cur->next;
            }
            cur->next = new ListNode(val);
            ++_numNode;
        }

        void MyLinkedList::addAtIndex(int index, int val){
            if(index>_numNode)
                return;
            if(index==_numNode){
                addAtTail(val);
                return;
            }
            if(index<_numNode){
                ListNode *cur = _dummyNode;
                for(int i=0; i<index; ++i){
                    cur = cur->next;
                }
                ListNode *tmp = cur->next;
                cur->next = new ListNode(val);
                cur->next->next = tmp;
                ++_numNode;
            }
        }

        void MyLinkedList::deleteAtIndex(int index){
            if(index >= _numNode)
                return;
            
            ListNode *cur = _dummyNode;
            for(int i=0; i<index; ++i){
                cur = cur->next;
            }
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            --_numNode;
        }
    }

    namespace Solution03{
        ListNode* Solution::reverseList(ListNode* head){
            // 重新定义一个链表, 是浪费了内存
            // ListNode *rev = new ListNode(0);  // 有虚拟头节点
            // while (head!=nullptr)
            // {
            //     ListNode * tmp = rev->next;
            //     rev->next = head;
            //     head = head->next;
            //     rev->next->next = tmp;
            // }
            // return rev->next;
            
            // 直接在原链表的基础上进行反转 节省了内存
            ListNode *pre=nullptr, *cur = head;
            while(head){
                ListNode * tmp = cur->next;
                cur->next = pre;
                if(!tmp) break;
                pre = cur;
                cur = tmp;
            }
            return cur;
        }
    }    

    namespace Solution04{
        ListNode* Solution::swapPairs(ListNode* head){
            // 添加虚拟节点
            ListNode *dummyNode = new ListNode(0);
            dummyNode->next = head;

            ListNode *cur = dummyNode;
            while(true){
                if(!(cur->next && cur->next->next))
                    break;
                ListNode * firstNode = cur->next;
                ListNode * thirdNode = firstNode->next->next;
                cur->next = firstNode->next;
                cur->next->next = firstNode;
                cur->next->next->next = thirdNode;
                cur = cur->next->next;
            }
            return dummyNode->next;
        }
    }

    namespace Solution05{
        ListNode * Solution::removeNthFromEnd(ListNode* head, int n){
            // 添加虚拟节点
            ListNode *dummyNode = new ListNode(0);
            dummyNode->next = head;

            int dist = 0;  // 快指针与慢指针之间的距离
            ListNode *preDelNode = dummyNode, *fastNode = dummyNode;
            while (fastNode)
            {
                if(dist<=n){
                    fastNode = fastNode->next;
                    ++dist;
                }else{
                    preDelNode = preDelNode->next;
                    --dist;
                }
            }
            if(dist=n){
                ListNode *tmp = preDelNode->next;
                preDelNode->next = preDelNode->next->next;
                delete tmp;
            }
            return dummyNode->next;
        }
    }

    namespace Solution06{
        ListNode * Solution::getIntersectionNode(ListNode *headA, ListNode *headB){
            int numA = 0, numB = 0;
            ListNode *curA = headA, *curB = headB;
            while (curA)
            {
                ++numA;
                curA = curA->next;
            }

            while (curB)
            {
                ++numB;
                curB = curB->next;
            }

            curA = headA, curB = headB;
            ListNode *inter{nullptr};

            if (numB > numA)
            {
                for (int i = 0; i < numB - numA; ++i)
                {
                    curB = curB->next;
                }
            }
            else if (numB < numA)
            {
                for (int i = 0; i < numA - numB; ++i)
                {
                    curA = curA->next;
                }
            }
            else
            {
            }

            while (curA && curB)
            {
                if (curA->val == curB->val)
                {
                    inter = curA;
                    break;
                }
                else
                {
                    curA = curA->next;
                    curB = curB->next;
                }
            }
            return inter;
        }
    }
}
