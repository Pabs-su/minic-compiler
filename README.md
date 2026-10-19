# Compilador miniC a MIPS

Este repositorio contiene la implementación completa de un compilador capaz de traducir programas escritos en un subconjunto simplificado de C (`miniC`) a código ensamblador ejecutable para la arquitectura MIPS.

El proyecto abarca el ciclo completo de compilación:
1. **Análisis Léxico:** Implementado con `flex`.
2. **Análisis Sintáctico:** Implementado con `bison`.
3. **Análisis Semántico y Generación de Código:** Escrito en `C`.

## Stack Tecnológico
* **C**
* **Flex** (Lexical Analyzer Generator)
* **Bison** (GNU Parser Generator)
* **Make / GCC**
* **SPIM / MARS** (Simuladores MIPS)

## Alcance y Características (miniC)

El lenguaje fuente, `miniC`, presenta las siguientes características y restricciones:

* **Tipos de Datos:** Soporta exclusivamente variables y constantes de tipo entero (tamaño `word` en MIPS, 32 bits, valores absolutos entre 0 y 2^31).
* **Operaciones:**
  * Aritmética básica: Suma (`+`), Resta (`-`), Multiplicación (`*`), División entera (`/`), Cambio de signo unario (`-`).
  * **Ampliación:** Operador de potencia entera (`**`), no asociativo y con prioridad sobre el cambio de signo (ej: `-2**3` se evalúa como `-(2**3)`).
* **Estructuras de Control:** `if`, `if-else`, y bucles `while`.
* **Entrada/Salida:** Instrucciones integradas `read` (para leer enteros de consola) y `print` (para mostrar enteros o cadenas de caracteres).
* **Evaluación de Condiciones:** Al no existir operadores relacionales explícitos (en la versión base), las expresiones aritméticas se evalúan lógicamente como en C estándar: `0` es *Falso* y cualquier otro valor entero es *Verdadero*.
* **Estructura del Programa:** Consiste en un bloque principal único delimitado por `void main() { ... }`.

El código resultante es un archivo ensamblador (extensión `.s`) estructurado en una sección `.data` para símbolos y `.text` para instrucciones, utilizando llamadas al sistema (`syscall`) para las operaciones de E/S.

## Guía de Compilación y Ejecución

### 1. Construir el Compilador
Asegúrate de tener instalados `flex`, `bison` y `gcc`. En la terminal, ejecuta:
```bash
make
