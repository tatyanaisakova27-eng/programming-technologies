#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

// Класс - контейнер для хранения и обработки разнородных объектов(полиморфный массив)
class Keeper {
private:
    Base** data;
    int size;

public:
    Keeper();
    ~Keeper();

    int getSize() const;
    void add(Base* item);
    void remove(int index);
    void displayAll() const;
    Base* get(int index);

    // Методы полной сериализации и десериализации данных
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif