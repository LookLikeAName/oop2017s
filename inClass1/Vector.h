#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <string>
class Vector {
public:
  Vector(double a [], int dim) {
    d = dim;
    v = new double[d];
    for (int i=0; i < d; ++i)
        v[i] = a[i];
  }
  ~Vector() {delete [] v;}
  int dim() {
      return d;
  }
  double component (int dim){
      return v[dim-1];
  }
private:
  int d;
  double *v;
};

double innerProduct(Vector a, Vector b){
    double result= 0;
    if(a.dim()!=b.dim()){
        throw std::string("wrong dim");
    }
    for(int i=1;i<=a.dim();i++){
        result+=a.component(i)*b.component(i);
    }
    return result;
}

#endif // VECTOR_H_INCLUDED
