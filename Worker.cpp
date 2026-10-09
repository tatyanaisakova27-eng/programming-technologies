#include "Worker.h"
#include "Exception.h"

// Конструктор по умолчанию передает ID типа (2) в базовый класс
Worker::Worker() : Base(2), fullName(""), position(""), salary(0), address(""), phone("") {
    std::cout << "[Worker] Default constructor called" << std::endl;
}

// Конструктор с параметрами
Worker::Worker(std::string fn, std::string pos, double sal, std::string addr, std::string ph)
    : Base(2), fullName(fn), position(pos), salary(sal), address(addr), phone(ph) {
    std::cout << "[Worker] Parameterized constructor called" << std::endl;
}

// Конструктор копирования
Worker::Worker(const Worker& other) : Base(2) {
    std::cout << "[Worker] Copy constructor called" << std::endl;
    *this = other;
}

Worker::~Worker() {
    std::cout << "[Worker] Destructor called" << std::endl;
}

// Перегрузка оператора присваивания с защитой от самоприсваивания
Worker& Worker::operator=(const Worker& other) {
    if (this != &other) {
        fullName = other.fullName;
        position = other.position;
        salary = other.salary;
        address = other.address;
        phone = other.phone;
    }
    return *this;
}

std::string Worker::getFullName() const { return fullName; }
void Worker::setFullName(std::string fn) { fullName = fn; }
std::string Worker::getPosition() const { return position; }
void Worker::setPosition(std::string pos) { position = pos; }
double Worker::getSalary() const { return salary; }
void Worker::setSalary(double sal) { if (sal < 0) throw FactoryException("Salary cannot be negative!"); salary = sal; }
std::string Worker::getAddress() const { return address; }
void Worker::setAddress(std::string addr) { address = addr; }
std::string Worker::getPhone() const { return phone; }
void Worker::setPhone(std::string ph) { phone = ph; }

// Консольный ввод данных с защитой от отрицательной зарплаты
void Worker::input() {
    std::cin.ignore();
    std::cout << "Enter employee Full Name: "; std::getline(std::cin, fullName);
    std::cout << "Enter position: "; std::getline(std::cin, position);
    std::cout << "Enter salary: "; std::cin >> salary;
    if (salary < 0) throw FactoryException("Error: Salary cannot be negative!");
    std::cin.ignore();
    std::cout << "Enter home address: "; std::getline(std::cin, address);
    std::cout << "Enter phone number: "; std::getline(std::cin, phone);
}

// Вывод форматированной информации о работнике фабрики
void Worker::display() const {
    std::cout << "[Worker] Name: " << fullName << " | Position: " << position
        << " | Salary: " << salary << " | Address: " << address << " | Phone: " << phone << std::endl;
}

void Worker::edit() {
    std::cout << "Editing employee details:\n";
    input();
}

// Сохранение полей объекта сотрудника в поток файла
void Worker::save(std::ofstream& out) const {
    out << type_id << "\n" << fullName << "\n" << position << "\n" << salary << "\n" << address << "\n" << phone << "\n";
}

// Чтение полей объекта сотрудника из потока файла
void Worker::load(std::ifstream& in) {
    in.ignore();
    std::getline(in, fullName);
    std::getline(in, position);
    in >> salary;
    in.ignore();
    std::getline(in, address);
    std::getline(in, phone);
}
