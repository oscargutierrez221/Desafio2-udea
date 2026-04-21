#include "partido.h"
#include <iostream>

using namespace std;

partido::partido()
{
    fecha          = "";
    hora           = "";
    sede           = "";
    Arbitro1 = "";
    Arbitro2 = "";
    Arbitro3 = "";
    equipo1        = nullptr;
    equipo2        = nullptr;
    jugado         = false;
    fueAProrroga   = false;
    ganador        = nullptr;
    posesionEquipo1 = 0.0;
    posesionEquipo2 = 0.0;

    convocadosEquipo1 = new jugador*[11];
    convocadosEquipo2 = new jugador*[11];

    for (int i = 0; i < 11; i++)
    {
        convocadosEquipo1[i] = nullptr;
        convocadosEquipo2[i] = nullptr;
    }
}

partido::partido(string fecha, string hora, string sede, string arbitro1, string arbitro2, string arbitro3, equipo* equipo1, equipo* equipo2)
{
    this->fecha          = fecha;
    this->hora           = hora;
    this->sede           = sede;
    this->Arbitro1 = arbitro1;
    this->Arbitro2 = arbitro2;
    this->Arbitro3 = arbitro3;
    this->equipo1        = equipo1;
    this->equipo2        = equipo2;
    jugado               = false;
    fueAProrroga         = false;
    ganador              = nullptr;
    posesionEquipo1      = 0.0;
    posesionEquipo2      = 0.0;

    convocadosEquipo1 = new jugador*[11];
    convocadosEquipo2 = new jugador*[11];

    for (int i = 0; i < 11; i++)
    {
        convocadosEquipo1[i] = nullptr;
        convocadosEquipo2[i] = nullptr;
    }
}

partido::partido(const partido& otro)
{
    fecha           = otro.fecha;
    hora            = otro.hora;
    sede            = otro.sede;
    Arbitro1  = otro.Arbitro1;
    Arbitro2  = otro.Arbitro2;
    Arbitro3  = otro.Arbitro3;
    equipo1         = otro.equipo1;
    equipo2         = otro.equipo2;
    jugado          = otro.jugado;
    fueAProrroga    = otro.fueAProrroga;
    ganador         = otro.ganador;
    statsEquipo1    = otro.statsEquipo1;
    statsEquipo2    = otro.statsEquipo2;
    posesionEquipo1 = otro.posesionEquipo1;
    posesionEquipo2 = otro.posesionEquipo2;

    convocadosEquipo1 = new jugador*[11];
    convocadosEquipo2 = new jugador*[11];

    for (int i = 0; i < 11; i++)
    {
        convocadosEquipo1[i] = otro.convocadosEquipo1[i];
        convocadosEquipo2[i] = otro.convocadosEquipo2[i];
    }
}

partido::~partido()
{
    delete[] convocadosEquipo1;
    delete[] convocadosEquipo2;
}

string partido::getFecha() const
{
    return fecha;
}


string partido::getHora() const
{
    return hora;
}

string partido::getSede() const
{
    return sede;
}

equipo* partido::getEquipo1() const
{
    return equipo1;
}

equipo* partido::getEquipo2() const
{
    return equipo2;
}

bool partido::fueJugado() const
{
    return jugado;
}

bool partido::resueltoEnProrroga() const
{
    return fueAProrroga;
}

equipo* partido::getGanador() const
{
    return ganador;
}

const resultados& partido::getStatsEquipo1() const
{
    return statsEquipo1;
}

const resultados& partido::getStatsEquipo2() const
{
    return statsEquipo2;
}

double partido::getPosesionEquipo1() const
{
    return posesionEquipo1;
}

double partido::getPosesionEquipo2() const
{
    return posesionEquipo2;
}

jugador* partido::getConvocadoEquipo1(int indice) const
{
    return convocadosEquipo1[indice];
}

jugador* partido::getConvocadoEquipo2(int indice) const
{
    return convocadosEquipo2[indice];
}

void partido::setFecha(string fecha)
{
    this->fecha = fecha;
}

void partido::setHora(string hora)
{
    this->hora = hora;
}

void partido::setSede(string sede)
{
    this->sede = sede;
}

void partido::setArbitros(string arbitro1, string arbitro2, string arbitro3)
{
    Arbitro1 = arbitro1;
    Arbitro2 = arbitro2;
    Arbitro3 = arbitro3;
}

void partido::setEquipo1(equipo* equipo1)
{
    this->equipo1 = equipo1;
}

void partido::setEquipo2(equipo* equipo2)
{
    this->equipo2 = equipo2;
}

void partido::simular()
{
    // Por implementar: lógica de simulación con la ecuación de goles esperados
}

void partido::mostrarResultado() const
{
    // Por implementar: Para esto debermos tener lista la clase de resultados
}
