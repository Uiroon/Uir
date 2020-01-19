#pragma once
class Function4 {
public:
	int find(vector<int> vec, int target)
	{
		int low = 0, high = vec.size() - 1;
		while (low < high)
		{
			int mid = (high + low) / 2;
			if (target < vec[mid])
			{
				high = mid - 1;
			}
			else if (target > vec[mid]) {
				low = mid + 1;
			}
			else {
				return mid;
			}
		}
		return -1;
	}

	static bool comp(const int& c1, const int& c2)
	{
		return c1 < c2;
	}
	Function4() {
		//==================˳���������===================
		vector<int> oderList;
		int oderListLength;
		int oderListInputtmp;
		system("cls");
		cout << "==================˳���������==================" << endl ;

		do {
			cout << "�����������ĳ��ȣ�";
			cin >> oderListLength;
		} while (oderListLength <= 0);

		for (int i = 0; i < oderListLength; i++) {
			cout << "�������" << i + 1 << "��Ԫ�أ�";
			cin >> oderListInputtmp;
			oderList.push_back(oderListInputtmp);
		}
		sort(oderList.begin(), oderList.end(), comp);
		cout << "------------------------------------------" << endl;

		cout << "˳����е�����Ϊ��" << endl;
		for (vector<int>::iterator it = oderList.begin(); it < oderList.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;

		random_shuffle(oderList.begin(), oderList.end());
		cout << "------------------------------------------" << endl;

		cout << "���Һ���е�����Ϊ��" << endl;
		for (vector<int>::iterator it = oderList.begin(); it < oderList.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;

		BTree<int> bt = BTree<int>();
		for (vector<int>::iterator it = oderList.begin(); it < oderList.end(); it++) {
			bt.Insert(bt.getRoot(), *it);
		}
		cout << "------------------------------------------" << endl;

		cout << "����������ǰ�������������Ϊ��";
		bt.PreOrder(bt.getRoot());
		cout << endl<<"�������������������������Ϊ��";
		bt.InOrder(bt.getRoot());
		cout << endl<<"���������պ��������������Ϊ��";
		bt.PostOrder(bt.getRoot());
		cout << endl;
		cout << "------------------------------------------" << endl;

		cout << "��������Ҫɾ����Ԫ�أ�";
		cin >> oderListInputtmp;
		bt.Delete(bt.getRoot(), oderListInputtmp);
		cout << "------------------------------------------" << endl;
		cout << "ɾ�������������ǰ�������������Ϊ��";
		bt.PreOrder(bt.getRoot());
		cout << endl<<"ɾ����������������������������Ϊ��";
		bt.InOrder(bt.getRoot());
		cout << endl<<"ɾ������������պ��������������Ϊ��";
		bt.PostOrder(bt.getRoot());
		cout << endl;

		sort(oderList.begin(), oderList.end(), comp);
		cout << "------------------------------------------" << endl;

		cout << "˳����е�����Ϊ��" << endl;
		for (vector<int>::iterator it = oderList.begin(); it < oderList.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
		cout << "------------------------------------------" << endl;

		cout << "������Ҫ���ҵ����ݣ�";
		cin >> oderListInputtmp;
		int loc;
		loc = find(oderList, oderListInputtmp);

		cout << "����" << oderListInputtmp << "�ڵ�ǰ˳���ĵ�" << loc + 1 << "��λ����" << endl;
		system("pause");
	}
};