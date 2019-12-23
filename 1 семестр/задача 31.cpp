//Реализовать универсальный поиск глобального максимума методом имитации отжига
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
const int repeat=7;
const int start_temp=23;
const int end_temp=1;
const int N=4;
struct arg
{
    double value;
    double left, right;
};
struct syst_arg
{
  arg point [N];
};
double F1(syst_arg grid){
return (0.5*grid.point[1].value*sin(grid.point[0].value)-0.25*grid.point[2].value*grid.point[0].value+3)*cos(2*grid.point[3].value+1-exp(grid.point[2].value));
}
double F2 (syst_arg grid){
return cos(4*grid.point[0].value+2*grid.point[0].value)*sin(grid.point[0].value-5*grid.point[0].value-grid.point[0].value)*cos(grid.point[0].value*grid.point[0].value);
}
int sign(double x){
    if (x > 0)
        return 1;
    else
        return -1;

    return 0;
}

double decrease (int level)
{
    return start_temp*pow(0.97,level);
}
double TransitionProbability (double dE, double t){
return exp(-dE/t);
}
bool inTransition (double probability )
{
    double transition=(double)(rand())/ RAND_MAX;
    if (probability>transition) return true;
    else return false;
}
syst_arg candidate (syst_arg grid, double t )
{
    double delta=0;
    double s=0;
    double new_arg=0;
    syst_arg temp;
    for (int i=0;i<N; i++){
    do
    {
         delta = (double)(rand()) / RAND_MAX;
         s=sign(delta - 0.5) * t * (pow(1 + 1 / t, abs(2 * delta - 1)) - 1);
        new_arg = grid.point[i].value + s * (grid.point[i].right - grid.point[i].left);
    }
    while (new_arg<grid.point[i].left||new_arg>grid.point[i].right);
    temp.point[i].value=new_arg;
    temp.point[i].left=grid.point[i].left;
    temp.point[i].right=grid.point[i].right;
}
return temp;
}
syst_arg new_state (double (*f)(syst_arg),syst_arg previous_grid, double t){
double dE=0, previous_E=f(previous_grid);
syst_arg next_grid;
do
{
    next_grid=candidate(previous_grid,t);
    dE=previous_E-f(next_grid);
}
while (!(inTransition(TransitionProbability(dE,t))));
return next_grid;
}
double poisk (double (*f)(syst_arg), syst_arg start_state, syst_arg &max_grid){
syst_arg grid;
int level=0;
double maximum=0, f_value=0, t=start_temp;
grid=start_state;
maximum=f(start_state);
while (t>end_temp){
    level++;
    t=decrease(level);
    grid=new_state (f,grid,t);
    f_value=f(grid);
    if (f_value>maximum){
        max_grid=grid;
        maximum=f_value;
    }
}
    return maximum;
}
void Initialisation (syst_arg &start_state){
cout << "Coordinate of borders : "<<endl;
    for (int i = 0; i < N; i++)
    {
        cout<<i+1<<") ";
        cin >> start_state.point[i].left >> start_state.point[i].right;
        start_state.point[i].value = start_state.point[i].left + ((double)(rand()) / RAND_MAX) * (start_state.point[i].right - start_state.point[i].left);
    }
}
std::ostream& operator<< (std::ostream &out, syst_arg grid)
{
    out << "{";
    for (int i = 0; i < N; i++)
    {
        out << grid.point[i].value;
        if (i < N - 1)
        {
            out << ", ";
        }
    }
    out << "}";

    return out;
}
int main()
{
    syst_arg start_state, current_max_grid, max_grid;
    double current_max_value=0, max_value=0;
    srand(time(0));

    Initialisation(start_state);
    current_max_value=F1(start_state);
    for (int i=0; i<repeat; i++){
        current_max_value=poisk(F1,start_state,current_max_grid);
        if (i==0||current_max_value>max_value){
            max_value=current_max_value;
            max_grid=current_max_grid;
        }
    }
    cout<<"max:"<<max_value<<endl;
    cout<<"point:"<<max_grid;



    return 0;
}
