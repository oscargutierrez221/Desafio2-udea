#ifndef RESULTADOS_H
#define RESULTADOS_H


class resultados {
private:
    int golesFavor;
    int golesContra;
    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;
    int tarjetasAmarillas;
    int tarjetasRojas;
    int faltasCometidas;

public:
    resultados();
    resultados(const resultados &otro);

    int getGolesFavor() const;
    int getGolesContra() const;
    int getPartidosGanados() const;
    int getPartidosEmpatados() const;
    int getPartidosPerdidos() const;
    int getTarjetasAmarillas() const;
    int getTarjetasRojas() const;
    int getFaltasCometidas() const;

    void setGolesFavor(int golesFavor);
    void setGolesContra(int golesContra);
    void setPartidosGanados(int partidosGanados);
    void setPartidosEmpatados(int partidosEmpatados);
    void setPartidosPerdidos(int partidosPerdidos);
    void setTarjetasAmarillas(int tarjetasAmarillas);
    void setTarjetasRojas(int tarjetasRojas);
    void setFaltasCometidas(int faltasCometidas);

    void actualizarDesdePartido(int golesFavor, int golesContra, int tarjetasAmarillas, int tarjetasRojas, int faltasCometidas);
    int calcularDiferenciaGoles() const;
    int calcularPuntos() const;
    void resetear();
    void mostrar() const;
};

#endif // RESULTADOS_H
