#include "Car.h"
#include "Exception.h"

// Конструктор по умолчанию передает ID типа (3) в базовый класс
Car::Car() : Base(3), brand(""), model(""), licensePlate("") {
    std::cout << "[Car] Default constructor called" << std::endl;
}

// Конструктор с параметрами
Car::Car(std::string b, std::string m, std::string lp) : Base(3), brand(b), model(m), licensePlate(lp) {
    std::cout << "[Car] Parameterized constructor called" << std::endl;
}

// Конструктор копирования использует перегруженный оператор присваивания
Car::Car(const Car& other) : Base(3) {
    std::cout << "[Car] Copy constructor called" << std::endl;
    *this = other;
}

Car::~Car() {
    std::cout << "[Car] Destructor called" << std::endl;
}

// Перегрузка оператора присваивания с защитой от самоприсваивания
Car& Car::operator=(const Car& other) {
    if (this != &other) {
        brand = other.brand;
        model = other.model;
        licensePlate = other.licensePlate;
    }
    return *this;
}

std::string Car::getBrand() const { return brand; }
void Car::setBrand(std::string b) { brand = b; }
std::string Car::getModel() const { return model; }
void Car::setModel(std::string m) { model = m; }
std::string Car::getLicensePlate() const { return licensePlate; }
void Car::setLicensePlate(std::string lp) { licensePlate = lp; }

// Консольный ввод данных (с поддержкой строк с пробелами через getline)
void Car::input() {
    std::cin.ignore();
    std::cout << "Enter car brand: "; std::getline(std::cin, brand);
    std::cout << "Enter car model: "; std::getline(std::cin, model);
    std::cout << "Enter license plate: "; std::getline(std::cin, licensePlate);
}

// Вывод форматированной информации об объекте
void Car::display() const {
    std::cout << "[Car] Brand: " << brand << " | Model: " << model << " | License Plate: " << licensePlate << std::endl;
}

void Car::edit() {
    std::cout << "Editing car details:\n";
    input();
}

// Построчное сохранение полей объекта в текстовый файл
void Car::save(std::ofstream& out) const {
    out << type_id << "\n" << brand << "\n" << model << "\n" << licensePlate << "\n";
}

// Построчное восстановление полей объекта из текстового файла
void Car::load(std::ifstream& in) {
    in.ignore();
    std::getline(in, brand);
    std::getline(in, model);
    std::getline(in, licensePlate);
}
