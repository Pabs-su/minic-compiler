void main() {
    var int x;
    x = 10;
    
    print("Prueba del Else Colgante: ");
    
    if (x > 5) 
        if (x == 100) 
            print("x es 100");
        else 
            print("x es mayor que 5 pero no es 100"); // DEBE IMPRIMIR ESTO
            
    // Si la prioridad de ABAJO_DEL_ELSE está mal, 
    // Bison podría pensar que el 'else' es del primer if.
}