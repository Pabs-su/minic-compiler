<div align="center">

# ⚙️ Compilador miniC a Ensamblador MIPS

![C](https://img.shields.io/badge/Lenguaje-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Flex](https://img.shields.io/badge/Lexer-Flex-4EAA25?style=for-the-badge)
![Bison](https://img.shields.io/badge/Parser-Bison-FF6F00?style=for-the-badge)
![MIPS](https://img.shields.io/badge/Target-MIPS_32-E34F26?style=for-the-badge)
![Linux](https://img.shields.io/badge/Entorno-Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

**Implementación completa de un compilador traductor desde el lenguaje `miniC` (subconjunto de C) hacia código ensamblador ejecutable para arquitectura MIPS32.**

*Proyecto desarrollado para la asignatura de Compiladores — Grado en Ingeniería Informática (Universidad de Murcia).*

</div>

---

## 📌 Arquitectura del Compilador

El compilador sigue una arquitectura en pipeline dividida en 4 etapas fundamentales, gestionando errores léxicos, sintácticos y semánticos en tiempo de compilación:

```text
[ Código Fuente (.mc) ]
          │
          ▼
┌───────────────────┐
│  1. Analizador    │ ──► Expresiones regulares (Flex) y filtrado de comentarios.
│     Léxico        │     Recuperación de errores en modo pánico.
└─────────┬─────────┘
          │ Flujo de Tokens
          ▼
┌───────────────────┐
│  2. Analizador    │ ──► Gramática Libre de Contexto BNF (Bison).
│     Sintáctico    │     Resolución de precedencias y asociatividad.
└─────────┬─────────┘
          │ Árbol Sintáctico / Reglas
          ▼
┌───────────────────┐
│  3. Analizador    │ ──► Gestión de Tabla de Símbolos (.data).
│     Semántico     │     Control de tipos, declaraciones duplicadas y constantes.
└─────────┬─────────┘
          │ Lista Enlazada de Cuádruplas
          ▼
┌───────────────────┐
│  4. Generador de  │ ──► Asignación dinámica de registros temporales ($t0 - $t9).
│     Código MIPS   │     Traducción de expresiones, saltos y llamadas (syscall).
└─────────┬─────────┘
          │
          ▼
[ Ensamblador MIPS (.s) ]
```

---

## ✨ Características Soportadas (`miniC`)

| Categoría | Especificación e Implementación |
| :--- | :--- |
| **Tipos de Datos** | Variables (`var`) y constantes (`const`) enteras de 32 bits (`word` en MIPS), además de literales de cadena (`.asciiz`). |
| **Operadores Aritméticos** | Suma (`+`), resta (`-`), multiplicación (`*`), división entera (`/`) y signo negativo unario (`-`). |
| **Operador Potencia** | Soporte para exponenciación entera (`**`) asociativa por la derecha mediante bucles en ensamblador. |
| **Control de Flujo** | Condicionales simples (`if`), compuestos (`if-else`) e iteraciones (`while`) evaluados al estilo C (`0` = Falso, `!= 0` = Verdadero). |
| **Entrada / Salida** | Instrucciones nativas `read(x)` y `print(lista)` traducidas directamente a servicios del sistema (`syscall 1, 4 y 5`). |
| **Validación Semántica** | Verificación de variables no declaradas, redeclaraciones prohibidas e inmutabilidad de constantes (`const`). |

---

## 🚀 Guía Rápida de Compilación y Uso

### 1. Requisitos previos
Necesitas un entorno Linux con las herramientas de construcción estándar:
```bash
sudo apt-get install gcc make flex bison spim
```

### 2. Compilar el proyecto
Ejecuta el `Makefile` incluido en el repositorio para generar el analizador léxico, el sintáctico y el binario final:
```bash
make
```

### 3. Traducir un programa `miniC` a `MIPS`
Pasa cualquier archivo de prueba `.mc` al compilador y vuelca la salida en un fichero `.s`:
```bash
./minic programa.mc > salida.s
```

### 4. Ejecutar en el simulador MIPS
Ejecuta el código ensamblador generado utilizando **SPIM** (o mediante interfaz gráfica en **MARS**):
```bash
spim -file salida.s
```

---

## 💻 Ejemplo de Traducción

### Entrada en `miniC` (`ejemplo.mc`)
```c
void main() {
    const int a = 0;
    var int c = 5 + 2 - 2;
    print("Inicio del programa\n");

    if (a) print("a\n");
    else while (c) {
        c = c - 2 + 1;
        print("c = ", c, "\n");
    }
    print("Final\n");
}
```

### Salida generada en `MIPS` (`salida.s`)
```mips
##################
# Seccion de datos
    .data
$str1:  .asciiz "Inicio del programa\n"
$str2:  .asciiz "a\n"
$str3:  .asciiz "c = "
$str4:  .asciiz "\n"
$str5:  .asciiz "Final\n"
_a:     .word 0
_c:     .word 0

###################
# Seccion de codigo
    .text
    .globl main
main:
    li $t0, 0
    sw $t0, _a
    li $t0, 5
    li $t1, 2
    add $t2, $t0,$t1
    li $t0, 2
    sub $t1, $t2,$t0
    sw $t1, _c
    la $a0,$str1
    li $v0, 4
    syscall
    ...
    # Final: exit
    li $v0, 10
    syscall
```

---
