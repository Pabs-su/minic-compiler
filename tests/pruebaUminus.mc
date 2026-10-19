void main() {
    var int a, b, c;
    a = 10;
    b = -5;
    
    // Debería calcular: 10 + (-(-5) * 2) = 10 + (5 * 2) = 20
    c = a + -(-b) * 2; 
    
    // Una operación super larga para ver si te quedas sin registros
    a = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10; 
    
    print("El valor de c debe ser 0: ", c);
    print("El valor de a debe ser 55: ", a);
}