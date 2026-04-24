#include "torneo.h"
#include "organizador.h"
#include <fstream>
#include <iostream>

using namespace std;

torneo::torneo()
{
    numEquipos = 48;
    numGrupos = 12;
    equiposPorGrupo = 4;
    numPartidos = 0;
    campeon = nullptr;

    equipos = new equipo *[numEquipos];
    partidos = new partido *[104];

    int i;
    for (i = 0; i < numEquipos; i = i + 1)
    {
        equipos[i] = nullptr;
    }

    for (i = 0; i < 104; i = i + 1)
    {
        partidos[i] = nullptr;
    }

    bombos = new equipo **[4];

    int j;
    for (i = 0; i < 4; i = i + 1)
    {
        bombos[i] = new equipo *[12];
        for (j = 0; j < 12; j = j + 1)
        {
            bombos[i][j] = nullptr;
        }
    }

    grupos = new equipo **[numGrupos];
    for (i = 0; i < numGrupos; i = i + 1)
    {
        grupos[i] = new equipo *[equiposPorGrupo];
        for (j = 0; j < equiposPorGrupo; j = j + 1)
        {
            grupos[i][j] = nullptr;
        }
    }
}

torneo::~torneo()
{
    int i;
    for (i = 0; i < numEquipos; i = i + 1)
    {
        delete equipos[i];
        equipos[i] = nullptr;
    }
    delete[] equipos;

    for (i = 0; i < numPartidos; i = i + 1)
    {
        delete partidos[i];
        partidos[i] = nullptr;
    }
    delete[] partidos;

    for (i = 0; i < 4; i = i + 1)
    {
        delete[] bombos[i];
    }
    delete[] bombos;

    for (i = 0; i < numGrupos; i = i + 1)
    {
        delete[] grupos[i];
    }
    delete[] grupos;
}

// Funcion auxiliar para convertir texto a numero
int convertirAEntero(string texto)
{
    int numero = 0;
    int i;
    for (i = 0; i < texto.length(); i = i + 1)
    {
        char digito = texto[i];
        if (digito >= '0' && digito <= '9')
        {
            numero = (numero * 10) + (digito - '0');
        }
    }
    return numero;
}

void torneo::cargarEquipos()
{
    ifstream archivo("/home/david/Documentos/Desafio2-udea/Desarrollo/CSV/equipos.txt");

    string paisCsv[1000];
    string nombreCsv[1000];
    string apellidoCsv[1000];
    string numeroCamisetaCsv[1000];
    string golesCsv[1000];
    string numAmarillasCsv[1000];
    string numRojasCsv[1000];
    string numMinutosCsv[1000];
    string partidosJugadosCsv[1000];
    string asistenciasCsv[1000];

    int total = 0;

    while (getline(archivo, paisCsv[total], ','))
    {
        getline(archivo, nombreCsv[total], ',');
        getline(archivo, apellidoCsv[total], ',');
        getline(archivo, numeroCamisetaCsv[total], ',');
        getline(archivo, golesCsv[total], ',');
        getline(archivo, numAmarillasCsv[total], ',');
        getline(archivo, numRojasCsv[total], ',');
        getline(archivo, numMinutosCsv[total], ',');
        getline(archivo, partidosJugadosCsv[total], ',');
        getline(archivo, asistenciasCsv[total]);
        total = total + 1;
    }

    archivo.close();

    int numEquiposCargados = 0;
    int i;
    int j;
    int k;

    for (i = 0; i < total; i = i + 1)
    {
        // Verificamos si este pais ya estaba antes
        bool yaExiste = false;

        for (j = 0; j < i; j = j + 1)
        {
            if (paisCsv[j] == paisCsv[i])
            {
                yaExiste = true;
                break;
            }
        }

        // Si el pais es nuevo, creamos el equipo y agregamos sus jugadores
        if (yaExiste == false && numEquiposCargados < numEquipos)
        {
            equipos[numEquiposCargados] = new equipo(paisCsv[i], paisCsv[i], "", 0, "");
            numEquiposCargados = numEquiposCargados + 1;

            for (k = 0; k < total; k = k + 1)
            {
                if (paisCsv[k] == paisCsv[i])
                {
                    int camiseta = convertirAEntero(numeroCamisetaCsv[k]);
                    int goles = convertirAEntero(golesCsv[k]);
                    int amarillas = convertirAEntero(numAmarillasCsv[k]);
                    int rojas = convertirAEntero(numRojasCsv[k]);
                    int minutos = convertirAEntero(numMinutosCsv[k]);
                    int partidos = convertirAEntero(partidosJugadosCsv[k]);
                    int asistencias = convertirAEntero(asistenciasCsv[k]);

                    int indiceEquipo = numEquiposCargados - 1;
                    equipos[indiceEquipo]->agregarJugador(nombreCsv[k], apellidoCsv[k], camiseta, goles, amarillas, rojas, minutos, partidos, asistencias);
                }
            }
        }
    }
}

void torneo::conformarBombos()
{
    // Contamos cuantos equipos hay cargados
    int totalCargados = 0;
    int i;

    for (i = 0; i < numEquipos; i = i + 1)
    {
        if (equipos[i] != nullptr)
        {
            totalCargados = totalCargados + 1;
        }
    }

    // Ordenamos por ranking FIFA
    organizador::ordenarEquiposPorRanking(equipos, totalCargados);

    // Repartimos los equipos en 4 bombos de forma equitativa
    int porBombo = totalCargados / 4;
    int pos = 0;
    int b;
    int e;

    for (b = 0; b < 4; b = b + 1)
    {
        for (e = 0; e < porBombo; e = e + 1)
        {
            bombos[b][e] = equipos[pos];
            pos = pos + 1;
        }
    }

    // Guardamos en archivo
    ofstream archivo("/home/david/Documentos/Desafio2-udea/Desarrollo/CSV/bombos.txt");
    archivo << "=== BOMBOS DEL SORTEO ===" << endl;

    for (b = 0; b < 4; b = b + 1)
    {
        archivo << endl;
        archivo << "BOMBO " << (b + 1) << ":" << endl;

        for (e = 0; e < porBombo; e = e + 1)
        {
            if (bombos[b][e] != nullptr)
            {
                archivo << "  - " << bombos[b][e]->getNombre() << endl;
            }
        }
    }

    archivo.close();
    cout << "Bombos conformados. Guardado en bombos.txt" << endl;
}

void torneo::conformarGrupos()
{
    // Cada grupo recibe un equipo de cada bombo (en orden)
    int i;
    int b;

    for (i = 0; i < numGrupos; i = i + 1)
    {
        for (b = 0; b < 4; b = b + 1)
        {
            grupos[i][b] = bombos[b][i];
        }
    }

    // Guardamos en archivo
    ofstream archivo("/home/david/Documentos/Desafio2-udea/Desarrollo/CSV/conformarGrupos.txt");
    archivo << "=== GRUPOS DEL TORNEO ===" << endl;

    int g;
    int e;

    for (g = 0; g < numGrupos; g = g + 1)
    {
        archivo << endl << "GRUPO " << (g + 1) << ":" << endl;

        for (e = 0; e < equiposPorGrupo; e = e + 1)
        {
            if (grupos[g][e] != nullptr)
            {
                archivo << "  - " << grupos[g][e]->getNombre() << endl;
            }
        }
    }

    archivo.close();
    cout << "Grupos conformados. Guardado en conformarGrupos.txt" << endl;
}

void torneo::simularEtapaGrupos()
{
    ofstream archivo("/home/david/Documentos/Desafio2-udea/Desarrollo/CSV/simularEtapaGrupos.txt");
    archivo << "=== PROGRAMACION ETAPA DE GRUPOS ===" << endl;

    string letras = "ABCDEFGHIJKL";

    // Por cada grupo creamos los 6 partidos (todos contra todos)
    int g;
    int e1;
    int e2;

    for (g = 0; g < numGrupos; g = g + 1)
    {
        archivo << endl;
        archivo << "--- GRUPO " << letras[g] << " ---" << endl;

        for (e1 = 0; e1 < equiposPorGrupo; e1 = e1 + 1)
        {
            for (e2 = e1 + 1; e2 < equiposPorGrupo; e2 = e2 + 1)
            {
                if (grupos[g][e1] != nullptr && grupos[g][e2] != nullptr)
                {
                    partidos[numPartidos] = new partido("", "", "", "", "", "", grupos[g][e1], grupos[g][e2]);
                    numPartidos = numPartidos + 1;
                    archivo << "  Partido " << numPartidos << ": " << grupos[g][e1]->getNombre() << " vs " << grupos[g][e2]->getNombre() << endl;
                }
            }
        }
    }

    archivo.close();

    // Asignamos fechas y sedes
    organizador::asignarFechasYSedes(partidos, numPartidos);

    cout << "Etapa de grupos programada. Guardado en simularEtapaGrupos.txt" << endl;
}

void torneo::simularR16()
{
    // Tomamos los 2 primeros equipos de cada grupo como clasificados
    equipo *clasificados[32];
    int numClasificados = 0;
    int g;

    for (g = 0; g < numGrupos; g = g + 1)
    {
        if (grupos[g][0] != nullptr && numClasificados < 32)
        {
            clasificados[numClasificados] = grupos[g][0];
            numClasificados = numClasificados + 1;
        }
        if (grupos[g][1] != nullptr && numClasificados < 32)
        {
            clasificados[numClasificados] = grupos[g][1];
            numClasificados = numClasificados + 1;
        }
    }

    // Armamos los partidos de a pares
    ofstream archivo("/home/david/Documentos/Desafio2-udea/Desarrollo/CSV/R16.txt");
    archivo << "=== DIECISEISAVOS DE FINAL ===" << endl;
    archivo << endl;

    int numPartidosR16 = numClasificados / 2;
    int i;

    for (i = 0; i < numPartidosR16; i = i + 1)
    {
        equipo *equipo1 = clasificados[i * 2];
        equipo *equipo2 = clasificados[i * 2 + 1];
        partidos[numPartidos] = new partido("", "", "", "", "", "", equipo1, equipo2);
        numPartidos = numPartidos + 1;
        archivo << "  Partido R16-" << (i + 1) << ": " << equipo1->getNombre() << " vs " << equipo2->getNombre() << endl;
    }

    archivo.close();
    cout << "R16 programado. Guardado en R16.txt" << endl;
}

void torneo::simularR8()
{
    // Tomamos los ganadores reales de los partidos del R16
    equipo *ganadoresR16[16];
    int numGanadores = 0;
    int i;

    for (i = 0; i < numPartidos && numGanadores < 16; i = i + 1)
    {
        if (partidos[i] != nullptr)
        {
            equipo *ganador = organizador::obtenerGanadorReal(partidos[i]);
            if (ganador != nullptr)
            {
                ganadoresR16[numGanadores] = ganador;
                numGanadores = numGanadores + 1;
            }
        }
    }

    ofstream archivo("/home/david/Documentos/Desafio2-udea/Desarrollo/CSV/R8.txt");
    archivo << "=== OCTAVOS DE FINAL ===" << endl;
    archivo << endl;

    int numPartidosR8 = numGanadores / 2;

    for (i = 0; i < numPartidosR8; i = i + 1)
    {
        equipo *equipo1 = ganadoresR16[i * 2];
        equipo *equipo2 = ganadoresR16[i * 2 + 1];
        partidos[numPartidos] = new partido("", "", "", "", "", "", equipo1, equipo2);
        numPartidos = numPartidos + 1;
        archivo << "  Partido R8-" << (i + 1) << ": " << equipo1->getNombre() << " vs " << equipo2->getNombre() << endl;
    }

    archivo.close();
    cout << "Octavos programados. Guardado en R8.txt" << endl;
}

void torneo::simularCuartos()
{
    // Tomamos los ganadores reales de los partidos del R8
    equipo *clasificados[8];
    int numClasificados = 0;
    int i;

    for (i = numPartidos - 1; i >= 0 && numClasificados < 8; i = i - 1)
    {
        if (partidos[i] != nullptr)
        {
            equipo *ganador = organizador::obtenerGanadorReal(partidos[i]);
            if (ganador != nullptr)
            {
                clasificados[numClasificados] = ganador;
                numClasificados = numClasificados + 1;
            }
        }
    }

    ofstream archivo("/home/david/Documentos/Desafio2-udea/Desarrollo/CSV/cuartos.txt");
    archivo << "=== CUARTOS DE FINAL ===" << endl;
    archivo << endl;

    int numPartidosCuartos = numClasificados / 2;

    for (i = 0; i < numPartidosCuartos; i = i + 1)
    {
        equipo *equipo1 = clasificados[i * 2];
        equipo *equipo2 = clasificados[i * 2 + 1];
        partidos[numPartidos] = new partido("", "", "", "", "", "", equipo1, equipo2);
        numPartidos = numPartidos + 1;
        archivo << "  Cuartos-" << (i + 1) << ": " << equipo1->getNombre() << " vs " << equipo2->getNombre() << endl;
    }

    archivo.close();
    cout << "Cuartos programados. Guardado en cuartos.txt" << endl;
}

void torneo::simularSemifinal()
{
    // Tomamos los ganadores reales de los partidos de cuartos
    equipo *semifinalistas[4];
    int numSemi = 0;
    int i;

    for (i = numPartidos - 1; i >= 0 && numSemi < 4; i = i - 1)
    {
        if (partidos[i] != nullptr)
        {
            equipo *ganador = organizador::obtenerGanadorReal(partidos[i]);
            if (ganador != nullptr)
            {
                semifinalistas[numSemi] = ganador;
                numSemi = numSemi + 1;
            }
        }
    }

    ofstream archivo("/home/david/Documentos/Desafio2-udea/Desarrollo/CSV/semifinal.txt");
    archivo << "=== SEMIFINALES ===" << endl;
    archivo << endl;

    int numPartidosSemi = numSemi / 2;

    for (i = 0; i < numPartidosSemi; i = i + 1)
    {
        equipo *equipo1 = semifinalistas[i * 2];
        equipo *equipo2 = semifinalistas[i * 2 + 1];
        partidos[numPartidos] = new partido("", "", "", "", "", "", equipo1, equipo2);
        numPartidos = numPartidos + 1;
        archivo << "  Semifinal " << (i + 1) << ": " << equipo1->getNombre() << " vs " << equipo2->getNombre() << endl;
    }

    archivo.close();
    cout << "Semifinales programadas. Guardado en semifinal.txt" << endl;
}

void torneo::simularFinal()
{
    // Tomamos los ganadores reales de las semifinales
    equipo *finalistas[2];
    int numFinalistas = 0;
    int i;

    for (i = numPartidos - 1; i >= 0 && numFinalistas < 2; i = i - 1)
    {
        if (partidos[i] != nullptr)
        {
            equipo *ganador = organizador::obtenerGanadorReal(partidos[i]);
            if (ganador != nullptr)
            {
                finalistas[numFinalistas] = ganador;
                numFinalistas = numFinalistas + 1;
            }
        }
    }

    ofstream archivo("/home/david/Documentos/Desafio2-udea/Desarrollo/CSV/final.txt");
    archivo << "=== GRAN FINAL ===" << endl;
    archivo << endl;

    if (numFinalistas == 2)
    {
        equipo *equipo1 = finalistas[0];
        equipo *equipo2 = finalistas[1];

        partidos[numPartidos] = new partido("", "", "", "", "", "", equipo1, equipo2);
        numPartidos = numPartidos + 1;

        archivo << "  FINAL: " << equipo1->getNombre() << " vs " << equipo2->getNombre() << endl;

        archivo.close();
        cout << "Final guardada en final.txt" << endl;
    }
    else
    {
        archivo.close();
        cout << "Final guardada en final.txt" << endl;
    }
}

void torneo::determinarCampeon()
{
    // El ultimo partido es la final
    if (numPartidos > 0)
    {
        partido *final = partidos[numPartidos - 1];
        if (final != nullptr)
        {
            campeon = organizador::obtenerGanadorReal(final);
        }
    }
}

void torneo::ordenarGrupos()
{
    int g;
    int i;
    int j;

    for (g = 0; g < numGrupos; g = g + 1)
    {
        for (i = 0; i < equiposPorGrupo - 1; i = i + 1)
        {
            for (j = i + 1; j < equiposPorGrupo; j = j + 1)
            {
                int ptsI = grupos[g][i]->getResultados().calcularPuntos();
                int ptsJ = grupos[g][j]->getResultados().calcularPuntos();

                int difI = grupos[g][i]->getResultados().calcularDiferenciaGoles();
                int difJ = grupos[g][j]->getResultados().calcularDiferenciaGoles();

                if (ptsJ > ptsI || (ptsJ == ptsI && difJ > difI))
                {
                    equipo *temp = grupos[g][i];
                    grupos[g][i] = grupos[g][j];
                    grupos[g][j] = temp;
                }
            }
        }
    }
}

void torneo::verificarAvanzeFase(int partidoActual)
{
    if (partidoActual == 72)
    {
        cout << "\n--- ETAPA DE GRUPOS FINALIZADA ---" << endl;
        ordenarGrupos();
        simularR16();
    }
    else if (partidoActual == 72 + 16)
    {
        cout << "\n--- DIECISEISAVOS FINALIZADOS ---" << endl;
        simularR8();
    }
    else if (partidoActual == 72 + 16 + 8)
    {
        cout << "\n--- OCTAVOS FINALIZADOS ---" << endl;
        simularCuartos();
    }
    else if (partidoActual == 72 + 16 + 8 + 4)
    {
        cout << "\n--- CUARTOS FINALIZADOS ---" << endl;
        simularSemifinal();
    }
    else if (partidoActual == 72 + 16 + 8 + 4 + 2)
    {
        cout << "\n--- SEMIFINALES FINALIZADAS ---" << endl;
        simularFinal();
    }
    else if (partidoActual == 72 + 16 + 8 + 4 + 2 + 1)
    {
        determinarCampeon();
        cout << "\n===================================" << endl;
        cout << "EL TORNEO HA FINALIZADO POR COMPLETO" << endl;
        if (campeon != nullptr)
        {
            cout << "CAMPEON DEL MUNDO: " << campeon->getNombre() << " !!!" << endl;
        }
        cout << "===================================" << endl;
    }
}

void torneo::iniciarTorneo()
{
    if (equipos[0] == nullptr)
    {
        cout << "Cargando equipos automaticamente..." << endl;
        cargarEquipos();
    }
    if (bombos[0][0] == nullptr)
    {
        cout << "Conformando bombos automaticamente..." << endl;
        conformarBombos();
    }
    if (grupos[0][0] == nullptr)
    {
        cout << "Conformando grupos automaticamente..." << endl;
        conformarGrupos();
    }

    cout << "Iniciando torneo y programando fase de grupos..." << endl;
    simularEtapaGrupos();

    int opcion;
    int partidoActual = 0;

    do
    {
        cout << "\n=== MENU DE SIMULACION ===" << endl;
        cout << "Partidos jugados: " << partidoActual << " / " << numPartidos << endl;
        cout << "1. Siguiente fecha (Simular 1 partido)" << endl;
        cout << "2. Simular todos los partidos restantes" << endl;
        cout << "3. Volver al menu principal" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1)
        {
            if (partidoActual < numPartidos)
            {
                partidos[partidoActual]->simular();
                // Si es fase eliminatoria (partido 72 en adelante), resolvemos empates
                if (partidoActual >= 72)
                {
                    organizador::resolverEmpateEliminatoria(partidos[partidoActual]);
                }
                partidos[partidoActual]->mostrarResultado();
                partidoActual = partidoActual + 1;
                verificarAvanzeFase(partidoActual);
            }
            else
            {
                cout << "El torneo ya ha finalizado!" << endl;
            }
        }
        else if (opcion == 2)
        {
            cout << "Simulando el resto del torneo en automatico..." << endl;
            while (partidoActual < numPartidos)
            {
                partidos[partidoActual]->simular();
                // Si es fase eliminatoria, resolvemos empates
                if (partidoActual >= 72)
                {
                    organizador::resolverEmpateEliminatoria(partidos[partidoActual]);
                }
                partidoActual = partidoActual + 1;
                verificarAvanzeFase(partidoActual);
            }

            // Mostrar reporte final automaticamente
            cout << "" << endl;
            cout << "=== TORNEO FINALIZADO ===" << endl;
            organizador::mostrarReporteFinal(equipos, numEquipos, partidos, numPartidos, campeon);
            organizador::medirRecursos(0, numEquipos, numPartidos, numEquipos * 26);
        }
        else if (opcion != 3)
        {
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 3);
}
