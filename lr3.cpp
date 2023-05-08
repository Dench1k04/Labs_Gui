#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k; // Количество вершин
    vector<int> winner(m);
    for (int i = 0; i < m; i++) // Нужные нам вершины
    {
        cin >> winner[i];
        winner[i]--; // Сдвиг индекса, так как у нас отсчёт в задаче начинается с 1, а в коде с нуля
    }
    vector<vector<int>> path(n, vector<int>(n, 1e6)); // Матрица смежности (1е6 значит, что ребра нет)
    for (int i = 0; i < k; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        a--; //Свдиг индекса
        b--;
        if (path[a][b] > t)
        {
            path[a][b] = t;
            path[b][a] = t;
        }
    }
    int start; // Вершина, в которой мы находимся
    cin >> start;
    start--; // Сдвиг индекса
    vector<int> count(n, 1e6); // Счётчик пути до вершин
    vector<bool> used(n, false); // Посещена ли вершина
    count[start] = 0;
    while (start != -1) // Алгоритм Дейкстры
    {
        int next = -1, mini = 1e6;
        for (int j = 0; j < n; j++)
        {
            if (count[j] > count[start] + path[start][j]) // Обновляем расстояние до смежных вершин
            {
                count[j] = count[start] + path[start][j];
            }
            if (count[j] < mini && !used[j]) // Ищем непосещённую вершину с минимальным расстоянием
            {
                next = j;
                mini = count[j];
            }
        }
        used[start] = true; // Отмечаем, что данную вершину мы посетили
        start = next; // Переходим в следующую вершину
    }
    bool deliver = true; // Предположим, что посетили все вершины
    int longest = 0; // Ставим значение, равное минимальному возможному расстоянию
    for (int i = 0; i < m && deliver; i++)
    {
        if (!used[winner[i]]) // Проверяем всем ли победителям доставили призы
        {
            deliver = false;
        }
        longest = max(count[winner[i]], longest); // Ищем максимальную дистанцию
    }
    if (deliver) // Если доставили призы всем
    {
        cout << "The good sponsor!\n" << longest;
    }
    else // Иначе
    {
        cout << "It is not fault of sponsor...";
    }
 
    return 0;
}