#include "organizador.h"
#include <iostream>

using namespace std;

organizador::organizador()
{
}

void organizador::ordenarEquiposPorRanking(equipo **equipos, int cantidad)
{
    int i;
    int j;

    for (i = 0; i < cantidad - 1; i = i + 1)
    {
        for (j = i + 1; j < cantidad; j = j + 1)
        {
            if (equipos[j] != nullptr && equipos[i] != nullptr)
            {
                if (equipos[j]->getRanking() > equipos[i]->getRanking())
                {
                    equipo *temp = equipos[i];
                    equipos[i] = equipos[j];
                    equipos[j] = temp;
                }
            }
        }
    }
}
