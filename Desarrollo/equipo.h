#ifndef EQUIPO_H
#define EQUIPO_H
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

    void mostrarEstadisticas() const;
};

#endif // EQUIPO_H
