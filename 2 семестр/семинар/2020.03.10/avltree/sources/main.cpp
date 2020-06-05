#include "functions.h"
using namespace std;
int main()
{
    srand(time(NULL));
    int number, repeat;
    cout << "size of transposition: " << endl;
    cin >> number;
    cout << "experiment accuracy: " << endl;
    cin >> repeat;
    experiment (number, repeat);
    return 0;
}