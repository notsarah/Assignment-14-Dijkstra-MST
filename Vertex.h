/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #14  : Dijkstra & MST
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/25/16
 *************************************************************************/

#ifndef VERTEX_H
#define VERTEX_H


template <typename T>
class Vertex {
public:
    Vertex();
    Vertex(T el);
    Vertex(T el, int pos);
    ~Vertex();

    T getElement() const;
    int getPosition() const;
    bool getIsVisit() const;

    void setElement(T newElement);
    void setPosition(int pos);
    void setIsVisited(bool newVisit);


private:
    T element;
    int position;
    bool isVisited;

};

template <typename T>
Vertex<T>::Vertex() {
    position = -1;
}

template <typename T>
Vertex<T>::Vertex(T el) {
    element = el;
}

template <typename T>
Vertex<T>::Vertex(T el, int pos) {
    element = el;
    position = pos;
}

template <typename T>
Vertex<T>::~Vertex() {
    position = -1;
}

template <typename T>
T Vertex<T>::getElement() const {
    return element;
}

template <typename T>
int Vertex<T>::getPosition() const {
    return position;
}

template <typename T>
void Vertex<T>::setElement(T newElement) {
    element = newElement;
}

template <typename T>
void Vertex<T>::setPosition(int pos) {
    position = pos;
}

template <typename T>
bool Vertex<T>::getIsVisit() const {
    return isVisited;
}

template <typename T>
void Vertex<T>::setIsVisited(bool newVisit) {
    isVisited = newVisit;
}

#endif //VERTEX_H
