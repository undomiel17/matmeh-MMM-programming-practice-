#include <iostream>
#include <new>

using namespace std;

    template <typename T>
class Queue
{
private:
  T* q;
  int count;
public:

  Queue()
  {
    count = 0;
  }
  ~Queue()
  {
    if (count > 0)
      delete[] q;
  }

  Queue(const Queue& qcur)
  {
    count = qcur.count;

    try {
      q = new T[count];
      for (int i = 0; i < count; i++)
        q[i] = qcur.q[i];
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
      count = 0;
    }
  }
  Queue& operator=(const Queue& qcur)
  {
    T* qsup;

    try {

      qsup = new T[qcur.count];

      if (count > 0)
        delete[] q;

      q = qsup;
      count = qcur.count;

      for (int i = 0; i < count; i++)
        q[i] = qcur.q[i];
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
    }
    return *this;
  }

   int GetCount()
  {

   return count;
  }
   bool IsEmpty()
  {
    return count == 0;
  }

  void push(T newelement)
  {
    T* qsup;
    qsup = q;

    try {
      q = new T[count + 1];
      for (int i = 0; i < count; i++)
        q[i] = qsup[i];
      q[count] = newelement;
      count++;
      if (count > 1)
        delete[] qsup;
    }
    catch (bad_alloc e)
    {

      cout << e.what() << endl;
      q = qsup;
    }
  }

  T pop()
  {
    if (count == 0)
      return 0;
    T newelement;

    newelement = q[0];
    try {
      T* qsup;
      qsup = new T[count - 1];

      count--;

      for (int i = 0; i < count; i++)
        qsup[i] = q[i + 1];

      if (count > 0)
        delete[] q;

      q = qsup;
      return newelement;
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
      return 0;
    }
  }

  T GetFirst()
  {
    if (count > 0)
      return q[0];
    else
      return 0;
  }

  void clear()
  {
    if (count > 0)
    {
      delete[] q;
      count = 0;
    }
  }


  void print(const char* qcur){
    cout << "Queue: " << qcur << endl;
    for (int i = 0; i < count; i++)
      cout << q[i] << " ";
    cout << endl;
    cout << "---------------------" << endl;
  }
};
int main()
{
    Queue <int> Q1;
    Queue <int> Q2;

    if (!Q1.IsEmpty())
          Q1.print("Q1");
        else cout<< "Empty"<<endl;

    for (int i=0; i<10; i++)
        Q1.push (i+1);
    Q1.print ("Q1");
    Q2=Q1;
    Q1.clear();
    cout<<"Count of Q1: "<<Q1.GetCount()<<endl;
    Q1.print("Q1");
    cout<<"First element of Q1: "<<Q1.GetFirst()<<endl;

    cout << "---------------------" << endl;

    cout<<"Count of Q2: "<<Q2.GetCount()<<endl;
    Q2.print("Q2");
    cout<<"First element of Q2: "<<Q2.GetFirst()<<endl;

    Queue <char> Q3;
    Q3.push ('a');
    Q3.push ('b');
    Q3.push ('c');
    Q3.print("Q3");
    return 0;
}
