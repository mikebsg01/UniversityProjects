/*
 * ALGORITHM: Depth-First Search (DFS)
 *
 * @author Michael Serrato <mikebsg01@gmail.com>
 */
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <deque>
#include <map>
#define debug(x) cout << #x << ": " << x << endl
#define MAXE 26
#define INF -1
using namespace std;

int V, E;
vector<int> AdjacencyList[MAXE];
map<char, int> VertexIndexes;
char Vertex[MAXE];
bool visited[MAXE];
deque<int> currentPath;
vector<deque<int> > allPaths;
int numOfPaths;
int iterations;

void printAdjacencyList(vector<int> A[]);
void printAdjacencyMatrix(vector<int> A[]);
void dfs(int s, int t, int level, vector<int> A[]);

int main() {
    int i, idx;
    char tempX, tempY;
    map<char, int>::iterator it;
    vector<char> X, Y;

    cout << "Cantidad de nodos: ";
    cin >> V;

    cout << "Cantidad de aristas: ";
    cin >> E;
    cout << "\n";

    for (i = 0; i < E; ++i) {
        cout << "Ingresar arista #" << (i + 1) << ": ";
        cin >> tempX >> tempY;

        X.push_back(tempX);
        Y.push_back(tempY);

        if (!VertexIndexes.count(tempX)) {
            VertexIndexes[tempX] = 1;
        }
        if (!VertexIndexes.count(tempY)) {
            VertexIndexes[tempY] = 1;
        }
    }

    for(it = VertexIndexes.begin(), idx = 0; it != VertexIndexes.end(); ++it, ++idx) {
        Vertex[idx] = it->first;
        it->second = idx;
    }

    for (i = 0; i < E; ++i) {
        AdjacencyList[VertexIndexes[X[i]]].push_back(VertexIndexes[Y[i]]);
        AdjacencyList[VertexIndexes[Y[i]]].push_back(VertexIndexes[X[i]]);
    }

    printAdjacencyMatrix(AdjacencyList);

    cout << "Obtener todas las rutas entre vertices: ";
    cin >> tempX >> tempY;
    cout << "\n";

    dfs(VertexIndexes[tempX], VertexIndexes[tempY], 0, AdjacencyList);

    cout << "Rutas encontradas:\n";

    for (i = 0; i < allPaths.size(); ++i) {
        while (!allPaths[i].empty()) {
            cout << Vertex[allPaths[i].front()] << " ";
            allPaths[i].pop_front();
        }
        cout << "\n";
    }
    cout << "Total de rutas posibles: " << allPaths.size() << "\n";
    debug(iterations);
    return 0;
}

void printAdjacencyList(vector<int> A[]) {
    cout << "\nLista de Adyacencia:\n";

    for (int i = 0; i < V; ++i) {
        cout << Vertex[i] << " | ";

        for (int j = 0; j < A[i].size(); ++j) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printAdjacencyMatrix(vector<int> A[]) {
    int i, j;

    cout << "\nMatriz de adyacencia:\n    ";

    for (j = 0; j < V; ++j) {
        cout << Vertex[j] << " ";
    }

    cout << "\n   ";

    for (j = 0; j < V; ++j) {
        cout << "--";
    }

    cout << "\n";

    for (i = 0; i < V; ++i) {
        cout << Vertex[i] << " | ";

        for (j = 0; j < V; ++j) {
            if (find(A[i].begin(), A[i].end(), j) != A[i].end()) {
                cout << "1 ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void dfs(int s, int t, int level, vector<int> A[]) {
    ++iterations;

    cout << "Variable actual: " << Vertex[s] 
         << "\tNivel de profundidad: " << level;

    if (s == t and currentPath.size() > 0) {
        deque<int> temp = deque<int>(currentPath);

        allPaths.push_back(currentPath);
        cout << "\t\tRuta: ";

        while (!temp.empty()) {
            cout << Vertex[temp.front()] << " ";
            temp.pop_front();
        }
        cout << "\n";
        ++numOfPaths;
        return;
    } else if (!level) {
        cout << "\n";
        visited[s] = true;
        currentPath.push_back(s);
        dfs(s, t, level + 1, A);
        currentPath.pop_back();
        visited[s] = false;
        cout << "\n";
    } else {
        cout << "\n";
        for (int i = 0; i < A[s].size(); ++i) {
            ++iterations;
            if (!visited[A[s][i]]) {
                visited[A[s][i]] = true;
                currentPath.push_back(A[s][i]);
                dfs(A[s][i], t, level + 1, A);
                currentPath.pop_back();
                visited[A[s][i]] = false;
            }
        }
    }
}