#include <iostream>
#include "Keeper.h"
#include "Furniture.h"
#include "Worker.h"
#include "Car.h"
#include "Exception.h"

// Отображение интерактивного текстового меню в консоли
void showMenu() {
    std::cout << "\n======= FACTORY MANAGEMENT MENU =======" << std::endl;
    std::cout << "1. Add Object" << std::endl;
    std::cout << "2. Delete Object" << std::endl;
    std::cout << "3. Edit Object" << std::endl;
    std::cout << "4. Display All Objects" << std::endl;
    std::cout << "5. Save Container to File" << std::endl;
    std::cout << "6. Load Container from File" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

int main() {
    Keeper keeper; // Инициализация главного управляющего контейнера фабрики
    int choice = -1;
    std::string filename = "factory_data.txt";

    // Главный цикл работы программы
    while (choice != 0) {
        showMenu();
        std::cin >> choice;

        // Блок try-catch для безопасного отлова и обработки всех исключений 
        try {
            if (choice == 1) { // Создание нужного динамического объекта на основе выбора пользователя
                std::cout << "Select type to add (1 - Furniture, 2 - Worker, 3 - Car): ";
                int type;
                std::cin >> type;
                Base* newObj = nullptr;

                if (type == 1) newObj = new Furniture();
                else if (type == 2) newObj = new Worker();
                else if (type == 3) newObj = new Car();
                else throw FactoryException("Invalid object type selected!");

                newObj->input();
                keeper.add(newObj);
                std::cout << "Object added successfully!\n";

            }
            else if (choice == 2) { // Удаление существующего объекта
                keeper.displayAll();
                if (keeper.getSize() > 0) {
                    std::cout << "Enter the index of the object to delete: ";
                    int idx;
                    std::cin >> idx;
                    keeper.remove(idx);
                    std::cout << "Object deleted successfully!\n";
                }

            }
            else if (choice == 3) { // Редактирование существующего объекта
                keeper.displayAll();
                if (keeper.getSize() > 0) {
                    std::cout << "Enter the index of the object to edit: ";
                    int idx;
                    std::cin >> idx;
                    keeper.get(idx)->edit();
                    std::cout << "Object updated successfully!\n";
                }

            }
            else if (choice == 4) { // Вывод всей фабрики на экран
                keeper.displayAll();

            }
            else if (choice == 5) { // Экспорт данных в текстовый файл
                keeper.saveToFile(filename);

            }
            else if (choice == 6) { // Импорт данных из текстового файла
                keeper.loadFromFile(filename);
            }
        }

        // Перехват кастомных исключений валидации параметров или работы с индексами/файлами
        catch (const FactoryException& e) {
            std::cerr << "\n[EXCEPTION CAUGHT] " << e.getMessage() << std::endl;
        }

        // Базовый перехватчик на случай непредвиденных системных сбоев
        catch (...) {
            std::cerr << "\n[UNKNOWN ERROR OCCURRED]" << std::endl;
        }
    }

    return 0;
}
