#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <string>

class Base {
protected:
    int type_id; // 1 - Мебель, 2 - Работник, 3 - Машина
public:
    Base(int id);
    virtual ~Base();

    int getTypeId() const;

    virtual void input() = 0;
    virtual void display() const = 0;
    virtual void edit() = 0;
    virtual void save(std::ofstream& out) const = 0;
    virtual void load(std::ifstream& in) = 0;
};

#endif

