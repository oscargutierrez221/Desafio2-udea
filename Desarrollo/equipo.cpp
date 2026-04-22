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
    estadisticas = otro.estadisticas;
    numJugadores = otro.numJugadores;
    for (int i = 0; i < numJugadores; i++)
        jugadores[i] = otro.jugadores[i];
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

void equipo::agregarJugador(string nombre, string apellido, int camiseta, int goles, int amarillas, int rojas, int minutos, int partidos, int asistencias)
{
    if (numJugadores < 26) {
        jugadores[numJugadores] = new jugador(nombre, apellido, camiseta);
        jugadores[numJugadores]->cargarEstadisticas(goles, partidos, minutos, asistencias, amarillas, rojas, 0);
        jugadores[numJugadores]->mostrarEstadisticas();
        numJugadores++;
    }
}

jugador* equipo::getJugador(int i) const
{
    return jugadores[i];
}

int equipo::getNumJugadores() const
{
    return numJugadores;
}
