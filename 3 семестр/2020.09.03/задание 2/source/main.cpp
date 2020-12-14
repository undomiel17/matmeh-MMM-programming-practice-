#include "functions.h"
int main()
{
     srand(time(0));
    int k,n;
    cout<<"number of buffers:"<<endl;
    cin>>k;
    cout<<"length of buffers:"<<endl;
    cin>>n;
    raid <int> raid5(k,n);
    raid5.read();
    //raid5.print();
    raid5.control();
    raid5.print();
    int mistake= rand()%n;
    raid5.loss(mistake);
    cout<<"data of disk "<<mistake+1<<" are lost"<<endl;
    raid5.print();
    raid5.recovery(mistake);
    raid5.print();
    return 0;
}
