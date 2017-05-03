#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include "../inClass1/Matrix.h"

class Polygon {
public:
    Polygon(Vector * a[], int numberOfVertices)
    :vertices(a, numberOfVertices) // constructor initialization
    {}

    Vector & vertex(int i) const {
        return vertices[i];
    }

    double perimeter() const{

    }
private:
    Matrix vertices;
};

#endif // POLYGON_H_INCLUDED
