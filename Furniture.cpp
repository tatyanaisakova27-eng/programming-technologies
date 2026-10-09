#include "Furniture.h"
#include "Exception.h"

// Конструктор по умолчанию передает ID типа (1) в базовый класс
Furniture::Furniture() : Base(1), type(""), height(0), width(0), depth(0), color(""), material(""), price(0) {
    std::cout << "[Furniture] Default constructor called" << std::endl;
}

// Конструктор с параметрами
Furniture::Furniture(std::string t, double h, double w, double d, std::string c, std::string m, double p)
    : Base(1), type(t), height(h), width(w), depth(d), color(c), material(m), price(p) {
    std::cout << "[Furniture] Parameterized constructor called" << std::endl;
}

// Конструктор копирования
Furniture::Furniture(const Furniture& other) : Base(1) {
    std::cout << "[Furniture] Copy constructor called" << std::endl;
    *this = other;
}

Furniture::~Furniture() {
    std::cout << "[Furniture] Destructor called" << std::endl;
}

// Перегрузка оператора присваивания с защитой от самоприсваивания
Furniture& Furniture::operator=(const Furniture& other) {
    if (this != &other) {
        type = other.type;
        height = other.height;
        width = other.width;
        depth = other.depth;
        color = other.color;
        material = other.material;
        price = other.price;
    }
    return *this;
}

std::string Furniture::getType() const { return type; }
void Furniture::setType(std::string t) { type = t; }
double Furniture::getHeight() const { return height; }
void Furniture::setHeight(double h) { if (h < 0) throw FactoryException("Height cannot be negative!"); height = h; }
double Furniture::getWidth() const { return width; }
void Furniture::setWidth(double w) { if (w < 0) throw FactoryException("Width cannot be negative!"); width = w; }
double Furniture::getDepth() const { return depth; }
void Furniture::setDepth(double d) { if (d < 0) throw FactoryException("Depth cannot be negative!"); depth = d; }
std::string Furniture::getColor() const { return color; }
void Furniture::setColor(std::string c) { color = c; }
std::string Furniture::getMaterial() const { return material; }
void Furniture::setMaterial(std::string m) { material = m; }
double Furniture::getPrice() const { return price; }
void Furniture::setPrice(double p) { if (p < 0) throw FactoryException("Price cannot be negative!"); price = p; }

// Консольный ввод данных с валидацией числовых значений
void Furniture::input() {
    std::cin.ignore();
    std::cout << "Enter furniture type: "; std::getline(std::cin, type);
    std::cout << "Enter height: "; std::cin >> height;
    std::cout << "Enter width: "; std::cin >> width;
    std::cout << "Enter depth: "; std::cin >> depth;
    std::cin.ignore();
    std::cout << "Enter color: "; std::getline(std::cin, color);
    std::cout << "Enter material: "; std::getline(std::cin, material);
    std::cout << "Enter price: "; std::cin >> price;
    if (height < 0 || width < 0 || depth < 0 || price < 0) {
        throw FactoryException("Error: Numeric parameters cannot be negative!");
    }
}

// Вывод форматированной информации об объекте мебели
void Furniture::display() const {
    std::cout << "[Furniture] Type: " << type << " | Dimensions: " << height << "x" << width << "x" << depth
        << " | Color: " << color << " | Material: " << material << " | Price: " << price << std::endl;
}

void Furniture::edit() {
    std::cout << "Editing furniture details:\n";
    input();
}

// Сохранение полей объекта мебели в поток файла
void Furniture::save(std::ofstream& out) const {
    out << type_id << "\n" << type << "\n" << height << "\n" << width << "\n" << depth << "\n" << color << "\n" << material << "\n" << price << "\n";
}

// Чтение полей объекта мебели из потока файла
void Furniture::load(std::ifstream& in) {
    in.ignore();
    std::getline(in, type);
    in >> height >> width >> depth;
    in.ignore();
    std::getline(in, color);
    std::getline(in, material);
    in >> price;
}
