#ifndef WORKER_H
#define WORKER_H

#include "Base.h"

// Класс-наследник для хранения данных о сотрудниках фабрики
class Worker : public Base {
private:
    std::string fullName;
    std::string position;
    double salary;
    std::string address;
    std::string phone;

public:
    Worker();
    Worker(std::string fn, std::string pos, double sal, std::string addr, std::string ph);
    Worker(const Worker& other); // Конструктор копирования
    virtual ~Worker();

    Worker& operator=(const Worker& other); // Перегрузка оператора присваивания

    std::string getFullName() const;
    void setFullName(std::string fn);
    std::string getPosition() const;
    void setPosition(std::string pos);
    double getSalary() const;
    void setSalary(double sal);
    std::string getAddress() const;
    void setAddress(std::string addr);
    std::string getPhone() const;
    void setPhone(std::string ph);

    void input() override;
    void display() const override;
    void edit() override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
};

#endif