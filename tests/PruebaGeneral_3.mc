void main() {
    var int i;
    i = 0;

    print("Bucle Do-While con Break: ");
    do {
        if (i == 5) {
            print(" Rompemos en 5 ");
            break; 
        }
        print(i);
        i = i + 1;
    } while (i < 10);

    print(" Fin del test.");
}