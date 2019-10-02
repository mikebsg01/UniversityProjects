/*
 * ALGORITHM: Dijkstra
 *
 * @author Michael Serrato <mikebsg01@gmail.com>
 */
 #include <iostream>
 #include <algorithm>
 #include <climits>
 #include <vector>
 #include <map>
 #include <set>
 #define PB push_back
 #define MP make_pair
 #define X first
 #define Y second
 #define REP(i, x, y) for (i = x; i != y; ++i)
 #define MAXE 26
 #define INF INT_MAX
 using namespace std;
 typedef pair<int, int> Pair;
 
 int V, E;
 map<char, int> VertexIndexes;
 char Vertex[MAXE];
 vector<Pair> AdjacencyList[MAXE];
 int parent[MAXE];
 
 void printAdjacencyList(vector<Pair> A[]);
 int find(vector<Pair>& A, int index);
 void printAdjacencyMatrix(vector<Pair> A[]);
 void printMinimumCostPath(int parent, int index);
 int dijkstra(vector<Pair> A[], int n, int s, int t, int parent[]);
 
 int main() {
     int tempWeight, idx, i;
     char tempA, tempB;
     vector<char> A, B;
     vector<int> W;
     map<char, int>::iterator it;
 
     cout << "Cantidad de nodos: ";
     cin >> V;
 
     cout << "Cantidad de aristas: ";
     cin >> E;
     cout << "\n";
 
     REP(i, 0, E) {
         cout << "Ingresar arista #" << (i + 1) << ": ";
         cin >> tempA >> tempB >> tempWeight;
         
         A.PB(tempA);
         B.PB(tempB);
         W.PB(tempWeight);
 
         if (!VertexIndexes.count(tempA)) {
             VertexIndexes[tempA] = 1;
         }
 
         if (!VertexIndexes.count(tempB)) {
             VertexIndexes[tempB] = 1;
         }
     }
 
     idx = 0;
     REP(it, VertexIndexes.begin(), VertexIndexes.end()) {
         Vertex[idx] = it->first;
         it->second = idx++;
     }
 
     REP(i, 0, E) {
         AdjacencyList[VertexIndexes[A[i]]].PB(MP(W[i], VertexIndexes[B[i]]));
         AdjacencyList[VertexIndexes[B[i]]].PB(MP(W[i], VertexIndexes[A[i]]));
         printAdjacencyList(AdjacencyList);
     }
 
     printAdjacencyMatrix(AdjacencyList);
 
     cout << "Obtener todas las rutas entre vertices: ";
     cin >> tempA >> tempB;
     cout << "\n";
 
     cout << "\nCosto minimo: " << dijkstra(AdjacencyList, V, VertexIndexes[tempA], VertexIndexes[tempB], parent) << "\n";
     return 0;
 }
 
 void printAdjacencyList(vector<Pair> A[]) {
     cout << "\nLista de Adyacencia:\n";
 
     for (int i = 0; i < V; ++i) {
         cout << Vertex[i] << " | ";
 
         for (int j = 0; j < A[i].size(); ++j) {
             cout << "(" << Vertex[A[i][j].Y] << "," << A[i][j].X << ") ";
         }
         cout << "\n";
     }
     cout << "\n";
 }
 
 int find(vector<Pair>& A, int index) {
     for (int i = 0; i < A.size(); ++i) {
         if (A[i].Y == index) {
             return i;
             break;
         }
     }
     return -1;
 }
 
 void printAdjacencyMatrix(vector<Pair> A[]) {
     int i, j, idx;
 
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
             idx = find(A[i], j);
 
             if (idx != -1) {
                 cout << A[i][idx].X << " ";
             } else {
                 cout << ". ";
             }
         }
         cout << "\n";
     }
     cout << "\n";
 }
 
 void printMinimumCostPath(int parent[], int index) {
     if (parent[index] == -1) {
         cout << Vertex[index];
         return;
     }
 
     printMinimumCostPath(parent, parent[index]);
     cout << " -> " << Vertex[index];
 }
 
 int dijkstra(vector<Pair> A[], int n, int s, int t, int parent[]) {
     set<Pair> heap;
     vector<int> dist(n, INF); // costs
 
     parent[s] = -1;
     dist[s] = 0;
     heap.insert(MP(0, s));
 
     while (!heap.empty()) {
         Pair currentState = *heap.begin();
         heap.erase(heap.begin());
 
         cout << "Variable actual: " << Vertex[currentState.Y] << "\n";
 
         if (currentState.Y == t) {
             cout << "\nRuta de costo minimo:\n";
             printMinimumCostPath(parent, t);
             cout << "\n";
             return currentState.X;
             break;
         }
 
         for (int i = 0; i < A[currentState.Y].size(); ++i) {
             // temp = (cost until adjacency node, adjacency node)
             Pair temp(currentState.X + A[currentState.Y][i].X, A[currentState.Y][i].Y);
 
             if (temp.X < dist[temp.Y]) {
                 parent[temp.Y] = currentState.Y; // minimum cost path update
                 heap.erase(MP(dist[temp.Y], temp.Y)); // delete previus state
                 dist[temp.Y] = temp.X; // cost update until the new node
                 heap.insert(temp); // save new state
             }
         }
     }
     
     /*
      * ------------------------------------------------------ //
      * Delete the statement "break" and "return" of 
      * the "while" and uncomment this block for print all 
      * the minimum cost paths for all the nodes from the 
      * source node.
      * ------------------------------------------------------ //
      *
      *  for (int i = 0; i < V; ++i) {
      *     printMinimumCostPath(parent, i);
      *     cout << "\n";
      *  }
      *
      * ------------------------------------------------------ //
      */
     return -1;
 }