#include "persona.h"
#include "empresa.h"
#include <iostream>

using namespace std;

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci) {
// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre 'nom' y cédula de identidad 'ci' al cargo 'cargo',
// siempre que el cargo exista en la empresa y que esa persona no esté asignada 
// a otro cargo. En caso contrario, la operación quedará sin efecto.
    return NO_IMPLEMENTADA;
}

TipoRet EliminarPersona(Empresa &e, Cadena ci) {
// Eliminar una persona de un cargo.
// Elimina una persona de cédula 'ci' de la empresa, siempre y cuando la misma exista.
// En caso contrario, la operación quedará sin efecto.
    return NO_IMPLEMENTADA;
}

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci) {
// Reasignar una persona a un nuevo cargo.
// Reasigna una persona de la empresa de cédula 'ci' al nuevo cargo de nombre 'cargo'
// siempre que el cargo exista en la empresa y que esa persona no esté ya asignada a
// dicho cargo. En caso contrario, la operación quedará sin efecto.
    return NO_IMPLEMENTADA;
}

TipoRet ListarPersonas(Empresa e, Cadena cargo) {
// Dado un cargo, listar las personas asignadas al mismo.
// Lista todas las personas asignadas al cargo de nombre 'cargo', ordenadas por
// fecha de alta a la empresa.
    return NO_IMPLEMENTADA;
}
