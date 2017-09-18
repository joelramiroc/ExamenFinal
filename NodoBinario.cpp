#include "NodoBinario.h"

NodoBinario::NodoBinario(int valor)
{
    this->valor = valor;
    this->derecho = NULL;
    this->izquierdo = NULL;
}

NodoBinario::~NodoBinario()
{
    //dtor
}
