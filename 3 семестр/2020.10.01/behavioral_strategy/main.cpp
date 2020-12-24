
//Стратегия — это поведенческий паттерн проектирования, который определяет семейство
//схожих алгоритмов и помещает каждый из них в собственный класс,
//после чего алгоритмы можно взаимозаменять прямо во время исполнения программы.
// Контекст используется для вызова алгоритма, определённого конкретной Стратегией, выбираемой пользователем.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Strategy
{
public:
    virtual ~Strategy() {}
    virtual float DoWork(const vector<float> &data) const = 0;
};

class Context
{
    //работает со всеми стратегиями
private:
    Strategy *strategy_;

public:
    Context(Strategy *strategy = nullptr) : strategy_(strategy)
    {
    }
    ~Context()
    {
        delete this->strategy_;
    }
   //замена стратегии изнутри
    void set_strategy(Strategy *strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }

    void Choose() const
    {
        // ...
        std::cout << "Context: "<<endl;
        float result = this->strategy_->DoWork(vector<float>{1.0, 2.0, 3.0, 4.0, 5.0});
        std::cout << result << endl;
        // ...
    }
};


class ConcreteStrategyA : public Strategy
{
public:
    float DoWork(const vector<float> &data) const override
    {
        float result;
        for_each(begin(data), end(data), [&result](const float &number) {
            result += number;
        });
        result/=data.size();

        return result;
    }
};
class ConcreteStrategyB : public Strategy
{
    float DoWork(const vector<float> &data) const override
    {
        float result=1.0;
        for_each(begin(data), end(data), [&result](const float &number) {
            result *= number;
        });
        result=pow(result,data.size());

        return result;
    }
};

 // Клиентский код выбирает конкретную стратегию и передаёт её в контекст. Клиент
 //должен знать о различиях между стратегиями, чтобы сделать правильный выбор.


void ClientCode()
{
    Context *context = new Context(new ConcreteStrategyA);
    std::cout << "Client: Strategy is average"<<endl;
    context->Choose();
    std::cout << "\n";
    std::cout << "Client: Strategy is geometric mean."<<endl;
    context->set_strategy(new ConcreteStrategyB);
    context->Choose();
    delete context;
}

int main()
{
    ClientCode();
    return 0;
}
