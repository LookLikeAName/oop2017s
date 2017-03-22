#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <string>
#include <vector>
class Vector {
public:
  Vector(double a [], int dim) {
    d = dim;
    v = new double[d];
    for (int i=0; i < d; ++i)
        v[i] = a[i];
  }
  Vector(Vector & vec){
    d = vec.d;
    v = new double [d];
    for (int i=0; i < d; ++i)
        v[i] = vec.v[i];
  }
  ~Vector() {delete [] v;}
  //constant member function
  int dim() const {
      return d;
  }
  double &component (int dim) const {

      return v[dim-1];
  }
private:
  int d;
  double *v;
};

double innerProduct(Vector &a, Vector &b){
    double result= 0;
    if(a.dim()!=b.dim()){
        throw std::string("wrong dim");
    }
    for(int i=1;i<=a.dim();i++){
        result+=a.component(i)*b.component(i);
    }
    return result;
}

void multiply(double c, Vector &v){
    for(int i=1; i<=v.dim();i++){
        v.component(i)=c*v.component(i);
    }
}
void linearTransform(double c,const Vector &  v1,Vector &v2){
    for(int i=1; i<=v1.dim();i++){
        v2.component(i)=c*v1.component(i)+v2.component(i);
    }
}
void swapVector(std::vector <Vector*> &m,int i,int j){
    Vector* t = m[i];
    m[i] = m[j];
    m[j] = t;

}
#endif // VECTOR_H_INCLUDED
