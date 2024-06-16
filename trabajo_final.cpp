#include <iostream>
using namespace std;
int tipo_de_vino(string);
bool toro(string);
int cantidad_toro(string);
int cantidad_oferta(bool);
int precio_mayor(int);
void mas_caro_ex(int, int, int, int, int);
void cantidad_de_tipos(string);

int main()
{
  int codigo, precio_sin_impuesto, precio_venta, cantidad_malbec = 0, cantidad_tinto = 0, porc_cant_mayor;
  int i = 0, cantidad_blanco = 0, suma_toro = 0, suma_oferta = 0, suma_cant_mayor = 0, mayor = 0;
  int mas_caro, suma_sin_impuestos = 0, codigo_mas_caro, listado_de_marcas[i];
  string nombre, marca, tipo;
  bool oferta, decision = 1;

  do
  {
    cout << " Ingrese el codigo del vino: ";
    cin >> codigo;
    cout << " Ingrese el nombre del vino: ";
    cin >> nombre;
    cout << " Ingrese la marca del vino: ";
    cin >> marca;
    cout << " Ingrese el tipo de vino: ";
    cin >> tipo;
    cout << " Ingrese el precio sin impuesto: ";
    cin >> precio_sin_impuesto;
    cout << " Ingrese el precio de venta al publico: ";
    cin >> precio_venta;
    cout << " Si el elemento posee oferta ingrese 1, caso contrario ingrese 0: ";
    cin >> oferta;
    i++;
    cout << " Si desea ingresar la informacion de otro vino, ingrese 1, caso contrario ingrese 0: ";
    cin >> decision;
    cantidad_de_tipos(tipo);
    suma_toro += cantidad_toro(marca);
    suma_oferta += cantidad_oferta(oferta);
    suma_cant_mayor += precio_mayor(precio_sin_impuesto);
    suma_sin_impuestos += precio_sin_impuesto;
    mas_caro_ex(precio_venta, mayor, mas_caro, codigo_mas_caro, codigo);
  } while (decision == 1);
  porc_cant_mayor = (suma_cant_mayor * 100) / i;
  return 0;
}

int tipo_de_vino(string vino)
{

  if (vino == "malbec")
  {
    return 1;
  }
  else if (vino == "tinto")
  {
    return 2;
  }
  else if (vino == "blanco")
  {
    return 3;
  }
  return 0;
}

bool toro(string marca)
{
  if (marca == "toro")
  {
    return 1;
  }
  else
    return 0;
}

int cantidad_toro(string marca)
{
  int cant_toro = 0;
  if (toro(marca) == 1)
  {
    cant_toro++;
  }
  return cant_toro;
}

int cantidad_oferta(bool of)
{
  if (of == 1)
  {
    return 1;
  }
  else
    return 0;
}

int precio_mayor(int precios)
{
  if (precios > 15000)
  {
    return 1;
  }
  else
    return 0;
}

int floresta_y_blanco(string marca, string tipo)
{
  if ((tipo == "floresta") && (marca == "blanco"))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void mas_caro_ex(int precio_venta, int mayor, int mas_caro, int codigo_mas_caro, int codigo)
{
  if (precio_venta > mayor)
  {
    mas_caro = precio_venta;
    codigo_mas_caro = codigo;
  }
}

void cantidad_de_tipos(string tipo)
{
  int cantidad_malbec = 0, cantidad_blanco = 0, cantidad_tinto = 0;
  if (tipo_de_vino(tipo) == 1)
  {
    cantidad_malbec++;
  }
  if (tipo_de_vino(tipo) == 2)
  {
    cantidad_blanco++;
  }
  if (tipo_de_vino(tipo) == 3)
  {
    cantidad_tinto++;
  }
}
