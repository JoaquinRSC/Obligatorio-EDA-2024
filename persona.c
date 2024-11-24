#include "persona.h"
#include <iostream>
#include <cstring>

using namespace std;

struct nodo_personas {
    Cadena nombre;
    Cadena ci;
    Personas siguiente;  
};

TipoRet ListarPersonas(Empresa &e, Cadena cargo) {
    // Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa.
    // Lista todas las personas asignadas al cargo de nombre cargo.
    Cargos cargoActual = e->cs;

    while (cargoActual != NULL) { 
        if (strcmp(cargoActual->nombre, cargo) == 0) {
            Personas personaActual = cargoActual->personas; 
            if (personaActual == NULL) {
                cout << "No hay personas asignadas al cargo: " << cargo << endl; 
                return OK;
            }
            cout << "Personas asignadas al cargo " << cargo << ":" << endl;
            while (personaActual != NULL) {
                cout << "- Nombre: " << personaActual->nombre 
                     << ", CI: " << personaActual->ci << endl; 
                personaActual = personaActual->siguiente;
            }
            return OK;
        }
        cargoActual = cargoActual->sh;
    }

    cout << "El cargo " << cargo << " no existe en la empresa." << endl; 
    return ERROR;
}

TipoRet BuscarPersonaEnCargo(Cargos &cargo, Cadena ci) {
    // Buscar si la persona con cédula 'ci' está en el cargo dado
    Personas temp = cargo->personas;
    while (temp != NULL) {
        if (strcmp(temp->ci, ci) == 0) {
            return OK;  
        }
        temp = temp->siguiente;
    }
    return ERROR;
}

TipoRet EliminarPersonaDeCargo(Cargos &cargo, Cadena ci) {
    // Eliminar a la persona con cédula 'ci' del cargo dado
    Personas prev = NULL;
    Personas temp = cargo->personas;
    
    while (temp != NULL) {
        if (strcmp(temp->ci, ci) == 0) {
            if (prev == NULL) {
                cargo->personas = temp->siguiente;  
            } else {
                prev->siguiente = temp->siguiente;  
            }
            delete[] temp->nombre;
            delete[] temp->ci;
            delete temp;
            return OK;  
        }
        prev = temp;
        temp = temp->siguiente;
    }
    return ERROR; 
}

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci) {
    // Asignar una persona a un cargo, si este existe.
    // Asigna una persona de nombre 'nom' y cédula de identidad 'ci' al cargo 'cargo',
    // siempre que el cargo exista en la empresa y que esa persona no esté asignada 
    // a ese u otro cargo, en caso contrario la operación quedará sin efecto.
    Cargos cargoActual = e->cs;  
    bool cargoEncontrado = false;
    
    while (cargoActual != NULL) {
        if (strcmp(cargoActual->nombre, cargo) == 0) {
            cargoEncontrado = true;
            break;  
        }
        cargoActual = cargoActual->sh;  
    }

    if (!cargoEncontrado) {
        cout << "El cargo no existe en la empresa." << endl;
        return ERROR;
    }

    Cargos tempCargo = e->cs;  
    while (tempCargo != NULL) {
        if (BuscarPersonaEnCargo(tempCargo, ci) == OK) {
            cout << "La persona ya está asignada a otro cargo." << endl;
            return ERROR;  
        }
        tempCargo = tempCargo->sh;
    }

    if (cargoActual->personas == NULL) {
        cargoActual->personas = CrearPersona(nom, ci);  
    } else {
        AgregarPersonaALista(cargoActual->personas, nom, ci);
    }

    return OK; 
}

TipoRet EliminarPersona(Empresa &e, Cadena ci) {
    // Eliminar una persona de un cargo dentro de la empresa.
    // Busca en todos los cargos para encontrar la persona y eliminarla del cargo asignado.
    Cargos cargoActual = e->cs;
    bool personaEliminada = false;

    while (cargoActual != NULL) {
        if (BuscarPersonaEnCargo(cargoActual, ci) == OK) {
            if (EliminarPersonaDeCargo(cargoActual, ci) == OK) {
                personaEliminada = true;
                break;  
            }
        }
        cargoActual = cargoActual->sh;
    }

    if (!personaEliminada) {
        cout << "La persona no se encuentra en ningún cargo." << endl;
        return ERROR;  
    }

    return OK;
}

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci) {
    // Reasignar una persona a un nuevo cargo.
    // Reasigna una persona de la empresa de cédula 'ci' al nuevo cargo de nombre 'cargo'
    // siempre que el cargo exista en la empresa y que esa persona no esté ya asignada a
    // dicho cargo. En caso contrario, la operación quedará sin efecto.
    Cargos cargoActual = e->cs;  
    bool cargoEncontrado = false;

    while (cargoActual != NULL) {
        if (strcmp(cargoActual->nombre, cargo) == 0) {
            cargoEncontrado = true;
            break;  
        }
        cargoActual = cargoActual->sh;
    }

    if (!cargoEncontrado) {
        cout << "El cargo no existe en la empresa." << endl;
        return ERROR;
    }

    if (BuscarPersonaEnCargo(cargoActual, ci) == OK) {
        cout << "La persona ya está asignada a este cargo." << endl;
        return ERROR;
    }

    Cargos tempCargo = e->cs;  
    while (tempCargo != NULL) {
        if (BuscarPersonaEnCargo(tempCargo, ci) == OK) {
            EliminarPersonaDeCargo(tempCargo, ci);  
            break;
        }
        tempCargo = tempCargo->sh;
    }

    AgregarPersonaALista(cargoActual->personas, "", ci);
    return OK;
}
