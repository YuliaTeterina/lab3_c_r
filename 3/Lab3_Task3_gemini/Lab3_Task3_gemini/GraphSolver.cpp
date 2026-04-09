#include "GraphSolver.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>

FGraphSolver::FGraphSolver()
    : vertexCount(0)
{
}

FGraphSolver::~FGraphSolver()
{
}

void FGraphSolver::reset()
{
    vertexCount = 0;
    adjacencyMatrix.clear();
}

bool FGraphSolver::loadFromFile(const std::string& fileName)
{
    std::ifstream fileStream(fileName);
    if (!fileStream.is_open())
    {
        return false;
    }

    reset();

    // Читаем количество вершин
    if (!(fileStream >> vertexCount) || vertexCount <= 0)
    {
        return false;
    }

    // Инициализируем матрицу
    adjacencyMatrix.resize(vertexCount, std::vector<int32_t>(vertexCount));

    // Читаем матрицу смежности
    for (int32_t i = 0; i < vertexCount; ++i)
    {
        for (int32_t j = 0; j < vertexCount; ++j)
        {
            if (!(fileStream >> adjacencyMatrix[i][j]))
            {
                reset();
                return false;
            }
        }
    }

    return true;
}

std::vector<int32_t> FGraphSolver::performBFS(int32_t startVertex) const
{
    // Если вершина вне диапазона, возвращаем пустой результат
    if (startVertex < 0 || startVertex >= vertexCount)
    {
        return {};
    }

    std::vector<int32_t> result;
    std::vector<bool> visited(vertexCount, false);
    std::queue<int32_t> traversalQueue;

    // Инициализация начала обхода
    visited[startVertex] = true;
    traversalQueue.push(startVertex);

    while (!traversalQueue.empty())
    {
        int32_t currentVertex = traversalQueue.front();
        traversalQueue.pop();

		//FIX_ME: не добавляем начальную вершину в результат, т.к. по условию задачи нужно вывести достижимые вершины
        //result.push_back(currentVertex);

        if (currentVertex != startVertex)
        {
            result.push_back(currentVertex);
        }

        /*
         * Проходим по всем возможным соседям текущей вершины.
         * Т.к. цикл идет от 0 до vertexCount, вершины добавляются
         * в очередь строго в порядке возрастания их номеров,
         * что удовлетворяет условию задачи.
         */
        for (int32_t neighbor = 0; neighbor < vertexCount; ++neighbor)
        {
            // Если m[i][j] != 0, значит дуга существует
            if (adjacencyMatrix[currentVertex][neighbor] != 0 && !visited[neighbor])
            {
                visited[neighbor] = true;
                traversalQueue.push(neighbor);
            }
        }
    }

    return result;
}

int32_t FGraphSolver::getVertexCount() const
{
    return vertexCount;
}