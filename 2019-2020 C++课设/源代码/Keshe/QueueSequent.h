#pragma once
template <class T>
class QueueSequent {
private:
	vector<T> Queue;
public:
	QueueSequent() {
		Queue =vector<T>();
	}
	void Init() {
		Queue = vector<T>();
	}
	void Push(T dataPush) {
		Queue.push_back(dataPush);
	}
	T Pop() {
		if (Queue.empty()) {
			return -1;
		}else{
			T tmp = Queue.front();
			typename std::vector<T>::iterator it = Queue.begin();
			Queue.erase(it);
			return tmp;
		}	
	}
	void Output() {
		int count = 1;
		if (Queue.empty()) {
			cout << endl << "========队列中的数据为空========" << endl << endl;
		}
		else {
			cout << endl << "========队列中的数据========" << endl << endl;
			for (typename std::vector<T>::iterator it = Queue.begin(); it < Queue.end(); it++, count++) {
				cout << "第" << count << "个数据为:" << *it << endl;
			}
		}
	}
};