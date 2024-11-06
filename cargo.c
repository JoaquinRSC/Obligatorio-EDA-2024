#include "cargo.h"
#include "empresa.h"
#include <iostream>
#include <cstring>

using namespace std;

struct nodo_cargos {
    Cadena nombre;
    Cargos ph;
    Cargos sh;
};

Cargos CrearCargos(Cadena cargo) {
    // Crea la estructura de Cargos con el cargo de mayor jerarquía.
    Cargos cs = new(nodo_cargos);
    cs->nombre = new char[MAX_COMANDO];
    strcpy(cs->nombre, cargo);
    cs->ph = NULL;
    cs->sh = NULL;
    return cs;
}

void ListarCargosJerarquicamenteAux(Cargos cs, int tabs) {
    // Imprime los cargos tabulados según su jerarquía.
    if (cs != NULL) {
        for (int i = 0; i < tabs; i++)
            cout << "\t";
        cout << cs->nombre << endl;
        ListarCargosJerarquicamenteAux(cs->ph, tabs + 1);
        ListarCargosJerarquicamenteAux(cs->sh, tabs);
    }
}

void ListarCargosJerarquicamente(Cargos cs) {
    // Imprime los cargos jerárquicamente.
    ListarCargosJerarquicamenteAux(cs, 1);
}

TipoRet InsertarCargo(Cargos cs, Cadena cargoPadre, Cadena nuevoCargo) {
    // Inserta un nuevoCargo como hijo de cargoPadre.
    // Si cargoPadre no existe o nuevoCargo ya está en la estructura, retorna ERROR.
    return NO_IMPLEMENTADA;
}
