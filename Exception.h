#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

// Собственный класс для обработки исключительных ситуаций в программе
class FactoryException {
private:
    std::string message;
public:
    FactoryException(const std::string& msg) : message(msg) {}
    std::string getMessage() const { return message; } // Метод для получения описания ошибки
};

#endif
