#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
};

int contarPuntosEnCuadrante(Point puntos[], int n, int cuadrante) {
    int contador = 0;

    for (int i = 0; i < n; i++) {
        double x = puntos[i].x;
        double y = puntos[i].y;

        // Ignorar puntos sobre los ejes
        if (x == 0 || y == 0) {
            continue;
        }

        if (cuadrante == 1 && x > 0 && y > 0) {
            contador++;
        }
        else if (cuadrante == 2 && x < 0 && y > 0) {
            contador++;
        }
        else if (cuadrante == 3 && x < 0 && y < 0) {
            contador++;
        }
        else if (cuadrante == 4 && x > 0 && y < 0) {
            contador++;
        }
    }

    return contador;
}

int main() {
    int n;
    int cuadrante;
    cout <<"El programa le pedira unas coordenadas y contara la cantidad de coordenadas que esten en el cuadrante que especifique"<< endl;
    cout << "Ingrese la cantidad de coordenadas que desea evaluar: ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "La cantidad debe estar entre 1 y 10." << endl;
        return 1;
    }

    Point puntos[100];

    for (int i = 0; i < n; i++) {
        cout << "Ingrese x de la coordenada " << i + 1 << ": ";
        cin >> puntos[i].x;

        cout << "Ingrese y de la coordenada " << i + 1 << ": ";
        cin >> puntos[i].y;
    }
    cout << "Ingrese el cuadrante en el que desea buscar (1-4): ";
    cin >> cuadrante;

    int resultado = contarPuntosEnCuadrante(puntos, n, cuadrante);

    cout << "Cantidad de coordenadas en el cuadrante " << cuadrante <<" es: "<< resultado << endl;

    return 0;
}