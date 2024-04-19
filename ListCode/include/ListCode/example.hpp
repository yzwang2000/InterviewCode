#pragma once

#include <vector>
#include <iostream>

// 链表的定义
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int value) : val(value){};
};

namespace ListCode
{
    // 产生链表
    inline void generateList(ListNode *& head,  std::vector<int> arr){
        ListNode * curNode;
        for(int val: arr){
            if(!head){
                head = new ListNode(val);
                curNode = head;
            }else{
                curNode->next = new ListNode(val);
                curNode = curNode->next;
            }
        }
    }

    // 打印链表
    inline void printList(ListNode * head){
        if(!head) std::cout << "[]" ;
        while (true)
        {
            if(!head) break;
            std::cout << head->val << " ";
            if(head->next){
                head = head->next;
            }else{
                break;
            }
        }
        std::cout << std::endl;
    }

    namespace Solution01
    {
        class Solution
        {
        public:
            static ListNode *removeElements(ListNode *head, int val);
        };
    }

    namespace Solution02{
        class MyLinkedList
        {
        public:
            MyLinkedList();
            int get(int index) const;
            void addAtHead(int val);
            void addAtTail(int val);
            void addAtIndex(int index, int val);
            void deleteAtIndex(int index);
        
        private:
            ListNode * _dummyNode;   // 虚拟头指针
            size_t _numNode;         // 节点个数
        };
    }

    namespace Solution03{
        class Solution{
        public:
            static ListNode* reverseList(ListNode* head);
        };
    }

    namespace Solution04{
        class Solution
        {
        public:
            static ListNode* swapPairs(ListNode* head);
        };
    }

    namespace Solution05{
        class Solution 
        {
        public:
            static ListNode* removeNthFromEnd(ListNode* head, int n);
        };
    }

    namespace Solution06{
        class Solution{
        public:
            static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
        };
    }

}