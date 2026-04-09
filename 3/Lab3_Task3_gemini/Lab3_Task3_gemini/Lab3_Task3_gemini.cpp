#include <iostream>
#include <string>
#include <vector>
#include "GraphSolver.h"

/**
 * Функция для вывода интерфейса и обработки логики взаимодействия.
 */
int main()
{
    // Установка русской локализации для консоли
    setlocale(LC_ALL, "Russian");

    FGraphSolver solver;
    std::string fileName;

    std::cout << "=== Программа поиска в ширину (BFS) на ориентированном графе ===" << std::endl;
    std::cout << "Введите имя файла с матрицей смежности: ";
    std::cin >> fileName;

    if (!solver.loadFromFile(fileName))
    {
        std::cerr << "Ошибка: Не удалось прочитать файл или данные некорректны." << std::endl;
        return 1;
    }

    int32_t startK = 0;
    int32_t maxVertex = solver.getVertexCount() - 1;

    std::cout << "Файл успешно загружен. Вершин в графе: " << solver.getVertexCount() << std::endl;
    //FIX_ME: для удобства пользователя, счёт должна начиваться с 1
    //std::cout << "Введите начальную вершину k (от 0 до " << maxVertex << "): ";
    std::cout << "Введите начальную вершину k (от 1 до " << maxVertex << "): ";


    // Проверка ввода на число и диапазон
    if (!(std::cin >> startK) || startK < 1 || startK > maxVertex)
    {
        std::cerr << "Ошибка: Введена некорректная начальная вершина." << std::endl;
        return 1;
    }

	// Преобразуем к 0-индексации для внутренней логики
    startK--;

    // Запуск алгоритма
    std::vector<int32_t> reachableVertices = solver.performBFS(startK);

    // Вывод результата
    if (reachableVertices.empty())
    {
        std::cout << "Из вершины " << startK + 1<< " нет достижимых вершин." << std::endl;
    }
    else
    {
        std::cout << "Вершины, достижимые из " << startK + 1 << " (в порядке BFS):" << std::endl;
        for (size_t i = 0; i < reachableVertices.size(); ++i)
        {
            std::cout << reachableVertices[i] + 1 << (i == reachableVertices.size() - 1 ? "" : " -> ");
        }
        std::cout << std::endl;
    }

    return 0;
}