void main() {
    var int i, j;
    i = 0;
    
    print("Inicio del laberinto");
    while (i < 3) {
        j = 0;
        print(" Nivel exterior: ", i);
        
        do {
            if (j == 1) {
                print(" -- Rompiendo interior");
                break; // Debe salir SOLO del do-while
            }
            print(" ---- Nivel interior: ", j);
            j = j + 1;
        } while (j < 3);
        
        if (i == 2) {
            print(" Rompiendo exterior");
            break; // Debe salir del while principal
        }
        i = i + 1;
    }
    print(" Fin del laberinto");
}