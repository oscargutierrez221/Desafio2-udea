# UdeAWorldCup - Simulador del Mundial FIFA 2026

Repositorio del **Desafío 2** de Programación Orientada a Objetos (POO) de la Universidad de Antioquia.

Desarrollamos un simulador completo del Mundial de Fútbol FIFA 2026 en **C++** usando exclusivamente Programación Orientada a Objetos, memoria dinámica y sin contenedores avanzados de la STL (como se solicitó en el enunciado).

## Sobre el Proyecto

**UdeAWorldCup** permite:
- Cargar 48 equipos y sus jugadores desde archivos CSV
- Conformar bombos y grupos respetando restricciones de confederaciones (máximo 2 equipos UEFA por grupo)
- Simular los 104 partidos del torneo (fase de grupos + eliminatorias)
- Llevar estadísticas detalladas de equipos y jugadores
- Mostrar resultados, tablas de posiciones y determinar el campeón

### Tecnologías utilizadas
- **Lenguaje:** C++
- **Framework:** Qt-Creator
- **Build system:** qmake

## Estructura del Repositorio

```bash
Desafio2-udea/
├── Desarrollo/                    # Código fuente principal del simulador
│   ├── Desarrollo.pro             
│   ├── main.cpp
│   ├── equipo.h / equipo.cpp
│   ├── jugador.h / jugador.cpp
│   ├── partido.h / partido.cpp
│   ├── resultados.h / resultados.cpp
│   ├── torneo.h / torneo.cpp
│   ├── organizador.h / organizador.cpp
│   └── CSV/                       # Archivos de datos (equipos y jugadores)
│
├── Momento 1 - Informe/           # Entrega del primer momento (informe inicial)
│└── Material/
│   └── Diagrama de clases inicial
│
├── Momento 3 - Documentacion/     # Documentación completa del proyecto
│   ├── documentacion.md
│   └── Material/
│       └── Diagrama de clases documentacion.png
│
│
├──  Momento 4 - Video
│   ├── Evidencia Video.txt
├ 
└── README.md
```

## Cómo compilar y ejecutar

### Requisitos
- Tener Qt-Creator
### Pasos

1. Clona el repositorio:
   ```bash
   git clone https://github.com/oscargutierrez221/Desafio2-udea.git
   ```

2. Abre el proyecto en **Qt Creator**:
   - Abre el archivo `Desarrollo/Desarrollo.pro`

3. Configura el kit de Qt y compila.

4. Cambia las rutas de los archivos CSV
5. Ejecuta la aplicación (Ctrl + R).

## Integrantes

- **Óscar David Gutiérrez Hernández** (oscargutierrez221)
- **Johan Steven Guarnizo Posada** (JohanSteven-08)

## Entregas

- **Momento 1**: Informe inicial → [`Momento 1 - Informe/`](Momento%201%20-%20Informe/)
- **Momento 2**: Desarrollo del proyecto (código fuente) → [`Momento 2 - Desarrollo/`](Momento%202%20-%20Desarrollo/)
- **Momento 3**: Documentación técnica completa → [`Momento 3 - Documentacion/`](Momento%203%20-%20Documentacion/)
- **Momento 4**: Video de sustentación → [`Momento 4 - Video/`](Momento%204%20-%20Video/)
