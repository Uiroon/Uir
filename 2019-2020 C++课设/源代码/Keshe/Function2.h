#pragma once
//��ʽ����
class Function2 {
public:
	Function2() {
		QueueList<int> queuelist = QueueList<int>();

		int queuelistData;
		int choice = 0;
		while (choice != 5) {
			system("cls");
			cout << "==================��ʽ����==================" << endl << "1:��ʼ��" << endl << "2:���" << endl << "3:����" << endl << "4:��ʾ�����е�����" << endl << "5:�˳�" << endl << "��ѡ����Ҫ�Ĺ��ܣ�";
			cin >> choice;
			switch (choice) {
			case 1:
				queuelist.Init();
				break;
			case 2:
				cout << "��������Ҫ��ӵ�����:";
				cin >> queuelistData;
				queuelist.Push(queuelistData);
				cout << endl << "����:" << queuelistData << "���" << endl;
				system("pause");
				break;
			case 3:
				queuelistData = queuelist.Pop();
				if (queuelistData == -1) {
					cout << endl << "����Ϊ���޷�����" << endl;
					system("pause");
					break;
				}
				else {
					cout << endl << "����:" << queuelistData << "����" << endl;
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