#include <iostream>
using namespace std;
int FindSmallestSum(int* a1, int* a2, int n)
{
	int i,m=10000;
	for(i=0;i<=n-1;i++)	m=min(abs(a1[i]+a2[i]),m);
	return m;
}

int main(int argc, char const *argv[])
{
int n; int* a1; int* a2;
cin >> n;
a1 = new int[n]; a2 = new int[n];
for (int i=0; i<n; i++) {
cin >> a1[i];
}
for (int i=0; i<n; i++) {
cin >> a2[i];
}
cout << FindSmallestSum(a1, a2, n) << endl;
return 0;
}
