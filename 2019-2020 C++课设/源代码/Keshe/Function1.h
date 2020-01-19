#pragma once
//==================链表部分===================
class Function1 {
public:
	Function1(){
	int length = 0;
	int deleteNode;
	system("cls");
	cout << "==================链表部分=================="<<endl<<"请输入需要创建的链表的长度:";
	cin >> length;
	LinkList<int> list = LinkList<int>(length);
	list.Output();
	cout << endl << "请输入需要删除的节点对应的值:";
	cin >> deleteNode;
	list.Delete(deleteNode);
	list.Output();
	system("pause");
	}
};
