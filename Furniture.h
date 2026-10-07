#ifndef FURNITURE_H
#define FURNITURE_H

#include "Base.h"

// Класс-наследник для хранения данных о производимой мебели
class Furniture : public Base {
private:
    std::string type;
    double height;
    double width;
    double depth;
    std::string color;
    std::string material;
    double price;

public:
    Furniture();
    Furniture(std::string t, double h, double w, double d, std::string c, std::string m, double p);
    Furniture(const Furniture& other); // Конструктор копирования
    virtual ~Furniture();

    Furniture& operator=(const Furniture& other);

    std::string getType() const;
    void setType(std::string t);
    double getHeight() const;
    void setHeight(double h);
    double getWidth() const;
    void setWidth(double w);
    double getDepth() const;
    void setDepth(double d);
    std::string getColor() const;
    void setColor(std::string c);
    std::string getMaterial() const;
    void setMaterial(std::string m);
    double getPrice() const;
    void setPrice(double p);

    // Переопределенные методы пользовательского ввода, вывода и работы с файлами
    void input() override;
    void display() const override;
    void edit() override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
};

#endif
