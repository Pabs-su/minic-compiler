// Prueba Integral de Generacion de Codigo
void main() {
    var int base = 2, multiplicador = 3; 
    var int result = base * multiplicador;
    const int limite = 10;
    var int contador = 0;

    print("Iniciando calculos...\n");

    do {
        if (contador == 5) {
            print("Llegamos a la mitad\n");
        } else {
            result = result + 1;
        }
        contador = contador + 1;
    } while (contador < limite);

    while (result > 0) {
        result = result - 2;
        if (result <= 5) {
            print("Rompiendo el bucle!\n");
            break; // Salto fuera del while
        }
    }

    print("Valor final: ", result);
}