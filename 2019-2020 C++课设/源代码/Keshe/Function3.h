#pragma once
class Function3 {
public:
	Function3() {
		///////////////˳��

		QueueSequent<int> queuesequent = QueueSequent<int>();
		int queuesequentData;
		int choice=0;
		while (choice!=5) {
			system("cls");
			
			cout << "==================˳�����==================" << endl << "1:��ʼ��" << endl << "2:���" << endl << "3:����" << endl << "4:��ʾ�����е�����" << endl << "5:�˳�" << endl << "��ѡ����Ҫ�Ĺ��ܣ�";			cin >> choice;
			switch (choice) {
			case 1:
				queuesequent.Init();
				break;
			case 2:
				cout << "��������Ҫ��ӵ�����:";
				cin >> queuesequentData;
				queuesequent.Push(queuesequentData);
				cout << endl << "����:" << queuesequentData << "���" << endl;
				system("pause");
				break;
			case 3:
				queuesequentData = queuesequent.Pop();
				if (queuesequentData == -1) {
					cout << endl << "����Ϊ���޷�����" << endl;
					system("pause");
					break;
				}
				else {
					cout << endl << "����:" << queuesequentData << "����" << endl;
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