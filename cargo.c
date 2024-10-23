#include "cargo.h"
#include "empresa.h"
#include <iostream>
#include <cstring>

using namespace std;


struct nodo_cargos{
    Cadena nombre;
    Cargos ph;
    Cargos sh;
};

Cargos CrearCargos(Cadena cargo){
// Crea la estructura de Cargos con el cargo de mayor jerarquia.
    Cargos cs = new(nodo_cargos);
    cs->nombre = new(char[MAX_COMANDO]);
    strcpy(cs->nombre, cargo);
    cs->ph = NULL;
    cs->sh = NULL;
    return cs;
}

void ListarCargosJerarquicamenteAux(Cargos cs, int tabs){
// Imprime los cargos tabulados segun su jerarquia.
    if (cs != NULL){
        for(int i=0; i<tabs; i++)
            cout << "\t";
        cout << cs->nombre << endl;
        ListarCargosJerarquicamenteAux(cs->ph, tabs + 1);
        ListarCargosJerarquicamenteAux(cs->sh, tabs);
    }
}


void ListarCargosJerarquicamente(Cargos cs){
// Imprime os cargos jerarquicamente.
    ListarCargosJerarquicamenteAux(cs, 1);
}


TipoRet InsertarCargo(e->cs, cargoPadre, nuevoCargo){
// Inserta un nuevoCargo como hijo de cargoPadre.
// Si padre no existe o nuevoCargo ya esta en la estructura retorna ERROR.


    return NO_IMPLEMENTADA;
}

/*
TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo) {
// Insertar un nuevo cargo como dependiente de otro ya existente.
// El nuevo cargo no debe existir en el sistema.
    if (e == nullptr) {
        return ERROR;
    }

    nodo_empresa *cargoActual = e;
    while (cargoActual != nullptr) {
        if (strcmp(cargoActual->cargo, cargoPadre) == 0) {
            nodo_empresa *nuevo = new nodo_empresa;
            if (nuevo == nullptr) {
                return ERROR;
            }

            nuevo->cargo = new char[strlen(nuevoCargo) + 1];
            strcpy(nuevo->cargo, nuevoCargo);
            nuevo->siguiente = cargoActual->siguiente;
            cargoActual->siguiente = nuevo;

            return OK;
        }
        cargoActual = cargoActual->siguiente;
    }

    return ERROR;
}

TipoRet EliminarCargo(Empresa &e, Cadena cargo) {
// Eliminar un cargo, junto con sus subcargos y personas asociadas.
// Elimina un cargo en la empresa si cargo ya existe en la misma.
// En otro caso, la operación quedará sin efecto.
// Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también, así como
// las personas asociadas a cada uno de los cargos suprimidos.
    if (e == nullptr) {
        return ERROR;
    }

    nodo_empresa *actual = e;
    nodo_empresa *anterior = nullptr;

    while (actual != nullptr && strcmp(actual->cargo, cargo) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        return ERROR; 
    }

    if (anterior == nullptr) {
        e = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete[] actual->cargo;
    delete actual; 
    return OK;
}

TipoRet ListarCargosAlf(Empresa e) {
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo.
    if (e == nullptr) {
        cout << "No hay cargos en la empresa.\n";
        return ERROR;
    }

    Cadena cargoActual;
    bool swapped;

    do {
        swapped = false;
        Empresa p = e;
        while (p != nullptr && p->siguiente != nullptr) {
            if (strcmp(p->cargo, p->siguiente->cargo) > 0) {
                cargoActual = p->cargo;
                p->cargo = p->siguiente->cargo;
                p->siguiente->cargo = cargoActual;
                swapped = true;
            }
            p = p->siguiente;
        }
    } while (swapped);

    cout << "Cargos ordenados alfabéticamente:\n";
    Empresa p = e;
    while (p != nullptr) {
        cout << p->cargo << endl;
        p = p->siguiente;
    }

    return OK;
}

TipoRet ListarJerarquia(Empresa e) {
// Listar todos los cargos de la empresa en orden jerárquico.
// Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
// según se muestra el ejemplo de la letra.
    if (e == nullptr) {
        cout << "No hay cargos en la jerarquía.\n";
        return ERROR;
    }

    cout << "Cargos en orden jerárquico:\n";

    nodo_empresa* actual = e;
    int nivel = 0;

    while (actual != nullptr) {
        for (int i = 0; i < nivel; ++i) {
            cout << "    "; 
        }
        cout << actual->cargo << endl;

        actual = actual->siguiente;

        nivel++;
    }

    return OK;
}

TipoRet ListarSuperCargos(Empresa e, Cadena cargo) {
// Dado un cargo listar los cargos que lo anteceden.
// Lista todas los cargos que anteceden, en la jerarquía, al cargo de nombre cargo.
    if (e == nullptr) {
        cout << "No hay cargos en la empresa.\n";
        return ERROR;
    }

    nodo_empresa* actual = e;
    nodo_empresa* antecesor = nullptr;
    bool encontrado = false;

    while (actual != nullptr) {
        if (strcmp(actual->cargo, cargo) == 0) {
            encontrado = true;
            break;
        }
        antecesor = actual;
        actual = actual->siguiente; 
    }

    if (!encontrado) {
        cout << "Cargo no encontrado.\n";
        return ERROR;
    }

    cout << "Cargos que anteceden a " << cargo << ":\n";

    actual = e; 
    while (actual != antecesor) { 
        cout << actual->cargo << endl;
        actual = actual->siguiente; 
    }

    return OK;
}
*/