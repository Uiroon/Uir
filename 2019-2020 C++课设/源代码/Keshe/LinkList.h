#pragma once

template<class T>
class LinkList {
private:
	Node<T>* head;
public:
	LinkList() {
		head = NULL;
	}
	~LinkList() {
		Node<T>* del = new Node<T>();
		while (head != NULL) {
			del = head->next;
			delete head;
			head = del;
		}
		delete head;
	}
	LinkList(int num) {
		Node<T>* p = new Node<T>();
		Node<T>* s = new Node<T>();
		T x;
		for(int i = 0; i < num;i++) {
			cout << "�������" << i+1 << "�����ݣ�";
			cin >> x;
			s = new Node<T>();
			s->data = x;
			if (head == NULL) {
				head = s;
			}
			else {
				p->next = s;
			}
			p = s;
		}
		p->next = NULL;
		if (head != NULL) {
			cout << endl<<"========�������========" << endl<<endl;
		}
		else {
			cout <<endl<< "========����Ϊ��========" << endl<<endl;
		}
		this->Sort();
	}
	void Output() {
		if (this->getLength() == 0) {
			cout << endl << "========�����е�����Ϊ��========" << endl << endl;
		}else{
			cout << endl << "========�����е�����========" << endl << endl;
			Node<T>* p = head;
			int count = 1;
			while (p != NULL) {
				cout << "��" << count++ << "������Ϊ:" << p->data << endl;
				p = p->next;
			}
		}
		
	}
	void Delete(T data1) {
		Node<T>* p = head;
		Node<T>* s=new Node<T>();
		while (data1 != p->data && p->next != NULL) {
			s = p;
			p = p->next;
		}
		if (data1 == p->data) {
			if (p == head) {
				head = p->next;
			}
			else {
				s->next = p->next;
			}
			delete p;
			cout << "ɾ���ɹ�" << endl << endl;
		}
		else {
			cout << "�޸�����" << endl << endl;
		}
	}
	void LocationDelete(int location) {
		int count = 0;
		Node<T>* p = head;
		Node<T>* s = new Node<T>();
		if (location > this->getLength()) {
			cout << "�������ȣ��޷�ɾ��";
		}
		else if (location < 0) {
			cout << "ɾ��λ�ò���С����";
		}
		else if (location == 0 && head != NULL&&head->next!=NULL) {

			s = p->next;
			head=s;
		}
		else if (location == 0 && head != NULL && head->next == NULL) {
			head = NULL;
		}
		else if (location == 0 && head == NULL) {
			cout << "����Ϊ�գ��޷�ɾ��";
		}
		else {
			for (p; count < location - 1; p = p->next, count++) {
			}
			s=p->next;
			p->next = s->next;

		}
	}
	void Sort() {
		Node<T>* p = new Node<T>();
		Node<T>* q = new Node<T>();
		for (p = head; p->next != NULL; p = p->next)
		{
			for (q = head; q->next != NULL; q= q->next)
				if (q->data > q->next->data) {
					swap(q->data, q->next->data);
					/*T tmp;
					tmp = q->data;
					q->data = q->next->data;
					q->next->data = tmp;*/
				}
		}
	}
	void Add(int location,T data1) {
		Node<T>* p = head;
		Node<T>* s = new Node<T>();
		Node<T>* tmp = new Node<T>();
		int count = 0;
		if (location > this->getLength()) {
			cout << "�������ȣ��޷�����";
		}
		else if (location < 0) {
			cout << "����λ�ò���С����";
		}
		else if (location == 0&&head!=NULL) {
			s->data = data1;
			s->next = head;
			head = s;
		}
		else if (location == 0 && head == NULL) {
			s->data = data1;
			s->next = NULL;
			head = s;
		}else {
			for (p; count < location-1; p = p->next,count++) {
			}
			s->data = data1;
			s->next=p->next;
			p->next = s;

		}
	}
	int getLength() {
		Node<T>* p = head;
		Node<T>* s = new Node<T>();
		int count = 0;
		if (p == NULL) {
			return count;
		}
		else {
			count = 1;
			for (p; p->next != NULL; p = p->next) {
				count++;
			}
			return count;
		}
	}
	Node<T>* getHead() {
		
		return head;
	}
	void swap(T& a, T& b) {
		T tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
};