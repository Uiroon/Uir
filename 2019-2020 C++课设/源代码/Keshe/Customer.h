#pragma once
class Customer {
private:
	string name;
	int level1;
	int level2;
	int level3;
public:
	Customer(string str,int a,int b,int c){
		name = str;
		level1 = a;
		level2 = b;
		level3 = c;
	}
	void setName(string str) {
		name = str;
	}
	string getName()const {
		return name;
	}
	void setLevel(int l,int a) {
		if (l == 1) {
			level1 = a;
		}else if (l == 2) {
			level2 = a;
		}
		else if (l == 3) {
			level3 = a;
		}
		
	}
	int getLevel(int l)const {
		if (l == 1) {
			return level1;
		}else if (l == 2) {
			return level2;
		}
		else if (l == 3) {
			return level3;
		}
		
	}
	
	
};