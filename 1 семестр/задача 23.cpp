//������������� ������ ��������� ����� �����, ����� ��������� ����������� �� ����������. ��� ��������� (������������� �� ������������) ������ ���� ���������� ��������� ��� ���������.���������� ��������� ������ ���� ��� �� ���������. ������� ����� ����� � �� ��� � �� ���������� ���� ��������- ������. ������������ - ��� �����������.
#include <iostream>
#include <cmath>
#define delta 0.0001
using namespace std;
double F1(double * grid){
return sin(0.5*grid[0]*grid[0]-0.25*grid[1]*grid[1]+3)*cos(2*grid[0]+1-exp(grid[1]));
}
double F2 (double*grid){
return cos(4*grid[0]+2*grid[1])*sin(grid[1]-5*grid[2]-grid[3])*cos(grid[4]*grid[3]);
}
void gradient(double (*f)(double* ),double* grid,int n){
double gridb[n];
double gridm[n];
for(int i=0;i<n;i++){
gridb[i]=grid[i];
gridm[i]=grid[i];
};
for(int i = 0;i<n;i++){
gridb[i]+=delta;
gridm[i]-=delta;
grid[i]-=delta*(((*f)(gridb)-(*f)(gridm))/(2*delta));
gridb[i]-=delta;
gridm[i]+=delta;
}
}
bool GradientDescent(double (*f)(double*), double *grid,int n){// ����������� �����
double before,after;
before = f(grid);
gradient(f, grid, n);
after=f(grid);
while(after<before){ //������� ���������� �� ��������
gradient(f,grid,n); //���������� �����
swap(before, after);
after=f(grid);
}
cout<<"[";
for(int i = 0; i<n;i++){
    cout<<grid[i];
    if (i!=n-1) cout<<";";
};
cout<<"]";
return true;
};

int main() {
int n;//����������� �������
cin>>n;
double grid[n];
double grid2[n];
for(int i = 0;i<n;grid[i++]=0){};
for(int i = 0;i<n;i++){
    cin>>grid[i];
    grid2[i]=grid[i];
};
GradientDescent(F1, grid,n);
for (int i=0;i<n;i++){
    grid[i]=grid2[i]; //�������������� �����
}
cout<<endl;
GradientDescent(F2, grid,n);
return 0;
}
