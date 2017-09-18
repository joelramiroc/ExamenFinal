#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>

using namespace std;

class Libro
{
public:

    string nombre;
    string autor;
    int existencias;

    Libro(string nombre, string autor, int existencias);
    virtual ~Libro();
protected:
private:
};

#endif // LIBRO_H
