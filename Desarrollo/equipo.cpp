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
    numJugadores = 0;
}

equipo::equipo(const equipo &otro)
{
    nombre = otro.nombre;
    pais = otro.pais;
    confederacion = otro.confederacion;
    ranking = otro.ranking;
    directorTecnico = otro.directorTecnico;
    numJugadores = otro.numJugadores;

    int i;
    for (i = 0; i < numJugadores; i = i + 1)
    {
        jugadores[i] = otro.jugadores[i];
    }
}

equipo::equipo(string nombre, string pais, string confederacion, int ranking, string directorTecnico)
{
    this->nombre = nombre;
    this->pais = pais;
    this->confederacion = confederacion;
    this->ranking = ranking;
    this->directorTecnico = directorTecnico;
    numJugadores = 0;
}

equipo::~equipo()
{
    int i;
    for (i = 0; i < numJugadores; i = i + 1)
    {
        delete jugadores[i];
        jugadores[i] = nullptr;
    }
}

string equipo::getNombre() const
{
    return nombre;
}

string equipo::getConfederacion() const
{
    return confederacion;
}

int equipo::getRanking() const
{
    return ranking;
}

resultados &equipo::getResultados()
{
    return estadisticas;
}

void equipo::agregarJugador(string nombre, string apellido, int camiseta, int goles, int amarillas, int rojas, int minutos, int partidos, int asistencias)
{
    if (numJugadores < 26)
    {
        jugadores[numJugadores] = new jugador(nombre, apellido, camiseta);
        jugadores[numJugadores]->cargarEstadisticas(goles, partidos, minutos, asistencias, amarillas, rojas, 0);
        numJugadores = numJugadores + 1;
    }
}

jugador *equipo::getJugador(int i) const
{
    return jugadores[i];
}

int equipo::getNumJugadores() const
{
    return numJugadores;
}

bool equipo::operator==(const equipo& otro) const
{
    return this->nombre == otro.nombre;
}
