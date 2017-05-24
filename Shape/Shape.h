#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <string>
#include <sstream>
#include "../Polygon/Polygon.h"
const double PI=3.14159;
class Circle
{
public:
    Circle(Vector const &center, double radius):c(center),r(radius){}
    std::string name() const {
        return std::string("circle");
    }
    double area() const{
        return PI*r*r;
    }
    double perimeter() const{
        return 2.0*PI*r;
    }
private:
    Vector c;
    double r;
};
std::string printShape (Polygon const &p)
{
    std::stringstream ss;
    ss << "name:" << p.name() << ", area= " << p.area()
       << ", perimeter= " << p.perimeter();
    return ss.str();
}

std::string printShape (Circle const &p)
{
    std::stringstream ss;
    ss << "name:" << p.name() << ", area= " << p.area()
       << ", perimeter= " << p.perimeter();
    return ss.str();
}


#endif // SHAPE_H_INCLUDED
