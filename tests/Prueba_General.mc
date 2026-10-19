/*
Fichero de prueba donde probaremos todas las posibles opciones del codigo, para poder depurarlo de forma correcta

*/


void main(){

    var int a = 10; //Declaramos en una sola linea la variable y asignamos codigo
    var int b;
    b = 20;
    var int i = 0; //variable para simular bucle while

    while(i<20){
        //Bucle que en teoria deberia de hacer 20 iteraciones
        if(i == 15){
            break; //Probamos tanto los if, como el break
        }
        i = i+1;
    }
    print("El valor de la variable i es de: ",i);
}