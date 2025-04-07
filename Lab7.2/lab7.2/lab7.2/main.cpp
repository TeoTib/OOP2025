#include <iostream>
using namespace std;

template <typename T>
class TreeNode {
public:
    T value;
    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(T val) : value(val), firstChild(nullptr), nextSibling(nullptr) {}
};

template <typename T>
class Tree {
private:
    TreeNode<T>* root;

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        delete_node(root);
    }

    // Add node
    TreeNode<T>* add_node(TreeNode<T>* parent, T value) {
        TreeNode<T>* newNode = new TreeNode<T>(value);
        if (parent == nullptr) {
            if (root) delete_node(root);
            root = newNode;
            return root;
        }

        if (parent->firstChild == nullptr) {
            parent->firstChild = newNode;
        }
        else {
            TreeNode<T>* current = parent->firstChild;
            while (current->nextSibling != nullptr) {
                current = current->nextSibling;
            }
            current->nextSibling = newNode;
        }
        return newNode;
    }

    // returneaza firstchild al lui parent sau nullptr daca nu exista parent
    TreeNode<T>* get_node(TreeNode<T>* parent) {
        if (parent == nullptr) return root;
        return parent->firstChild;
    }

    // sterge nodul si toti copiii
    void delete_node(TreeNode<T>* node) {
        if (node == nullptr) return;

        // daca stergem root-ul
        if (node == root) {
            deleteTree(root);
            root = nullptr;
            return;
        }

        // cautam parintele ca sa putem rupe legatura din lista de frati
        TreeNode<T>* parent = find_parent(root, node);
        if (parent != nullptr) {
            TreeNode<T>* child = parent->firstChild;
            TreeNode<T>* prev = nullptr;
            //child o sa fie nodul meu si prev nodul de dinainte
            while (child != nullptr && child != node) {
                prev = child;
                child = child->nextSibling;
            }

            if (child == node) {
                if (prev == nullptr)
                    parent->firstChild = node->nextSibling; // node era primul copil
                else
                    prev->nextSibling = node->nextSibling; //restabilim legatura fara nodul node (de la node-1 la node+1)
            }
        }
        //si apoi recursiv eliminam tot de la node in jos
        deleteTree(node);
    }
    void deleteTree(TreeNode<T>* node) {
        if (node == nullptr) return;

        TreeNode<T>* child = node->firstChild;
        //luam fiecare frate si il stergem recursiv
        while (child != nullptr) {
            TreeNode<T>* next = child->nextSibling;
            deleteTree(child);
            child = next;
        }

        delete node;
    }
    //vreau sa ajung de la current(root in general) la target, nodul copil
    TreeNode<T>* find_parent(TreeNode<T>* current, TreeNode<T>* target) {
        if (current == nullptr) return nullptr;

        TreeNode<T>* child = current->firstChild;
        while (child != nullptr) {
            if (child == target)
                return current;
            //recursiv, caut in firstchild nodul meu
            TreeNode<T>* res = find_parent(child, target);
            if (res != nullptr)
                return res;

            child = child->nextSibling;
        }
        return nullptr;
    }

    // Recursive find cu comparator pointer la o functie (int_cmp)
    TreeNode<T>* find(TreeNode<T>* node, const T& value, bool (*cmp)(const T&, const T&)) {
        if (node == nullptr) return nullptr;

        if (cmp(node->value, value)) return node;

        TreeNode<T>* child = node->firstChild;
        //pentru fiecare sibling, facem recursiv find
        while (child != nullptr) {
            TreeNode<T>* result = find(child, value, cmp);
            if (result) return result;
            child = child->nextSibling;
        }

        return nullptr;
    }

    // insereaza nodul la un index printre ceilalti copii
    TreeNode<T>* insert(TreeNode<T>* parent, T value, int index) {
        TreeNode<T>* newNode = new TreeNode<T>(value);
        if (parent == nullptr) {
            if (root) delete_node(root);
            root = newNode;
            return root;
        }

        if (index == 0 || parent->firstChild == nullptr) {
            newNode->nextSibling = parent->firstChild;
            parent->firstChild = newNode;
        }
        //il inserez intre ceilalti copii
        else {
            TreeNode<T>* prev = parent->firstChild;
            int count = 1;
            while (prev->nextSibling && count < index) {
                prev = prev->nextSibling;
                count++;
            }
            newNode->nextSibling = prev->nextSibling; //fratele care ar fi urmat
            prev->nextSibling = newNode; //pe pozitia corecta
        }

        return newNode;
    }

    // sorteaza copiii folosind comparatorul sau <
    void sort(TreeNode<T>* parent, bool (*cmp)(const T&, const T&) = nullptr) {
        if (parent == nullptr || parent->firstChild == nullptr) return;

        // Converteste linked list in array de pointeri catre noduri
        const int MAX = 100;
        TreeNode<T>* arr[MAX];
        int size = 0;
        TreeNode<T>* current = parent->firstChild;

        while (current != nullptr && size < MAX) {
            arr[size++] = current;
            current = current->nextSibling;
        }

        // Sorteaza vectorul
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                bool shouldSwap = false;
                if (cmp) //daca exista pointerul catre functia de comparare
                    shouldSwap = cmp(arr[j]->value, arr[i]->value);
                else
                    shouldSwap = arr[j]->value < arr[i]->value;
                //swap-ul efectiv
                if (shouldSwap) {
                    TreeNode<T>* temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        // pt ca pointerii nextsibling sa aiba valorie corecte (restabilite dupa sortare)
        for (int i = 0; i < size - 1; i++) {
            arr[i]->nextSibling = arr[i + 1];
        }
        arr[size - 1]->nextSibling = nullptr; //ultimul copil
        parent->firstChild = arr[0]; //primul copil
    }

    // numara toti descendentii recursiv
    int count(TreeNode<T>* node = nullptr) { //parametru default null daca apelez fara pointer
        if (node == nullptr) {
            if (root == nullptr) return 0; // arbore gol
            node = root; // doar la APELUL initial
        }

        int total = 0;
        TreeNode<T>* current = node->firstChild;
        while (current != nullptr) {
            total += 1 + count(current);
            current = current->nextSibling;
        }
        return total;
    }
};

bool int_cmp(const int& a, const int& b) {
    return a == b;
}
bool int_cmp2(const int& a, const int& b) {
    return a < b;
}

int main() {
    Tree<int> myTree;

    TreeNode<int>* root = myTree.add_node(nullptr, 10);
    TreeNode<int>* n1 = myTree.add_node(root, 5);
    TreeNode<int>* n2 = myTree.add_node(root, 20);
    myTree.add_node(n1, 2);
    myTree.add_node(n1, 3);
    myTree.add_node(n2, 30);

    cout << "Nr total noduri: " << myTree.count() << endl;
    myTree.delete_node(n2);
    cout << "Nr total noduri: " << myTree.count() << endl;
    TreeNode<int>* n3 = myTree.add_node(root, 20);
    myTree.add_node(n3, 60);
    myTree.add_node(n3, 40);
    myTree.insert(n3, 50, 1);
    TreeNode<int>* found = myTree.find(root, 50, int_cmp);
    if (found) cout << "Am gasit nodul cu valoarea 50." << endl;
    cout <<"si urmatorul nod dupa el este: "<< found->nextSibling->value<<endl;
    myTree.sort(n3, int_cmp2);
    cout << "primul copil al lui n3 dupa sortare este: "<< n3->firstChild->value<<endl;
    cout<<"nr de copii al lui n3 este: "<<myTree.count(n3);

    return 0;
}