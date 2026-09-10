// TorreAjedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Torre {
  private:
    int fila;
    int columna;
	bool isBlack;

    bool validarMovimiento(int newfila, int newcolum) {
        if (newfila == fila && newcolum!=columna) {
            return (newfila == fila) || (newcolum == columna);
            return true;
        }
        else if (newcolum == columna && newfila != fila) {
            return (newfila == fila) || (newcolum == columna);
            return true;
        }else {
            return false;
        }
    }
  public:
      Torre(int f, int c, bool black) {
          fila = f;
          columna = c;
          isBlack = black;
      }
      void movimiento(int newfila, int newcolum) {
          if (newfila >= 1 && newfila <= 8 && newcolum>=1 && newcolum<=8) {
              if (validarMovimiento(newfila, newcolum)) {
                  fila = newfila;
                  columna = newcolum;
                  cout << "Movimiento exitoso";
              }
              else {
                  cout << "Movimiento invalido para una torre";
              }
          }
          else {
              cout << "Coordenadas invalidas" << endl;
          }
      }
      string dibuja() {
          if (isBlack) {
              return "[##]";
          }
          else {
              return "[TT]";
          }
      }

      void imprimir() {
          string color = isBlack ? "Negro" : "Blanco";
          cout <<dibuja() << " " << color << " en la fila: " << fila << ", Columna: " << columna << endl;
      }
};

int main()
{
    Torre torreBlanca(1, 1, false);
    Torre torreNegra(8, 8, true);

    cout << "    POSICION DE LAS TORRES" << endl;
    torreBlanca.imprimir();
    torreNegra.imprimir();
    cout << "-----------------------------------" << endl;

    int nuevaFila, nuevaColumna;

    cout << "\n--- Moviendo de la Torre Blanca ---" << endl;
    cout << "Ingrese nueva fila (1-8): ";
    cin >> nuevaFila;
    cout << "Ingrese nueva columna (1-8): ";
    cin >> nuevaColumna;

    torreBlanca.movimiento(nuevaFila, nuevaColumna);
    torreBlanca.imprimir();

    cout << "\n--- Moviendo de la Torre Negra ---" << endl;
    cout << "Ingrese nueva fila (1-8): ";
    cin >> nuevaFila;
    cout << "Ingrese nueva columna (1-8): ";
    cin >> nuevaColumna;

    torreNegra.movimiento(nuevaFila, nuevaColumna);
    torreNegra.imprimir(); 

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
