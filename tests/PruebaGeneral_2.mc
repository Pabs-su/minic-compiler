void main() {
    var int x;
    print("Introduce x: ");
    read(x);

    if (x >= 10) {
        if (x == 100) {
            print("Es exactamente cien");
        } else {
            print("Es mayor o igual a 10 pero no es cien");
        }
    } else {
        print("Es menor que 10");
    }
}