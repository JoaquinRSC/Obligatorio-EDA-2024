#include "empresa.h"
#include <iostream>
#include <cstring>

using namespace std;

TipoRet CrearOrg(Empresa &e, Cadena cargo) {
// Inicializa la empresa y crea el primer cargo de la empresa.
// Originalmente la misma debería estar vacía; en otro caso, la operación quedará sin efecto. 
    e = new nodo_empresa;
    if (e == nullptr) { 
        return ERROR;
    }

    e->cargo = new char[strlen(cargo) + 1];
    strcpy(e->cargo, cargo);
    e->siguiente = nullptr;

    return OK;
}

TipoRet EliminarOrg(Empresa &e) {
// Eliminar el organigrama, elimina toda la estructura del organigrama, liberando la memoria asignada.
    if (e == nullptr) {
        return ERROR;
    }

    nodo_empresa *actual = e;
    nodo_empresa *temp;

    while (actual != nullptr) {
        temp = actual;
        actual = actual->siguiente;

        delete[] temp->cargo;
        delete temp;
    }

    e = nullptr; 
    return OK; 
}
