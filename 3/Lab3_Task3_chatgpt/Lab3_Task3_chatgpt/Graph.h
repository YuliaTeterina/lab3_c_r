#pragma once

#include <vector>
#include <string>

/**
 * Класс ориентированного графа.
 * Хранит матрицу смежности и реализует обход в ширину (BFS).
 */
class Graph
{
public:
    Graph();

    /**
     * Загрузка графа из матрицы смежности
     */
    //FIX_ME: название методов должно быть lowercase
    //bool LoadFromMatrix(const std::vector<std::vector<int>>& adjacencyMatrix);
    bool loadFromMatrix(const std::vector<std::vector<int>>& adjacencyMatrix);


    /**
     * Поиск в ширину (BFS)
     * @param startVertex - стартовая вершина (0-based)
     * @return список достижимых вершин в порядке обхода
     */
     //FIX_ME: название методов должно быть lowercase
    //std::vector<int> BreadthFirstSearch(int startVertex) const;
    std::vector<int> breadthFirstSearch(int startVertex) const;

    //FIX_ME: название методов должно быть lowercase
    //int GetVertexCount() const;
    int getVertexCount() const;

private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int vertexCount;
};