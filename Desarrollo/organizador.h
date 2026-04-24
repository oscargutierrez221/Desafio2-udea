#ifndef ORGANIZADOR_H
#define ORGANIZADOR_H

#include "equipo.h"
#include "partido.h"


using namespace std;

class organizador {
public:
  organizador();

  static void ordenarEquiposPorRanking(equipo **equipos, int cantidad);
  static bool validarRestriccionesGrupos(equipo ***grupos, int numGrupos, int equiposPorGrupo);
  static void asignarFechasYSedes(partido **partidos, int numPartidos);
  static void resolverEmpateEliminatoria(partido *p);
  static equipo *obtenerGanadorReal(partido *p);
  static void mostrarReporteFinal(equipo **equipos, int numEquipos, partido **partidos, int numPartidos, equipo *campeon);
  static void medirRecursos(int iteracionesTotales, int numEquipos, int numPartidos, int numJugadores);
};

#endif // ORGANIZADOR_H
