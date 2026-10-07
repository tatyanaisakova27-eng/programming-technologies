#ifndef CAR_H
#define CAR_H

#include "Base.h"

// Класс-наследник для хранения данных о машинах фабрики
class Car : public Base {
private:
    std::string brand;
    std::string model;
    std::string licensePlate;

public:
    Car();
    Car(std::string b, std::string m, std::string lp);
    Car(const Car& other); // Конструктор копирования
    virtual ~Car();

    Car& operator=(const Car& other); // Перегрузка оператора присваивания

    std::string getBrand() const;
    void setBrand(std::string b);
    std::string getModel() const;
    void setModel(std::string m);
    std::string getLicensePlate() const;
    void setLicensePlate(std::string lp);

    // Переопределенные методы управления и работы с файлами
    void input() override;
    void display() const override;
    void edit() override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
};

#endif