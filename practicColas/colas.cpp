#include "colas.h"
#pragma once
#include <iostream>
#include "colas.h"

int main() {
    Cola<string> miCola(5);
    miCola.colas_practico("Atzel");
    miCola.colas_practico("Diego");
    miCola.colas_practico("Mendez");
    miCola.colas_practico("Pirlo");
    miCola.colas_practico("Elmer");
    miCola.colas_practico("Franco");

    miCola.imprimir();

    string aux = miCola.colas_practico();

    miCola.imprimir();

    return 0;
}