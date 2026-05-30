#include "jugador.h"
#include <string>

jugador::jugador(std::string nombre, std::string apellido, int numeroCamiseta)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->numeroCamiseta = numeroCamiseta;
}

jugador::jugador(const jugador &otro)
{
    nombre = otro.nombre;
    apellido = otro.apellido;
    numeroCamiseta = otro.numeroCamiseta;
    goles = otro.goles;
    asistencias = otro.asistencias;
    tarjetasAmarillas = otro.tarjetasAmarillas;
    tarjetasRojas = otro.tarjetasRojas;
    faltasCometidas = otro.faltasCometidas;
    minutosJugados = otro.minutosJugados;
    partidosJugados = otro.partidosJugados;
}

jugador::~jugador()
{
}

void jugador::actualizarEstadisticasPartido(int goles, int amarillas, int rojas, int faltas, int minutos)
{
    partidosJugados = partidosJugados + 1;
    this->goles = this->goles + goles;
    minutosJugados = minutosJugados + minutos;
    asistencias = asistencias + 0;
    tarjetasAmarillas = tarjetasAmarillas + amarillas;
    tarjetasRojas = tarjetasRojas + rojas;
    faltasCometidas = faltasCometidas + faltas;
}

void jugador::cargarEstadisticas(int goles, int partidos, int minutos, int asistencias, int amarillas, int rojas, int faltas)
{
    this->goles = goles;
    this->partidosJugados = partidos;
    this->minutosJugados = minutos;
    this->asistencias = asistencias;
    this->tarjetasAmarillas = amarillas;
    this->tarjetasRojas = rojas;
    this->faltasCometidas = faltas;
}

std::string jugador::getNombre() const
{
    return nombre;
}

std::string jugador::getApellido() const
{
    return apellido;
}

int jugador::getGoles() const
{
    return goles;
}
