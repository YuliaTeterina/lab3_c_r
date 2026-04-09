#pragma once

#include <vector>
#include <string>
#include <cstdint>

/**
 * Класс FGraphSolver предназначен для обработки ориентированного графа.
 * Включает методы загрузки матрицы смежности из файла и поиска в ширину.
 */
class FGraphSolver
{
public:
    FGraphSolver();
    ~FGraphSolver();

    /**
     * Загружает данные графа из текстового файла.
     * @param fileName - путь к файлу.
     * @return true, если файл успешно прочитан и данные валидны.
     */
    bool loadFromFile(const std::string& fileName);

    /**
     * Выполняет поиск в ширину (BFS) от заданной вершины.
     * @param startVertex - индекс начальной вершины (0...n-1).
     * @return Вектор с номерами вершин в порядке их обхода.
     */
    std::vector<int32_t> performBFS(int32_t startVertex) const;

    /** Возвращает количество вершин в графе. */
    int32_t getVertexCount() const;

private:
    int32_t vertexCount;
    // Матрица смежности: m[i][j] > 0 означает наличие дуги с весом.
    std::vector<std::vector<int32_t>> adjacencyMatrix;

    /** Сбрасывает состояние объекта. */
    void reset();
};