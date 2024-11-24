#ifndef CARGO_H
#define CARGO_H

#include "empresa.h"
#include "definiciones.h"

typedef struct nodo_cargos *Cargos;

Cargos CrearCargos(Cadena cargo);
// Crea la estructura de Cargos con el cargo de mayor jerarquía.

void ListarCargosJerarquicamente(Cargos cs);
// Imprime los cargos jerárquicamente.

TipoRet InsertarCargo(Cargos cs, Cadena cargoPadre, Cadena nuevoCargo);
// Inserta un nuevoCargo como hijo de cargoPadre.
// Si cargoPadre no existe o nuevoCargo ya está en la estructura, retorna ERROR.

void DestruirCargos(Cargos &cs);

TipoRet EliminarCargoDeJerarquia(Cargos &cs, Cadena cargo);

void ListarCargosAlf(Cargos cs);

// Función auxiliar para buscar los ancestros de un cargo
bool BuscarPadres(Cargos cs, Cadena cargo, bool& encontrado);

#endif
