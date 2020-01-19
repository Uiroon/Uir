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
			cout << endl << "========队列中的数据为空========" << endl << endl;
		}else{
			cout << endl << "========队列中的数据========" << endl << endl;
			Node<T>* p = list.getHead();
			int count = 1;
			while (p != NULL) {
				cout << "第" << count++ << "个数据为:" << p->data << endl;
				p = p->next;
			}
		}
		
	}
};