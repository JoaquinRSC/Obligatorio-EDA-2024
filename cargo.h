#ifndef CARGO_H
#define CARGO_H

#include "empresa.h"
#include "persona.h"
#include "definiciones.h"

typedef struct nodo_cargo {
    Cadena nombre;
    struct nodo_cargo* siguiente;

    Persona* personas;
} nodo_cargo; 

TipoRet NuevoCargo(nodo_empresa *&e, Cadena cargoPadre, Cadena nuevoCargo);
// Insertar un nuevo cargo como dependiente de otro ya existente.
// El nuevo cargo no debe existir en el sistema.

TipoRet EliminarCargo(Empresa &e, Cadena cargo);
// Eliminar un cargo, junto con sus subcargos y personas asociadas.
// Elimina un cargo en la empresa si cargo ya existe en la misma.
// En otro caso, la operación quedará sin efecto.
// Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también, así como
// las personas asociadas a cada uno de los cargos suprimidos.

TipoRet ListarCargosAlf(Empresa e);
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo.

TipoRet ListarJerarquia(Empresa e);
// Listar todos los cargos de la empresa en orden jerárquico.
// Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
// según se muestra el ejemplo de la letra.

TipoRet ListarSuperCargos(Empresa e, Cadena cargo);
// Dado un cargo listar los cargos que lo anteceden.
// Lista todas los cargos que anteceden, en la jerarquía, al cargo de nombre cargo.

#endif
