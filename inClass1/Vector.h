#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <string>
#include <vector>
#include <sstream>
class Vector {
public:
  Vector(double a [], int dim) {
    d = dim;
    v = new double[d];
    for (int i=0; i < d; ++i)
        v[i] = a[i];
  }
  Vector(Vector const & vec){
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

  double &operator[] (int dim) const {
      return v[dim-1];
  }

  double &component (int dim) const {

      return v[dim-1];
  }
  void multiply(double c){
        for(int i=1; i<=dim();i++){
            component(i)=c*component(i);
        }
  }
  // scalar alpha X plus Y: Y = aX+Y
    void saxpy(double a,const Vector & x){
    for(int i=1; i<=dim();i++){
        component(i)=a*x.component(i)+component(i);
    }
}

std::string toString(){
    std::stringstream ss;
    ss << "[ ";
    for (int i=1; i<=dim();i++)
        ss << (*this)[i] << " ";
    ss << "]";
    return ss.str();
}


private:
  int d;
  double *v;
};

bool operator == (Vector const & u, Vector const & v) {
    for(int i = 1; i <= u.dim(); i++) {
        if(u[i] != v[i])
            return false;
    }
    return true;
}

double innerProduct(Vector const &a, Vector const &b){
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

void pivot(unsigned r, std::vector<Vector *> & m) {
    unsigned i=r;
    for (; i<=m.size(); ++i)
        if (m[i]->component(r) != 0)
            break;
    if (i != r && i <= m.size())
        swapVector(m, r, i);
}

void eliminateForward(unsigned i, std::vector<Vector *> & m) {
        for (unsigned j=i+1; j <=m.size()-1; ++j)
            linearTransform(-m[j]->component(i), *m[i], *m[j]);
}

void forward(std::vector<Vector *> & m) {
    for (unsigned i=1; i<=m.size()-1; ++i) {
        pivot(i,m);
        multiply(1/m[i]->component(i), *m[i]);
        eliminateForward(i, m);
    }
}

void backward(std::vector<Vector *> & m) {
    for (int i = m.size()-1; i >= 1; --i)
        for (int j = i-1; j >= 1; --j)
            linearTransform(-m[j]->component(i),*m[i],*m[j]);
}

void GuassJordan(std::vector<Vector *> & m){
    forward(m);
    backward(m);
}
std::string extractComponents(std::string const &s) {
    std::stringstream ts(s);
    char c;
    ts>>c;
    std::string components;
    getline(ts,components,']');
    return components;
}
Vector stringToVector(std::string const &s){
    std::string comps = extractComponents(s);
    std::stringstream cs(comps);
    std::string temd;
    double vec [256];
    int dim=0;
    while(getline(cs,temd,' '))
    {
       std::stringstream ts(temd);
       if(ts >> vec[dim])
          dim++;
    }
    return Vector(vec, dim);
}



#endif // VECTOR_H_INCLUDED
