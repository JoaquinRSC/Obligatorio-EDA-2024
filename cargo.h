#ifndef CARGO_H
#define CARGO_H

#include "empresa.h"
#include "persona.h"
#include "definiciones.h"

typedef struct nodo_cargos * Cargos;

Cargos CrearCargos(Cadena cargo);
// Crea la estructura de Cargos con el cargo de mayor jerarquia.


void ListarCargosJerarquicamente(Cargos cs);
// Imprime os cargos jerarquicamente.


TipoRet InsertarCargo(e->cs, cargoPadre, nuevoCargo);
// Inserta un nuevoCargo como hijo de cargoPadre.
// Si padre no existe o nuevoCargo ya esta en la estructura retorna ERROR.



/*
typedef struct nodo_cargo {
    Cadena nombre;
    struct nodo_cargo* siguiente;

    Persona* personas;
} nodo_cargo; 
*/
#endif
