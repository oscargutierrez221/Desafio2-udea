#include "torneo.h"
#include "organizador.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Inicializar semilla aleatoria
    srand(time(0));

    torneo CopaMundial2026;
    int opcion;

    do
    {
        std::cout << "\n=== Copa Mundial de la FIFA 2026 ===\n";
        std::cout << "1. Simular torneo completo\n";
        std::cout << "2. Mostrar resultados\n";
        std::cout << "3. Salir\n";
        std::cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            CopaMundial2026.iniciarTorneo();
            break;
        case 2:
            organizador::mostrarReporteFinal(CopaMundial2026.getEquipos(), 48, CopaMundial2026.getPartidos(), CopaMundial2026.getNumPartidos(), CopaMundial2026.getCampeon());
            organizador::medirRecursos(0, 48, CopaMundial2026.getNumPartidos(), 1248);
            break;
        case 0:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 0);

    return 0;
}
