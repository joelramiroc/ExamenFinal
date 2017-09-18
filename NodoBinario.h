#ifndef NODOBINARIO_H
#define NODOBINARIO_H

#include <iostream>
using namespace std;

class NodoBinario
{
public:
    int valor;
    NodoBinario* izquierdo;
    NodoBinario* derecho;

    NodoBinario(int valor);
    virtual ~NodoBinario();
protected:
private:
};

#endif // NODOBINARIO_H
