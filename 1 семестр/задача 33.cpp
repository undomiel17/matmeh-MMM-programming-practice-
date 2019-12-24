//Дана таблица  размером n * m. Требуется найти в ней такую прямоугольную область , состоящую только из нулей, и среди всех таких — имеющую наибольшую площадь.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;

int main()
{
    int n, m;
cout<<"number of lines:";
cin >> m;
cout<<endl<<"number of columns:";
cin>> n;
vector < vector<int> > a (m, vector<int> (n));
srand(time(0));
for (int i=0; i<m; i++){
    for (int j=0;j<n; j++){
        a[i][j]=rand()%2;
        cout<<a[i][j]<<"  ";
    }
    cout<<endl;
}
int area = 0;
vector<int> north (n, -1), west (n), east (n);
stack<int> st;
for (int i=0; i<m; ++i) {
	for (int j=0; j<n; ++j)
		if (a[i][j] == 1)
			north[j] = i;
	while (!st.empty()) st.pop();
	for (int j=0; j<n; ++j) {
		while (!st.empty() && north[st.top()] <= north[j])  st.pop();
		if (st.empty()) west[j] =  -1;
		else west[j]= st.top();
		st.push (j);
	}
	while (!st.empty()) st.pop();
	for (int j=n-1; j>=0; --j) {
		while (!st.empty() && north[st.top()] <= north[j])  st.pop();
		if (st.empty()) east[j] =  n;
		else east[j]=st.top();
		st.push (j);
	}
	for (int j=0; j<n; ++j)
		area = max (area, (i - north[j]) * (east[j] - west[j] - 1));
}

cout <<"maximum zero submatrix: "<< area;
return 0;
}
