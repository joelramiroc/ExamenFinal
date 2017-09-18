#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Libro.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

int TAMANO_DE_REGISTRO=104;
//Escribe todos los datos del libro en un archivo con nombre nombre_archivo en la posicion dada
void escribir(string nombre_archivo, Libro*libro, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in | ios::out);
  if(!out.is_open())
  {
    out.open(nombre_archivo.c_str());
  }

    out.seekp(posicion*TAMANO_DE_REGISTRO);

    out.write((char*)&libro->existencias,4);
    out.write(libro->nombre.c_str(),50);
    out.write(libro->autor.c_str(),50);
    out.close();
}

//Devuelve el libro guardado en el archivo en la posicion dada
Libro* leer(string nombre_archivo, int posicion)
{

    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*TAMANO_DE_REGISTRO);

      char nombre[50];
      char autor[50];
      int existencias;

    in.read((char*)&existencias,4);
      in.read(nombre,50);
      in.read(autor,50);
    Libro* enviar = new Libro(nombre,autor,existencias);
      in.close();
    return enviar;//enviar;
}

//Crea un mapa en base a las llaves y valores dados, asocia cada llave con los valores en la misma posicion
map<string, int> convertirEnMapa(set<string> llaves, set<int> valores)
{
    map<string, int> respuesta;
    set<string>::iterator i= llaves.begin();
    set<int>::iterator j= valores.begin();
	while(i!=llaves.end() || j!=valores.end())
    {
        string n= *i;
        int n2= *j;
        respuesta[n]=n2;
            i++;
            j++;
    }
    return respuesta;
}

//Devuelve una cola con los mismos valores que el parametro exepto que no tiene el ultimo valor
queue<int> popBack(queue<int> cola)
{
    queue<int> respuesta;
int n= cola.size();
int contara=0;
   while(!cola.empty() && contara<(n-1))
    {
        respuesta.push(cola.front());
		cola.pop();
		contara++;
	}
    return respuesta;
}

//Reemplaza todos los valores del arbol
void reemplazarValores(NodoBinario* raiz, int valor)
{
    if(raiz==NULL)
    {
        return;
    }
    raiz->valor=valor;
    reemplazarValores(raiz->derecho,valor);
    reemplazarValores(raiz->izquierdo,valor);
}


//Devuelve la cantidad de bits "encendidos" o con el valores de 1

bool estadoBit(char valor, int pos)
{
  int mascara = 1;
  mascara = mascara<<pos;
  return valor & mascara;
}

int contarBits(char byte)
{
    int contara=0;
    for(int n=0;n<8;n++)
    {
        if(estadoBit(byte,n)){
            contara++;
        }
    }
    return contara;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

