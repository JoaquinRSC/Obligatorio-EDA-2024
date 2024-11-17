#include "empresa.h"
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
    // Primero buscamos si el cargoPadre está en el nivel actual
    while (cs != NULL) {
        if (strcmp(cs->nombre, cargoPadre) == 0) {
            // Si encontramos el cargoPadre, comprobamos si el nuevo cargo ya existe
            Cargos temp = cs->ph;
            while (temp != NULL) {
                if (strcmp(temp->nombre, nuevoCargo) == 0) {
                    return ERROR;  // El cargo ya existe
                }
                temp = temp->sh;
            }

            // Si no existe, creamos el nuevo cargo y lo insertamos como hijo
            Cargos nuevo = CrearCargos(nuevoCargo);
            nuevo->sh = cs->ph;  // El nuevo cargo será el primer hijo
            cs->ph = nuevo;      // Insertamos el nuevo cargo como hijo del cargo padre
            return OK;
        }

        // Si no encontramos el cargoPadre en el nivel actual, seguimos buscando en los hermanos
        TipoRet resultado = InsertarCargo(cs->sh, cargoPadre, nuevoCargo);
        if (resultado == OK) {
            return OK;  // Si se insertó correctamente en los subcargos, retornamos OK
        }

        cs = cs->ph;  // Continuamos con el siguiente nivel (subcargos)
    }

    // Si no se encuentra el cargo padre en ningún nivel, retornamos ERROR
    return ERROR;
}

TipoRet EliminarCargoDeJerarquia(Cargos &cs, Cadena cargo) {
    if (cs == NULL) return ERROR;

    // Verificar si el cargo actual es el cargo raíz (cargo de mayor jerarquía)
    // Si es el primer cargo, no se debe eliminar
    if (strcmp(cs->nombre, cargo) == 0 && cs->ph == NULL && cs->sh == NULL) {
        cout << "No se puede eliminar el cargo raíz, ya que debe existir al menos un cargo." << endl;
        return ERROR;
    }

    // Si el cargo actual es el que debe eliminarse
    if (strcmp(cs->nombre, cargo) == 0) {
        Cargos temp = cs;
        cs = cs->sh;  // Mover al siguiente hermano
        delete temp;  // Liberar memoria del cargo eliminado
        return OK;
    }

    // Si no es el cargo actual, buscar en los hijos
    TipoRet resultado = EliminarCargoDeJerarquia(cs->ph, cargo);
    if (resultado == OK) return OK;

    // Si no se encontró en los hijos, buscar en los hermanos
    return EliminarCargoDeJerarquia(cs->sh, cargo);
}

void DestruirCargos(Cargos &cs) {
    if (cs == NULL) return;

    // Primero destruir los subcargos (hijos)
    DestruirCargos(cs->ph);

    // Luego destruir los hermanos
    DestruirCargos(cs->sh);

    // Finalmente, liberar la memoria del cargo actual
    delete[] cs->nombre;  // Liberar la cadena que contiene el nombre del cargo
    delete cs;            // Liberar el nodo del cargo
    cs = NULL;            // Asegurarse de que el puntero ya no apunte a la memoria liberada
}

void trim(Cadena& str) {
    // Eliminar espacios al principio
    while (*str == ' ') str++;

    // Eliminar espacios al final
    char* end = str + strlen(str) - 1;
    while (end >= str && *end == ' ') end--;
    *(end + 1) = '\0';  // Aseguramos que la cadena termine correctamente
}

// Función auxiliar para contar el número de cargos
int ContarCargos(Cargos cs) {
    int count = 0;
    if (cs != nullptr) {
        // Contamos el cargo actual
        count++;

        // Contamos recursivamente los cargos hijos (padre-hijo)
        count += ContarCargos(cs->ph);

        // Contamos recursivamente los cargos hermanos (hermano-hermano)
        count += ContarCargos(cs->sh);
    }
    return count;
}

// Función auxiliar para listar los cargos en orden alfabético
void ListarCargosAlfAux(Cargos cs, string cargos[], int& index) {
    if (cs != nullptr) {
        // Agregar el nombre del cargo al arreglo
        cargos[index++] = cs->nombre;

        // Recursión para recorrer los hijos (padre-hijo)
        ListarCargosAlfAux(cs->ph, cargos, index);

        // Recursión para recorrer los hermanos (hermano-hermano)
        ListarCargosAlfAux(cs->sh, cargos, index);
    }
}

// Implementación de la función que lista los cargos en orden alfabético
void ListarCargosAlf(Cargos cs) {
    // Contamos el número total de cargos
    int totalCargos = ContarCargos(cs);

    // Usamos un arreglo estático para almacenar los nombres de los cargos
    string cargos[totalCargos];
    int index = 0;

    // Llamamos a la función auxiliar para llenar el arreglo con los nombres
    ListarCargosAlfAux(cs, cargos, index);

    // Ordenamos el arreglo alfabéticamente usando sort
    sort(cargos, cargos + totalCargos);

    // Después de ordenar
    cout << "Cargos después de ordenar:" << endl;
    for (int i = 0; i < totalCargos; i++) {
        cout << cargos[i] << endl;  // Imprime cada cargo en una nueva línea
    }
}

// Función auxiliar para buscar los ancestros de un cargo e imprimirlos.
bool BuscarPadres(Cargos cs, Cadena cargo, bool& encontrado) {
    if (cs == NULL) return false;

    // Primero, buscamos en el cargo actual
    if (strcmp(cs->nombre, cargo) == 0) {
        encontrado = true;
        return true;  // Si encontramos el cargo, retornamos true
    }

    // Si no es el cargo actual, buscamos en los hijos (ph) o hermanos (sh)
    if (BuscarPadres(cs->ph, cargo, encontrado)) {
        if (encontrado) {
            cout << cs->nombre << endl; // Imprimimos el cargo padre
            return true; // Si se encontró en los hijos, retornamos true
        }
    }

    // Si no se encontró en los hijos, buscamos en los hermanos
    return BuscarPadres(cs->sh, cargo, encontrado);
}
