#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

using namespace std;

class jugador {
private:
    string nombre;
    string apellido;
    int numeroCamiseta;

    int partidosJugados;
    int goles;
    int asistencias;
    int tarjetasAmarillas;
    int tarjetasRojas;
    int faltasCometidas;
    int minutosJugados;

public:
    jugador(string nombre, string apellido, int numeroCamiseta);

    jugador(const jugador &otro);

    ~jugador();

    string getNombre() const;
    string getApellido() const;
    int getNumeroCamiseta() const;
    void mostrarEstadisticas() const;

    void setNumeroCamiseta(int numero);
    void setNombre(string nuevoNombre);
    void setApellido(string nuevoApellido);

    void actualizarEstadisticasPartido(int goles, int amarillas, int rojas, int faltas, int minutos);
    void cargarEstadisticas(int goles, int partidos, int minutos, int asistencias, int amarillas, int rojas, int faltas);

    int getGoles() const;

};

#endif // JUGADOR_H
