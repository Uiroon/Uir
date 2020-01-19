#pragma once
class AirlineManager {
private:
	vector<AirlineInfo> allAirline;
	int numOfAirline=0;
public:
	void load() {
		ifstream infile;
		infile.open("Airline.txt");
		infile >> numOfAirline;
		for (int i = 0; i < numOfAirline; i++) {
			string tmpdeparture;
			string tmparrival;
			string tmpflightNumber;
			string tmpplaneNumber;
			int tmpday;
			int tmpmax1;
			int tmpmax2;
			int tmpmax3;
			int tmpleft1;
			int tmpleft2;
			int tmpleft3;
			infile >> tmpdeparture >> tmparrival >> tmpflightNumber >> tmpplaneNumber >> tmpday >> tmpmax1 >> tmpmax2 >> tmpmax3 >> tmpleft1 >> tmpleft2 >> tmpleft3;
			AirlineInfo atmp(tmpdeparture, tmparrival, tmpflightNumber, tmpplaneNumber, tmpday, tmpmax1, tmpmax2, tmpmax3, tmpleft1, tmpleft2, tmpleft3);
			allAirline.push_back(atmp);
		}
	}
	void display() {
		int i = 1;
		for (vector<AirlineInfo>::iterator it = allAirline.begin(); it < allAirline.end(); it++, i++) {
			cout << endl << "����" << i << "��Ϣ���£�" << endl
				<< left << setw(10) << "�����أ�" << left << setw(10) << it->getDeparture()
				<< left << setw(10) << "Ŀ�ĵأ�" << left << setw(10) << it->getArrival() << endl
				<< left << setw(10) << "�����:" << left << setw(10) << it->getFlightNumber() 
				<< left << setw(10) << "�ɻ��ţ�" << left << setw(10) << it->getPlaneNumber() << endl
				<< left << setw(10) << "�ɻ����գ�" << left << setw(10) << it->getDay()
				<< left << setw(10) << "��Ա���" << left << setw(10) << it->getMax(1)+ it->getMax(2) + it->getMax(3)  << endl
				<< left << setw(10) << "һ�Ȳ���Ʊ����" << left << setw(10) << it->getLeft(1) << endl
				<< left << setw(10) << "���Ȳ���Ʊ����" << left << setw(10) << it->getLeft(2) << endl
				<< left << setw(10) << "���Ȳ���Ʊ����" << left << setw(10) << it->getLeft(3) << endl;
		}
	}
	AirlineInfo &choose(bool flag) {
		int chosen;
		int func;
		do{
			system("cls");
			if (flag) {
				cout << endl << "====================��Ʊ====================";
			}
			else {
				cout << endl << "====================��Ʊ====================";
			}
			display();
			if (flag) {
				cout << endl << "============================================" << endl << "��������Ҫ��Ʊ�ĺ�����ţ�";
			}
			else {
				cout << endl << "============================================" << endl << "��������Ҫ��Ʊ�ĺ�����ţ�";
			}
		
		cin >> chosen;
		if (chosen > numOfAirline) {
			while (chosen > numOfAirline) {
				cout << "��ѡ����ȷ�ĺ������";
				cin >> chosen;
			}
		}
		system("cls");
		cout <<   "====================ȷ�Ϻ�����Ϣ====================" << endl
			 << "��ѡ��ĺ���" << chosen << "��Ϣ���£�" << endl
			<< left << setw(10) << "�����أ�" << left << setw(10) << allAirline[chosen - 1].getDeparture()
			<< left << setw(10) << "Ŀ�ĵأ�" << left << setw(10) << allAirline[chosen - 1].getArrival() << endl
			<< left << setw(10) << "�����:" << left << setw(10) << allAirline[chosen - 1].getFlightNumber()
			<< left << setw(10) << "�ɻ��ţ�" << left << setw(10) << allAirline[chosen - 1].getPlaneNumber() << endl
			<< left << setw(10) << "�ɻ����գ�" << left << setw(10) << allAirline[chosen - 1].getDay()
			<< left << setw(10) << "��Ա���" << left << setw(10) << allAirline[chosen - 1].getMax(1)+ allAirline[chosen - 1].getMax(2) + allAirline[chosen - 1].getMax(3) << endl
			<< left << setw(10) << "һ�Ȳ���Ʊ����" << left << setw(10) << allAirline[chosen - 1].getLeft(1) << endl
			<< left << setw(10) << "���Ȳ���Ʊ����" << left << setw(10) << allAirline[chosen - 1].getLeft(2) << endl
			<< left << setw(10) << "���Ȳ���Ʊ����" << left << setw(10) << allAirline[chosen - 1].getLeft(3) << endl
			<< endl << "============================================" << endl
			<< "�Ƿ�ȷ��ѡ��ú��ࣿ����0����ѡ��,������������ȷ�ϣ�";
		cin >> func;
		} while (func == 0);
		return allAirline[chosen - 1];
	}
	void oderTicket(AirlineInfo& tmp) {
		if (tmp.addCustomer()) {
			cout << "��Ʊ�ɹ�";
			system("pause");
		}
		else {
			cout << "��Ʊʧ��";
			system("pause");
		};
	}
	void refundTicket(AirlineInfo& tmp) {
		if (tmp.delCustomer()) {
			cout << "��Ʊ�ɹ�";
			system("pause");
		}
		else {
			cout << "��Ʊʧ��";
			system("pause");
		}
	}
	
	void start() {
		int fun=0;
		this->load();
		AirlineInfo tmp;
	    while(fun!=3){
			system("cls");
			cout <<  "====================��ӭʹ�ñ�����ϵͳ====================" << endl
				<< endl
				<< "1����Ʊ" << endl << "2����Ʊ" << endl << "3���˳�" << endl
				<< "��ѡ���ܣ�";
			cin >> fun;
			if (fun < 1 || fun>3) {
				while (fun > 3 || fun < 1) {
					system("cls");
					cout << "====================��ӭʹ�ñ�����ϵͳ====================" << endl
						<< endl
						<< "1.��Ʊ" << endl << "2.��Ʊ" << endl << "3.�˳�" << endl
						<< "����ѡ�����Ϊ1,2,3��������ѡ��";
					cin >> fun;
				}
			}
			switch (fun) {
			case 1:
				oderTicket(choose(true));
				break;
			case 2:
				refundTicket(choose(true));
				break;
			case 3:
				system("cls");
				ofstream outfile("CustomerInfo.txt", ios::trunc);
				ofstream outfile1("Airline.txt", ios::trunc);
				outfile1 << numOfAirline << endl;
				int i = 1;
				for (vector<AirlineInfo>::iterator it1 = allAirline.begin(); it1 < allAirline.end(); it1++,i++) {
					vector<Customer> tmp = it1->sortCustomer();
					outfile <<"====================����" << i << "====================" << endl
						<< left << setw(10) << "�����أ�" << left << setw(10) << it1->getDeparture()
						<< left << setw(10) << "Ŀ�ĵأ�" << left << setw(10) << it1->getArrival() << endl
						<< left << setw(10) << "�����:" << left << setw(10) << it1->getFlightNumber()
						<< left << setw(10) << "�ɻ��ţ�" << left << setw(10) << it1->getPlaneNumber() << endl
						<< left << setw(10) << "�ɻ����գ�" << left << setw(10) << it1->getDay()
						<< left << setw(10) << "��Ա���" << left << setw(10) << it1->getMax(1) + it1->getMax(2) + it1->getMax(3) << endl
						<< left << setw(10) << "һ�Ȳ���Ʊ����" << left << setw(10) << it1->getLeft(1) << endl
						<< left << setw(10) << "���Ȳ���Ʊ����" << left << setw(10) << it1->getLeft(2) << endl
						<< left << setw(10) << "���Ȳ���Ʊ����" << left << setw(10) << it1->getLeft(3) << endl
						<< "�˿���Ϣ���£�" << endl;
					
					outfile1 << it1->getDeparture() << " " << it1->getArrival() << " " << it1->getFlightNumber() << " " << it1->getPlaneNumber() << " "
						<< it1->getDay() << " " << it1->getMax(1) << " " << it1->getMax(2) << " " << it1->getMax(3) << " "<<it1->getLeft(1) << " " << it1->getLeft(2) << " " << it1->getLeft(3) << " " << endl;
					for (vector<Customer>::iterator it2 = tmp.begin(); it2 < tmp.end(); it2++) {
						outfile << "--------------------------------------------" << endl
							<<left << setw(10) << "������" << left << setw(10) << it2->getName() << endl
							<< left << setw(10) << "һ�Ȳն�Ʊ������" << left << setw(10) << it2->getLevel(1) << endl
							<< left << setw(10) << "���Ȳն�Ʊ������" << left << setw(10) << it2->getLevel(2) << endl
							<< left << setw(10) << "���Ȳն�Ʊ������" << left << setw(10) << it2->getLevel(3) << endl;
					}
					
				}

				cout << "====================��лʹ�ñ�����ϵͳ====================" << endl;
				system("pause");
				break;
			}
		}
		
	}
};