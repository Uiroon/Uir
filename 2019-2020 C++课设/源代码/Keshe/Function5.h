#pragma once
class Function5 {
public:
	Function5() {
		//==================����===================
		system("cls");
		cout << "==================����===================" << endl;
		Sort st;
		st.initialize();
		st.output(st.getSrc());
		cout << "------------------ð������------------------" << endl;
		st.output(st.BubbleSort());
		cout << "------------------��������------------------" << endl;
		st.output(st.QuickSort());
		cout << "------------------�鲢����------------------" << endl;
		st.output(st.MergeSort());
		cout << "------------------��������------------------" << endl;
		st.output(st.InsertSort());
		cout << "------------------������------------------" << endl;
		st.output(st.HeapSort());
		system("pause");
	}
};