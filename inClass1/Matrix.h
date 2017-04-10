#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>
#include "Vector.h"

class Matrix{
public:
    Matrix(Vector * vec[], int n){
        vs.push_back(0);
        for(int i = 1 ; i < n ; i++){
            vs.push_back(new Vector(*vec[i]));
        }
    }
    // deep copy trio
    Matrix(Matrix & m){
        vs.push_back(0);
        for(int i = 1 ; i < vs.size() ; i++){
            vs.push_back( new Vector(*m.vs[i]));
        }
    }
    ~Matrix() {
        for (int i=0; i< vs.size(); ++i)
            delete vs[i];
    }

    Matrix &operator = (Matrix const & m){
        if (this != &m) {
            for (int i=0; i< vs.size(); ++i)
                delete vs[i];
            vs.clear();
            vs.push_back(0);
            for(int i = 1 ; i < m.vs.size() ; i++){
                vs.push_back( new Vector(*m.vs[i]));
            }
        }
        return *this;
    }
    // accessors
    Vector &operator [] (int i) const{
        return *vs[i];
    }

private:
    std::vector <Vector*> vs;

};

#endif // MATRIX_H_INCLUDED
