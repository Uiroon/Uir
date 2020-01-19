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
			cout << endl << "航班" << i << "信息如下：" << endl
				<< left << setw(10) << "出发地：" << left << setw(10) << it->getDeparture()
				<< left << setw(10) << "目的地：" << left << setw(10) << it->getArrival() << endl
				<< left << setw(10) << "航班号:" << left << setw(10) << it->getFlightNumber() 
				<< left << setw(10) << "飞机号：" << left << setw(10) << it->getPlaneNumber() << endl
				<< left << setw(10) << "飞机周日：" << left << setw(10) << it->getDay()
				<< left << setw(10) << "成员定额：" << left << setw(10) << it->getMax(1)+ it->getMax(2) + it->getMax(3)  << endl
				<< left << setw(10) << "一等舱余票量：" << left << setw(10) << it->getLeft(1) << endl
				<< left << setw(10) << "二等舱余票量：" << left << setw(10) << it->getLeft(2) << endl
				<< left << setw(10) << "三等舱余票量：" << left << setw(10) << it->getLeft(3) << endl;
		}
	}
	AirlineInfo &choose(bool flag) {
		int chosen;
		int func;
		do{
			system("cls");
			if (flag) {
				cout << endl << "====================订票====================";
			}
			else {
				cout << endl << "====================退票====================";
			}
			display();
			if (flag) {
				cout << endl << "============================================" << endl << "请输入需要订票的航班序号：";
			}
			else {
				cout << endl << "============================================" << endl << "请输入需要退票的航班序号：";
			}
		
		cin >> chosen;
		if (chosen > numOfAirline) {
			while (chosen > numOfAirline) {
				cout << "请选择正确的航班序号";
				cin >> chosen;
			}
		}
		system("cls");
		cout <<   "====================确认航班信息====================" << endl
			 << "您选择的航班" << chosen << "信息如下：" << endl
			<< left << setw(10) << "出发地：" << left << setw(10) << allAirline[chosen - 1].getDeparture()
			<< left << setw(10) << "目的地：" << left << setw(10) << allAirline[chosen - 1].getArrival() << endl
			<< left << setw(10) << "航班号:" << left << setw(10) << allAirline[chosen - 1].getFlightNumber()
			<< left << setw(10) << "飞机号：" << left << setw(10) << allAirline[chosen - 1].getPlaneNumber() << endl
			<< left << setw(10) << "飞机周日：" << left << setw(10) << allAirline[chosen - 1].getDay()
			<< left << setw(10) << "成员定额：" << left << setw(10) << allAirline[chosen - 1].getMax(1)+ allAirline[chosen - 1].getMax(2) + allAirline[chosen - 1].getMax(3) << endl
			<< left << setw(10) << "一等舱余票量：" << left << setw(10) << allAirline[chosen - 1].getLeft(1) << endl
			<< left << setw(10) << "二等舱余票量：" << left << setw(10) << allAirline[chosen - 1].getLeft(2) << endl
			<< left << setw(10) << "三等舱余票量：" << left << setw(10) << allAirline[chosen - 1].getLeft(3) << endl
			<< endl << "============================================" << endl
			<< "是否确认选择该航班？输入0重新选择,输入其他数字确认：";
		cin >> func;
		} while (func == 0);
		return allAirline[chosen - 1];
	}
	void oderTicket(AirlineInfo& tmp) {
		if (tmp.addCustomer()) {
			cout << "订票成功";
			system("pause");
		}
		else {
			cout << "订票失败";
			system("pause");
		};
	}
	void refundTicket(AirlineInfo& tmp) {
		if (tmp.delCustomer()) {
			cout << "退票成功";
			system("pause");
		}
		else {
			cout << "退票失败";
			system("pause");
		}
	}
	
	void start() {
		int fun=0;
		this->load();
		AirlineInfo tmp;
	    while(fun!=3){
			system("cls");
			cout <<  "====================欢迎使用本航班系统====================" << endl
				<< endl
				<< "1：订票" << endl << "2：退票" << endl << "3：退出" << endl
				<< "请选择功能：";
			cin >> fun;
			if (fun < 1 || fun>3) {
				while (fun > 3 || fun < 1) {
					system("cls");
					cout << "====================欢迎使用本航班系统====================" << endl
						<< endl
						<< "1.订票" << endl << "2.退票" << endl << "3.退出" << endl
						<< "功能选项仅能为1,2,3，请重新选择：";
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
					outfile <<"====================航班" << i << "====================" << endl
						<< left << setw(10) << "出发地：" << left << setw(10) << it1->getDeparture()
						<< left << setw(10) << "目的地：" << left << setw(10) << it1->getArrival() << endl
						<< left << setw(10) << "航班号:" << left << setw(10) << it1->getFlightNumber()
						<< left << setw(10) << "飞机号：" << left << setw(10) << it1->getPlaneNumber() << endl
						<< left << setw(10) << "飞机周日：" << left << setw(10) << it1->getDay()
						<< left << setw(10) << "成员定额：" << left << setw(10) << it1->getMax(1) + it1->getMax(2) + it1->getMax(3) << endl
						<< left << setw(10) << "一等舱余票量：" << left << setw(10) << it1->getLeft(1) << endl
						<< left << setw(10) << "二等舱余票量：" << left << setw(10) << it1->getLeft(2) << endl
						<< left << setw(10) << "三等舱余票量：" << left << setw(10) << it1->getLeft(3) << endl
						<< "乘客信息如下：" << endl;
					
					outfile1 << it1->getDeparture() << " " << it1->getArrival() << " " << it1->getFlightNumber() << " " << it1->getPlaneNumber() << " "
						<< it1->getDay() << " " << it1->getMax(1) << " " << it1->getMax(2) << " " << it1->getMax(3) << " "<<it1->getLeft(1) << " " << it1->getLeft(2) << " " << it1->getLeft(3) << " " << endl;
					for (vector<Customer>::iterator it2 = tmp.begin(); it2 < tmp.end(); it2++) {
						outfile << "--------------------------------------------" << endl
							<<left << setw(10) << "姓名：" << left << setw(10) << it2->getName() << endl
							<< left << setw(10) << "一等舱订票数量：" << left << setw(10) << it2->getLevel(1) << endl
							<< left << setw(10) << "二等舱订票数量：" << left << setw(10) << it2->getLevel(2) << endl
							<< left << setw(10) << "三等舱订票数量：" << left << setw(10) << it2->getLevel(3) << endl;
					}
					
				}

				cout << "====================感谢使用本航班系统====================" << endl;
				system("pause");
				break;
			}
		}
		
	}
};