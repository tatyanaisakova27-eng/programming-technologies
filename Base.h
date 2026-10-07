#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <string>

// Абстрактный базовый класс для всех объектов фабрики
class Base {
protected:
    int type_id;
public:
    Base(int id);
    virtual ~Base();

    int getTypeId() const;

    // Чисто виртуальные методы (интерфейс для классов-наследников)
    virtual void input() = 0;
    virtual void display() const = 0;
    virtual void edit() = 0;
    virtual void save(std::ofstream& out) const = 0;
    virtual void load(std::ifstream& in) = 0;
};

#endif

