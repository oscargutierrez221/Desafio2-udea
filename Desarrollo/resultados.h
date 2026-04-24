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
  int getTarjetasAmarillas() const;
  int getTarjetasRojas() const;
  int getFaltasCometidas() const;

  void actualizarDesdePartido(int golesFavor, int golesContra, int tarjetasAmarillas, int tarjetasRojas, int faltasCometidas);
  int calcularDiferenciaGoles() const;
  int calcularPuntos() const;
  void mostrar() const;
};

#endif // RESULTADOS_H
