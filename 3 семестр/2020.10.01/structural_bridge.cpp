//Мост — это структурный паттерн проектирования, который разделяет один или несколько классов на две отдельные иерархии — абстракцию и реализацию, 
//позволяя изменять их независимо друг от друга.
//Как правило, интерфейс Реализации предоставляет только
//примитивные операции, в то время как Абстракция определяет операции более
 //высокого уровня, основанные на этих примитивах.
#include <iostream>
using namespace std;

class Implementation {
 public:
  virtual ~Implementation() {}
  virtual string OperationImplementation() const = 0;
};

//Каждая Конкретная Реализация соответствует определённой платформе.
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

//Абстракция устанавливает интерфейс для «управляющей» части двух иерархий классов.

class Abstraction {
  /**
   * @var Implementation ссылка на нужную реализацию (основанную на собственной платформе)
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
//Также можно выбирать операции для разных реализаций.
//Это расширенная.
class ExtendedAbstraction : public Abstraction {
 public:
  ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {
  }
  string Operation() const override {
    return "ExtendedAbstraction: Extended operation with:\n" +
           this->implementation_->OperationImplementation();
  }
};

//Клиент управляет. Так что связан только с абстракцией.
void ClientCode(const Abstraction& abstraction) {
  // ...
  cout << abstraction.Operation();
  // ...
}
//Клиент может работать с предварительно выбранной комбинацией абстракции и реализации.

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
