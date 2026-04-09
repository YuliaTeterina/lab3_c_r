#pragma once

#include <vector>
#include <string>

/**
 * Класс для работы с файлами
 */
class FileManager
{
public:
    /**
     * Чтение графа из файла
     * @param fileName - имя файла
     * @param adjacencyMatrix - выходная матрица
     * @return успех операции
     */
     //FIX_ME: название методов должно быть lowercase
    //static bool ReadGraphFromFile(const std::string& fileName, std::vector<std::vector<int>>& adjacencyMatrix);
    static bool readGraphFromFile(const std::string& fileName, std::vector<std::vector<int>>& adjacencyMatrix);
};