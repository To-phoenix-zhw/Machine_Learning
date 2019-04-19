// Machine Learning——The first algorithm——Gradient descent
#define LOCAL
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 20;
const double epi = 1e-5;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int x, y;	// 每一个样本 
	int m = 0; // 总的样本数 
	double sita0 = 0, sita1 = 0;// θ0和θ1 
	double rate = 0.01;	// 学习率α 
	int xset[maxn] = {0}, yset[maxn] = {0}; // 训练集 
	while (scanf("%d%d", &x, &y) == 2) {
		xset[m] = x;
		yset[m++] = y;
	}
//	cout<<"m="<<m<<endl;
	double d1 = 0, d2 = 0;
	do {
		double temp1 = 0, temp2 = 0;
		for (int i = 0; i < m; i++) {
			temp1 += sita0 + sita1 * xset[i] - yset[i]; 
			temp2 += ((sita0 + sita1 * xset[i] - yset[i]) * xset[i]);
		}
		
		d1 = temp1 / m;
		d2 = temp2 / m;
		
		sita0 = sita0 - rate * d1;
		sita1 = sita1 - rate * d2;		
	} while (!(fabs(d1) < epi && fabs(d2) < epi));
	
	cout<<"sita0 = " << sita0 << endl;
	cout<<"sita1 = " << sita1 << endl;
	cout<< sita0 + sita1 * xset[0] <<endl;
	cout<<yset[0]<<endl;
	return 0;
} 
