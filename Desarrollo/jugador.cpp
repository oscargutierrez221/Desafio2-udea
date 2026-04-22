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
  nombre = otro.nombre;
  apellido = otro.apellido;
  numeroCamiseta = otro.numeroCamiseta;
  partidosJugados = otro.partidosJugados;
  goles = otro.goles;
  asistencias = otro.asistencias;
  tarjetasAmarillas = otro.tarjetasAmarillas;
  tarjetasRojas = otro.tarjetasRojas;
  faltasCometidas = otro.faltasCometidas;
  minutosJugados = otro.minutosJugados;
}

jugador::~jugador()
{
    cout << "Destructor llamado" << endl;
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
  cout << "Nombre: " << nombre << " " << apellido << endl;
  cout << "Goles: " << goles << endl;
  cout << "Camiseta: " << numeroCamiseta << endl;
  cout << "Minutos jugados: " << minutosJugados << endl;
  cout << "Tarjetas amarillas: " << tarjetasAmarillas << endl;
  cout << "Tarjetas rojas: " << tarjetasRojas << endl;
  cout << "Faltas cometidas: " << faltasCometidas << endl;
  cout << "Asistencias: " << asistencias << endl;
  cout << "Partidos jugados: " << partidosJugados << endl;
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
  partidosJugados++;
  this->goles += goles;
  minutosJugados += minutos;
  asistencias += 0;
  tarjetasAmarillas += amarillas;
  tarjetasRojas += rojas;
  faltasCometidas += faltas;
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
