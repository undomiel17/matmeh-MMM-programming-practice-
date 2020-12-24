#include <iostream>
using namespace std;
/**
 * ���������� ������������� ��������� ��� ���� ������� ����������. �� �� ������
 * ��������������� ���������� ����������. �� �������� ��� ���������� ����� ����
 * ���������� �������. ��� �������, ��������� ���������� ������������� ������
 * ����������� ��������, � �� ����� ��� ���������� ���������� �������� �����
 * �������� ������, ���������� �� ���� ����������.
 */

class Implementation {
 public:
  virtual ~Implementation() {}
  virtual string OperationImplementation() const = 0;
};

/**
 * ������ ���������� ���������� ������������� ����������� ��������� � ���������
 * ��������� ���������� � �������������� API ���� ���������.
 */
class ConcreteImplementationA : public Implementation {
 public:
  string OperationImplementation() const override {
    return "Implementation on the First platform.\n";
  }
};
class ConcreteImplementationB : public Implementation {
 public:
  string OperationImplementation() const override {
    return "Implementation on the Second platform.\n";
  }
};

/**
 * ���������� ������������� ��������� ��� ������������ ����� ���� ��������
 * �������. ��� �������� ������ �� ������ �� �������� ���������� � ����������
 * ��� ��� ��������� ������.
 */

class Abstraction {
  /**
   * @var Implementation
   */
 protected:
  Implementation* implementation_;

 public:
  Abstraction(Implementation* implementation) : implementation_(implementation) {
  }

  virtual ~Abstraction() {
  }

  virtual string Operation() const {
    return "Abstraction: Base operation with:\n" +
           this->implementation_->OperationImplementation();
  }
};
/**
 * ����� ��������� ���������� ��� ��������� ������� ����������.
 */
class ExtendedAbstraction : public Abstraction {
 public:
  ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {
  }
  string Operation() const override {
    return "ExtendedAbstraction: Extended operation with:\n" +
           this->implementation_->OperationImplementation();
  }
};

/**
 * �� ����������� ����� �������������, ����� ������ ���������� ����������� �
 * ����������� �������� ����������, ���������� ��� ������ �������� ������ ��
 * ������ ����������. ����� �������, ���������� ��� ����� ������������ �����
 * ���������� ���������� � ����������.
 */
void ClientCode(const Abstraction& abstraction) {
  // ...
  cout << abstraction.Operation();
  // ...
}
/**
 * ���������� ��� ������ �������� � ����� �������������� ������������������
 * ����������� ���������� � ����������.
 */

int main() {
  Implementation* implementation = new ConcreteImplementationA;
  Abstraction* abstraction = new Abstraction(implementation);
  ClientCode(*abstraction);
  cout << endl;
  delete implementation;
  delete abstraction;

  implementation = new ConcreteImplementationB;
  abstraction = new ExtendedAbstraction(implementation);
  ClientCode(*abstraction);

  delete implementation;
  delete abstraction;

  return 0;
}
