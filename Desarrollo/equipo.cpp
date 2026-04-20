#include "equipo.h"
#include <iostream>

using namespace std;

equipo::equipo()
{
    nombre = "";
    pais = "";
    confederacion = "";
    ranking = 0;
    directorTecnico = "";
}

equipo::equipo(const equipo &otro)
{
    nombre          = otro.nombre;
    pais            = otro.pais;
    confederacion   = otro.confederacion;
    ranking         = otro.ranking;
    directorTecnico = otro.directorTecnico;
    estadisticas    = otro.estadisticas;
}

equipo::equipo(string nombre, string pais, string confederacion, int ranking, string directorTecnico)
{
    this->nombre          = nombre;
    this->pais            = pais;
    this->confederacion   = confederacion;
    this->ranking         = ranking;
    this->directorTecnico = directorTecnico;
}

string equipo::getNombre() const
{
    return nombre;
}

string equipo::getPais() const
{
    return pais;
}

string equipo::getConfederacion() const
{
    return confederacion;
}

int equipo::getRanking() const
{
    return ranking;
}

string equipo::getDirectorTecnico() const
{
    return directorTecnico;
}

resultados& equipo::getResultados()
{
    return estadisticas;
}

const resultados& equipo::getResultados() const
{
    return estadisticas;
}

void equipo::mostrarEstadisticas() const
{
    cout << "=== " << nombre << " ===" << endl;
    estadisticas.mostrar();
}
