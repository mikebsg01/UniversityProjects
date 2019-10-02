/*
 * ALGORITHM: MAX-HEAP SORT
 *
 * @author Serrato Guerrero Michael Brandon <mikebsg01@gmail.com>
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class MaxHeap {
private:
    vector<int>* v;
public:
    MaxHeap();
    int size() const;
    bool empty() const;
    void push(const int element);
    int top() const;
    int pop();
    vector<int>& getCurrentList() const;
    string toString() const;
};

void printVector(vector<int>& vector);

int main() {
    MaxHeap maxHeap;
    vector<int> list;
    int N, element, i;

    cout << "\n\tALGORITHM: MAX-HEAP SORT - By: Michael Serrato\n\n"
         << "Cantidad de elementos (N): ";
    cin >> N;
    cout << "\n";
    
    for (i = 0; i < N; ++i) {
        cout << "Ingrese el elemento #" << (i + 1) << ": ";
        cin >> element;
        list.push_back(element);
    }

    cout << "\n\tLISTA DESORDENADA:\n\t";
    printVector(list);

    cout << "\n\t========== AGREGANDO VALORES AL MONTICULO ==========\n";
    for (i = 0; i < N; ++i) {
        maxHeap.push(list[i]);
        cout << "\n\tValor agregado: " << list[i] << "\n"
             << "\tEstado actual del monticulo:\n\t" 
             << maxHeap.toString() << "\n";
    }
    
    int v;
    i = 0;

    cout << "\n\t========== ELIMINANDO EL VALOR MAXIMO EN EL MONTICULO ==========\n";
    while (!maxHeap.empty()) {
        cout << "\n\tRemover nodo maximo #" << ++i
             << "\n\tValor: " << (v = maxHeap.pop()) << "\n"
             << "\tEstado actual del monticulo:\n\t";
        list[N - i] = v;
        cout << maxHeap.toString() << "\n";
    }

    cout << "\n\tLISTA ORDENADA:\n\t";
    printVector(list);
    return 0;
}

MaxHeap::MaxHeap() {
    this->v = new vector<int>();
}

int MaxHeap::size() const {
    return this->v->size();
}

bool MaxHeap::empty() const {
    return this->v->empty();
}

void MaxHeap::push(const int element) {
    int childPos = this->size(),
        parentPos;

    this->v->push_back(element);
    
    while (childPos > 0 and 
           this->v->at(parentPos = (childPos - 1) / 2) < this->v->at(childPos)) {
        iter_swap(this->v->begin() + parentPos, this->v->begin() + childPos);
        childPos = parentPos;
    }
}

int MaxHeap::top() const {
    return this->v->at(0);
}

int MaxHeap::pop() {
    int n = this->size() - 1,
        root = this->top(),
        parentPos = 0,
        childPos;

    this->v->at(parentPos) = this->v->at(n); // change root for the last child
    this->v->erase(this->v->begin() + n); // delete last child

    // while having at least one child
    while ((childPos = (2 * parentPos + 1)) < n) {
        // check right child
        if ((childPos + 1) < n and 
            this->v->at(childPos + 1) > this->v->at(childPos)) {
            ++childPos;
        }

        if (this->v->at(childPos) > this->v->at(parentPos)) {
            iter_swap(this->v->begin() + parentPos, this->v->begin() + childPos);
            parentPos = childPos;
        } else {
            break;
        }
    }
    return root;
}

vector<int>& MaxHeap::getCurrentList() const {
    return *new vector<int>(*this->v);
}

string MaxHeap::toString() const {
    ostringstream oss;
    int n = this->size();

    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            oss << " ";
        }
        oss << this->v->at(i);
    }
    return oss.str();
}

void printVector(vector<int>& vector) {
    int n = vector.size();

    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << vector[i];
    }
    cout << "\n";
}
/* --------------------------------------------------------------------------------------------------- //
                                CORRIDAS DE LOS CASOS TÍPICOS
------------------------------------------------------------------------------------------------------ // 

Cantidad de elementos (N): 6

Ingrese el elemento #1: 4
Ingrese el elemento #2: 3
Ingrese el elemento #3: 7
Ingrese el elemento #4: 1
Ingrese el elemento #5: 8
Ingrese el elemento #6: 5

        LISTA DESORDENADA:
        4 3 7 1 8 5

        ========== AGREGANDO VALORES AL MONTICULO ==========

        Valor agregado: 4
        Estado actual del monticulo:
        4

        Valor agregado: 3
        Estado actual del monticulo:
        4 3

        Valor agregado: 7
        Estado actual del monticulo:
        7 3 4

        Valor agregado: 1
        Estado actual del monticulo:
        7 3 4 1

        Valor agregado: 8
        Estado actual del monticulo:
        8 7 4 1 3

        Valor agregado: 5
        Estado actual del monticulo:
        8 7 5 1 3 4

        ========== ELIMINANDO EL VALOR MAXIMO EN EL MONTICULO ==========

        Remover nodo maximo #1
        Valor: 8
        Estado actual del monticulo:
        7 4 5 1 3

        Remover nodo maximo #2
        Valor: 7
        Estado actual del monticulo:
        5 4 3 1

        Remover nodo maximo #3
        Valor: 5
        Estado actual del monticulo:
        4 1 3

        Remover nodo maximo #4
        Valor: 4
        Estado actual del monticulo:
        3 1

        Remover nodo maximo #5
        Valor: 3
        Estado actual del monticulo:
        1

        Remover nodo maximo #6
        Valor: 1
        Estado actual del monticulo:


        LISTA ORDENADA:
        1 3 4 5 7 8

------------------------------------------------------------------------------------------------------

Cantidad de elementos (N): 10

Ingrese el elemento #1: 5
Ingrese el elemento #2: 8
Ingrese el elemento #3: 6
Ingrese el elemento #4: 1
Ingrese el elemento #5: 4
Ingrese el elemento #6: 7
Ingrese el elemento #7: 3
Ingrese el elemento #8: 9
Ingrese el elemento #9: 2
Ingrese el elemento #10: 0

        LISTA DESORDENADA:
        5 8 6 1 4 7 3 9 2 0

        ========== AGREGANDO VALORES AL MONTICULO ==========

        Valor agregado: 5
        Estado actual del monticulo:
        5

        Valor agregado: 8
        Estado actual del monticulo:
        8 5

        Valor agregado: 6
        Estado actual del monticulo:
        8 5 6

        Valor agregado: 1
        Estado actual del monticulo:
        8 5 6 1

        Valor agregado: 4
        Estado actual del monticulo:
        8 5 6 1 4

        Valor agregado: 7
        Estado actual del monticulo:
        8 5 7 1 4 6

        Valor agregado: 3
        Estado actual del monticulo:
        8 5 7 1 4 6 3

        Valor agregado: 9
        Estado actual del monticulo:
        9 8 7 5 4 6 3 1

        Valor agregado: 2
        Estado actual del monticulo:
        9 8 7 5 4 6 3 1 2

        Valor agregado: 0
        Estado actual del monticulo:
        9 8 7 5 4 6 3 1 2 0

        ========== ELIMINANDO EL VALOR MAXIMO EN EL MONTICULO ==========

        Remover nodo maximo #1
        Valor: 9
        Estado actual del monticulo:
        8 5 7 2 4 6 3 1 0

        Remover nodo maximo #2
        Valor: 8
        Estado actual del monticulo:
        7 5 6 2 4 0 3 1

        Remover nodo maximo #3
        Valor: 7
        Estado actual del monticulo:
        6 5 3 2 4 0 1

        Remover nodo maximo #4
        Valor: 6
        Estado actual del monticulo:
        5 4 3 2 1 0

        Remover nodo maximo #5
        Valor: 5
        Estado actual del monticulo:
        4 2 3 0 1

        Remover nodo maximo #6
        Valor: 4
        Estado actual del monticulo:
        3 2 1 0

        Remover nodo maximo #7
        Valor: 3
        Estado actual del monticulo:
        2 0 1

        Remover nodo maximo #8
        Valor: 2
        Estado actual del monticulo:
        1 0

        Remover nodo maximo #9
        Valor: 1
        Estado actual del monticulo:
        0

        Remover nodo maximo #10
        Valor: 0
        Estado actual del monticulo:


        LISTA ORDENADA:
        0 1 2 3 4 5 6 7 8 9

------------------------------------------------------------------------------------------------------

Cantidad de elementos (N): 9

Ingrese el elemento #1: 1
Ingrese el elemento #2: 2
Ingrese el elemento #3: 50
Ingrese el elemento #4: 3
Ingrese el elemento #5: 80
Ingrese el elemento #6: 51
Ingrese el elemento #7: 70
Ingrese el elemento #8: 4
Ingrese el elemento #9: -10

        LISTA DESORDENADA:
        1 2 50 3 80 51 70 4 -10

        ========== AGREGANDO VALORES AL MONTICULO ==========

        Valor agregado: 1
        Estado actual del monticulo:
        1

        Valor agregado: 2
        Estado actual del monticulo:
        2 1

        Valor agregado: 50
        Estado actual del monticulo:
        50 1 2

        Valor agregado: 3
        Estado actual del monticulo:
        50 3 2 1

        Valor agregado: 80
        Estado actual del monticulo:
        80 50 2 1 3

        Valor agregado: 51
        Estado actual del monticulo:
        80 50 51 1 3 2

        Valor agregado: 70
        Estado actual del monticulo:
        80 50 70 1 3 2 51

        Valor agregado: 4
        Estado actual del monticulo:
        80 50 70 4 3 2 51 1

        Valor agregado: -10
        Estado actual del monticulo:
        80 50 70 4 3 2 51 1 -10

        ========== ELIMINANDO EL VALOR MAXIMO EN EL MONTICULO ==========

        Remover nodo maximo #1
        Valor: 80
        Estado actual del monticulo:
        70 50 51 4 3 2 -10 1

        Remover nodo maximo #2
        Valor: 70
        Estado actual del monticulo:
        51 50 2 4 3 1 -10

        Remover nodo maximo #3
        Valor: 51
        Estado actual del monticulo:
        50 4 2 -10 3 1

        Remover nodo maximo #4
        Valor: 50
        Estado actual del monticulo:
        4 3 2 -10 1

        Remover nodo maximo #5
        Valor: 4
        Estado actual del monticulo:
        3 1 2 -10

        Remover nodo maximo #6
        Valor: 3
        Estado actual del monticulo:
        2 1 -10

        Remover nodo maximo #7
        Valor: 2
        Estado actual del monticulo:
        1 -10

        Remover nodo maximo #8
        Valor: 1
        Estado actual del monticulo:
        -10

        Remover nodo maximo #9
        Valor: -10
        Estado actual del monticulo:


        LISTA ORDENADA:
        -10 1 2 3 4 50 51 70 80

------------------------------------------------------------------------------------------------------ */