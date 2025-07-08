#ifndef DataGenerate_H
#define DataGenerate_H

#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

std::string generateName()
{
    std::vector<std::string> surnames = {
        "Voloshinskiy", "Ivanov", "Petrov", "Sidorov", "Komarov",
        "Lebedev", "Smirnov", "Morozov", "Novikov", "Popov"
    };

    std::vector<std::string> names = {
        "Rostislav", "Artem", "Daniil", "Vadim", "Oleg",
        "Yuri", "Alexey", "Nikita", "Kirill", "Vladislav"
    };

    std::vector<std::string> patronymics = {
        "Anatolevich", "Ivanovich", "Petrovich", "Nikolaevich",
        "Sergeevich", "Alexeevich", "Yurievich", "Andreevich"
    };

    return surnames[std::rand() % surnames.size()] + " " +
           names[std::rand() % names.size()] + " " +
           patronymics[std::rand() % patronymics.size()];
}

std::string generateCarModel()
{
    std::vector<std::string> brands = {
        "Toyota", "BMW", "Mercedes", "Lada", "Ford",
        "Audi", "Hyundai", "Kia", "Mazda", "Volkswagen"
    };

    std::vector<std::string> models = {
        "Camry", "X5", "E200", "Granta", "Focus",
        "A4", "Solaris", "Rio", "CX-5", "Polo", "Passat"
    };

    return brands[std::rand() % brands.size()] + " " +
           models[std::rand() % models.size()];
}

std::string generateDate()
{
    int day = std::rand() % 28 + 1;      // 1–28
    int month = std::rand() % 12 + 1;    // 1–12
    int year = 2020 + (std::rand() % 6); // 2020–2025

    return std::to_string(day) + " " +
           std::to_string(month) + " " +
           std::to_string(year);
}

void GenerateData(const std::string& filename, int n)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // инициализация генератора

    std::ofstream out(filename);
    if (!out.is_open()) return;

    for (int line = 1; line <= n; ++line)
    {
        out << generateName() << " "
            << generateCarModel() << " "
            << generateDate() << " "
            << std::to_string(line) << "\n";
    }

    out.close();
}

#endif
