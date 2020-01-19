#pragma once
template <class T>
class QueueList {
private :
	LinkList<T> list=LinkList<T>();
public:
	QueueList() {
		list = LinkList<T>();
	}
	~QueueList() {
		list.~LinkList();
	}
	void Init() {
		list = LinkList<T>();
	}
	void Push(T dataPush) {
		list.Add(list.getLength(), dataPush);
	}	
	T Pop() {
		if (list.getHead() == NULL) {
				return -1;
		}
		else{
			T tmp = list.getHead()->data;
			list.LocationDelete(0);
			return tmp;
		}
		
	}
	void Output() {
		if (list.getLength() == 0) {
			cout << endl << "========�����е�����Ϊ��========" << endl << endl;
		}else{
			cout << endl << "========�����е�����========" << endl << endl;
			Node<T>* p = list.getHead();
			int count = 1;
			while (p != NULL) {
				cout << "��" << count++ << "������Ϊ:" << p->data << endl;
				p = p->next;
			}
		}
		
	}
};