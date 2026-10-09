#include "Keeper.h"
#include "Furniture.h"
#include "Worker.h"
#include "Car.h"
#include "Exception.h"

Keeper::Keeper() : data(nullptr), size(0) {
    std::cout << "[Keeper] Container initialized" << std::endl;
}

// Деструктор последовательно очищает каждый динамический объект, затем сам массив
Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete data[i]; // Вызов виртуального деструктора базового класса
    }
    delete[] data;
    std::cout << "[Keeper] Container destroyed" << std::endl;
}

int Keeper::getSize() const { return size; }

// Добавление элемента с ручным перевыделением памяти
void Keeper::add(Base* item) {
    Base** newData = new Base * [size + 1];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = item;
    delete[] data;
    data = newData;
    size++;
}

// Удаление элемента по индексу с уменьшением размера массива
void Keeper::remove(int index) {
    if (index < 0 || index >= size) {
        throw FactoryException("Deletion error: Index out of range!");
    }
    delete data[index];
    Base** newData = new Base * [size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            newData[j++] = data[i];
        }
    }
    delete[] data;
    data = newData;
    size--;
}

// Демонстрация полиморфизма: вызов метода display() через указатель базового класса
void Keeper::displayAll() const {
    std::cout << "\n";
    if (size == 0) {
        std::cout << "The container is empty.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << "[" << i << "] ";
        data[i]->display();// Виртуальный вызов метода конкретного наследника
    }
}

Base* Keeper::get(int index) {
    if (index < 0 || index >= size) {
        throw FactoryException("Access error: Index out of range!");
    }
    return data[index];
}

// Сохранение контейнера: сначала записывается размер, затем вызывается save() для каждого объекта
void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw FactoryException("Error: Could not open file for writing!");
    }
    out << size << "\n";
    for (int i = 0; i < size; ++i) {
        data[i]->save(out);
    }
    out.close();
    std::cout << "Data successfully saved to: " << filename << std::endl;
}

// Восстановление контейнера с динамическим восстановлением типов по маркерам (ID)
void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw FactoryException("Error: Could not open file for reading!");
    }

    // Полная очистка текущих данных перед загрузкой нового файла
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
    data = nullptr;
    size = 0;

    int newSize;
    if (!(in >> newSize)) return;

    // Считывание и фабрикация объектов на основе считанного type_id
    for (int i = 0; i < newSize; ++i) {
        int id;
        in >> id;
        Base* item = nullptr;
        if (id == 1) item = new Furniture();
        else if (id == 2) item = new Worker();
        else if (id == 3) item = new Car();

        if (item) {
            item->load(in);
            add(item);
        }
    }
    in.close();
    std::cout << "Data successfully loaded from: " << filename << std::endl;
}
