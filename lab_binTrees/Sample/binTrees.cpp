#include "binTrees.h"

#include "binTrees.h"

// ============= node =============
template <typename T>
node<T>::node(const T& val)
    : value(val), right(nullptr), left(nullptr) {
}

// ============= binTree =============

template <typename T>
binTree<T>::binTree() {
    // TODO: реализовать конструктор
    root = nullptr;
    nodeCount = 0;
}

template <typename T>
binTree<T>::binTree(const binTree<T>& other) {
    // TODO: реализовать конструктор копирования
    root = nullptr;
    nodeCount = 0;
}

template <typename T>
binTree<T>::~binTree() {
    // TODO: реализовать деструктор
}

template <typename T>
void binTree<T>::insert(const T& val) {
    // TODO: реализовать вставку элемента
}

template <typename T>
bool binTree<T>::remove(const T& val) {
    // TODO: реализовать удаление элемента
    return false;
}

template <typename T>
bool binTree<T>::find(const T& val) {
    // TODO: реализовать поиск элемента
    return false;
}