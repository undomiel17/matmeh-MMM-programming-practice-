#include "functions.h"
template <typename T1, typename T2>

    void swap(const T1& obj1, const T2& obj2)
    {
//����������
        T1 tmp = obj1;
//������� ����������� �������� � ��������. ����������� ��� ������� � ���� �������
        const_cast<T1&> (obj1) = reinterpret_cast<T1&> (
                                    const_cast<T2&> (obj2));
        const_cast<T2&> (obj2) = reinterpret_cast<T2&> (
                                    const_cast<T1&> (tmp));
    }