#include "torneo.h"

using namespace std;

torneo::torneo() {
    fechaInicio = "";
    numEquipos = 48;
    numGrupos = 12;
    equiposPorGrupo = 4;
    jugadoresPorEquipo = 26;
    numPartidos = 0;
    campeon = nullptr;

    equipos = new equipo *[numEquipos];
    partidos = new partido *[104];

    for (int i = 0; i < numEquipos; i++) {
        equipos[i] = nullptr;
    }

    for (int i = 0; i < 104; i++) {
        partidos[i] = nullptr;
    }

    bombos = new equipo **[4];
    for (int i = 0; i < 4; i++) {
        bombos[i] = new equipo *[12];
        for (int j = 0; j < 12; j++) {
            bombos[i][j] = nullptr;
        }
    }

    grupos = new equipo **[numGrupos];
    for (int i = 0; i < numGrupos; i++) {
        grupos[i] = new equipo *[equiposPorGrupo];
        for (int j = 0; j < equiposPorGrupo; j++) {
            grupos[i][j] = nullptr;
        }
    }
}

torneo::torneo(string fechaInicio, int numEquipos, int numGrupos,
               int equiposPorGrupo, int jugadoresPorEquipo) {
    this->fechaInicio = fechaInicio;
    this->numEquipos = numEquipos;
    this->numGrupos = numGrupos;
    this->equiposPorGrupo = equiposPorGrupo;
    this->jugadoresPorEquipo = jugadoresPorEquipo;
    numPartidos = 0;
    campeon = nullptr;

    equipos = new equipo *[numEquipos];
    partidos = new partido *[104];

    for (int i = 0; i < numEquipos; i++) {
        equipos[i] = nullptr;
    }

    for (int i = 0; i < 104; i++) {
        partidos[i] = nullptr;
    }

    bombos = new equipo **[4];
    for (int i = 0; i < 4; i++) {
        bombos[i] = new equipo *[12];
        for (int j = 0; j < 12; j++) {
            bombos[i][j] = nullptr;
        }
    }

    grupos = new equipo **[numGrupos];
    for (int i = 0; i < numGrupos; i++) {
        grupos[i] = new equipo *[equiposPorGrupo];
        for (int j = 0; j < equiposPorGrupo; j++) {
            grupos[i][j] = nullptr;
        }
    }
}

torneo::torneo(const torneo &otro) {
    fechaInicio = otro.fechaInicio;
    numEquipos = otro.numEquipos;
    numGrupos = otro.numGrupos;
    equiposPorGrupo = otro.equiposPorGrupo;
    jugadoresPorEquipo = otro.jugadoresPorEquipo;
    numPartidos = otro.numPartidos;
    campeon = otro.campeon;

    equipos = new equipo *[numEquipos];
    for (int i = 0; i < numEquipos; i++) {
        equipos[i] = otro.equipos[i];
    }

    partidos = new partido *[104];
    for (int i = 0; i < 104; i++) {
        partidos[i] = otro.partidos[i];
    }

    bombos = new equipo **[4];
    for (int i = 0; i < 4; i++) {
        bombos[i] = new equipo *[12];
        for (int j = 0; j < 12; j++) {
            bombos[i][j] = otro.bombos[i][j];
        }
    }

    grupos = new equipo **[numGrupos];
    for (int i = 0; i < numGrupos; i++) {
        grupos[i] = new equipo *[equiposPorGrupo];
        for (int j = 0; j < equiposPorGrupo; j++) {
            grupos[i][j] = otro.grupos[i][j];
        }
    }
}

torneo::~torneo() {
    delete[] equipos;
    delete[] partidos;

    for (int i = 0; i < 4; i++) {
        delete[] bombos[i];
    }
    delete[] bombos;

    for (int i = 0; i < numGrupos; i++) {
        delete[] grupos[i];
    }
    delete[] grupos;
}

string torneo::getFechaInicio() const
{
    return fechaInicio;
}

int torneo::getNumEquipos() const
{
    return numEquipos;
}

int torneo::getNumGrupos() const
{
    return numGrupos;
}

int torneo::getNumPartidos() const
{
    return numPartidos;
}

equipo *torneo::getEquipo(int indice) const
{
    return equipos[indice];
}

equipo *torneo::getEquipoGrupo(int grupo, int posicion) const
{
    return grupos[grupo][posicion];
}

partido *torneo::getPartido(int indice) const
{
    return partidos[indice];
}

equipo *torneo::getCampeon() const
{
    return campeon;
}

void torneo::setFechaInicio(string fechaInicio)
{
    this->fechaInicio = fechaInicio;
}

void torneo::setCampeon(equipo *campeon)
{
    this->campeon = campeon;
}

void torneo::cargarEquipos()
{
    // Por implementar: leer equipos y jugadores desde archivo CSV
}

void torneo::conformarBombos()
{
    // Por implementar: ordenar por ranking y repartir en 4 bombos de 12
}

void torneo::conformarGrupos()
{
    // Por implementar: sorteo respetando restricciones de confederación
}

void torneo::simularEtapaGrupos()
{
    // Por implementar: 72 partidos (6 por grupo), asignando fechas y sedes
}

void torneo::simularR16()
{
    // Por implementar: 16 partidos de dieciseisavos de final
}

void torneo::simularR8()
{
    // Por implementar: 8 partidos de octavos de final
}

void torneo::simularCuartos()
{
    // Por implementar: 4 partidos de cuartos de final
}

void torneo::simularSemifinal()
{
    // Por implementar: 2 semifinales
}

void torneo::simularFinal()
{
    // Por implementar: partido por el tercer puesto y gran final
}

void torneo::mostrarRankingFinal() const
{
    // Por implementar: los 4 primeros puestos del mundial
}

void torneo::mostrarMaximoGoleadorCampeon() const
{
    // Por implementar: máximo goleador del equipo campeón
}

void torneo::mostrarTresMayoresGoleadores() const
{
    // Por implementar: top 3 goleadores de toda la copa
}

void torneo::mostrarEquipoMasGoleador() const
{
    // Por implementar: equipo con más goles históricos (tras actualización)
}

void torneo::mostrarConfederacionPorEtapa() const
{
    // Por implementar: confederación con mayor presencia en R16, R8 y R4
}
