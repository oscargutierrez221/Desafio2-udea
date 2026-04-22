#ifndef EQUIPO_H
#define EQUIPO_H
#include "jugador.h"
#include "resultados.h"
#include <string>

using namespace std;

class equipo {
private:
    string nombre;
    string pais;
    string confederacion;
    int ranking;
    string directorTecnico;
    resultados estadisticas;
    jugador* jugadores[26];
    int numJugadores;

public:
    equipo();
    equipo(const equipo &otro);
    equipo(string nombre, string pais, string confederacion, int ranking, string directorTecnico);

    string getNombre() const;
    string getPais() const;
    string getConfederacion() const;
    int getRanking() const;
    string getDirectorTecnico() const;

    resultados& getResultados();
    const resultados& getResultados() const;

    void agregarJugador(string nombre, string apellido, int camiseta,
                        int goles, int amarillas, int rojas, int minutos, int partidos, int asistencias);
    jugador* getJugador(int i) const;
    int getNumJugadores() const;

    void mostrarEstadisticas() const;
};

#endif // EQUIPO_H
