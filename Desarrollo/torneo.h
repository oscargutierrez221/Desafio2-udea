#ifndef TORNEO_H
#define TORNEO_H

#include "equipo.h"
#include "partido.h"
#include <string>

class torneo {
private:
  string fechaInicio;
  int numEquipos;         // 48
  int numGrupos;          // 12
  int equiposPorGrupo;    // 4
  int jugadoresPorEquipo; // 26

  equipo **equipos;

  // --- Bombos del sorteo (4 bombos de 12 equipos) ---
  equipo ***bombos;

  // --- Grupos (12 grupos de 4 equipos) ---
  equipo ***grupos;

  // --- Partidos (104 en total) ---
  partido **partidos;
  int numPartidos;

  // --- Equipo campeón ---
  equipo *campeon;

public:
  torneo();
  torneo(string fechaInicio, int numEquipos, int numGrupos, int equiposPorGrupo,
         int jugadoresPorEquipo);
  torneo(const torneo &otro);
  ~torneo();

  string getFechaInicio() const;
  int getNumEquipos() const;
  int getNumGrupos() const;
  int getNumPartidos() const;
  equipo *getEquipo(int indice) const;
  equipo *getEquipoGrupo(int grupo, int posicion) const;
  partido *getPartido(int indice) const;
  equipo *getCampeon() const;

  void setFechaInicio(string fechaInicio);
  void setCampeon(equipo *campeon);

  void cargarEquipos();
  void conformarBombos();
  void conformarGrupos();
  void simularEtapaGrupos();
  void simularR16();
  void simularR8();
  void simularCuartos();
  void simularSemifinal();
  void simularFinal();

  void mostrarRankingFinal() const;
  void mostrarMaximoGoleadorCampeon() const;
  void mostrarTresMayoresGoleadores() const;
  void mostrarEquipoMasGoleador() const;
  void mostrarConfederacionPorEtapa() const;
};

#endif // TORNEO_H
