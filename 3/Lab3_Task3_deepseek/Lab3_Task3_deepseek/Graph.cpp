#include "Graph.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <queue>
#include <algorithm>
#include <iostream>

bool Graph::loadFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл '" << fileName << "'." << std::endl;
        return false;
    }

    // Чтение количества вершин
    std::size_t n = 0;
    file >> n;
    if (file.fail() || n == 0)
    {
        std::cerr << "Ошибка: первая строка файла должна содержать положительное целое число (количество вершин)." << std::endl;
        return false;
    }

    adjacencyMatrix.clear();
    adjacencyMatrix.reserve(n);

    // Чтение матрицы смежности
    for (std::size_t i = 0; i < n; ++i)
    {
        std::vector<int> row;
        row.reserve(n);
        for (std::size_t j = 0; j < n; ++j)
        {
            int value = 0;
            file >> value;
            if (file.fail())
            {
                std::cerr << "Ошибка: недостаточно данных в строке " << i + 1 << " матрицы." << std::endl;
                return false;
            }
            row.push_back(value);
        }
        adjacencyMatrix.push_back(std::move(row));
    }

    // Проверяем, что прочитали ровно n строк
    if (adjacencyMatrix.size() != n)
    {
        std::cerr << "Ошибка: количество строк матрицы не соответствует указанному n." << std::endl;
        return false;
    }

    return true;
}

std::vector<int> Graph::bfs(int startVertex) const
{
    if (adjacencyMatrix.empty())
    {
        std::cerr << "Ошибка: граф не загружен." << std::endl;
        return {};
    }

    std::size_t startIdx = toIndex(startVertex);

    std::vector<bool> visited(adjacencyMatrix.size(), false);
    std::queue<std::size_t> queue;
    std::vector<int> result; // храним 1‑индексированные номера вершин

    visited[startIdx] = true;
    queue.push(startIdx);

    //FIX_ME: не добавляем начальную вершину в результат, т.к. по условию задачи нужно вывести достижимые вершины
    //result.push_back(startVertex);

    while (!queue.empty())
    {
        std::size_t current = queue.front();
        queue.pop();

        // Собираем всех соседей (вершины, в которые есть дуга)
        std::vector<std::size_t> neighbors;
        for (std::size_t j = 0; j < adjacencyMatrix.size(); ++j)
        {
            if (adjacencyMatrix[current][j] != 0 && !visited[j])
            {
                neighbors.push_back(j);
            }
        }

        // Сортируем соседей по возрастанию номера вершины (1-база)
        std::sort(neighbors.begin(), neighbors.end(),
            [](std::size_t a, std::size_t b) { return a < b; });

        // Добавляем отсортированных соседей в очередь и результат
        for (std::size_t neighbor : neighbors)
        {
            visited[neighbor] = true;
            queue.push(neighbor);
            result.push_back(static_cast<int>(neighbor) + 1); // переводим в 1-индексацию
        }
    }

    return result;
}

bool Graph::hasEdge(int u, int v) const
{
    std::size_t i = toIndex(u);
    std::size_t j = toIndex(v);
    return adjacencyMatrix[i][j] != 0;
}

std::size_t Graph::toIndex(int vertex) const
{
    if (vertex < 1 || static_cast<std::size_t>(vertex) > adjacencyMatrix.size())
    {
        throw std::out_of_range("Номер вершины вне допустимого диапазона (1.." +
            std::to_string(adjacencyMatrix.size()) + ").");
    }
    return static_cast<std::size_t>(vertex - 1);
}