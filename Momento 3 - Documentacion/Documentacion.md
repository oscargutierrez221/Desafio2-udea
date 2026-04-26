**Integrantes:**
- Johan Steven Guarnizo Posada
- Óscar David Gutiérrez Hernández

## Índice

- [1. Contextualización](#1-contextualización)
  - [1.1 Descripción del desafío y objetivos](#11-descripción-del-desafío-y-objetivos)
  - [1.2 Consideraciones del desarrollo](#12-consideraciones-del-desarrollo)
- [2. Desarrollo](#2-desarrollo)
  - [2.1 Arquitectura y diagrama de clases](#21-arquitectura-y-diagrama-de-clases)
  - [2.2 Estructura del repositorio](#22-estructura-del-repositorio)
  - [2.3 Descripción detallada de las clases principales](#23-descripción-detallada-de-las-clases-principales)
  - [2.4 Relaciones entre clases](#24-relaciones-entre-clases)
- [3. Conclusiones y desafíos encontrados](#3-conclusiones-y-desafíos-encontrados)
  - [3.1 Conclusiones del proyecto](#31-conclusiones-del-proyecto)
  - [3.2 Desafíos encontrados en la implementación](#32-desafíos-encontrados-en-la-implementación)
- [4. Material de consulta](#4-material-de-consulta)


## 1. Contextualización

### 1.1 Descripción del desafío y objetivos

Este proyecto consistió en desarrollar un simulador del Mundial de Fútbol FIFA 2026 llamado **UdeAWorldCup**. Tuvimos que crear un sistema en C++ usando Programación Orientada a Objetos que pudiera gestionar 48 equipos, simular 104 partidos en total, y manejar toda la lógica del torneo desde la fase de grupos hasta la final.

El desafío nos pidió implementar funcionalidades como:
- Cargar datos de equipos y jugadores desde archivos CSV sin usar librerías externas
- Simular partidos con resultados aleatorios basados en el ranking FIFA
- Organizar los equipos en grupos respetando restricciones de confederación (máximo 2 equipos europeos por grupo)
- Llevar estadísticas de cada equipo y jugador durante todo el torneo
- Implementar la lógica de fases eliminatorias desde dieciseisavos hasta la final

Básicamente, este trabajo nos servía para practicar conceptos de POO como clases, objetos, herencia, composición, agregación, manejo de memoria dinámica y relaciones entre clases. Era un proyecto grande para ser un trabajo académico, pero eso nos permitió enfrentarnos a problemas reales de programación.

### 1.2 Consideraciones del desarrollo

Desde el inicio tuvimos que trabajar bajo varias restricciones que nos dieron en clase. Al principio nos parecieron limitantes excesivas, pero entendimos que eran para forzarnos a aprender los conceptos fundamentales:

1. **Lenguaje:** Solo C++ con POO, nada de programación estructural. Todo tenía que ser orientado a objetos.

2. **Prohibición de STL:** No podíamos usar `vector`, `list`, `map` ni ningún contenedor de la librería estándar. Solo arreglos tradicionales de C. Esto nos obligó a entender cómo funcionan los arrays por dentro.

3. **Memoria dinámica obligatoria:** Todo manejo de datos tenía que ser con `new` y `delete`, para practicar punteros y entender la gestión de memoria manual.

4. **Sin structs:** Solo clases, porque estábamos aprendiendo POO. Las structs son más de C que de C++.

5. **Librerías limitadas:** Solo podíamos usar `fstream` para archivos y `string` para texto. No querían que usáramos librerías externas que nos facilitaran el trabajo.

6. **Código modular:** Separar todo en archivos `.h` y `.cpp` como se debe en proyectos profesionales.

7. **Include guards:** Todos los archivos `.h` debían tener `#ifndef`, `#define` y `#endif` para evitar inclusiones múltiples.

## 2. Desarrollo

### 2.1 Arquitectura y diagrama de clases

Antes de empezar a codear, nos sentamos a diseñar la estructura del programa. No queríamos empezar a escribir código sin saber cómo se iban a relacionar las clases. Usamos el concepto de "divide y vencerás": cada clase tiene una responsabilidad específica.

![alt text](<material/Diagrama de clases documentacion.png>)

El diagrama muestra cómo organizamos todo. Decidimos crear 6 clases principales:

- **Equipo**: guarda la info básica del país, su confederación, ranking FIFA, y maneja sus jugadores
- **Jugador**: almacena estadísticas individuales de cada futbolista (goles, asistencias, tarjetas, etc.)
- **Resultados**: lleva el conteo de puntos, goles, tarjetas y faltas de un equipo durante el torneo
- **Partido**: simula un encuentro entre dos equipos y actualiza estadísticas
- **Organizador**: funciones auxiliares estáticas como ordenar, validar grupos, asignar fechas
- **Torneo**: coordina todo el flujo del mundial, desde cargar equipos hasta determinar el campeón

La decisión de separar en 6 clases nos pareció la mejor porque cada una tiene una función clara y no hay código duplicado. Por ejemplo, la lógica de simulación está solo en Partido, y la coordinación general solo en Torneo.

### 2.2 Estructura del repositorio

Organizamos el proyecto en carpetas para que quedara ordenado y profesional:

```
Desafio2-udea/
├── Desarrollo/              # Código fuente (.cpp y .h)
│   ├── Desarrollo.pro 
│   ├── main.cpp
│   ├── equipo.cpp / equipo.h
│   ├── jugador.cpp / jugador.h
│   ├── partido.cpp / partido.h
│   ├── resultados.cpp / resultados.h
│   ├── torneo.cpp / torneo.h
│   ├── organizador.cpp / organizador.h
│   └── CSV/                 # Archivos de datos del torneo
│       ├── equipos.txt
│       ├── bombos.txt
│       └── ...
├── Momento 1 - Informe/     # Informes iniciales del desafío
└── Documentación/           # Documentacion
    ├── documentacion.md
    └── Material/
        └── Diagrama de clases documentacion.png
```

La separación en carpetas nos ayudó a mantener el orden. Los archivos CSV los pusimos en una carpeta aparte porque son datos de entrada que el programa lee, no código.

### 2.3 Descripción detallada de las clases principales

#### **Equipo (equipo.h / equipo.cpp)**

La clase `Equipo` representa a cada selección participante del mundial. Guarda datos como el nombre del país, confederación (UEFA, CONMEBOL, etc.), ranking FIFA y el director técnico.

Lo más importante de esta clase fue implementar la relación de **composición** con la clase `Jugador`: cada equipo "tiene" jugadores y es responsable de crearlos y destruirlos. Si el equipo se destruye, sus jugadores también deben destruirse.

```cpp
#ifndef EQUIPO_H
#define EQUIPO_H

#include "jugador.h"
#include "resultados.h"
#include <string>

using namespace std;

class Equipo {
private:
    string nombre;
    string pais;
    string confederacion;
    int ranking;
    string directorTecnico;
    
    Jugador* jugadores[26];  // Máximo 26 jugadores por equipo
    int numJugadores;
    Resultados estadisticas;  // Relación de agregación

public:
    // Constructores
    Equipo();
    Equipo(string nombre, string pais, string confederacion, int ranking, string directorTecnico);
    Equipo(const Equipo &otro);  // Constructor por copia
    
    // Destructor
    ~Equipo();
    
    // Métodos principales
    void agregarJugador(string nombre, string apellido, int camiseta, int goles, int amarillas, int rojas, int minutos, int partidos, int asistencias);
    
    // Getters
    string getNombre() const;
    string getConfederacion() const;
    int getRanking() const;
    Resultados& getResultados();
    Jugador* getJugador(int i) const;
    int getNumJugadores() const;
};

#endif
```

El constructor por defecto inicializa todo en valores por defecto (strings vacíos, ranking en 0, numJugadores en 0). Que lo pusimos siguiendo las indicaciones de clases donde dijeron que a pesar de que no fuese necesario era una buena practica:

```cpp
Equipo::Equipo() {
    nombre = "";
    pais = "";
    confederacion = "";
    ranking = 0;
    directorTecnico = "";
    numJugadores = 0;
}
```

El destructor es crucial porque cada jugador se crea dinámicamente con `new`, entonces debe liberarse con `delete`. Si no hacemos esto, tenemos fugas de memoria:

```cpp
Equipo::~Equipo() {
    for (int i = 0; i < numJugadores; i++) {
        delete jugadores[i];      // Liberamos cada jugador
        jugadores[i] = nullptr;   // Buena práctica: puntero a null
    }
}
```

El método `agregarJugador` crea un nuevo jugador con `new` y lo añade al arreglo:

```cpp
void Equipo::agregarJugador(string nombre, string apellido, int camiseta, int goles, int amarillas, int rojas, int minutos, int partidos, int asistencias) {
    if (numJugadores < 26) {
        // Creamos el jugador con new (memoria dinámica)
        jugadores[numJugadores] = new Jugador(nombre, apellido, camiseta);
        
        // Cargamos sus estadísticas
        jugadores[numJugadores]->cargarEstadisticas( goles, partidos, minutos, asistencias, amarillas, rojas, 0);
        
        numJugadores++;
    }
}
```

El método `getResultados()` retorna una referencia (`Resultados&`) al objeto de estadísticas. Esto permite que quien llame al método pueda modificar directamente las estadísticas del equipo sin tener que hacerlo a través de métodos intermedios. Es parte de la relación de agregación.

#### **Jugador (jugador.h / jugador.cpp)**

La clase `Jugador` almacena la información de cada futbolista. Es una clase relativamente sencilla pero fundamental para el sistema.

```cpp
#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class Jugador {
private:
    // Datos básicos
    string nombre;
    string apellido;
    int numeroCamiseta;
    
    // Estadísticas
    int partidosJugados;
    int goles;
    int asistencias;
    int tarjetasAmarillas;
    int tarjetasRojas;
    int faltasCometidas;
    int minutosJugados;

public:
    Jugador(string nombre, string apellido, int numeroCamiseta);
    Jugador(const Jugador &otro);
    ~Jugador();
    
    void actualizarEstadisticasPartido(int goles, int amarillas, int rojas, int faltas, int minutos);
    void cargarEstadisticas(int goles, int partidos, int minutos, int asistencias, int amarillas, int rojas, int faltas);
    
    // Getters
    string getNombre() const;
    string getApellido() const;
    int getGoles() const;
};

#endif
```

Los métodos principales son:

**`actualizarEstadisticasPartido()`**: Se llama después de cada partido para sumar las estadísticas de ese encuentro a las totales del jugador. Usamos `this->` para diferenciar entre el atributo de la clase y el parámetro cuando tienen el mismo nombre:

```cpp
void Jugador::actualizarEstadisticasPartido(int goles, int amarillas, int rojas, int faltas, int minutos) {
    partidosJugados++; // Un partido más jugado
    this->goles = this->goles + goles; // Sumamos goles
    minutosJugados = minutosJugados + minutos;
    tarjetasAmarillas = tarjetasAmarillas + amarillas;
    tarjetasRojas = tarjetasRojas + rojas;
    faltasCometidas = faltasCometidas + faltas;
}
```

**`cargarEstadisticas()`**: Se usa al inicio del programa para cargar datos históricos desde el archivo CSV:

```cpp
void Jugador::cargarEstadisticas(int goles, int partidos, int minutos, int asistencias, int amarillas, int rojas, int faltas) {
    this->goles = goles;
    this->partidosJugados = partidos;
    this->minutosJugados = minutos;
    this->asistencias = asistencias;
    this->tarjetasAmarillas = amarillas;
    this->tarjetasRojas = rojas;
    this->faltasCometidas = faltas;
}
```

El destructor de `Jugador` está vacío porque esta clase no crea objetos dinámicamente, solo almacena datos simples (`strings` e `int`).

#### **Resultados (resultados.h / resultados.cpp)**

Esta clase es la que permite saber cómo va un equipo en el torneo. Acumula todas las estadísticas de los partidos jugados.

```cpp
#ifndef RESULTADOS_H
#define RESULTADOS_H

class Resultados {
private:
    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;
    int golesFavor;
    int golesContra;
    int tarjetasAmarillas;
    int tarjetasRojas;
    int faltasCometidas;

public:
    Resultados();
    Resultados(const Resultados &otro);
    
    void actualizarDesdePartido(int golesFavor, int golesContra, int amarillas, int rojas, int faltas);
    int calcularPuntos() const;
    int calcularDiferenciaGoles() const;
    
    // Getters
    int getGolesFavor() const;
    int getTarjetasAmarillas() const;
    int getTarjetasRojas() const;
    int getFaltasCometidas() const;
    void mostrar() const;
};

#endif
```

Los métodos clave son:

**`calcularPuntos()`**: Implementa las reglas del fútbol: 3 puntos por victoria, 1 por empate, 0 por derrota:

```cpp
int Resultados::calcularPuntos() const {
    if (golesFavor > golesContra) {
        return 3; // Victoria
    } else if (golesFavor == golesContra) {
        return 1; // Empate
    } else {
        return 0; // Derrota
    }
}
```

**`actualizarDesdePartido()`**: Suma las estadísticas de un partido recién jugado al acumulado del equipo:

```cpp
void Resultados::actualizarDesdePartido(int golesFavor, int golesContra, int amarillas, int rojas, int faltas) {
    this->golesFavor = this->golesFavor + golesFavor;
    this->golesContra = this->golesContra + golesContra;
    this->tarjetasAmarillas = this->tarjetasAmarillas + amarillas;
    this->tarjetasRojas = this->tarjetasRojas + rojas;
    this->faltasCometidas = this->faltasCometidas + faltas;
    
    // Determinamos si ganó, empató o perdió
    if (golesFavor > golesContra) {
        partidosGanados++;
    } else if (golesFavor == golesContra) {
        partidosEmpatados++;
    } else {
        partidosPerdidos++;
    }
}
```

#### **Partido (partido.h / partido.cpp)**

Aquí está la magia de la simulación. La clase `Partido` representa un encuentro entre dos equipos y contiene toda la lógica para simularlo usando números aleatorios.

```cpp
#ifndef PARTIDO_H
#define PARTIDO_H

#include "equipo.h"
#include "resultados.h"
#include <string>

class Partido {
private:
    string fecha;
    string hora;
    string sede;
    
    Equipo* equipo1;
    Equipo* equipo2;
    
    bool jugado;
    Equipo* ganador;
    
    Resultados statsEquipo1;  // Estadísticas de este partido específico
    Resultados statsEquipo2;

public:
    Partido();
    Partido(string fecha, string hora, string sede, Equipo* equipo1, Equipo* equipo2);
    ~Partido();
    
    void simular();
    void mostrarResultado() const;
    
    // Getters y setters
    Equipo* getEquipo1() const;
    Equipo* getEquipo2() const;
    Equipo* getGanador() const;
    void setGanador(Equipo* g);
    void setFecha(string f);
    void setHora(string h);
    void setSede(string s);
};

#endif
```

El método más importante es `simular()`, que genera resultados aleatorios:

```cpp
void Partido::simular() {
    // Generamos goles aleatorios entre 0 y 3 para cada equipo
    int golesEq1 = rand() % 4;
    int golesEq2 = rand() % 4;
    
    // Variables para acumular estadísticas del equipo 1
    int amarillasEq1 = 0, rojasEq1 = 0, faltasEq1 = 0;
    
    // Recorremos los jugadores del equipo 1 y les asignamos estadísticas
    for (int i = 0; i < equipo1->getNumJugadores(); i++) {
        Jugador* jug = equipo1->getJugador(i);
        if (jug != nullptr) {
            // ¿Este jugador marcO un gol?
            int golesJug = (i < golesEq1) ? 1 : 0;
            
            // Tarjeta amarilla con probabilidad 1/7
            int amarilla = (rand() % 7 == 0) ? 1 : 0;
            
            // Tarjeta roja con probabilidad 1/25
            int roja = (rand() % 25 == 0) ? 1 : 0;
            
            // Faltas entre 0 y 2
            int faltas = rand() % 3;
            
            // Actualizamos estadísticas del jugador
            jug->actualizarEstadisticasPartido(golesJug, amarilla, roja, faltas, 90);
            
            // Acumulamos para el equipo
            amarillasEq1 += amarilla;
            rojasEq1 += roja;
            faltasEq1 += faltas;
        }
    }
    
    // Hacemos lo mismo para el equipo 2...
    
    // Actualizamos estadísticas de los equipos
    equipo1->getResultados().actualizarDesdePartido(golesEq1, golesEq2, amarillasEq1, rojasEq1, faltasEq1);
    equipo2->getResultados().actualizarDesdePartido(golesEq2, golesEq1, amarillasEq2, rojasEq2, faltasEq2);
    
    // Determinamos el ganador
    if (golesEq1 > golesEq2) {
        ganador = equipo1;
    } else if (golesEq2 > golesEq1) {
        ganador = equipo2;
    } else {
        ganador = nullptr;  // Empate
    }
    
    jugado = true;
}
```

Usamos `rand() % 4` para obtener números entre 0 y 3 (goles), y diferentes probabilidades para las tarjetas.

#### **Organizador (organizador.h / organizador.cpp)**

Esta fue una clase de la que vimos necesidad luego de empezar la implementacion y por eso no se encuentra en el primer diagrama de clases del informe.Esta clase es diferente porque solo tiene métodos estáticos. No necesitamos crear objetos de tipo Organizador, solo usamos sus funciones auxiliares. La palabra clave `static` significa que los métodos pertenecen a la clase, no a instancias individuales.

```cpp
#ifndef ORGANIZADOR_H
#define ORGANIZADOR_H

#include "equipo.h"
#include "partido.h"

class Organizador {
public:
    static void ordenarEquiposPorRanking(Equipo** equipos, int cantidad);
    static bool validarRestriccionesGrupos(Equipo*** grupos, int numGrupos, int equiposPorGrupo);
    static void asignarFechasYSedes(Partido** partidos, int numPartidos);
    static void resolverEmpateEliminatoria(Partido* p);
    static Equipo* obtenerGanadorReal(Partido* p);
    static void mostrarReporteFinal(Equipo** equipos, int numEquipos, Partido** partidos, int numPartidos, Equipo* campeon);
};

#endif
```

Los métodos estáticos más importantes:

**`ordenarEquiposPorRanking()`**: Se usa para ordenar equipos de mayor a menor ranking. Un ranking mayor significa mejor posición (el #1 es el mejor del mundo):

```cpp
void Organizador::ordenarEquiposPorRanking(Equipo** equipos, int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (equipos[j] != nullptr && equipos[i] != nullptr) {
                if (equipos[j]->getRanking() > equipos[i]->getRanking()) {
                    Equipo* temp = equipos[i];
                    equipos[i] = equipos[j];
                    equipos[j] = temp;
                }
            }
        }
    }
}
```

**`validarRestriccionesGrupos()`**: Verifica la regla de FIFA: máximo 2 equipos de la UEFA (Europa) por grupo. Siendo porque era una de las restriccionesd el desafio:

```cpp
bool Organizador::validarRestriccionesGrupos(Equipo*** grupos, int numGrupos, int equiposPorGrupo) {
    for (int g = 0; g < numGrupos; g++) {
        int uefa = 0;
        for (int i = 0; i < equiposPorGrupo; i++) {
            if (grupos[g][i] != nullptr) {
                if (grupos[g][i]->getConfederacion() == "UEFA") {
                    uefa++;
                }
            }
        }
        if (uefa > 2) return false;  // No cumple la regla
    }
    return true;
}
```

**`resolverEmpateEliminatoria()`**: En fases eliminatorias no puede haber empates. Si un partido termina empatado, desempata por ranking FIFA (gana el mejor):

```cpp
void Organizador::resolverEmpateEliminatoria(Partido* p) {
    int goles1 = p->getStatsEquipo1().getGolesFavor();
    int goles2 = p->getStatsEquipo2().getGolesFavor();
    
    if (goles1 == goles2) {  // Empate
        int ranking1 = p->getEquipo1()->getRanking();
        int ranking2 = p->getEquipo2()->getRanking();
        
        if (ranking1 > ranking2) {
            p->setGanador(p->getEquipo1());
        } else {
            p->setGanador(p->getEquipo2());
        }
    }
}
```

#### **Torneo (torneo.h / torneo.cpp)**

Esta es la clase más grande y compleja. Coordina todo el funcionamiento del mundial. Tiene punteros dobles y triples porque manejamos arrays de objetos dinámicos.

```cpp
#ifndef TORNEO_H
#define TORNEO_H

#include "equipo.h"
#include "partido.h"

class Torneo {
private:
    // Configuración del torneo
    int numEquipos;
    int numGrupos;
    int equiposPorGrupo;
    
    // Estructuras de datos principales
    Equipo** equipos;
    Equipo*** bombos;
    Equipo*** grupos;
    Partido** partidos;
    int numPartidos;
    Equipo* campeon;

public:
    Torneo();
    ~Torneo();
    
    // Métodos de configuración
    void cargarEquipos();
    void conformarBombos();
    void conformarGrupos();
    
    // Métodos de simulación
    void simularEtapaGrupos();
    void simularR16();
    void simularR8();
    void simularCuartos();
    void simularSemifinal();
    void simularFinal();
    void iniciarTorneo();
    
    // Métodos auxiliares
    void ordenarGrupos();
    void verificarAvanzeFase(int partidoActual);
    void determinarCampeon();
    
    // Getters
    Equipo** getEquipos() { return equipos; }
    Partido** getPartidos() { return partidos; }
    int getNumPartidos() { return numPartidos; }
    Equipo* getCampeon() { return campeon; }
};

#endif
```

El constructor es complejo porque debe inicializar toda la estructura de datos dinámica:

```cpp
Torneo::Torneo() {
    numEquipos = 48;
    numGrupos = 12;
    equiposPorGrupo = 4;
    numPartidos = 0;
    campeon = nullptr;
    
    // Array de equipos
    equipos = new Equipo*[numEquipos];
    for (int i = 0; i < numEquipos; i++) {
        equipos[i] = nullptr;
    }
    
    // Array de partidos (máximo 104)
    partidos = new Partido*[104];
    for (int i = 0; i < 104; i++) {
        partidos[i] = nullptr;
    }
    
    // bombos (4 bombos x 12 equipos cada uno)
    bombos = new Equipo**[4];
    for (int i = 0; i < 4; i++) {
        bombos[i] = new Equipo*[12];
        for (int j = 0; j < 12; j++) {
            bombos[i][j] = nullptr;
        }
    }
    
    // grupos (12 grupos x 4 equipos cada uno)
    grupos = new Equipo**[numGrupos];
    for (int i = 0; i < numGrupos; i++) {
        grupos[i] = new Equipo*[equiposPorGrupo];
        for (int j = 0; j < equiposPorGrupo; j++) {
            grupos[i][j] = nullptr;
        }
    }
}
```

El destructor libera toda la memoria en orden inverso (primero objetos, luego arrays):

```cpp
Torneo::~Torneo() {
    // Liberar equipos
    for (int i = 0; i < numEquipos; i++) {
        delete equipos[i];
        equipos[i] = nullptr;
    }
    delete[] equipos;
    
    // Liberar partidos
    for (int i = 0; i < numPartidos; i++) {
        delete partidos[i];
        partidos[i] = nullptr;
    }
    delete[] partidos;
    
    // Liberar bombos
    for (int i = 0; i < 4; i++) {
        delete[] bombos[i];
    }
    delete[] bombos;
    
    // Liberar grupos
    for (int i = 0; i < numGrupos; i++) {
        delete[] grupos[i];
    }
    delete[] grupos;
}
```

**Cargar equipos desde CSV:**

El método `cargarEquipos()` lee el archivo de texto con los datos de equipos y jugadores:

```cpp
void Torneo::cargarEquipos() {
    ifstream archivo("Desarrollo/CSV/equipos.txt");
    
    string paisCsv[1000];
    string nombreCsv[1000];
    // ... Y los demas array... 
    
    int total = 0;
    
    // Leemos línea por línea separando por comas
    while (getline(archivo, paisCsv[total], ',')) {
        getline(archivo, nombreCsv[total], ',');
        // ... leemos todos los campos
        getline(archivo, confederacionCsv[total]);
        total++;
    }
    
    archivo.close();
    
    // Procesamos los datos y creamos equipos y jugadores. No pongo el codigo aqui porque se veria muy largo y feo.
}
```

**Función auxiliar para convertir strings a enteros:**

Como leemos todo como texto del CSV, necesitamos convertir los números:

```cpp
int convertirAEntero(string texto) {
    int numero = 0;
    for (int i = 0; i < texto.length(); i++) {
        char digito = texto[i];
        if (digito >= '0' && digito <= '9') {
            numero = (numero * 10) + (digito - '0');
        }
    }
    return numero;
}
```

**Conformar bombos:**

Primero ordenamos los equipos por ranking, luego los distribuimos en 4 bombos:

```cpp
void Torneo::conformarBombos() {
    // Contar cuántos equipos hay cargados
    int totalCargados = 0;
    for (int i = 0; i < numEquipos; i++) {
        if (equipos[i] != nullptr) totalCargados++;
    }
    
    // Ordenar por ranking
    Organizador::ordenarEquiposPorRanking(equipos, totalCargados);
    
    // Distribuir en bombos
    int porBombo = totalCargados / 4;
    int pos = 0;
    for (int b = 0; b < 4; b++) {
        for (int e = 0; e < porBombo; e++) {
            bombos[b][e] = equipos[pos];
            pos++;
        }
    }
}
```

**Conformar grupos:**

Tomamos un equipo de cada bombo para formar grupos balanceados:

```cpp
void torneo::conformarGrupos()
{
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

    // Validamos restricciones de confederacion
    bool valido = organizador::validarRestriccionesGrupos(grupos, numGrupos, equiposPorGrupo);
    if (valido == false)
    {
        cout << "ADVERTENCIA: Algunos grupos no cumplen restricciones de confederacion (max 2 UEFA)" << endl;
    }

    cout << "Grupos conformados. Guardado en conformarGrupos.txt" << endl;
}
```

**Simular etapa de grupos:**

Generamos todos los partidos de grupos (todos contra todos):

```cpp
void Torneo::simularEtapaGrupos() {
    string letras = "ABCDEFGHIJKL";  // 12 grupos
    
    for (int g = 0; g < numGrupos; g++) {
        for (int e1 = 0; e1 < equiposPorGrupo; e1++) {
            for (int e2 = e1 + 1; e2 < equiposPorGrupo; e2++) {
                if (grupos[g][e1] != nullptr && grupos[g][e2] != nullptr) {
                    // Creamos el partido
                    partidos[numPartidos] = new Partido("", "", "", grupos[g][e1], grupos[g][e2]);
                    numPartidos++;
                }
            }
        }
    }
    
    // Asignamos fechas y sedes a todos los partidos creados
    Organizador::asignarFechasYSedes(partidos, numPartidos);
}
```

Esto genera 6 partidos por grupo × 12 grupos = 72 partidos en total para la fase de grupos.

**Verificar avance de fase:**

Este método coordina cuándo termina una fase y empieza otra:

```cpp
void Torneo::verificarAvanzeFase(int partidoActual) {
    if (partidoActual == 72) {
        // Terminó fase de grupos
        ordenarGrupos(); // Ordenamos por puntos
        simularR16(); // Creamos partidos de dieciseisavos
    }
    else if (partidoActual == 84) {
        // Terminaron dieciseisavos
        simularR8();
    }
    else if (partidoActual == 90) {
        // Terminaron octavos
        simularCuartos();
    }
    else if (partidoActual == 93) {
        // Terminaron cuartos
        simularSemifinal();
    }
    else if (partidoActual == 95) {
        // Terminaron semifinales
        simularFinal();
    }
    else if (partidoActual == 96) {
        // Terminó el torneo
        determinarCampeon();
    }
}
```

#### **main.cpp**

El archivo principal es muy sencillo porque toda la lógica está en las clases:

```cpp
#include <iostream>
#include <cstdlib> // Necesario para rand() y srand()
#include <ctime> // Necesario para time()
#include "torneo.h"

using namespace std;

int main() {
    // PAra los numeros aleatorios
    srand(time(nullptr));
    
    // Creamos el torneo
    Torneo mundial2026;
    
    // Cargamos los equipos desde el archivo
    mundial2026.cargarEquipos();
    
    // Conformamos bombos y grupos
    mundial2026.conformarBombos();
    mundial2026.conformarGrupos();
    
    // Simulamos la etapa de grupos
    mundial2026.simularEtapaGrupos();
    
    // Iniciamos el menú interactivo
    mundial2026.iniciarTorneo();
    
    return 0;
}
```

Usamos `srand(time(nullptr))` para que los números aleatorios sean diferentes cada vez que ejecutamos el programa.

### 2.4 Relaciones entre clases

Las relaciones entre nuestras clases fueron un punto clave que tuvimos que pensar bien desde el diseño. Entender estas relaciones nos ayudó a organizar mejor el código y evitar problemas de memoria.

#### **Composición (Equipo - Jugador)**

Esta es la relación más fuerte. Los jugadores "pertenecen" al equipo y no pueden existir sin él en nuestro sistema. Cuando un equipo se destruye, todos sus jugadores también se destruyen.

- Implementada con: `Jugador* jugadores[26]` dentro de Equipo
- Los jugadores se crean con `new` en `agregarJugador()`
- El destructor de Equipo hace `delete` de cada jugador

#### **Agregación (Equipo - Resultados)**

El equipo "tiene" resultados, pero estos pueden existir independientemente. En nuestro caso, usamos agregación porque los resultados de un partido específico no se destruyen cuando termina.

- Implementada con: `Resultados estadisticas` dentro de Equipo (no puntero, objeto directo)
- También usamos `Resultados` independientes en la clase Partido

#### **Asociación (Partido - Equipo)**

Un partido "usa" equipos pero no los posee. Los equipos pueden existir sin el partido y pueden participar en múltiples partidos.

- Implementada con: `Equipo* equipo1` y `Equipo* equipo2` en Partido
- Usamos punteros porque los equipos ya existen y son creados por Torneo

#### **Dependencia (Organizador - todas las demás)**

La clase Organizador depende de Equipo y Partido, pero no tiene atributos de estas clases. Solo usa objetos que le pasan como parámetros en sus métodos estáticos.

- Métodos estáticos que reciben punteros como parámetros
- No hay atributos de tipo Equipo o Partido en Organizador

#### **Coordinación (Torneo - todas las demás)**

Torneo es la clase que coordina todo. Tiene atributos de tipo Equipo, Partido, y usa Organizador.

- `Equipo** equipos`: array de punteros a equipos
- `Partido** partidos`: array de punteros a partidos
- Llama a métodos estáticos de Organizador
- Es la clase "fachada" que simplifica el uso del sistema

## 3. Conclusiones y desafíos encontrados

### 3.1 Conclusiones del proyecto

Terminar este proyecto nos dio una perspectiva completamente diferente de la programación. Al principio del curso veíamos la POO como algo abstracto y teórico, pero al tener que aplicarlo en un proyecto real de este tamaño, entendimos por qué existe y por qué es tan usado en la industria.

Aprendimos que diseñar bien las clases desde el inicio ahorra mucho trabajo después. Cuando definimos claramente qué responsabilidad tiene cada clase (Equipo maneja jugadores, Partido simula encuentros, Torneo coordina todo), el código fluye más natural y es más fácil de mantener. Si hubiéramos empezado a codear sin planificar, seguramente tendríamos un desastre de código.

El manejo de memoria dinámica fue el tema que más nos costó, pero al final lo dominamos. Entender cuándo usar `new`, cuándo hacer `delete`, y en qué orden liberar la memoria nos hizo ser más cuidadosos y conscientes de lo que pasa "detrás del escenario" cuando un programa corre.

También valoramos más el trabajo en equipo. Dividir tareas, revisar el código del compañero, discutir cómo resolver ciertos problemas, cosa que fue realmente dificil porque todo era por meet. Algunas veces discutíamos por la mejor forma de implementar algo, pero esas discusiones nos llevaron a mejores soluciones.


### 3.2 Desafíos encontrados en la implementación

**Los punteros dobles y triples:**
Nos costó muchísimo entender la sintaxis de `Equipo**` y `Equipo***`. Al principio no entendíamos por qué necesitábamos tantos asteriscos. Con la práctica vimos que `Equipo*` es un puntero a un objeto, `Equipo**` es un array de punteros, y `Equipo***` es una matriz de punteros. La sintaxis `bombos[b][e]` para acceder a elementos requirió bastante práctica.

**Liberar memoria sin errores:**
En varias ocasiones el programa se colgaba porque liberábamos memoria en el orden incorrecto. Aprendimos que primero hay que hacer `delete` de los objetos individuales, luego `delete[]` de los arrays, y seguir ese orden estrictamente. También tuvimos cuidado con los punteros dobles: primero liberamos las filas de la matriz, luego la matriz misma.

**Parsear el archivo CSV:**
Leer el archivo de equipos con `getline()` fue más difícil de lo que pensábamos. Tuvimos que manejar correctamente las comas y crear nuestra propia función para convertir strings a enteros porque estábamos leyendo todo como texto. Al principio los números nos daban valores raros porque no convertíamos bien los caracteres a enteros.

**Validar restricciones de grupos:**
Implementar la regla de "máximo 2 equipos de UEFA por grupo" nos obligó a crear un algoritmo que recorriera todos los grupos, contara equipos por confederación, y rehiciera el sorteo si no se cumplía. Fue un buen ejercicio de lógica de programación. No implementamos el reshuffle completo por falta de tiempo, pero la validación sí está funcionando.

**Coordinar las fases del torneo:**
El método que verifica cuándo termina una fase y empieza otra (`verificarAvanzeFase`) fue complicado. Tuvimos que llevar la cuenta exacta de cuántos partidos se juegan en cada etapa (72 grupos + 12 R16 + 6 R8 + 3 cuartos + 2 semifinales + 1 final = 96 partidos) y asegurarnos de que las transiciones ocurrieran en el momento correcto. Un error en estos números y el torneo se desorganizaba.

**Documentar todo el código:**
Curiosamente, explicar cómo funcionaba cada método nos ayudó a entender mejor nuestra propia implementación. Al escribir la documentación nos dimos cuenta de detalles que habíamos pasado por hoyo y corregimos algunos errores menores. Fue como explicarle a alguien más cómo funciona, lo que obliga a entenderlo bien uno mismo.

## 4. Material de consulta

- [Material de referencia 1 (YouTube)](https://www.youtube.com/watch?v=cGW5AiNrOOo&list=PL5YuOOJ-FGGjjK8j50TkEcjCcZ8dRAiPy&index=58)
- [Material de referencia 2 (YouTube)](https://www.youtube.com/watch?v=IAPL8cHLnuY&list=PL5YuOOJ-FGGjjK8j50TkEcjCcZ8dRAiPy&index=59)
- [Material de referencia 3 (YouTube)](https://www.youtube.com/watch?v=s4QG1mtSQ6Y&list=PL5YuOOJ-FGGjjK8j50TkEcjCcZ8dRAiPy&index=61)
- [Material de referencia 4 (YouTube)](https://www.youtube.com/watch?v=aEVH7oFoWnw&list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh&index=127)
- [Material de referencia 5 (YouTube)](https://www.youtube.com/watch?v=tbVHbfIVxs4&list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh&index=128)
- [Material de referencia 6 (YouTube)](https://youtu.be/gAqx0xvTDD0?si=tU3_auD5rBSPCFHw)
- [Material de referencia 7 (YouTube)](https://youtu.be/yvfeZyIzS10?si=qn5r_EvZMX2vuGfr)
- [Material de referencia 8 (YouTube)](https://youtu.be/B7XtOkeKYQU?si=LgAeSQtjQzxgJqjW)
- [Material de referencia 9 (YouTube)](https://youtu.be/wYboaB70-Zw?si=KZZrfV6hDdtkDGs-)