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
        double p=0;
        for(int i=1;i<vertices.nRows();i++){
            p+=(vertices[i+1]-vertices[i]).length();
        }
        p+=(vertices[vertices.nRows()]-vertices[1]).length();
        return p;
    }
    double area() const{
        double area=0;
        for(int i=2;i<vertices.nRows();i++){
           area+=VectorArea(vertices[1],vertices[i],vertices[i+1]);
        }
        return area;
    }
private:
    Matrix vertices;
};

#endif // POLYGON_H_INCLUDED
