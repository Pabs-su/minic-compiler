void main() {
    const int TOPE = 100;
    var int a;
    
    // Error 1: Uso de variable no declarada
    a = b + 10; 
    
    // Error 2: Asignación a una constante
    TOPE = 50;  
    
    if (a > 0) {
        // Error 3: Break fuera de un bucle
        break;  
    }
}