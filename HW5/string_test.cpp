#include <iostream>
#include "String.h"


void test_list_from_string_and_print()
{
	cout << "TESTS: list_from_string_and_print" << endl;
	List L1 = ListNode::list_from_string("Hello");
	List L2 = ListNode::list_from_string("World");
	ListNode::print(cout, L1);
	ListNode::print(cout, L2);
	cout << endl;
	ListNode::list_delete(L1);
	ListNode::list_delete(L2);	
}

void test_list_append()
{
	cout << "TESTS: list_append" << endl;
	List L1 = ListNode::list_from_string("Hello");
	List L2 = ListNode::list_from_string("World");
	List C = ListNode::list_append(L1, L2);
	ListNode::print(cout, C);
	cout << endl;
	ListNode::list_delete(L1);
	ListNode::list_delete(L2);
	ListNode::list_delete(C);
}

void test_list_reverse()
{
	cout << "TESTS: list_reverse" << endl;
	List L1 = ListNode::list_from_string("Hello");
	List L2 = ListNode::list_from_string("World");
	List C = ListNode::list_append(L1, L2);
	List R = ListNode::list_reverse(C);
	ListNode::print(cout, R);
	cout << endl;
	ListNode::list_delete(L1);
	ListNode::list_delete(L2);
	ListNode::list_delete(C);
	ListNode::list_delete(R);
}

void test_concatenate()
{
	cout << "TESTS: concatenate" << endl;
	String s1("abcd");
	String s2("efg");
	String s3 = s1 + s2;
	s3.print(cout);
	cout << endl;
}
int main()
{
	test_list_from_string_and_print();
	test_list_append();
	test_list_reverse();
	
	//test_constructors_and_print();
	//test_assignment();
	//test_relationals();
	//test_reverse();
	test_concatenate();
	//test_indexOf();

	ListNode::report_allocations();
	return 0;
}