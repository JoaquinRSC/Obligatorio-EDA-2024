#include "cargo.h"
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct nodo_cargos {
    Cadena nombre;
    Cargos ph;
    Cargos sh;
    Personas personas;
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
    while (cs != NULL) {
        if (strcmp(cs->nombre, cargoPadre) == 0) {
            Cargos temp = cs->ph;
            while (temp != NULL) {
                if (strcmp(temp->nombre, nuevoCargo) == 0) {
                    return ERROR;  
                }
                temp = temp->sh;
            }

            Cargos nuevo = CrearCargos(nuevoCargo);
            nuevo->sh = cs->ph;  
            cs->ph = nuevo;      
            return OK;
        }

        TipoRet resultado = InsertarCargo(cs->sh, cargoPadre, nuevoCargo);
        if (resultado == OK) {
            return OK;  
        }

        cs = cs->ph;  
    }

    return ERROR;
}

TipoRet EliminarCargoDeJerarquia(Cargos &cs, Cadena cargo) {
    if (cs == NULL) return ERROR;

    if (strcmp(cs->nombre, cargo) == 0 && cs->ph == NULL && cs->sh == NULL) {
        cout << "No se puede eliminar el cargo raíz, ya que debe existir al menos un cargo." << endl;
        return ERROR;
    }

    if (strcmp(cs->nombre, cargo) == 0) {
        Cargos temp = cs;
        cs = cs->sh;  
        delete temp;  
        return OK;
    }

    TipoRet resultado = EliminarCargoDeJerarquia(cs->ph, cargo);
    if (resultado == OK) return OK;

    return EliminarCargoDeJerarquia(cs->sh, cargo);
}

void DestruirCargos(Cargos &cs) {
    if (cs == NULL) return;

    DestruirCargos(cs->ph);

    DestruirCargos(cs->sh);

    delete[] cs->nombre;  
    delete cs;            
    cs = NULL;            
}

void trim(Cadena& str) {
    while (*str == ' ') str++;

    char* end = str + strlen(str) - 1;
    while (end >= str && *end == ' ') end--;
    *(end + 1) = '\0';  
}

int ContarCargos(Cargos cs) {
    int count = 0;
    if (cs != nullptr) {
        count++;

        count += ContarCargos(cs->ph);

        count += ContarCargos(cs->sh);
    }
    return count;
}

void ListarCargosAlfAux(Cargos cs, string cargos[], int& index) {
    if (cs != nullptr) {
        cargos[index++] = cs->nombre;

        ListarCargosAlfAux(cs->ph, cargos, index);

        ListarCargosAlfAux(cs->sh, cargos, index);
    }
}

void ListarCargosAlf(Cargos cs) {
    int totalCargos = ContarCargos(cs);

    string cargos[totalCargos];
    int index = 0;

    ListarCargosAlfAux(cs, cargos, index);

    sort(cargos, cargos + totalCargos);

    cout << "Cargos después de ordenar:" << endl;
    for (int i = 0; i < totalCargos; i++) {
        cout << cargos[i] << endl;  
    }
}

bool BuscarPadres(Cargos cs, Cadena cargo, bool& encontrado) {
    if (cs == NULL) return false;

    if (strcmp(cs->nombre, cargo) == 0) {
        encontrado = true;
        return true;  
    }

    if (BuscarPadres(cs->ph, cargo, encontrado)) {
        if (encontrado) {
            cout << cs->nombre << endl; 
            return true; 
        }
    }

    return BuscarPadres(cs->sh, cargo, encontrado);
}
