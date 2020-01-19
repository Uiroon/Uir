#pragma once
class Sort {
private:
	vector<int> src;
	int n=0;
public:
	vector<int> getSrc() {
		return src;
	}
	vector<int> initialize() {
		int tmp;
		cout << "请输入需要排列的数据数量:";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "请输入第" << i + 1 << "个数据:";
			cin >> tmp;
			src.push_back(tmp);
		}
		return src;
	}
	void output(vector<int> a) {
		cout << endl<<"当前的数据情况为:" << endl;
		for (vector<int>::iterator it = a.begin(); it < a.end(); it++) {
			cout <<left<<setw(6)<< *it;
		}
		cout << endl;
	}
	void input(vector<int> a) {
		src.clear();
		for (vector<int>::iterator it = a.begin(); it < a.end(); it++) {
			src.push_back(*it);
		}
	}
	vector<int>  BubbleSort() {
		vector<int> arr = src;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] > arr[j]) {
					/*int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;*/
					swap(arr[i], arr[j]);
				}
			}
		}
		cout << endl<<"完成冒泡排序";
		return arr;
	}
	vector<int> InsertSort() {
		vector<int> arr =src;
		int tmp, i, j;
		for (i = 1; i < n; i++) {
			tmp = arr[i];
			for (j = i; j > 0 && arr[j - 1] > tmp; j--) {
				arr[j] = arr[j - 1];
			}
			arr[j] = tmp;
		}
		cout << endl<<"完成插入排序";
		return arr;
	}
	vector<int> MergeSort() {
		vector<int> arr = src;
		subMerge(arr, 0, n - 1);
		cout << endl << "完成归并排序";
		return arr;
		
	}
	
	void subMerge(vector<int>& arr, int start, int end) {
		int left = start;
		if (start != end)
		{
			int mid = (start + end) / 2;
			subMerge(arr, start, mid);
			subMerge(arr, mid + 1, end);
			vector<int> tmp_arr(end - start + 1);
			int i = 0;
			int tmp = mid + 1;
			while (start <= mid && tmp <= end)
			{
				if (arr[start] <= arr[tmp])
				{
					tmp_arr[i++] = arr[start++];
				}
				else
				{
					tmp_arr[i++] = arr[tmp++];
				}
			}
			while (start <= mid)
			{
				tmp_arr[i++] = arr[start++];
			}
			while (tmp <= end)
			{
				tmp_arr[i++] = arr[tmp++];
			}
			for (int j = left; j <= end; j++)
			{
				arr[j] = tmp_arr[j - left];
			}
			
		}
	}
	vector<int> QuickSort() {
		vector<int> arr = src;
		subQuick(arr, 0, n - 1);
		cout << endl << "完成快速排序";
		return arr;
	}
	void subQuick(vector<int>& arr, int start, int end)
	{
		int i = start, j = end;
		int temp;
		if (start < end)
		{
			temp = arr[start];
			while (i != j)
			{
				while (j > i&& arr[j] > temp)
					j--;
				arr[i] = arr[j];
				while (i < j && arr[i] < temp)
					i++;
				arr[j] = arr[i];
			}
			arr[i] = temp;
			subQuick(arr, start, i - 1);
			subQuick(arr, i + 1, end);
		}
	}
	vector<int> HeapSort() {
		vector<int> arr = src;
		subHeap(arr, n);
		cout << endl << "完成堆排序";
		return arr;
	}
	void heapSortAdjust(vector<int>& arr, int len, int index)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		int maxIndex = index;
		if (left<len && arr[left] > arr[maxIndex])     maxIndex = left;
		if (right<len && arr[right] > arr[maxIndex])     maxIndex = right;

		if (maxIndex != index)
		{
			swap(arr[maxIndex], arr[index]);
			heapSortAdjust(arr, len, maxIndex);
		}

	}
	void subHeap(vector<int>& arr, int size)
	{
		for (int i = size / 2 - 1; i >= 0; i--)
		{
			heapSortAdjust(arr, size, i);
		}
		for (int i = size - 1; i >= 1; i--)
		{
			swap(arr[0], arr[i]);           
			heapSortAdjust(arr, i, 0);              
		}
	}

};