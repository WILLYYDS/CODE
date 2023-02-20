#include<iostream>
using namespace std;
#include "String.h"

void String::error(const char* msg) const
{
	cout << "ERROR: " << msg << endl;
}

bool String::in_bounds(int i) const
{
	return i >= 0 && i < ListNode::list_length(head);
}

String::String(List L)
{
	head = L;
}

String::String(const char* s)
{
	head = ListNode::list_from_string(s);
}

String::String(const String& s)
{
	head = ListNode::list_copy(s.head);
}

String::String(String&& s)
{
	head = s.head;
	s.head = nullptr;
}

String& String::operator = (String&& s)
{
	if (this != &s)
	{
		ListNode::list_delete(head);
		head = s.head;
		s.head = nullptr;
	}
	return *this;
}

String& String::operator = (const String& s)
{
	if (this != &s)
	{
		ListNode::list_delete(head);
		head = ListNode::list_copy(s.head);
	}
	return *this;
}

char& String::operator [] (int index)
{
	if (!in_bounds(index))
	{
		error("index out of bounds");
	}
	return ListNode::list_nth(head, index)->data;
}

int String::size() const
{
	return ListNode::list_length(head);
}

String String::reverse() const
{
	return String(ListNode::list_reverse(head));
}

int String::indexOf(const char c) const
{
	List L = head;
	int i = 0;
	while (L)
	{
		if (L->data == c)
		{
			return i;
		}
		L = L->next;
		i++;
	}
	return i;
}

int String::indexOf(const String s) const
{
	List L2 = s.head;
	return ListNode::list_difference(head, L2);
}

bool String::operator == (const String s) const
{
	List L2 = s.head;
	return ListNode::list_cmp(head, L2) == 0;
}

bool String::operator != (const String s) const
{
	List L2 = s.head;
	return ListNode::list_cmp(head, L2) != 0;
}

bool String::operator > (const String s) const
{
	List L2 = s.head;
	return ListNode::list_cmp(head, L2) > 0;
}

bool String::operator < (const String s) const
{
	List L2 = s.head;
	return ListNode::list_cmp(head, L2) < 0;
}

bool String::operator <= (const String s) const
{
	List L2 = s.head;
	return ListNode::list_cmp(head, L2) <= 0;
}

bool String::operator >= (const String s) const
{
	List L2 = s.head;
	return ListNode::list_cmp(head, L2) >= 0;
}

String String::operator +(const String s) const
{
	if (!head) return String(ListNode::list_copy(s.head));
	List L = ListNode::list_append(head, s.head);
	return String(L);
}

String& String::operator +=(const String s)
{
	List L2 = ListNode::list_copy(s.head);
	List L1 = head;
	if (!L1) head = L2;
	else
	{
		List L3 = L1;
		while (L3->next)
		{
			L3 = L3->next;
		}
		L3->next = L2;
	}
	//List L1 = head;
	//head = ListNode::list_append(head, s.head);
	//ListNode::list_delete(L1);
	//return *this;
}

void String::print(ostream& out) const
{
	ListNode::print(out, head);
}

void String::read(istream& in)//read
{
	ListNode::list_delete(head);
	char temp [1000];
	in >> temp;
	head = ListNode::list_from_string(temp);
}

String::~String()
{
	ListNode::list_delete(head);
}

ostream& operator << (ostream& out, const String s)
{
	s.print(out);
	return out;
}

istream& operator >>(istream& in, String& s)
{
	s.read(in);
	return in;
}