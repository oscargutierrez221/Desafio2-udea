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

    equipo* equipo1;
    equipo* equipo2;

    bool    jugado;
    equipo* ganador;

    resultados statsEquipo1;
    resultados statsEquipo2;

public:
    partido();
    partido(string fecha, string hora, string sede, equipo* equipo1, equipo* equipo2);
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
