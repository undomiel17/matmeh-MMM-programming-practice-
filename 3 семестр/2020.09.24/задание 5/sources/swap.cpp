#include "functions.h"
template <typename T1, typename T2>

    void swap(const T1& obj1, const T2& obj2)
    {
//хапоминает
        T1 tmp = obj1;
//снимает константное значение и приводит типы
        const_cast<T1&> (obj1) = reinterpret_cast<T1&> (
                                    const_cast<T2&> (obj2));
        const_cast<T2&> (obj2) = reinterpret_cast<T2&> (
                                    const_cast<T1&> (tmp));
    }
