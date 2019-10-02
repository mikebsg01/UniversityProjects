/*
 * DATA STRUCTURE: AVL Tree
 *
 * @author Serrato Guerrero Michael Brandon <mikebsg01@gmail.com>
 */
#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#define debug(x) cout << #x << ": " << x << "\n"
using namespace std;

class AVLTree {
private:
    class AVLTreeNode {
    public:
        static const int INF = INT_MAX;
        static const int EMPTY = -1;

        int value,
            leftChildPos,
            rightChildPos;
        
        AVLTreeNode(int value = INF, int leftChildPos = EMPTY, int rightChildPos = EMPTY) :
            value(value), leftChildPos(leftChildPos), rightChildPos(rightChildPos) {}
    };

    vector<AVLTreeNode>* v;
    int rootPos;

    int getRootPos() const;
    int rightRotation(const int nodePos);
    int getHeight(int nodePos) const;
    int balanceFactor(int nodePos) const;
    int balance(int nodePos);
    int insert(int nodePos, const int element);
    string readInInorder(int nodePos, int levelCount) const;

public:
    AVLTree();
    int size() const;
    bool empty() const;
    int getHeight() const;
    int balanceFactor() const;
    void insert(const int element);
    string readInInorder() const;
    string toString() const;
};

int main() {
    AVLTree avlTree;
    int N, x, i;

    cout << "Cantidad de elementos (N): ";
    cin >> N;
    cout << "\n";

    for (i = 0; i < N; ++i) {
        cout << "Insertar elemento #" << (i + 1) << ": ";
        cin >> x;
        avlTree.insert(x);
        cout << "\nEstado actual del Arbol AVL:\n"
             << avlTree.readInInorder() << "\n"
             << "Altura: " << avlTree.getHeight() << "\n\n";
        debug(avlTree.toString());
    }
    return 0;
}

int AVLTree::getRootPos() const {
    return this->rootPos;
}

int AVLTree::rightRotation(const int nodePos) {
    int tempPos = this->v->at(nodePos).leftChildPos;
    this->v->at(nodePos).leftChildPos = this->v->at(tempPos).rightChildPos;
    this->v->at(tempPos).rightChildPos = nodePos;
    return tempPos;
}

int AVLTree::getHeight(int nodePos) const {
    if (nodePos >= this->size() or nodePos <= AVLTreeNode::EMPTY) {
        return 0;
    }

    return 1 + max(this->getHeight(this->v->at(nodePos).leftChildPos),
                   this->getHeight(this->v->at(nodePos).rightChildPos));
}

int AVLTree::balanceFactor(int nodePos) const {
    int leftChildHeight = getHeight(this->v->at(nodePos).leftChildPos),
        rightChildHeight = getHeight(this->v->at(nodePos).rightChildPos);

    return leftChildHeight - rightChildHeight;
}

int AVLTree::balance(int nodePos) {
    int balanceFactor = this->balanceFactor(nodePos);
    
    if (balanceFactor > 1) {
        if (this->balanceFactor(this->v->at(nodePos).leftChildPos) > 0) {
            nodePos = rightRotation(nodePos);
        }
    }
    return nodePos;
}

int AVLTree::insert(int nodePos, const int element) {
    debug(nodePos);
    if (this->empty() or nodePos == AVLTreeNode::EMPTY) {
        AVLTreeNode* temp = new AVLTreeNode(element);

        this->v->push_back(*temp);
        return this->size() - 1;
    }

    if (element < this->v->at(nodePos).value) {
        int newPos = this->insert(this->v->at(nodePos).leftChildPos, element);
        this->v->at(nodePos).leftChildPos = newPos;
        nodePos = this->balance(nodePos);
    } else {
        int newPos = this->insert(this->v->at(nodePos).rightChildPos, element);
        this->v->at(nodePos).rightChildPos = newPos;
        nodePos = this->balance(nodePos);
    }
    return nodePos;
}

string AVLTree::readInInorder(int nodePos, int levelCount) const {
    ostringstream oss;

    if (nodePos >= this->size() or nodePos <= AVLTreeNode::EMPTY) {
        return oss.str();
    }

    oss << this->readInInorder(this->v->at(nodePos).rightChildPos, levelCount + 1);

    for (int i = 0; i < levelCount; ++i) {
        oss << "\t";
    }
    oss << this->v->at(nodePos).value << "\n";

    oss << this->readInInorder(this->v->at(nodePos).leftChildPos, levelCount + 1);
    
    return oss.str();
}

AVLTree::AVLTree() {
    this->v = new vector<AVLTreeNode>();
    this->rootPos = AVLTreeNode::EMPTY;
}

int AVLTree::size() const {
    return this->v->size();
}

bool AVLTree::empty() const {
    return this->v->empty();
}

int AVLTree::getHeight() const {
    return this->getHeight(this->getRootPos());
}

int AVLTree::balanceFactor() const {
    return this->balanceFactor(this->getRootPos());
}

void AVLTree::insert(const int element) {
   this->rootPos = this->insert(this->getRootPos(), element);
    debug(this->rootPos);
}

string AVLTree::readInInorder() const {
    return this->readInInorder(this->getRootPos(), 0);
}

string AVLTree::toString() const {
    ostringstream oss;
    int n = this->size();

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0) {
                oss << " ";
            }

            if (!i) {
                oss << this->v->at(j).value;
            } else if (i == 1) {
                oss << this->v->at(j).leftChildPos;
            } else {
                oss << this->v->at(j).rightChildPos;
            }
        }
        
        if (n > 0) {
            oss << "\n";
        }
    }

    return oss.str();
}