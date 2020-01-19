#pragma once
class AirlineInfo {
private:
	string departure;
	string arrival;
	string flightNumber;
	string planeNumber;
	int day;
	int max1;
	int max2;
	int max3;
	int left1;
	int left2;
	int left3;
	vector<Customer> customers;
public:
	AirlineInfo() { ; }
	AirlineInfo(string d, string a, string f, string p, int da, int m1, int m2, int m3, int l1,int l2,int l3) {
		departure = d;
		arrival = a;
		flightNumber = f;
		planeNumber = p;
		day = da;
		max1 = m1;
		max2 = m2;
		max3 = m3;
		left1 = l1;
		left2 = l2;
		left3 = l3;
		customers.clear();
	}
	void setDeparture(string str) {
		departure = str;
	}
	string getDeparture() {
		return departure;
	}
	void setArrival(string str) {
		arrival = str;
	}
	string getArrival() {
		return arrival;
	}
	void setFlightNumber(string str) {
		flightNumber = str;
	}
	string getFlightNumber() {
		return flightNumber;
	}
	void setPlaneNumber(string str) {
		planeNumber = str;
	}
	string getPlaneNumber() {
		return planeNumber;
	}
	void setDay(int d) {
		day = d;
	}
	int getDay() {
		return day;
	}
	int getMax(int l) {
		if (l == 1) {
			return max1;
		}
		else if (l == 2) {
			return max2;
		}
		else if (l == 3) {
			return max3;
		}
	}
	void setLeft(int le,int l) {
		
		if (le == 1) { left1 = l; }
		else if (le == 2) { left2 = l; }
		else if (le == 3) { left3 = l; }
	}
	int getLeft(int l) {
		if (l == 1) {
			return left1;
		}
		else if (l == 2) {
			return left2;
		}
		else if (l == 3) {
			return left3;
		}
		
	}
	
	
	bool addCustomer() {
		string tmpname;
		bool found = false;
		int tmpoder = 0;
		int tmpoder1=0;
		int tmpoder2=0;
		int tmpoder3=0;
		int tmplevel;
		cout << endl<<"====================输入客户信息====================" <<endl<< "请输入客户姓名：";
		cin >> tmpname;
		for (vector<Customer>::iterator it = customers.begin(); it < customers.end(); it++) {
			if (it->getName() == tmpname) {
				cout << "请输入舱位等级：";
				cin >> tmplevel;
				if (tmplevel > 3 || tmplevel < 1) {
					while (tmplevel > 3 || tmplevel < 1) {
						cout << "舱位等级仅能为1,2,3，请重新选择：";
						cin >> tmplevel;
					}
				}
				cout << "请输入订票量：";
				cin >> tmpoder;
				if (tmpoder > getLeft(tmplevel)) {
					while (tmpoder > getLeft(tmplevel)) {
						cout << "无足够余票，请重新输入订票量,输入0取消订票：";
						cin >> tmpoder;
						if (tmpoder == 0) {
							return false;
						}
					}
				}
				int tmpnum = it->getLevel(tmplevel);
				setLeft(tmplevel, getLeft(tmplevel) - tmpoder);
				it->setLevel(tmplevel, tmpnum + tmpoder);
				found = true;
				return true;
			}
		}
		if(!found){
			cout << "请输入舱位等级：";
			cin >> tmplevel;
			if (tmplevel > 3 || tmplevel < 1) {
				while (tmplevel > 3 || tmplevel < 1) {
					cout << "舱位等级仅能为1,2,3，请重新选择：";
					cin >> tmplevel;
				}
			}
			cout << "请输入订票量：";
			cin >> tmpoder;
			if (tmpoder > getLeft(tmplevel)) {
				while (tmpoder > getLeft(tmplevel)) {
					cout << "无足够余票，请重新输入订票量,输入0取消订票：";
					cin >> tmpoder;
					if (tmpoder == 0) {
						return false;
					}
				}
			}
			if (tmplevel == 1) {
				tmpoder1 = tmpoder;
			}
			else if (tmplevel == 2) {
				tmpoder2 = tmpoder;
			}
			else if (tmplevel == 3) {
				tmpoder3 = tmpoder;
			}
			Customer tmp = Customer(tmpname, tmpoder1, tmpoder2, tmpoder3);
			customers.push_back(tmp);
			setLeft(tmplevel, getLeft(tmplevel) - tmpoder);
			return true;
		}
		
	}
	bool delCustomer() {
		
		string tmpname;
		int tmpoder;
		int tmplevel;
		bool found=false;
		cout << "请输入需要退订的机票相关信息：" << endl
			<< "请输入客户姓名：";
		cin >> tmpname;
		for (vector<Customer>::iterator it = customers.begin(); it < customers.end(); it++) {
			if (it->getName() == tmpname) {
				cout <<endl<< "查询到客户：" << tmpname << "订购的机票有：" << endl;
					if (it->getLevel(1) != 0) {
						cout << "一等舱：" << it->getLevel(1) << endl;
					}
					if (it->getLevel(2) != 0) {
						cout << "二等舱：" << it->getLevel(2) << endl;
					}
					if (it->getLevel(3) != 0) {
						cout << "三等舱：" << it->getLevel(3) << endl;
					}
					cout << "请输入需要退订的舱位等级：";
					cin >> tmplevel;
					if (tmplevel > 3 || tmplevel < 1) {
						while (tmplevel > 3 || tmplevel < 1) {
							cout << "舱位等级仅能为1,2,3，请重新选择：";
							cin >> tmplevel;
						}
					}
					cout << "请输入需要退订的票数：";
					cin >> tmpoder;
					if (tmpoder > it->getLevel(tmplevel)) {
						while (tmpoder > it->getLevel(tmplevel)) {
							cout << "退票数量大于订票数，请重新输入：";
							cin >> tmpoder;
						}
					}
					setLeft(tmplevel, getLeft(tmplevel) + tmpoder);
					it->setLevel(tmplevel, it->getLevel(tmplevel) - tmpoder);
					if (it->getLevel(1) == 0 && it->getLevel(2) == 0 && it->getLevel(3) == 0) {
						customers.erase(it);
					}
					found = true;
					break;
			}
		}
		return found;
	}
	//static bool comp(const Customer& c1, const Customer& c2)
	//{
	//	if (c1.getLevel(1) < c2.getLevel(1)) {
	//		return true;
	//	}else if (c1.getLevel(1) == c2.getLevel(2)) {
	//		if (c1.getLevel(2) < c2.getLevel(2)) {
	//			return true;
	//		}
	//		else if (c1.getLevel(2) == c2.getLevel(2)) {
	//			if (c1.getLevel(3) < c2.getLevel(3)) {
	//				return true;
	//			}
	//			else if (c1.getLevel(3) == c2.getLevel(3)) {
	//				return true;
	//			}
	//		}
	//	}
	//	return false;
	//	
	//}
	static bool comp(const Customer& c1, const Customer& c2)
	{
		
		return c1.getName()<c2.getName();

	}
	vector<Customer> sortCustomer() {
		sort(customers.begin(), customers.end(), comp);
		return customers;
	}
};