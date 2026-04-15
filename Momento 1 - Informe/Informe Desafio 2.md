# Fiesta mundial con UdeAWorldCup
> Informática II - G1 - 17/04/2026 

**Integrantes:** 
- Johan Steven Guarnizo Posada

- Oscar David Gutierrez Hernandez 

## Indice

- [1. Contextualización](#1-contextualización)
    - [1.1 Descripción breve del desafío y objetivos del curso](#11-descripción-breve-del-desafío-y-objetivos-del-curso)
    - [1.2 Consideraciones del desarrollo](#12-consideraciones-del-desarrollo)
- [2. Análisis del problema](#2-análisis-del-problema)
    - [2.1 Requisitos de desarrollo](#21-requisitos-de-desarrollo)
    - [2.2 Pasos a seguir](#22-pasos-a-seguir)
    - [2.3 Lógica de Competencia y Sorteo](#23-lógica-de-competencia-y-sorteo)
    - [2.4 Motor de Simulación](#24-motor-de-simulación)
    - [2.5 Clasificación y Fase Final](#25-clasificación-y-fase-final)
    - [2.6 Diagrama de clases](#26-diagrama-de-clases)
- [3. Cronograma](#3-cronograma)

## 1.Contextualización.
### 1.1 Descripción breve del desafío y objetivos del curso.
<div style="text-align: justify;">

El desafío consiste en desarrollar un programa en `C++` utilizando el paradigma de `Programación Orientada a Objetos (POO)` para simular el mundial de fútbol de la FIFA 2026. El sistema, denominado **UdeAWorldCup**, debe permitir la gestión y simulación automática de 104 partidos, integrando datos de 48 equipos y sus respectivos jugadores.   

</div> 

Las funcionalidades claves incluyen: 

<div style="text-align: justify;">

- **Gestión de datos:** Carga y actualización de estadísticas históricas de equipos y jugadores desde archivos, sin usar librerías de terceros.

- **Simulación técnica:** Configuración de grupos bajo restricciones de confederación y cálculo de goles basado en modelos matemáticos de rendimiento (ranking FIFA y promedios históricos).

</div>

<div style="text-align: justify;">

De esta manera, el desafío busca evaluar de forma práctica el dominio de técnicas avanzadas de programación en `C++`. Al mismo tiempo, se pretende verificar si el estudiante ha adquirido las destrezas y conocimientos fundamentales de la programación orientada a objetos en este lenguaje, tales como la abstracción, la encapsulación, las relaciones entre clases, el diseño de diagramas de clases, el empleo de funciones amigas, la sobrecarga de operadores y el uso de plantillas. 
</div>

<div style="text-align: justify;">

### 1.2 Consideraciones del desarrollo

El desarrollo del proyecto está sujeto a las siguientes limitaciones:
1. **Lenguaje:** La solución debe implementarse exclusivamente en `C++` con POO (Programación Orientada a Objetos).
    
2. **Prohibición de la STL:** No se permite el uso de contenedores que no hayan sido autorizados como `vector` o `list`.
    
3. **Gestión de Memoria Dinámica:** El manejo de los datos del sistema debe realizarse mediante **memoria dinámica** (uso de `new` y `delete`).
    
4. **Sin Structs:** Está explícitamente prohibido el uso de `structs`.
    
5. **Librerías Externas:** No se pueden usar librerías externas no autorizadas, a excepción de las autorizadas en clase, como `fstream` para manejo de archivos CSV, `string` para manejo de cadenas de texto.
    
6. **Modularidad:** El código debe estar organizado de forma modular mediante el uso de múltiples archivos (archivos de cabecera `.h` y de implementación `.cpp`).
    
</div>

## 2. Análisis del problema.

### 2.1 Requisitos de desarrollo.

<div style="text-align: justify;">

Teniendo en cuenta que las indicaciones para el desarrollo del desafío son:
- **Carga de Datos:** El sistema debe leer datos desde archivos (como `selecciones_clasificadas_mundial.csv`) y actualizar las estadísticas tras cada partido.
    
- **Simulación de Etapas:** Debe simular la etapa de grupos (12 grupos de 4 equipos), dieciseisavos, octavos, cuartos, semifinales y la final.
    
- **Lógica de Partidos:** Los partidos deben simularse automáticamente determinando goles, tarjetas, faltas y posesión de balón mediante modelos probabilísticos y el ranking FIFA. Cosa, explicada ampliamente en laa guia del desafio.
    
- **Generación de Estadísticas:** Al finalizar, el programa debe desplegar un informe con los 4 primeros puestos, máximos goleadores y la confederación con mayor presencia en cada etapa.
    
- **Medición de Recursos:** El sistema debe mostrar en pantalla la cantidad de iteraciones realizadas y el total de memoria consumida por todas las estructuras y objetos en ejecución.

</div>

### 2.2 Pasos a seguir

Teniendo en cuenta los requisitos anteriores, consideramos que los pasos que deben de seguirse para una elaboración optima son los siguientes:

<div style="text-align: justify;">

- **Diseño**
    - **Modelado de Entidades:** Definir las clases principales como `Equipo`, `Jugador`, `Partido`, `Torneo` y `Resultados`.
    
    - **Definición de Relaciones:** Definir cómo se relacionan las clases entre sí (por ejemplo, un `Equipo` tiene 26 `Jugadores` y un `Torneo` agrupa a todos los `Equipos` participantes).
    
    - **Sobrecarga de Operadores:** Definir al menos dos operadores propios, como `==` para comparar equipos o `<<` para mostrar estadísticas en consola.
    
- **Gestión de Memoria Dinámica**
    - **Abstracción de Memoria Dinámica:** Diseñar las estructuras de datos que reemplazarán a la STL (listas enlazadas o arreglos dinámicos) para gestionar los 48 equipos y 1,248 jugadores.
    
    - **Control de Recursos:** Implementar los métodos de medición para rastrear la memoria consumida, para al final, mostrar la memoria consumida.
    
- **Persistencia y Carga de Datos**
    - **Lecturaa de archivos:** Se permite el uso de `fstream` para la lectura y escritura de los archivos.
    
    - **Plantillas:** Generar artificialmente los nombres, apellidos y números de camiseta (del 1 al 26) para cada selección.
    
    - **Goles:** Repartir los goles de cada equipo entre sus jugadores de forma uniforme.
    
### 2.3 Lógica de Competencia y Sorteo
- **Conformación de Bombos:** Implementar el algoritmo de ordenamiento por ranking FIFA para distribuir los equipos en 4 bombos de 12 integrantes cada uno.
    
- **Sorteo de Grupos:** Crear la lógica para conformar los 12 grupos de 4 equipos, validando las restricciones geográficas (máximo 2 equipos de la UEFA por grupo y evitar otras confederaciones repetidas).
    
### 2.4 Motor de Simulación
- **Programación del Calendario:** Configurar las fechas y sedes de los 104 partidos, asegurando que ningún equipo juegue más de una vez en un lapso de 3 días.
    
- **Cálculo de Resultados:** Implementar la ecuación de goles esperados basada en goles a favor ($GF_A$), en contra ($GC_B$) y el ranking FIFA para determinar el ganador.
    
- **Gestión de Incidencias:** Simular tarjetas, faltas y minutos de juego (90 min regulares o 120 min en prórroga) según las probabilidades dadas.
    
### 2.5 Clasificación y Fase Final
- **Tablas de Posiciones:** Desarrollar la lógica de puntuación (3 pts por ganar, 1 por empatar) y aplicar criterios de desempate (diferencia de goles, goles a favor, sorteo).
    
- **Transición de Rondas:** Programar el flujo desde dieciseisavos hasta la final, manejando la eliminación directa y el desempate por ranking FIFA en caso de igualdad.

### 2.6 Diagrama de clases

Para comprender dde mejor manera el funcionamiento del desarrollo que hemos expuesto a lo largo del documento, se ha creado un diagrama de clases que muestra las relaciones entre las clases que planeamos implementar.

![Diagrama de clases inicial](<Material/Diagrama de clases inicial.jpg>)

En términos generales, queremos que el flujo del programa arranque desde la clase `Torneo`, que es la que coordina todo. Esta se encarga de leer el archivo CSV y con esa información inicializa los 48 `Equipo`s. Cada `Equipo` a su vez crea y administra sus 26 `Jugador`es. Una vez cargados los datos, `Torneo` organiza el sorteo de grupos y genera los partidos. Para simular cada encuentro, se usa la clase `Partido`, que recibe los dos equipos enfrentados y calcula el resultado basándose en sus estadísticas y el ranking FIFA. Finalmente, `Resultados` almacena lo que ocurrió en cada partido y le devuelve la información a `Torneo` para que actualice las tablas de posiciones y avance a la siguiente ronda.

</div>

<div style="text-align: justify;">

## 3. Cronograma

Teniendo en cuenta que la entreega del informe es el viernes 16 y el sabado 17 es fecha de parciales presenciales en la sede, y a la vez, en vista de que la fecha de entrega del desafío en su totalidad es el viernes 24 de abril, consideramos correcto que las fechas paraa desarrollar el resto del desarrollo sean las siguientes:

- Desde el Domingo 19 de abril hasta el Lunes 20 de abril:
    - Desarrollar las clases con sus respectivos atributos y metodos. 

- Desde el Martes 21 de abril hasta el Jueves 23 de abril:
    - Desarrollar el motor de simulación y la lógica de competencia.
    - Desarrollar la clasificación y la fase final.

- Y, finalmente el viernes 24 de abril:
    - Desarrollar el informe y el diagrama de clases actualizado.
    - Desarrollar video.
    - Entregar el trabajo.

Siendo de esta forma que damos por finalizado el primer momento de este Desafio #2, el Informe. 

</div>