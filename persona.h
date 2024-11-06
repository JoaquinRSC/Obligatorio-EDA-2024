#ifndef PERSONA_H
#define PERSONA_H

#include "empresa.h"
#include "definiciones.h"

typedef struct nodo_personas *Personas;

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci);
// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre nom y cédula de identidad ci al cargo cargo
// siempre que el cargo exista en la empresa y esa persona no esté asignada a
// ese u otro cargo, en caso contrario la operación quedará sin efecto.

TipoRet EliminarPersona(Empresa &e, Cadena ci);
// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci);
// Reasignar una persona a un nuevo cargo.
// Reasigna una persona de la empresa de cédula ci al nuevo cargo de nombre cargo
// siempre que el cargo exista en la empresa y esa persona no esté ya asignada a
// dicho cargo. En caso contrario la operación quedará sin efecto.

TipoRet ListarPersonas(Empresa &e, Cadena cargo);
// Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa.
// Lista todas las personas asignadas al cargo de nombre cargo.

#endif
