#include "functions.h"
using namespace std;
int main()
{
 QueueP <int> Q1;
Q1.Push(1, 1, 3, 12.21);
Q1.Push(2, 2, 27, 12.21);
Q1.Push(3, 3, 5, 12.21);
Q1.Push(4, 6, 27, 12.21);
Q1.Push(5, 5, 27, 12.21);
Q1.Push(6, 4, 27, 12.40);
  Q1.Print("Q1");


  return 0;
}