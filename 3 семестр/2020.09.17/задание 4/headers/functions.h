#include <iostream>
#include <new>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
template <typename T>
     class QueueP;
template <typename T>
     void QueueP<T>::Push(T item, int priority, double worktime, double get);
template <typename T>
     T QueueP<T>::Pop();
//ñ÷èòàåò îêîí÷àòåëüíûå ïðèîðèòåòû
template <typename T>
     void QueueP<T>::Priority();
void start();
void START();
