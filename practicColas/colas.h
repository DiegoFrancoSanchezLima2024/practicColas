#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Cola
{
private:
    T* cola;
    int frente;
    int fin;
    int tamano;

public:
    Cola(int tamano);
    ~Cola();
    void colas_practico(T dato);
    T colas_practico();
    int getFrente();
    bool estaVacia();
    bool estaLlena();
    void imprimir();
};

template<typename T>
inline Cola<T>::Cola(int _tamano)
{
    tamano = _tamano;
    cola = new T[tamano];
    frente = -1;
    fin = -1;
}

template<typename T>
inline Cola<T>::~Cola()
{
    delete[] cola;
}

template<typename T>
inline void Cola<T>::colas_practico(T dato)
{
    if (!estaLlena())
    {
        if (frente == -1)
            frente = 0;
        fin = (fin + 1) % tamano;
        cola[fin] = dato;
    }
    else
    {
        cout << "La cola está llena" << endl;
    }
}

template<typename T>
inline T Cola<T>::colas_practico()
{
    if (!estaVacia())
    {
        T dato = cola[frente];
        if (frente == fin)
        {
            frente = -1;
            fin = -1;
        }
        else
        {
            frente = (frente + 1) % tamano;
        }
        return dato;
    }
    else
    {
        cout << "La cola está vacía" << endl;
        return T();  // Devuelve un valor predeterminado para mantener la consistencia del tipo de retorno
    }
}

template<typename T>
inline int Cola<T>::getFrente()
{
    return frente;
}

template<typename T>
inline bool Cola<T>::estaVacia()
{
    return frente == -1;
}

template<typename T>
inline bool Cola<T>::estaLlena()
{
    return (fin + 1) % tamano == frente;
}

template<typename T>
inline void Cola<T>::imprimir()
{
    int i = frente;
    while (i != -1)
    {
        cout << cola[i] << " ";
        if (i == fin)
            break;
        i = (i + 1) % tamano;
    }
    cout << endl;
}