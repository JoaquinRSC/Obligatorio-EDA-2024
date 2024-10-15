#include "empresa.h"
#include <iostream>

using namespace std;

TipoRet CrearOrg(Empresa &e, Cadena cargo) {
// Inicializa la empresa y crea el primer cargo de la empresa.
// Originalmente la misma debería estar vacía; en otro caso, la operación quedará sin efecto.
    if (e != nullptr) {
        return ERROR;
    }

    e = new nodo_empresa;
    e->cargo = cargo;
    e->siguiente = nullptr;

    return OK; 
}

TipoRet EliminarOrg(Empresa &e) {
// Eliminar el organigrama, elimina toda la estructura del organigrama, liberando la memoria asignada.
    if (e != nullptr) {
        eliminarCargos(e);
        e = nullptr;
    }
    
    return OK; 
}
