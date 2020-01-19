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
		//==================顺序表、二叉树===================
		vector<int> oderList;
		int oderListLength;
		int oderListInputtmp;
		system("cls");
		cout << "==================顺序表、二叉树==================" << endl ;

		do {
			cout << "请输入有序表的长度：";
			cin >> oderListLength;
		} while (oderListLength <= 0);

		for (int i = 0; i < oderListLength; i++) {
			cout << "请输入第" << i + 1 << "个元素：";
			cin >> oderListInputtmp;
			oderList.push_back(oderListInputtmp);
		}
		sort(oderList.begin(), oderList.end(), comp);
		cout << "------------------------------------------" << endl;

		cout << "顺序表中的内容为：" << endl;
		for (vector<int>::iterator it = oderList.begin(); it < oderList.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;

		random_shuffle(oderList.begin(), oderList.end());
		cout << "------------------------------------------" << endl;

		cout << "打乱后表中的内容为：" << endl;
		for (vector<int>::iterator it = oderList.begin(); it < oderList.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;

		BTree<int> bt = BTree<int>();
		for (vector<int>::iterator it = oderList.begin(); it < oderList.end(); it++) {
			bt.Insert(bt.getRoot(), *it);
		}
		cout << "------------------------------------------" << endl;

		cout << "二叉树按照前序遍历的输出结果为：";
		bt.PreOrder(bt.getRoot());
		cout << endl<<"二叉树按照中序遍历的输出结果为：";
		bt.InOrder(bt.getRoot());
		cout << endl<<"二叉树按照后序遍历的输出结果为：";
		bt.PostOrder(bt.getRoot());
		cout << endl;
		cout << "------------------------------------------" << endl;

		cout << "请输入想要删除的元素：";
		cin >> oderListInputtmp;
		bt.Delete(bt.getRoot(), oderListInputtmp);
		cout << "------------------------------------------" << endl;
		cout << "删除后二叉树按照前序遍历的输出结果为：";
		bt.PreOrder(bt.getRoot());
		cout << endl<<"删除后二叉树按照中序遍历的输出结果为：";
		bt.InOrder(bt.getRoot());
		cout << endl<<"删除后二叉树按照后序遍历的输出结果为：";
		bt.PostOrder(bt.getRoot());
		cout << endl;

		sort(oderList.begin(), oderList.end(), comp);
		cout << "------------------------------------------" << endl;

		cout << "顺序表中的内容为：" << endl;
		for (vector<int>::iterator it = oderList.begin(); it < oderList.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
		cout << "------------------------------------------" << endl;

		cout << "输入想要查找的数据：";
		cin >> oderListInputtmp;
		int loc;
		loc = find(oderList, oderListInputtmp);

		cout << "数据" << oderListInputtmp << "在当前顺序表的第" << loc + 1 << "个位置上" << endl;
		system("pause");
	}
};