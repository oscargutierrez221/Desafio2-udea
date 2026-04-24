#include "partido.h"
#include <iostream>

using namespace std;

partido::partido()
{
    fecha = "";
    hora = "";
    sede = "";
    Arbitro1 = "";
    Arbitro2 = "";
    Arbitro3 = "";
    equipo1 = nullptr;
    equipo2 = nullptr;
    jugado = false;
    fueAProrroga = false;
    ganador = nullptr;
    posesionEquipo1 = 0.0;
    posesionEquipo2 = 0.0;

    convocadosEquipo1 = new jugador *[11];
    convocadosEquipo2 = new jugador *[11];

    int i;
    for (i = 0; i < 11; i = i + 1)
    {
        convocadosEquipo1[i] = nullptr;
        convocadosEquipo2[i] = nullptr;
    }
}

partido::partido(string fecha, string hora, string sede, string arbitro1, string arbitro2, string arbitro3, equipo *equipo1, equipo *equipo2)
{
    this->fecha = fecha;
    this->hora = hora;
    this->sede = sede;
    this->Arbitro1 = arbitro1;
    this->Arbitro2 = arbitro2;
    this->Arbitro3 = arbitro3;
    this->equipo1 = equipo1;
    this->equipo2 = equipo2;
    jugado = false;
    fueAProrroga = false;
    ganador = nullptr;
    posesionEquipo1 = 0.0;
    posesionEquipo2 = 0.0;

    convocadosEquipo1 = new jugador *[11];
    convocadosEquipo2 = new jugador *[11];

    int i;
    for (i = 0; i < 11; i = i + 1)
    {
        convocadosEquipo1[i] = nullptr;
        convocadosEquipo2[i] = nullptr;
    }
}

partido::partido(const partido &otro)
{
    fecha = otro.fecha;
    hora = otro.hora;
    sede = otro.sede;
    Arbitro1 = otro.Arbitro1;
    Arbitro2 = otro.Arbitro2;
    Arbitro3 = otro.Arbitro3;
    equipo1 = otro.equipo1;
    equipo2 = otro.equipo2;
    jugado = otro.jugado;
    fueAProrroga = otro.fueAProrroga;
    ganador = otro.ganador;
    statsEquipo1 = otro.statsEquipo1;
    statsEquipo2 = otro.statsEquipo2;
    posesionEquipo1 = otro.posesionEquipo1;
    posesionEquipo2 = otro.posesionEquipo2;

    convocadosEquipo1 = new jugador *[11];
    convocadosEquipo2 = new jugador *[11];

    int i;
    for (i = 0; i < 11; i = i + 1)
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

equipo *partido::getEquipo1() const
{
    return equipo1;
}

equipo *partido::getEquipo2() const
{
    return equipo2;
}

const resultados &partido::getStatsEquipo1() const
{
    return statsEquipo1;
}

const resultados &partido::getStatsEquipo2() const
{
    return statsEquipo2;
}

equipo *partido::getGanador() const
{
    return ganador;
}

void partido::setGanador(equipo *g)
{
    ganador = g;
}

void partido::setFecha(string f)
{
    fecha = f;
}

void partido::setHora(string h)
{
    hora = h;
}

void partido::setSede(string s)
{
    sede = s;
}

void partido::simular()
{
    // Numeros aleatorios entre 0 y 3 para goles
    int golesEq1 = rand() % 4;
    int golesEq2 = rand() % 4;

    int amarillasEq1 = 0;
    int rojasEq1 = 0;
    int faltasEq1 = 0;
    int amarillasEq2 = 0;
    int rojasEq2 = 0;
    int faltasEq2 = 0;

    int i;
    int golesJug;
    int amarilla;
    int roja;
    int faltas;
    int minutos;
    jugador *jug;

    for (i = 0; i < equipo1->getNumJugadores(); i = i + 1)
    {
        jug = equipo1->getJugador(i);
        if (jug != nullptr)
        {
            golesJug = 0;
            if (i < golesEq1)
            {
                golesJug = 1;
            }

            // Amarilla aleatoria (probabilidad 1/7)
            if ((rand() % 7) == 0)
            {
                amarilla = 1;
            }
            else
            {
                amarilla = 0;
            }

            // Roja aleatoria (probabilidad 1/25)
            if ((rand() % 25) == 0)
            {
                roja = 1;
            }
            else
            {
                roja = 0;
            }

            faltas = rand() % 3;
            minutos = 90;

            jug->actualizarEstadisticasPartido(golesJug, amarilla, roja, faltas, minutos);

            amarillasEq1 = amarillasEq1 + amarilla;
            rojasEq1 = rojasEq1 + roja;
            faltasEq1 = faltasEq1 + faltas;
        }
    }

    for (i = 0; i < equipo2->getNumJugadores(); i = i + 1)
    {
        jug = equipo2->getJugador(i);
        if (jug != nullptr)
        {
            golesJug = 0;
            if (i < golesEq2)
            {
                golesJug = 1;
            }

            // Amarilla aleatoria (probabilidad 1/8)
            if ((rand() % 8) == 0)
            {
                amarilla = 1;
            }
            else
            {
                amarilla = 0;
            }

            // Roja aleatoria (probabilidad 1/30)
            if ((rand() % 30) == 0)
            {
                roja = 1;
            }
            else
            {
                roja = 0;
            }

            faltas = rand() % 4;
            minutos = 90;

            jug->actualizarEstadisticasPartido(golesJug, amarilla, roja, faltas, minutos);

            amarillasEq2 = amarillasEq2 + amarilla;
            rojasEq2 = rojasEq2 + roja;
            faltasEq2 = faltasEq2 + faltas;
        }
    }

    statsEquipo1.actualizarDesdePartido(golesEq1, golesEq2, amarillasEq1, rojasEq1, faltasEq1);
    statsEquipo2.actualizarDesdePartido(golesEq2, golesEq1, amarillasEq2, rojasEq2, faltasEq2);

    equipo1->getResultados().actualizarDesdePartido(golesEq1, golesEq2, amarillasEq1, rojasEq1, faltasEq1);
    equipo2->getResultados().actualizarDesdePartido(golesEq2, golesEq1, amarillasEq2, rojasEq2, faltasEq2);

    if (golesEq1 > golesEq2)
    {
        ganador = equipo1;
    }
    else if (golesEq2 > golesEq1)
    {
        ganador = equipo2;
    }
    else
    {
        ganador = nullptr;
    }

    jugado = true;
}

void partido::mostrarResultado() const
{
    cout << "---------------------------------" << endl;
    cout << "Fecha: " << fecha << " | Hora: " << hora << endl;
    cout << "Sede: " << sede << endl;
    cout << "" << endl;
    cout << equipo1->getNombre() << " " << statsEquipo1.getGolesFavor() << " - " << statsEquipo2.getGolesFavor() << " " << equipo2->getNombre() << endl;
    cout << "" << endl;
    cout << "Estadisticas del partido:" << endl;
    cout << "  " << equipo1->getNombre() << ": " << statsEquipo1.getTarjetasAmarillas() << " amarillas, " << statsEquipo1.getTarjetasRojas() << " rojas, " << statsEquipo1.getFaltasCometidas() << " faltas" << endl;
    cout << "  " << equipo2->getNombre() << ": " << statsEquipo2.getTarjetasAmarillas() << " amarillas, " << statsEquipo2.getTarjetasRojas() << " rojas, " << statsEquipo2.getFaltasCometidas() << " faltas" << endl;
    cout << "" << endl;

    if (ganador != nullptr)
    {
        cout << "Ganador: " << ganador->getNombre() << endl;
    }
    else
    {
        cout << "Resultado: Empate" << endl;
    }

    cout << "---------------------------------" << endl;
}
