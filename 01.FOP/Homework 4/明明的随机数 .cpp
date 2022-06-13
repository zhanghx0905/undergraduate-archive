/*问题描述
　　明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤100），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
输入格式
　　输入有2行，第1行为1个正整数，表示所生成的随机数的个数：N
　　第2行有N个用空格隔开的正整数，为所产生的随机数。
输出格式
　　输出也是2行，第1行为1个正整数M，表示不相同的随机数的个数。第2行为M个用空格隔开的正整数，为从小到大排好序的不相同的随机数。*/
#include<iostream>
using namespace std;
void MargeArray(int a[], int fd, int mid, int bk) {
	int i = fd, m = mid, j = mid + 1, n = bk, k = 0;
	int* temp = new int[4 * n];
	while ((i <= m) && (j <= n)) {
		if (a[i] <= a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}
	while (i <= m) temp[k++] = a[i++];
	while (j <= n) temp[k++] = a[j++];
	for (int i = 0; i < k; i++) a[fd + i] = temp[i];
	delete[] temp;
}
void MargeSort(int a[], int fd, int bk) {
	if (fd < bk) {
		int mid = (fd + bk) / 2;
		MargeSort(a, fd, mid);
		MargeSort(a, mid + 1, bk);
		MargeArray(a, fd, mid, bk);
	}
}
int main() {
	int temp,m=0,mark,count(0);
	int num[120] = { 0 };
	cin >> m;
	for (int i=0;i<m;i++) {
		mark = 0;
		cin >> temp;
		for (int j = 0; j < count; j++) {
			if (num[j] == temp) {
				mark = 1;
				break;
			}
		}
		if (mark == 0) num[count++] = temp;
	}
	MargeSort(num, 0, count - 1);
	cout << count << endl;
	for (int j = 0; j < count; j++) cout << num[j] << " ";
	return 0;
}