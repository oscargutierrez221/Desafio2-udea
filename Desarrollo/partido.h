#ifndef PARTIDO_H
#define PARTIDO_H
#include "equipo.h"
#include "jugador.h"
#include "resultados.h"
#include <string>

using namespace std;

class partido
{
private:
    // --- Información general ---
    string fecha;
    string hora;
    string sede;
    string Arbitro1;
    string Arbitro2;
    string Arbitro3;

    // --- Equipos participantes ---
    equipo* equipo1;
    equipo* equipo2;

    // --- Resultado ---
    bool    jugado;
    bool    fueAProrroga;
    equipo* ganador;

    // --- Estadísticas del partido por equipo (goles, tarjetas, faltas) ---
    resultados statsEquipo1;
    resultados statsEquipo2;

    // --- Posesión del balón por equipo (%) ---
    double posesionEquipo1;
    double posesionEquipo2;

    // --- 11 jugadores convocados por equipo ---
    jugador** convocadosEquipo1;
    jugador** convocadosEquipo2;

public:
    partido();
    partido(string fecha, string hora, string sede, string arbitro1, string arbitro2, string arbitro3, equipo* equipo1, equipo* equipo2);
    partido(const partido& otro);
    ~partido();

    // Getters de información general
    string  getFecha() const;
    string  getHora() const;
    string  getSede() const;
    equipo* getEquipo1() const;
    equipo* getEquipo2() const;
    bool    fueJugado() const;
    bool    resueltoEnProrroga() const;
    equipo* getGanador() const;

    // Getters de estadísticas
    const resultados& getStatsEquipo1() const;
    const resultados& getStatsEquipo2() const;
    double getPosesionEquipo1() const;
    double getPosesionEquipo2() const;

    // Getters de convocados
    jugador* getConvocadoEquipo1(int indice) const;
    jugador* getConvocadoEquipo2(int indice) const;

    // Setters de información general
    void setFecha(string fecha);
    void setHora(string hora);
    void setSede(string sede);
    void setArbitros(string arbitro1, string arbitro2, string arbitro3);
    void setEquipo1(equipo* equipo1);
    void setEquipo2(equipo* equipo2);

    // Simulación y presentación
    void simular();
    void mostrarResultado() const;
};

#endif // PARTIDO_H
