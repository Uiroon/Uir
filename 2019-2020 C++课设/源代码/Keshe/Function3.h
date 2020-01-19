#pragma once
class Function3 {
public:
	Function3() {
		///////////////顺序

		QueueSequent<int> queuesequent = QueueSequent<int>();
		int queuesequentData;
		int choice=0;
		while (choice!=5) {
			system("cls");
			
			cout << "==================顺序队列==================" << endl << "1:初始化" << endl << "2:入队" << endl << "3:出队" << endl << "4:显示队列中的数据" << endl << "5:退出" << endl << "请选择需要的功能：";			cin >> choice;
			switch (choice) {
			case 1:
				queuesequent.Init();
				break;
			case 2:
				cout << "请输入需要入队的数据:";
				cin >> queuesequentData;
				queuesequent.Push(queuesequentData);
				cout << endl << "数据:" << queuesequentData << "入队" << endl;
				system("pause");
				break;
			case 3:
				queuesequentData = queuesequent.Pop();
				if (queuesequentData == -1) {
					cout << endl << "队列为空无法出队" << endl;
					system("pause");
					break;
				}
				else {
					cout << endl << "数据:" << queuesequentData << "出队" << endl;
					system("pause");
					break;
				}
			case 4:
				queuesequent.Output();
				system("pause");
				break;
			case 5:
				break;
			}
		}
	}
};