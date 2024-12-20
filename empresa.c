#include "empresa.h"
#include "cargo.h"
#include "definiciones.h"
#include <iostream>
#include <cstring>

using namespace std;

struct nodo_empresa {
    Cargos cs;
};

TipoRet CrearOrg(Empresa &e, Cadena cargo) {
    // Inicializa la empresa y crea el primer cargo de la empresa.
    // Originalmente la misma debería estar vacía; en otro caso, la operación quedará sin efecto. 
    e = new(nodo_empresa);
    e->cs = CrearCargos(cargo);
    return OK;
}

TipoRet EliminarOrg(Empresa &e) {
    // Eliminar el organigrama, elimina toda la estructura del organigrama, liberando la memoria asignada.
    if (e == NULL) return ERROR;

    DestruirCargos(e->cs);

    delete e;
    e = NULL;

    return OK;
}

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo) {
    // Insertar un nuevo cargo como dependiente de otro ya existente.
    // El nuevo cargo no debe existir en el sistema.
    return InsertarCargo(e->cs, cargoPadre, nuevoCargo);
}

TipoRet EliminarCargo(Empresa &e, Cadena cargo) {
    // Eliminar un cargo, junto con sus subcargos y personas asociadas.
    // Elimina un cargo en la empresa si cargo ya existe en la misma.
    // En otro caso, la operación quedará sin efecto.
    // Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también,
    // así como las personas asociadas a cada uno de los cargos suprimidos.
    return EliminarCargoDeJerarquia(e->cs, cargo);
}

TipoRet ListarCargosAlf(Empresa &e) {
    // Listar todos los cargos ordenados alfabéticamente.
    // Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo.
    ListarCargosAlf(e->cs);
    return OK;
}

TipoRet ListarJerarquia(Empresa &e) {
    // Listar todos los cargos de la empresa en orden jerárquico.
    // Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
    // según se muestra el ejemplo de la letra.
    ListarCargosJerarquicamente(e->cs);
    return OK;
}

TipoRet ListarSuperCargos(Empresa &e, Cadena cargo) {
    bool encontrado = false;
    bool resultado = BuscarPadres(e->cs, cargo, encontrado);
    if (!encontrado) {
        cout << "Cargo no encontrado en la jerarquía." << endl;
    }
    return OK;
}

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci) {
    // Asignar una persona a un cargo, si este existe.
    // Asigna una persona de nombre nom y cédula de identidad ci al cargo cargo
    // siempre que el cargo exista en la empresa y esa persona no esté asignada a
    // ese u otro cargo, en caso contrario la operación quedará sin efecto.
    return AsignarPersona(e, cargo, nom, ci);
}

TipoRet EliminarPersona(Empresa &e, Cadena ci) {
    // Eliminar una persona de un cargo.
    // Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
    // en caso contrario la operación quedará sin efecto.
    return EliminarPersona(e, ci);
}

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci) {
    // Reasignar una persona a un nuevo cargo.
    // Reasigna una persona de la empresa de cédula ci al nuevo cargo de nombre cargo
    // siempre que el cargo exista en la empresa y esa persona no esté ya asignada a
    // dicho cargo. En caso contrario la operación quedará sin efecto.
    return ReasignarPersona(e, cargo, ci);
}

TipoRet ListarPersonas(Empresa &e, Cadena cargo) {
    // Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa.
    // Lista todas las personas asignadas al cargo de nombre cargo.
    return ListarPersonas(e, cargo);
}