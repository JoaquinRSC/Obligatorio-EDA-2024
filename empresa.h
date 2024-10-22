#ifndef EMPRESA_H
#define EMPRESA_H

#include "definiciones.h"

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empresa.h
// Modulo de Definición de la Empresa

typedef struct nodo_empresa {
    Cadena cargo;
    nodo_empresa* siguiente;
} * Empresa;


TipoRet CrearOrg(Empresa &e, Cadena cargo);
// Inicializa la empresa y crea el primer cargo de la empresa.
// Originalmente la misma debería estar vacía; en otro caso, la operación quedará sin efecto. 

TipoRet EliminarOrg(Empresa &e);
// Eliminar el organigrama, elimina toda la estructura del organigrama, liberando la memoria asignada.

#endif
