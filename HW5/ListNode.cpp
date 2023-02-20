#include<iostream>
#include "ListNode.h"
using namespace std;

int ListNode::total_allocations = 0;
int ListNode::net_allocations = 0;
int ListNode::total_bytes = 0;

List ListNode::list_from_string(const char* s)//char转换成List
{
    if (s == nullptr) return nullptr;
    List L = nullptr;
    List L1 = L;
    for (int i = 0; s[i] != '\0'; i++)
    {
        List temp = new ListNode(s[i], nullptr);
        if (L == nullptr)
        {
            L = temp;
            L1 = temp;
        }
        else
        {
            L1->next = temp;
            L1 = L1->next;
        }
    }
    return L;
}

List ListNode::list_copy(List L)
{
    List L3 = L;
    List L1 = nullptr;
    List L2 = L1;
    while (L3)
    {
        List temp = new ListNode(L3->data, nullptr);
        if (L1 == nullptr)
        {
            L1 = temp;
            L2 = temp;
        }
        else
        {
            L2->next = temp;
            L2 = temp;
        }
        L3 = L3->next;
    }
    return L1;
    //return !L ? nullptr : new ListNode(L->data, list_copy(L->next));
    // L  nullptr -> false     !L  true    
}
List ListNode::list_reverse(List L)
{
    List head = nullptr;
    List L1 = L;
    while (L1)
    {
        List temp = new ListNode(L1->data, nullptr);
        temp->next = head;
        head = temp;
        L1 = L1->next;
    }
    return head;
}
List ListNode::list_append(List L1, List L2)
{
    List L3 = list_copy(L1);
    List L4 = list_copy(L2);
    List L5 = L3;
    if (L3 == nullptr) return L4;
    while (L5->next)
    {
        L5 = L5->next;
    }
    L5->next = L4;
    return L3;
}
List ListNode::list_str(List haystack, List needle)
{
    List L1 = haystack;
    List L2 = needle;
    if (L2 == nullptr)
    {
        return nullptr;
    }
    while (L1)
    {
        if (L1->data == L2->data)
        {
            List L3 = L1;
            while (L2 && L3)
            {
                if (L3->data != L2->data)
                {
                    break;
                }
                L3 = L3->next;
                L2 = L2->next;
            }
            if (!L2)
            {
                return L1;
            }
            L2 = needle;
        }
        L1 = L1->next;
    }
    return nullptr;
}
List ListNode::list_chr(List str, int c)//找c在str中第一次出现的位置
{
    List L1 = str;
    while (L1)
    {
        if (L1->data == c)
        {
            return L1;
        }
        L1 = L1->next;
    }
    return nullptr;
}
List ListNode::list_nth(List str, int n)//找第n位的头指针
{
    if (str == nullptr) return nullptr;
    return n == 0 ? str : list_nth(str->next, n - 1);
    // for(int i = 0; i < n; i++)
    // {
    //     if(!str)
    //     {
    //         return nullptr;
    //     }
    //     str = str->next;
    // }
    // return str;
}
void ListNode::list_delete(List L)
{
    if (!L) return;
    list_delete(L->next);
    delete L;
}

void ListNode::print(ostream& out, List L)
{
    List L1 = L;
    while (L1 != nullptr)
    {
        out << L1->data;
        L1 = L1->next;
    }
}
int ListNode::list_difference(List L1, List L2)//第一次出现L2在L1中的指针出现的index
{
    int num = 0;
    if (L2 == nullptr || L2->data == '\0')
    {
        return list_length(L1);
    }
    List L3 = L1;
    while (L3)
    {
        if (L3->data != L2->data)
        {
            num++;
        }
        else
        {
            List L4 = L2;
            List L5 = L3;
            while (L4 && L5)
            {
                if (L5->data != L4->data)
                {
                    num = num + 1;
                    break;
                }
                L4 = L4->next;
                L5 = L5->next;
            }
            if (!L4)
            {
                return num;
            }
        }
        L3 = L3->next;
    }
    return -1;
}
List ListNode::list_last(List L)//找最后一位
{
    if (!L) return nullptr;
    while (L->next)
    {
        L = L->next;
    }
    return L;
}
int ListNode::list_cmp(List L1, List L2)
{
    if (!L1 && !L2) return 0;
    if (!L1) return -1;
    if (!L2) return 1;
    if (L1->data < L2->data) return -1;
    if (L1->data > L2->data) return 1;
    return list_cmp(L1->next, L2->next);
}
int ListNode::list_ncmp(List L1, List L2, int n)//比较前面n位里面的值
{
    if (!L1 && !L2) return 0;
    if (!L1) return -1;
    if (!L2) return 1;
    if (L1->data < L2->data) return -1;
    if (L1->data > L2->data) return 1;
    return n == 1 ? 0 : list_ncmp(L1->next, L2->next, n - 1);
}
int ListNode::list_length(List L)
{
    // int l = 0;
    // while(L != nullptr)
    // {
    //     l++;
    //     L = L->next;
    // }
    // return l;
    return !L ? 0 : 1 + list_length(L->next);
}