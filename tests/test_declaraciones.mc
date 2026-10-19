void main() {
    var int a = 10, b = 20; 
    var int c;
    const int FACTOR = 2;
    
    // Si la traducción hacia arriba funciona, c valdrá 60.
    // Si falla, a y b valdrán 0 y c valdrá 0.
    c = (a + b) * FACTOR;
    
    print("El valor de a es: ", a, "\n");
    print("El valor de b es: ", b, "\n");
    print("El valor de c debe ser 60: ", c, "\n");
}