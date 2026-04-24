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
    string fecha;
    string hora;
    string sede;
    string Arbitro1;
    string Arbitro2;
    string Arbitro3;

    equipo* equipo1;
    equipo* equipo2;

    bool    jugado;
    bool    fueAProrroga;
    equipo* ganador;

    resultados statsEquipo1;
    resultados statsEquipo2;

    double posesionEquipo1;
    double posesionEquipo2;

    jugador** convocadosEquipo1;
    jugador** convocadosEquipo2;

public:
    partido();
    partido(string fecha, string hora, string sede, string arbitro1, string arbitro2, string arbitro3, equipo* equipo1, equipo* equipo2);
    partido(const partido& otro);
    ~partido();

    equipo* getEquipo1() const;
    equipo* getEquipo2() const;
    const resultados& getStatsEquipo1() const;
    const resultados& getStatsEquipo2() const;
    equipo* getGanador() const;
    void setGanador(equipo* g);
    void setFecha(string f);
    void setHora(string h);
    void setSede(string s);

    void simular();
    void mostrarResultado() const;
};

#endif // PARTIDO_H
