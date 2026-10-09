#include "Base.h"

// Конструктор инициализирует ID типа (1 - Мебель, 2 - Работник, 3 - Машина)
Base::Base(int id) : type_id(id) {
    std::cout << "[Base] Parameterized constructor called for type ID: " << type_id << std::endl;
}

Base::~Base() {
    std::cout << "[Base] Destructor called for type ID: " << type_id << std::endl;
}

// Метод возвращает тип объекта 
int Base::getTypeId() const {
    return type_id;
}
