#pragma once
template < class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node()
	{
		this->next = NULL;
	}
};
