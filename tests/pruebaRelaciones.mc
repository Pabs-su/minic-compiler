void main(){
    print("hola mundo\n");
    var int x;
    print("Introduce un numero:\n");
    read(x);
    var int i = 0;
    while(x>=i){
        print(i,"\n");
        if(i == 0){
            print("Estamos en el comienzo del while\n");
        }
        i = i +1;
    }
}