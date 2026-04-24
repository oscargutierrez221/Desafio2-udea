#ifndef TORNEO_H
#define TORNEO_H

#include "equipo.h"
#include "partido.h"

class torneo {
private:
  int numEquipos;
  int numGrupos;
  int equiposPorGrupo;

  equipo **equipos;
  equipo ***bombos;
  equipo ***grupos;

  partido **partidos;
  int numPartidos;

  equipo *campeon;

public:
  torneo();
  ~torneo();

  void cargarEquipos();
  void conformarBombos();
  void conformarGrupos();
  void simularEtapaGrupos();
  void simularR16();
  void simularR8();
  void simularCuartos();
  void simularSemifinal();
  void simularFinal();

  void iniciarTorneo();
  void ordenarGrupos();
  void verificarAvanzeFase(int partidoActual);
  void determinarCampeon();

  equipo** getEquipos() { return equipos; }
  partido** getPartidos() { return partidos; }
  int getNumPartidos() { return numPartidos; }
  equipo* getCampeon() { return campeon; }
};

#endif // TORNEO_H
