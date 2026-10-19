void main() {
    var int a = 5;
    var int a;               // ERROR 1: Variable doblemente declarada
    const int PI = 3;
    
    PI = 4;                  // ERROR 2: Asignacion a constante
    
    b = 10;                  // ERROR 3: Asignacion a variable no declarada
    
    a = a + no_existo * 2;   // ERROR 4: Uso de variable no declarada en expresion
    
    read(a, variableFantasma); // ERROR 5: Read a variable no declarada
}