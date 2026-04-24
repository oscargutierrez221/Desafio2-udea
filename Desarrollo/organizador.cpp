#include "organizador.h"
#include "jugador.h"
#include <iostream>

using namespace std;

organizador::organizador()
{
}

void organizador::ordenarEquiposPorRanking(equipo **equipos, int cantidad)
{
    int i;
    int j;

    for (i = 0; i < cantidad - 1; i = i + 1)
    {
        for (j = i + 1; j < cantidad; j = j + 1)
        {
            if (equipos[j] != nullptr && equipos[i] != nullptr)
            {
                if (equipos[j]->getRanking() > equipos[i]->getRanking())
                {
                    equipo *temp = equipos[i];
                    equipos[i] = equipos[j];
                    equipos[j] = temp;
                }
            }
        }
    }
}

bool organizador::validarRestriccionesGrupos(equipo ***grupos, int numGrupos, int equiposPorGrupo)
{
    int g;
    int i;

    for (g = 0; g < numGrupos; g = g + 1)
    {
        int uefa = 0;

        for (i = 0; i < equiposPorGrupo; i = i + 1)
        {
            if (grupos[g][i] != nullptr)
            {
                if (grupos[g][i]->getConfederacion() == "UEFA")
                {
                    uefa = uefa + 1;
                }
            }
        }

        if (uefa > 2)
        {
            return false;
        }
    }

    return true;
}

void organizador::asignarFechasYSedes(partido **partidos, int numPartidos)
{
    string sedes[] = {"Estadio Azteca", "AT&T Stadium", "SoFi Stadium",
                      "Mercedes-Benz", "MetLife Stadium", "NRG Stadium",
                      "Lusail Stadium", "Al Bayt", "Al Janoub"};
    int numSedes = 9;
    int dia = 12;
    int mes = 6;
    int sedeIndex = 0;
    int i;

    for (i = 0; i < numPartidos; i = i + 1)
    {
        if (partidos[i] != nullptr)
        {
            string fecha = to_string(dia) + "/" + to_string(mes) + "/2026";
            string hora;

            if (i % 2 == 0)
            {
                hora = "14:00";
            }
            else
            {
                hora = "20:00";
            }

            partidos[i]->setFecha(fecha);
            partidos[i]->setHora(hora);
            partidos[i]->setSede(sedes[sedeIndex % numSedes]);
            sedeIndex = sedeIndex + 1;

            if (sedeIndex % 3 == 0)
            {
                dia = dia + 1;
            }
        }
    }
}

void organizador::resolverEmpateEliminatoria(partido *p)
{
    if (p == nullptr)
    {
        return;
    }

    int goles1 = p->getStatsEquipo1().getGolesFavor();
    int goles2 = p->getStatsEquipo2().getGolesFavor();

    if (goles1 == goles2)
    {
        int ranking1 = p->getEquipo1()->getRanking();
        int ranking2 = p->getEquipo2()->getRanking();

        if (ranking1 > ranking2)
        {
            p->setGanador(p->getEquipo1());
        }
        else
        {
            p->setGanador(p->getEquipo2());
        }
    }
}

equipo *organizador::obtenerGanadorReal(partido *p)
{
    if (p == nullptr)
    {
        return nullptr;
    }

    if (p->getGanador() != nullptr)
    {
        return p->getGanador();
    }

    int goles1 = p->getStatsEquipo1().getGolesFavor();
    int goles2 = p->getStatsEquipo2().getGolesFavor();

    if (goles1 > goles2)
    {
        return p->getEquipo1();
    }

    if (goles2 > goles1)
    {
        return p->getEquipo2();
    }

    return nullptr;
}

void organizador::mostrarReporteFinal(equipo **equipos, int numEquipos, partido **partidos, int numPartidos, equipo *campeon)
{
    cout << "\n=== REPORTE FINAL DEL MUNDIAL ===" << endl;

    if (campeon != nullptr)
    {
        cout << "CAMPEON: " << campeon->getNombre() << endl;
    }

    int maxGoles = -1;
    equipo *maxEquipo = nullptr;
    int i;
    int j;

    for (i = 0; i < numEquipos; i = i + 1)
    {
        if (equipos[i] != nullptr)
        {
            int gf = equipos[i]->getResultados().getGolesFavor();

            if (gf > maxGoles)
            {
                maxGoles = gf;
                maxEquipo = equipos[i];
            }
        }
    }

    if (maxEquipo != nullptr)
    {
        cout << "Equipo mas goleador: " << maxEquipo->getNombre() << " con " << maxGoles << " goles" << endl;
    }

    // Buscar maximo goleador individual
    int maxGolesJugador = -1;
    jugador *maxGoleador = nullptr;
    string nombreEquipoGoleador = "";

    for (i = 0; i < numEquipos; i = i + 1)
    {
        if (equipos[i] != nullptr)
        {
            for (j = 0; j < equipos[i]->getNumJugadores(); j = j + 1)
            {
                jugador *jug = equipos[i]->getJugador(j);
                if (jug != nullptr)
                {
                    int golesJug = jug->getGoles();
                    if (golesJug > maxGolesJugador)
                    {
                        maxGolesJugador = golesJug;
                        maxGoleador = jug;
                        nombreEquipoGoleador = equipos[i]->getNombre();
                    }
                }
            }
        }
    }

    if (maxGoleador != nullptr)
    {
        cout << "Maximo goleador: " << maxGoleador->getNombre() << " " << maxGoleador->getApellido() << " (" << nombreEquipoGoleador << ") con " << maxGolesJugador << " goles" << endl;
    }

    cout << "===================================" << endl;
}

void organizador::medirRecursos(int iteracionesTotales, int numEquipos, int numPartidos, int numJugadores)
{
    cout << "\n=== MEDICION DE RECURSOS ===" << endl;
    cout << "Iteraciones totales: " << iteracionesTotales << endl;

    int memoriaEquipos = numEquipos * 200;
    int memoriaPartidos = numPartidos * 300;
    int memoriaJugadores = numJugadores * 150;
    int totalMemoria = memoriaEquipos + memoriaPartidos + memoriaJugadores;

    cout << "Memoria estimada: " << totalMemoria << " bytes" << endl;
}
