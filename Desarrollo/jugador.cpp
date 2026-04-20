#include "jugador.h"
#include <iostream>
#include <string>

using namespace std;

jugador::jugador(string nombre, string apellido, int numeroCamiseta)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->numeroCamiseta = numeroCamiseta;
}

jugador::jugador(const jugador &otro)
{
    nombre             = otro.nombre;
    apellido           = otro.apellido;
    numeroCamiseta     = otro.numeroCamiseta;
    partidosJugados    = otro.partidosJugados;
    goles              = otro.goles;
    asistencias        = otro.asistencias;
    tarjetasAmarillas  = otro.tarjetasAmarillas;
    tarjetasRojas      = otro.tarjetasRojas;
    faltasCometidas    = otro.faltasCometidas;
    minutosJugados     = otro.minutosJugados;
}

jugador::~jugador()
{
    cout << "Destructor llamado para: " << nombre << " " << apellido << endl;
}

string jugador::getNombre() const
{
    return nombre;
}

string jugador::getApellido() const
{
    return apellido;
}

int jugador::getNumeroCamiseta() const
{
    return numeroCamiseta;
}

void jugador::mostrarEstadisticas() const
{
    cout << "El jugador " << nombre << " " << apellido << " tiene " << goles             << " goles."            << endl;
    cout << "El jugador " << nombre << " " << apellido << " tiene " << partidosJugados   << " partidos jugados." << endl;
    cout << "El jugador " << nombre << " " << apellido << " tiene " << minutosJugados    << " minutos jugados."  << endl;
    cout << "El jugador " << nombre << " " << apellido << " tiene " << asistencias       << " asistencias."      << endl;
    cout << "El jugador " << nombre << " " << apellido << " tiene " << tarjetasAmarillas << " tarjetas amarillas." << endl;
    cout << "El jugador " << nombre << " " << apellido << " tiene " << tarjetasRojas     << " tarjetas rojas."    << endl;
    cout << "El jugador " << nombre << " " << apellido << " tiene " << faltasCometidas   << " faltas cometidas."  << endl;
}

void jugador::setNumeroCamiseta(int numero)
{
    numeroCamiseta = numero;
}

void jugador::setNombre(string nuevonombre)
{
    nombre = nuevonombre;
}

void jugador::setApellido(string nuevoApellido)
{
    apellido = nuevoApellido;
}

void jugador::actualizarEstadisticasPartido(int goles, int amarillas, int rojas, int faltas, int minutos)
{
    partidosJugados    ++;
    this->goles        += goles;
    minutosJugados     += minutos;
    asistencias        += 0;
    tarjetasAmarillas  += amarillas;
    tarjetasRojas      += rojas;
    faltasCometidas    += faltas;
}
