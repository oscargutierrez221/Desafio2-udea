#ifndef EQUIPO_H
#define EQUIPO_H
#include "jugador.h"
#include "resultados.h"
#include <string>

class equipo {
private:
    std::string nombre;
    std::string pais;
    std::string confederacion;
    int ranking;
    std::string directorTecnico;
    resultados estadisticas;
    jugador* jugadores[26];
    int numJugadores;

public:
    equipo();
    equipo(const equipo &otro);
    ~equipo();
    equipo(std::string nombre, std::string pais, std::string confederacion, int ranking, std::string directorTecnico);

    std::string getNombre() const;
    std::string getConfederacion() const;
    int getRanking() const;

    resultados& getResultados();

    void agregarJugador(std::string nombre, std::string apellido, int camiseta, int goles, int amarillas, int rojas, int minutos, int partidos, int asistencias);
    jugador* getJugador(int i) const;
    int getNumJugadores() const;
};

#endif // EQUIPO_H
