#include "Base.h"

Base::Base(int id) : type_id(id) {
    std::cout << "[Base] Parameterized constructor called for type ID: " << type_id << std::endl;
}

Base::~Base() {
    std::cout << "[Base] Destructor called for type ID: " << type_id << std::endl;
}

int Base::getTypeId() const {
    return type_id;
}
