#include "functions.h"
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