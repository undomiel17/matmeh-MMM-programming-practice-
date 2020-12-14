#include <iostream>

using namespace std;

template <typename T>
class STACK
{
private:
  T* stack;
  int count;
public:
  STACK()
  {
    stack = nullptr;
    count = 0;
  }

  void push(T item)
  {
    T* tmp;
    try {
      tmp = stack;

      stack = new T[count + 1];

      count++;

      for (int i = 0; i < count - 1; i++)
        stack[i] = tmp[i];
      stack[count - 1] = item;

      if (count > 1)
        delete[] tmp;
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
    }
  }

  T pop()
  {
    if (count == 0)
      return 0;
    count--;
    return stack[count];
  }

  T Head()
  {
    if (count == 0)
      return 0;
    return stack[count - 1];
  }

  STACK(const STACK& st)
  {
    try {
      stack = new T[st.count];

      count = st.count;
      for (int i = 0; i < count; i++)
        stack[i] = st.stack[i];
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
    }
  }

  STACK operator=(const STACK& st)
  {
    if (count > 0)
    {
      count = 0;
      delete[] stack;
    }

    try {

      stack = new T[st.count];

      count = st.count;
      for (int i = 0; i < count; i++)
        stack[i] = st.stack[i];
    }
    catch (bad_alloc e)
    {

      cout << e.what() << endl;
    }

    return *this;
  }

  ~STACK()
  {
    if (count > 0)
      delete[] stack;
  }

  int Count()
  {
    return count;
  }

  bool IsEmpty()
  {
    return count == 0;
  }

  void Print()
  {
    T* p;
    p = stack;

    cout << "Stack: " << endl;
    if (count == 0)
      cout << "is empty." << endl;
else {
    for (int i = 0; i < count; i++)
    {
      cout << "Item[" << i << "] = " << p[i] << endl;
    }
    cout << endl;
  }
  }
T multipop (int k){
if (count==0) return 0;
count=count-k;
return stack [count];
}
};
template <> class STACK <bool>{
private:
  bool* stack;
  int count;
public:
STACK()
  {
    stack = nullptr;
    count = 0;
  }
STACK(const STACK& st)
  {
    try {
      stack = new bool[st.count];

      count = st.count;
      for (int i = 0; i < count; i++)
        if (st.stack[i]==true) stack[i] = true;
        else stack[i]=false;
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
    }
  }

  STACK operator=(const STACK& st)
  {
    if (count > 0)
    {
      count = 0;
      delete[] stack;
    }

    try {

      stack = new bool[st.count];

      count = st.count;
      for (int i = 0; i < count; i++)
       if (st.stack[i]==true) stack[i] = true;
       else stack[i]=false;
    }
    catch (bad_alloc e)
    {

      cout << e.what() << endl;
    }

    return *this;
  }

  ~STACK()
  {
    if (count > 0)
      delete[] stack;
  }

  int Count()
  {
    return count;
  }

  bool IsEmpty()
  {
    return count == 0;
  }

 void push(bool item)
  {
    bool* tmp;
    try {
      tmp = stack;

      stack = new bool[count + 1];

      count++;

      for (int i = 0; i < count - 1; i++)
       if (tmp[i]==true) stack[i]=true; else stack[i]=false;
     if (item==true) stack[count - 1]=true; else stack[count-1]=false;

      if (count > 1)
        delete[] tmp;
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
    }
  }
  bool Head()
  {
    if (count == 0)
      return 0;
     if (stack[count - 1]==true)
    return true;
    else return false;
  }
  bool pop()
  {
    if (count == 0)
      return 0;
    count--;
    if (stack[count]==true)
    return true;
    else return false;
  }

 void Print()
  {
    bool* p;
    p = stack;

    cout << "Stack: " << endl;
    if (count == 0)
      cout << "is empty." << endl;

    for (int i = 0; i < count; i++)
    {
      cout << "Item[" << i << "] = ";
      if (p[i]==true) cout<<"true"<<endl;
      else cout<<"false" << endl;
    }
    cout << endl;
  }
bool multipop (int k){
if (count==0) return 0;
count=count-k;
return stack [count];
}
};


int main()
{
    STACK<bool> st1;
    st1.Print();
    st1.push(false);
    cout<<std::boolalpha<<st1.Head()<<endl;
    st1.push(true);
    st1.push(false);
    cout<<st1.Count()<<endl;
    st1.Print();
    st1.pop();
    cout<<st1.Count()<<endl;
    st1.Print();
    return 0;
}
