#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct long_value {
  int *values;
 int length;
};
int pstrlen( char*a){
   int i=0;
    for(;*a; ++a, i++);
    return i;
}
long_value sum(long_value a, long_value b) {
  long_value s;
  s.length = a.length + 1;
  s.values = new int[s.length];

  s.values[a.length - 1] = a.values[a.length - 1];
  s.values[a.length] = 0;
  for (int i = 0; i < b.length; ++i)
    s.values[i] = a.values[i] + b.values[i];
  return s;
}

long_value &sub(long_value &a, long_value b) {
  for (int i = 0; i < b.length; ++i)
    a.values[i] -= b.values[i];
  return a;
}

void normalize(long_value l) {
  for (int i = 0; i < l.length - 1; ++i) {
    if (l.values[i] >= 10) {
      l.values[i + 1] += l.values[i]/10;
       l.values[i]=l.values[i]%10;
    } else if (l.values[i] < 0) {
      int x = (l.values[i] + 1) / 10 - 1;
      l.values[i + 1] += x;
      l.values[i] -= x * 10;
  }
}
}

long_value karatsuba(long_value a, long_value b) {
  long_value product;
  product.length = a.length + b.length;
  product.values = new int[product.length];

  if (a.length < 3) {
   int x=0;
    for (int i = 0; i < a.length; i++){
      for (int j = 0; j < b.length; j++) {
        product.values[i + j] += x+a.values[i] * b.values[j];
      }
  }
  }
   else {
    long_value a_1;
    a_1.values = a.values;
    a_1.length = (a.length + 1) / 2;

    long_value a_2;
    a_2.values = a.values + a_1.length;
    a_2.length = a.length / 2;

    long_value b_1;
    b_1.values = b.values;
    b_1.length = (b.length + 1) / 2;

    long_value b_2;
    b_2.values = b.values + b_1.length;
    b_2.length = b.length / 2;

    long_value sum_of_a = sum(a_1, a_2);
    normalize(sum_of_a);
    long_value sum_of_b = sum(b_1, b_2);
    normalize(sum_of_b);
    long_value product_of_sums_of_parts = karatsuba(sum_of_a, sum_of_b);

    long_value product_of_first_parts = karatsuba(a_1, b_1);
    long_value product_of_second_parts = karatsuba(a_2, b_2);
    long_value sum_of_middle_terms = sub(sub(product_of_sums_of_parts, product_of_first_parts), product_of_second_parts);

    memcpy(product.values, product_of_first_parts.values,
      product_of_first_parts.length * sizeof(int));
    memcpy(product.values + product_of_first_parts.length,
      product_of_second_parts.values, product_of_second_parts.length
      * sizeof(int));
    for (int i = 0; i < sum_of_middle_terms.length; ++i)
      product.values[a_1.length + i] += sum_of_middle_terms.values[i];


    delete [] sum_of_a.values;
    delete [] sum_of_b.values;
    delete [] product_of_sums_of_parts.values;
    delete [] product_of_first_parts.values;
    delete [] product_of_second_parts.values;
  }

  normalize(product);

  return product;
}
ostream& operator<<(ostream& out,const long_value& a){
    for(int i=a.length-1;i>=0;i--){
        out<<a.values[i];
    }
    return out;
}
istream& operator>>(istream& in, long_value& a){
    char xa[256];
    in.getline(xa,256);
    a.length=pstrlen(xa);
    a.values = new int[pstrlen(xa)];
    for(int i=pstrlen(xa)-1;i>=0;i--){
        a.values[i]=xa[i]-'0';
    }
    return in;
}
int main()
{
    long_value a;
    cin>>a;
    long_value b;
    cin>>a;
    cout<<karatsuba(a,b)<<endl;

    return 0;
}
