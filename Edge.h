/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #14  : Dijkstra & MST
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/25/16
 *************************************************************************/


#ifndef EDGE_H
#define EDGE_H

template <typename T>
class Edge {
public:
    Edge();
    Edge(T newStart, T newEnd, int newCost);
    ~Edge();

    T getStart() const;
    T getEnd() const;
    double getWeight() const;
    bool getIsDiscovered() const;

    void setStart(T newStart);
    void setEnd(T newEnd);
    void setWeight(int newCost);
    void setIsDiscovered(bool newDiscovery);

private:
    T start;
    T end;
    double weight;
    bool isDiscovered;
};

/*****************************************************************
 * Edge()
 *    CONSTRUCTOR
 * Initializes the following attributes: weight (distance),
 * stat, end, and isDiscovered.
 ****************************************************************/
template <typename T>
Edge<T>::Edge() {
    weight = 0;
    isDiscovered = false;
}

/*****************************************************************
 * Edge(T newStart, T newEnd, newCost)
 *    NON-DEFAULT CONSTRUCTOR
 * Initializes the following attributes: weight (distance),
 * starting, ending, and isDiscovered.
 ****************************************************************/
template <typename T>
Edge<T>::Edge(T newStart, T newEnd, int newCost) {
    start = newStart;
    end   = newEnd;
    weight  = newCost;
    isDiscovered = false;
}

/*****************************************************************
 * ~Edge()
 *    DESTRUCTOR
 * Destructs the attributes in Edge class.
 ****************************************************************/
template <typename T>
Edge<T>::~Edge() {
    weight = 0;
    isDiscovered = false;

}

/*****************************************************************
 * getStart() const
 *    ACCESSOR
 * Retrieves the representation of the start of the edge.
 * RETURNS -> start
 ****************************************************************/
template <typename T>
T Edge<T>::getStart() const {
    return start;
}

/*****************************************************************
 * getEnd() const
 *    ACCESSOR
 * Retrieves the representation of the end of the edge.
 * RETURNS -> end
 ****************************************************************/
template <typename T>
T Edge<T>::getEnd() const {
    return end;
}

/*****************************************************************
 * getWeight() const
 *    ACCESSOR
 * Retrieves the representation of the weight of the edge.
 * RETURNS -> weight
 ****************************************************************/
template <typename T>
double Edge<T>::getWeight() const {
    return weight;
}

/*****************************************************************
 * setStart(T newStart)
 *    MUTATOR
 * Sets start to a new start
 * RETURNS -> void
 ****************************************************************/
template <typename T>
void Edge<T>::setStart(T newStart) {
    start = newStart;
}

/*****************************************************************
 * setEnd(T newEnd)
 *    MUTATOR
 * Sets end to a new end
 * RETURNS -> void
 ****************************************************************/
template <typename T>
void Edge<T>::setEnd(T newEnd) {
    end = newEnd;
}

/*****************************************************************
 * setWeight(int newWeight)
 *    MUTATOR
 * Sets weight to a new weight
 * RETURNS -> void
 ****************************************************************/
template <typename T>
void Edge<T>::setWeight(int newWeight) {
    weight = newWeight;
}

/*****************************************************************
 * setIsDiscovered(bool isDiscovery)
 *    MUTATOR
 * Sets is discovered to a new discovery
 * RETURNS -> void
 ****************************************************************/
template <typename T>
void Edge<T>::setIsDiscovered(bool newDiscovery) {
    isDiscovered = newDiscovery;
}

/*****************************************************************
 * getIsDiscovered() const
 *    ACCESSOR
 * Retrieves if the edge has been discovered or not.
 * RETURNS -> isDiscovered
 ****************************************************************/
template <typename T>
bool Edge<T>::getIsDiscovered() const {
    return isDiscovered;
}

#endif //EDGE_H
