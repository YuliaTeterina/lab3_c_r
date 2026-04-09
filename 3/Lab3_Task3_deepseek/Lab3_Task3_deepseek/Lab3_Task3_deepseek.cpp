#include "Graph.h"
#include <iostream>
#include <limits>

int main()
{
    setlocale(LC_ALL, "Russian"); // поддержка русского вывода в консоль

    std::string fileName;
    std::cout << "Введите имя файла с описанием графа: ";
    std::cin >> fileName;

    Graph graph;
    if (!graph.loadFromFile(fileName))
    {
        std::cerr << "Программа завершена из-за ошибки загрузки графа." << std::endl;
        return 1;
    }

    std::size_t vertexCount = graph.getVertexCount();
    std::cout << "Граф успешно загружен. Количество вершин: " << vertexCount << std::endl;

    int startVertex = 0;
    std::cout << "Введите номер начальной вершины (от 1 до " << vertexCount << "): ";
    std::cin >> startVertex;

    // Проверка корректности номера вершины
    if (std::cin.fail() || startVertex < 1 || static_cast<std::size_t>(startVertex) > vertexCount)
    {
        std::cerr << "Ошибка: номер вершины должен быть целым числом от 1 до " << vertexCount << "." << std::endl;
        return 1;
    }

    std::vector<int> reachableVertices = graph.bfs(startVertex);

    if (reachableVertices.empty())
    {
        std::cout << "Из вершины " << startVertex << " недостижимы другие вершины (кроме самой себя)." << std::endl;
    }
    else
    {
        std::cout << "Порядок обхода вершин, достижимых из вершины " << startVertex << ":" << std::endl;
        for (std::size_t i = 0; i < reachableVertices.size(); ++i)
        {
            std::cout << reachableVertices[i];
            if (i + 1 < reachableVertices.size()) std::cout << " -> ";
        }
        std::cout << std::endl;
    }

    return 0;
}