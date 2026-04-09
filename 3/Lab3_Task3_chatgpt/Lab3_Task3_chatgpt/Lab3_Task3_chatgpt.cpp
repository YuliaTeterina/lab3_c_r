#include <iostream>
#include "Graph.h"
#include "FileManager.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string fileName;
    std::cout << "Введите имя файла: ";
    std::cin >> fileName;

    std::vector<std::vector<int>> adjacencyMatrix;

    if (!FileManager::readGraphFromFile(fileName, adjacencyMatrix))
    {
        std::cout << "Ошибка при чтении файла.\n";
        return 1;
    }

    Graph graph;

    if (!graph.loadFromMatrix(adjacencyMatrix))
    {
        std::cout << "Ошибка загрузки графа.\n";
        return 1;
    }

    int startVertex;
    std::cout << "Введите номер стартовой вершины (от 1 до "
        << graph.getVertexCount() << "): ";
    std::cin >> startVertex;

    // Перевод в 0-based индекс
    startVertex--;

    std::vector<int> result = graph.breadthFirstSearch(startVertex);

    if (result.empty())
    {
        std::cout << "Нет достижимых вершин.\n";
        return 0;
    }

    std::cout << "Результат обхода в ширину:\n";

    for (int vertex : result)
    {
        std::cout << vertex + 1 << " ";
    }

    std::cout << std::endl;

    return 0;
}