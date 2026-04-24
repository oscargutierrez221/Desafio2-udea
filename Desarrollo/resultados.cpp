#include "resultados.h"
#include <iostream>

using namespace std;

resultados::resultados()
{
    golesFavor = 0;
    golesContra = 0;
    partidosGanados = 0;
    partidosEmpatados = 0;
    partidosPerdidos = 0;
    tarjetasAmarillas = 0;
    tarjetasRojas = 0;
    faltasCometidas = 0;
}

resultados::resultados(const resultados &otro)
{
    golesFavor = otro.golesFavor;
    golesContra = otro.golesContra;
    partidosGanados = otro.partidosGanados;
    partidosEmpatados = otro.partidosEmpatados;
    partidosPerdidos = otro.partidosPerdidos;
    tarjetasAmarillas = otro.tarjetasAmarillas;
    tarjetasRojas = otro.tarjetasRojas;
    faltasCometidas = otro.faltasCometidas;
}

int resultados::getGolesFavor() const
{
    return golesFavor;
}

int resultados::getTarjetasAmarillas() const
{
    return tarjetasAmarillas;
}

int resultados::getTarjetasRojas() const
{
    return tarjetasRojas;
}

int resultados::getFaltasCometidas() const
{
    return faltasCometidas;
}

void resultados::actualizarDesdePartido(int golesFavor, int golesContra, int tarjetasAmarillas, int tarjetasRojas, int faltasCometidas)
{
    this->golesFavor = this->golesFavor + golesFavor;
    this->golesContra = this->golesContra + golesContra;
    this->tarjetasAmarillas = this->tarjetasAmarillas + tarjetasAmarillas;
    this->tarjetasRojas = this->tarjetasRojas + tarjetasRojas;
    this->faltasCometidas = this->faltasCometidas + faltasCometidas;

    if (golesFavor > golesContra)
    {
        this->partidosGanados = this->partidosGanados + 1;
    }
    else if (golesFavor == golesContra)
    {
        this->partidosEmpatados = this->partidosEmpatados + 1;
    }
    else
    {
        this->partidosPerdidos = this->partidosPerdidos + 1;
    }
}

int resultados::calcularDiferenciaGoles() const
{
    return golesFavor - golesContra;
}

int resultados::calcularPuntos() const
{
    if (golesFavor > golesContra)
    {
        return 3;
    }
    else if (golesFavor == golesContra)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void resultados::mostrar() const
{
    cout << "Partidos: " << partidosGanados << "G / " << partidosEmpatados << "E / " << partidosPerdidos << "P" << endl;
    cout << "Goles a favor: " << golesFavor << " | Goles en contra: " << golesContra << " | Diferencia: " << calcularDiferenciaGoles() << endl;
    cout << "Tarjetas amarillas: " << tarjetasAmarillas << " | Tarjetas rojas: " << tarjetasRojas << endl;
    cout << "Faltas cometidas: " << faltasCometidas << endl;
}

