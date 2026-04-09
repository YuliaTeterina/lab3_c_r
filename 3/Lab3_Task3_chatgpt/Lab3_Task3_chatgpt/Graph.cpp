#include "Graph.h"
#include <queue>
#include <algorithm>
#include <iostream>

Graph::Graph()
    : vertexCount(0)
{
}

bool Graph::loadFromMatrix(const std::vector<std::vector<int>>& adjacencyMatrixInput)
{
    if (adjacencyMatrixInput.empty())
    {
        std::cout << "Ошибка: пустая матрица смежности.\n";
        return false;
    }

    int size = adjacencyMatrixInput.size();

    // Проверка квадратности матрицы
    for (const auto& row : adjacencyMatrixInput)
    {
        if (row.size() != size)
        {
            std::cout << "Ошибка: матрица должна быть квадратной.\n";
            return false;
        }
    }

    adjacencyMatrix = adjacencyMatrixInput;
    vertexCount = size;

    return true;
}

int Graph::getVertexCount() const
{
    return vertexCount;
}

std::vector<int> Graph::breadthFirstSearch(int startVertex) const
{
    std::vector<int> result;

    if (startVertex < 0 || startVertex >= vertexCount)
    {
        std::cout << "Ошибка: некорректная стартовая вершина.\n";
        return result;
    }

    std::vector<bool> visited(vertexCount, false);
    std::queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty())
    {
        int currentVertex = queue.front();
        queue.pop();

        //FIX_ME: не добавляем начальную вершину в результат, т.к. по условию задачи нужно вывести достижимые вершины
        //result.push_back(currentVertex);
        if (currentVertex != startVertex)
        {
            result.push_back(currentVertex);
        }

        // Сбор соседей
        std::vector<int> neighbors;

        for (int i = 0; i < vertexCount; ++i)
        {
            if (adjacencyMatrix[currentVertex][i] != 0 && !visited[i])
            {
                neighbors.push_back(i);
            }
        }

        // Сортировка соседей по возрастанию (условие задачи)
        std::sort(neighbors.begin(), neighbors.end());

        // Добавление в очередь
        for (int neighbor : neighbors)
        {
            visited[neighbor] = true;
            queue.push(neighbor);
        }
    }

    return result;
}