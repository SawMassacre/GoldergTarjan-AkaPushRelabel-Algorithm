#include <bits/stdc++.h>

using namespace std;
//надо расставить (1)* метки согласно статье для удобства
// структура вершины
struct Vertex {
    int h, exc_flow;
    Vertex(int h, int e_flow) {
        this->h = h;
        this->exc_flow = e_flow;
    }
};

struct Edge {
    // переменные хранят текущий поток и пропускную способность ребра
    int flow, capacity;
    // ребро вида (uv) имеет вершину u явл. началом и вершину v явл. концом
    int u, v;
    // реализация ребра
    Edge(int flow, int capacity, int u, int v) {
        this->flow = flow;
        this->capacity = capacity;
        this->u = u;
        this->v = v;
    }
};

// класс отвечающий за потоковую систему
class Graph {
    int V; // количество вершин в графе
    vector <Vertex> ver;
    vector <Edge> edge;
    // функция проталкивания излишнего (блокирующего) потока из вершины
    bool push(int u);
    // функция маркирующая вершину u
    void relabel(int u);
    // функция отвечающая за предпоток
    void preflow(int s);
    // функция для обратных ребер
    void updateReverseEdgeFlow(int i, int flow);

public:
    Graph(int V);  // функции конструкции графов
    // функция добавления ребра в граф
    void addEdge(int u, int v, int w);
    //refresh
    void refresh();
    // максимальная проходимость (главная функция)
    //void newAmountOfV();
    int getMaxFlow(int s, int t);
};

Graph::Graph(int V) {
    this -> V = V;
    // уровень всех вершин становится нулевым,
    // переполнение всех вершин становится нулевым
    for (int i = 0; i < V; i++)
        ver.push_back(Vertex(0, 0));
}

void Graph::addEdge(int u, int v, int capacity) {
    // текущий поток становится нулевым для всех ребер
    edge.push_back(Edge(0, capacity, u, v));
}

void Graph::refresh() {
    //чистка векторов
    edge.clear();
    ver.clear();
}

void Graph::preflow(int s) {
    // приравнивание высоты истока количеству вершин
    // уровень остальных вершин нулевой
    ver[s].h = ver.size();
    // перебор ребер (ха ха)
    for (int i = 0; i < edge.size(); i++) {
        // если рассматриваемое ребро выходит из истока
        if (edge[i].u == s) {
            // если поток равен пропускной способности
            edge[i].flow = edge[i].capacity;
            // смежной вершине v добавляется переполняющий поток
            ver[edge[i].v].exc_flow += edge[i].flow;
            // добавление ребра из v в s в остаточном графе
            // с пропускной способностью равной нулю
            edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, s));
        }
    }
}

// функция возвращает индекс переполненной вершины
int overFlowVertex(vector<Vertex>& ver) {
    for (int i = 1; i < ver.size() - 1; i++)
        if (ver[i].exc_flow > 0)
            return i;
    // возвращает -1 если не найдена переполненная вершина
    return -1;
}

// обратный поток для потока на ребре
void Graph::updateReverseEdgeFlow(int i, int flow) {
    int u = edge[i].v, v = edge[i].u;
    for (int j = 0; j < edge.size(); j++) {
        if (edge[j].v == v && edge[j].u == u) {
            edge[j].flow -= flow;
            return;
        }
    }
    // добавление обратных ребер в остаточную сеть
    Edge e = Edge(0, flow, u, v);
    edge.push_back(e);
}

// проталкивание потока из переполненной вершины u
bool Graph::push(int u) {
    // проходка через все ребра для нахождения
    // смежного ребра в которое можно протолкнуть поток
    for (int i = 0; i < edge.size(); i++) {
        // проверка является ли индекс текущего ребра
        // таким же как индекс переполненной вершины
        if (edge[i].u == u) {
            // если поток равен максимальному потоку тогда запушить неудастся
            if (edge[i].flow == edge[i].capacity)
                continue;
            // протолкнуть можно только тогда, когда уровень смежной
            // вершины меньше чем уровень переполненной
            if (ver[u].h > ver[edge[i].v].h) {
                // проталкивание потока равного минимуму доступного
                // потока на ребре и блокирующего потока
                int flow = min(edge[i].capacity - edge[i].flow,
                               ver[u].exc_flow);
                // убрать блокирующий поток из переполненной вершины
                ver[u].exc_flow -= flow;
                // прибавление блокирующих поток смежным вершинам
                ver[edge[i].v].exc_flow += flow;
                // добавление остаточного потока (на ост. графе с нулевой
                // пропускной и отрицательным потоком)
                edge[i].flow += flow;
                updateReverseEdgeFlow(i, flow);
                return true;
            }
        }
    }
    return false;
}

// маркировка вершины
void Graph::relabel(int u)
{
    //временная переменная для хранения минимальной высоты смежных ребер
    int minHeight = INT_MAX;
    //найти смежное ребро с минмальной пропускной способностью
    for (int i = 0; i < edge.size(); i++) {
        if (edge[i].u == u) {
            // если ребро является насыщенным то оставляем
            if (edge[i].flow == edge[i].capacity)
                continue;
            // изменение минимальной глубины
            if (ver[edge[i].v].h < minHeight) {
                minHeight = ver[edge[i].v].h;
                // изменение глубины вершины u
                ver[u].h = minHeight + 1;
            }
        }
    }
}

// основная функция для вывода максимального проходимости графа
int Graph::getMaxFlow(int s, int t) {
    preflow(s);
    // цикл отвечающий за проталкивание переполненных вершин на всем графе
    while (overFlowVertex(ver) != -1) {
        int u = overFlowVertex(ver);
        if (!push(u))
            relabel(u);
    }
    // ver.back() возвращает последнюю вершину чей избыточный
    // (блокирующий) поток будет являться максимальным потоком для пути
    return ver.back().exc_flow;
}

int refreshVectors() {

}

int runTests(int testNum) {
    int c;
    vector <int> ans = {5, 6, 15, 14, 120};
    c = testNum;
    string message = "correct!";
    int V, s, t, receivedAns;
    switch (c) {
        case 0: {
            V = 6;
            Graph g(V);
            s = 0, t = 5;
            g.addEdge(0, 1, 3);
            g.addEdge(0, 2, 3);
            g.addEdge(1, 2, 2);
            g.addEdge(1, 3, 3);
            g.addEdge(2, 4, 2);
            g.addEdge(3, 4, 4);
            g.addEdge(3, 5, 2);
            g.addEdge(4, 5, 3);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
            << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
        case 1: {
            V = 7;
            Graph g(V);
            s = 0, t = 6;
            g.addEdge(0, 1, 3);
            g.addEdge(0, 2, 15);
            g.addEdge(1, 3, 8);
            g.addEdge(3, 2, 9);
            g.addEdge(3, 4, 8);
            g.addEdge(2, 4, 11);
            g.addEdge(4, 5, 3);
            g.addEdge(5, 6, 7);
            g.addEdge(3, 6, 10);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
                 << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
        case 2: {
            V = 4;
            Graph g(V);
            s = 0, t = 3;
            g.addEdge(0, 1, 10);
            g.addEdge(0, 2, 5);
            g.addEdge(1, 2, 15);
            g.addEdge(1, 3, 5);
            g.addEdge(2, 3, 10);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
                 << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
        case 3: {
            V = 7;
            Graph g(V);
            s = 0, t = 6;
            g.addEdge(0, 1, 4);
            g.addEdge(0, 2, 6);
            g.addEdge(0, 3, 5);
            g.addEdge(1, 2, 1);
            g.addEdge(2, 1, 1);
            g.addEdge(2, 3, 2);
            g.addEdge(3, 2, 2);
            g.addEdge(3, 5, 5);
            g.addEdge(2, 5, 4);
            g.addEdge(2, 4, 5);
            g.addEdge(1, 4, 7);
            g.addEdge(4, 5, 1);
            g.addEdge(5, 4, 1);
            g.addEdge(4, 6, 6);
            g.addEdge(5, 6, 8);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
                 << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
        case 4: {
            V = 6;
            Graph g(V);
            s = 0, t = 5;
            g.addEdge(0, 1, 90);
            g.addEdge(0, 3, 110);
            g.addEdge(1, 2, 60);
            g.addEdge(3, 1, 10);
            g.addEdge(1, 4, 30);
            g.addEdge(3, 4, 30);
            g.addEdge(2, 4, 40);
            g.addEdge(2, 5, 50);
            g.addEdge(4, 5, 100);
            receivedAns = g.getMaxFlow(s, t);
            if (ans[c] == receivedAns)
                message = "correct!";
            else
                message = "incorrect!";
            cout << "expected answer: " << ans[c] << " received answer: "
                 << receivedAns << " " << message << "\n";
            g.refresh();
            break;
        }
    }
}

int main() {
    int testQuantity = 5;
    for (int j = 0; j < testQuantity; j++) {
        runTests(j);
    }
}