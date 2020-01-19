#pragma once
//链式队列
class Function2 {
public:
	Function2() {
		QueueList<int> queuelist = QueueList<int>();

		int queuelistData;
		int choice = 0;
		while (choice != 5) {
			system("cls");
			cout << "==================链式队列==================" << endl << "1:初始化" << endl << "2:入队" << endl << "3:出队" << endl << "4:显示队列中的数据" << endl << "5:退出" << endl << "请选择需要的功能：";
			cin >> choice;
			switch (choice) {
			case 1:
				queuelist.Init();
				break;
			case 2:
				cout << "请输入需要入队的数据:";
				cin >> queuelistData;
				queuelist.Push(queuelistData);
				cout << endl << "数据:" << queuelistData << "入队" << endl;
				system("pause");
				break;
			case 3:
				queuelistData = queuelist.Pop();
				if (queuelistData == -1) {
					cout << endl << "队列为空无法出队" << endl;
					system("pause");
					break;
				}
				else {
					cout << endl << "数据:" << queuelistData << "出队" << endl;
					system("pause");
					break;
				}
			case 4:
				queuelist.Output();
				system("pause");
				break;
			case 5:
				queuelist.~QueueList();
				break;
			}
		}
	}
};