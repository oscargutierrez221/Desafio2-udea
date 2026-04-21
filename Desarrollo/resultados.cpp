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

int resultados::getGolesContra() const
{
    return golesContra;
}

int resultados::getPartidosGanados() const
{
    return partidosGanados;
}

int resultados::getPartidosEmpatados() const
{
    return partidosEmpatados;
}

int resultados::getPartidosPerdidos() const
{
    return partidosPerdidos;
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

void resultados::setGolesFavor(int golesFavor)
{
    this->golesFavor = golesFavor;
}

void resultados::setGolesContra(int golesContra)
{
    this->golesContra = golesContra;
}

void resultados::setPartidosGanados(int partidosGanados)
{
    this->partidosGanados = partidosGanados;
}

void resultados::setPartidosEmpatados(int partidosEmpatados)
{
    this->partidosEmpatados = partidosEmpatados;
}

void resultados::setPartidosPerdidos(int partidosPerdidos)
{
    this->partidosPerdidos = partidosPerdidos;
}

void resultados::setTarjetasAmarillas(int tarjetasAmarillas)
{
    this->tarjetasAmarillas = tarjetasAmarillas;
}

void resultados::setTarjetasRojas(int tarjetasRojas)
{
    this->tarjetasRojas = tarjetasRojas;
}

void resultados::setFaltasCometidas(int faltasCometidas)
{
    this->faltasCometidas = faltasCometidas;
}

void resultados::actualizarDesdePartido(int golesFavor, int golesContra, int tarjetasAmarillas, int tarjetasRojas, int faltasCometidas)
{
    this->golesFavor        += golesFavor;
    this->golesContra       += golesContra;
    this->tarjetasAmarillas += tarjetasAmarillas;
    this->tarjetasRojas     += tarjetasRojas;
    this->faltasCometidas   += faltasCometidas;

    if (golesFavor > golesContra) {
        this->partidosGanados++;
    }
    else if (golesFavor == golesContra) {
        this->partidosEmpatados++;
    }
    else {
        this->partidosPerdidos++;
    }
}

int resultados::calcularDiferenciaGoles() const
{
    return golesFavor - golesContra;
}

int resultados::calcularPuntos() const
{
    if (golesFavor > golesContra) {
        return 3;
    }
    else if (golesFavor == golesContra) {
        return 1;
    }
    else {
        return 0;
    }
}

void resultados::resetear()
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

void resultados::mostrar() const
{
    cout << "Partidos: " << partidosGanados << "G / " << partidosEmpatados << "E / " << partidosPerdidos << "P" << endl;
    cout << "Goles a favor: " << golesFavor << " | Goles en contra: " << golesContra << " | Diferencia: " << calcularDiferenciaGoles() << endl;
    cout << "Tarjetas amarillas: " << tarjetasAmarillas << " | Tarjetas rojas: " << tarjetasRojas << endl;
    cout << "Faltas cometidas: " << faltasCometidas << endl;
}
