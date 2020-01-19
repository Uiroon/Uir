#pragma once
class Function5 {
public:
	Function5() {
		//==================≈≈–Ú===================
		system("cls");
		cout << "==================≈≈–Ú===================" << endl;
		Sort st;
		st.initialize();
		st.output(st.getSrc());
		cout << "------------------√∞≈›≈≈–Ú------------------" << endl;
		st.output(st.BubbleSort());
		cout << "------------------øÏÀŸ≈≈–Ú------------------" << endl;
		st.output(st.QuickSort());
		cout << "------------------πÈ≤¢≈≈–Ú------------------" << endl;
		st.output(st.MergeSort());
		cout << "------------------≤Â»Î≈≈–Ú------------------" << endl;
		st.output(st.InsertSort());
		cout << "------------------∂—≈≈–Ú------------------" << endl;
		st.output(st.HeapSort());
		system("pause");
	}
};