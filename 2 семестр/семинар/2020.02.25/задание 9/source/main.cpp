#include "functions.h"
using namespace std;
int main()
{
    ex Example (1.2, 2,-10, 't', "pmml", 218724, 3456.5, true);
    Example.write();
    Example.proverka();
    Example.sum1();
    Example.sum2();
    return 0;
}
