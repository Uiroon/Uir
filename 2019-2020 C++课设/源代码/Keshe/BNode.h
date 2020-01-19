#pragma once
template <class T>
class bNode {
public:
	T data;
	bNode<T>* left;
	bNode<T>* right;
	bNode()
	{
		this->left = NULL;
		this->right = NULL;
	}
};