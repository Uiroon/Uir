#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
#include "Node.h"
#include "LinkList.h"
#include "QueueList.h"
#include "QueueSequent.h"
#include "BNode.h"
#include "BTree.h"
#include "Sort.h"
#include "Customer.h"
#include "AirlineInfo.h"
#include "AirlineManager.h"
#include "Function1.h"
#include "Function2.h"
#include "Function3.h"
#include "Function4.h"
#include "Function5.h"
#include "Function6.h"

int main()
{
	int fun = 0;
	while (fun != 6) {
		system("cls");
		cout << "====================课设====================" << endl
			<< endl
			<< "1.链表" << endl << "2.链式存储队列" << endl << "3.顺序存储队列" << endl << "4.有序表、二叉排序树" << endl << "5.排序" << endl << "6.订票系统" << endl
			<< "请选择功能：";
		cin >> fun;
		if (fun < 1 || fun>6) {
			while (fun > 6 || fun < 1) {
				system("cls");
				cout << "====================课设====================" << endl
					<< endl
					<< "1.链表" << endl << "2.链式存储队列" << endl << "3.顺序存储队列" << endl << "4.有序表、二叉排序树" << endl << "5.排序" << endl << "6.订票系统" << endl
					<< "功能选项仅能为1至6，请重新选择：";
				cin >> fun;
			}
		}
		switch (fun) {
		case 1:
			Function1();
			break;
		case 2:
			Function2();
			break;
		case 3:
			Function3();
			break;
		case 4:
			Function4();
			break;
		case 5:
			Function5();
			break;
		case 6:
			Function6();
			break;
		}
	}
}