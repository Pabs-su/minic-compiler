void main() {
    var int x, y, z, res;
    x = 5;
    y = -3;
    z = 10;
    
    // Precedencia: UMINUS, luego *, luego -, luego +
    // Debe ser: 5 + (-(-(-3)) * 10) - (20 / 4)
    // = 5 + (-3 * 10) - 5 = 5 - 30 - 5 = -30
    res = x + -(-y) * z - 20 / 4;
    print("El resultado debe ser -30: ", res, "\n");
    
    // Agotar registros: 10 operandos
    res = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;
    print("La suma del 1 al 10 debe ser 55: ", res, "\n");
}