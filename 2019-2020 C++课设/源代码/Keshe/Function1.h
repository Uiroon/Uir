#pragma once
//==================������===================
class Function1 {
public:
	Function1(){
	int length = 0;
	int deleteNode;
	system("cls");
	cout << "==================������=================="<<endl<<"��������Ҫ����������ĳ���:";
	cin >> length;
	LinkList<int> list = LinkList<int>(length);
	list.Output();
	cout << endl << "��������Ҫɾ���Ľڵ��Ӧ��ֵ:";
	cin >> deleteNode;
	list.Delete(deleteNode);
	list.Output();
	system("pause");
	}
};
