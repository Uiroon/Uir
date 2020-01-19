#pragma once
template <class T>
class BTree {
	bNode<T>* root=new bNode<T>();
public:
	BTree() {		
		root = NULL;
	}
	bNode<T>* sInsert(bNode<T>* node, T insert) {
		if (node == NULL) {	
				node = new bNode<T>();
				node->data = insert;
				node->left = NULL;
				node->right = NULL;	
		}
		else if (node->data >= insert) {
			node->left=sInsert(node->left, insert);
		}
		else if (node->data < insert) {
			node->right=sInsert(node->right, insert);
		}
		return node;
	}
	void Insert(bNode<T>* node, T insert) {
		root = sInsert(node,insert);
	}
	bNode<T>* sDelete(bNode<T>* node, T target) {
		if (node == NULL) {
			cout << "无该数据";
			return node;
		}
		else if (node->data == target) {
			if (node->left == NULL && node->right == NULL) {
				delete node;
				node = NULL;
			}
			else if (node->left != NULL && node->right == NULL) {
				bNode<T>* tmp = node;
				node = tmp->left;
				delete tmp;
			}
			else if (node->left == NULL && node->right != NULL) {
				bNode<T>* tmp = node;
				node = tmp->right;
				delete tmp;
			}
			else if (node->left != NULL && node->right != NULL) {
				bNode<T>* tmp = node->right;
				while (tmp->left != NULL) 
				{ 
					tmp = tmp->left; 
				}
				node->data = tmp->data;
				node->right=sDelete(node->right, tmp->data);
			}
		}
		else if (node->data < target) {
			node->right=sDelete(node->right, target);
		}
		else if (node->data > target) {
			node->left=sDelete(node->left, target);
		}
		return node;
	}
	void Delete(bNode<T>* node, T target) {
		root = sDelete(node, target);
	}
	void PreOrder(bNode<T>* p)//前序遍历
	{
		if (p == NULL)
			return;
		cout << p->data << " ";
		PreOrder(p->left);
		PreOrder(p->right);
	}
	void InOrder(bNode<T>* p)//中序遍历
	{
		if (p==NULL)
			return;
		InOrder(p->left);
		cout << p->data << " ";
		InOrder(p->right);
	}
	void PostOrder(bNode<T>* p)//前序遍历
	{
		if (p == NULL)
			return;
		PostOrder(p->left);
		PostOrder(p->right);
		cout << p->data << " ";
	}
	bNode<T>* getRoot() {
		return root;
	}
};