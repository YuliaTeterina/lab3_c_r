#include "FileManager.h"
#include <fstream>
#include <iostream>

bool FileManager::readGraphFromFile(const std::string& fileName, std::vector<std::vector<int>>& adjacencyMatrix)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "Ошибка: не удалось открыть файл.\n";
        return false;
    }

    int n;
    file >> n;

    if (n <= 0)
    {
        std::cout << "Ошибка: некорректное количество вершин.\n";
        return false;
    }

    adjacencyMatrix.resize(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!(file >> adjacencyMatrix[i][j]))
            {
                std::cout << "Ошибка: неверный формат файла.\n";
                return false;
            }

            if (adjacencyMatrix[i][j] < 0)
            {
                std::cout << "Ошибка: веса дуг не могут быть отрицательными.\n";
                return false;
            }
        }
    }

    file.close();
    return true;
}