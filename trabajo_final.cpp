#include <iostream>
using namespace std;
void cantidad_por_tipo(string, int &, int &, int &);
int cantidad_vino_toro(string);
int cantidad_oferta(bool);
void precio_mayor(int, int, int &, int &, string, string &);
int floresta_y_blanco(string, string);
int procentaje_venta(int);
void calcular_porcentaje_venta(int, int, int &);
void cantidad_de_tipos(string);
void lista_marcas(string, string[], int[]);
void encontrar_elemento_marca(string, string[], int[]);
void mostrar_lista_marcas(string[], int[]);

int main()
{
  int codigo, precio_sin_impuesto, precio_venta, cantidad_malbec = 0, cantidad_tinto = 0, cant_floresta_y_blanco = 0, porc_cant_mayor, suma_venta = 0;
  int i = 0, cantidad_blanco = 0, suma_toro = 0, suma_oferta = 0, suma_cant_mayor = 0, mayor = 0;
  int mas_caro, suma_sin_impuestos = 0, codigo_mas_caro, listado_de_precio[4] = {0, 0, 0, 0};
  string nombre, marca, tipo, nombre_mayor, listado_de_marcas[4] = {"toro", "linaje", "superior", "ventaron"}, listado_de_tipos[i];
  bool oferta, decision = false;

  do
  {
    i++;
    cout << i << ". " << endl;
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
    cout << " Si desea ingresar la informacion de otro vino, ingrese 1, caso contrario ingrese 0: ";
    cin >> decision;
    cout << endl;
    cantidad_por_tipo(tipo, cantidad_malbec, cantidad_tinto, cantidad_blanco);
    suma_toro += cantidad_vino_toro(marca);
    suma_oferta += cantidad_oferta(oferta);
    suma_venta += procentaje_venta(precio_venta);
    cant_floresta_y_blanco += floresta_y_blanco(marca, tipo);
    suma_sin_impuestos += precio_sin_impuesto;
    precio_mayor(precio_venta, codigo, mayor, codigo_mas_caro, nombre, nombre_mayor);
    lista_marcas(marca, listado_de_marcas, listado_de_precio);
  } while (decision == 1);
  // ejercicio a//
  cout << " La cantidad de vinos malbec es de: " << cantidad_malbec << endl;
  cout << " La cantidad de vinos tintos es de: " << cantidad_tinto << endl;
  cout << " La cantidad de vinos blancos es de: " << cantidad_blanco << endl;

  // ejercicio b//
  cout << " La cantidad de pedidos de vinos de marca toro fue de: " << suma_toro << endl;

  // ejercicio c//
  cout << " La cantidad de articulos con oferta fue de: " << suma_oferta << endl;

  // ejercicio d//
  calcular_porcentaje_venta(suma_venta, i, porc_cant_mayor);

  cout << " El porcentaje de vinos mayores a 15000 es de: " << porc_cant_mayor << "%" << endl;

  // ejercicio e//

  cout << " La cantidad de vinos de la marca Floresta y que sean vinos blancos es de: " << cant_floresta_y_blanco << endl;

  // ejercicio f//

  cout << " El vino mas caro fue " << nombre_mayor << ". Con un precio de: " << mayor << ". Codigo: " << codigo_mas_caro << endl;

  // ejercicio g//

  cout << " El precio total acumulado de los vinos, sin contar impuestos, es de: " << suma_sin_impuestos << endl;

  // ejercicio h//

  mostrar_lista_marcas(listado_de_marcas, listado_de_precio);
  return 0;
}

void cantidad_por_tipo(string tipo, int &cantidad_malbec, int &cantidad_tinto, int &cantidad_blanco)
{
  if (tipo == "malbec")
  {
    cantidad_malbec++;
  }
  else if (tipo == "tinto")
  {
    cantidad_tinto++;
  }
  else if (tipo == "blanco")
  {
    cantidad_blanco++;
  }
}

int cantidad_vino_toro(string marca)
{
  if (marca == "toro")
  {
    return 1;
  }
  else
    return 0;
}

int cantidad_oferta(bool oferta)
{
  if (oferta == 1)
  {
    return 1;
  }
  else
    return 0;
}

int procentaje_venta(int precio_venta)
{
  if (precio_venta > 15000)
  {
    return 1;
  }
  else
    return 0;
}

void calcular_porcentaje_venta(int suma, int i, int &porc_cant_mayor)
{
  porc_cant_mayor = ((suma * 100) / i);
}

int floresta_y_blanco(string marca, string tipo)
{
  if ((tipo == "blanco") && (marca == "floresta"))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void precio_mayor(int precio, int codigo, int &mayor, int &codigo_mayor, string nombre, string &nombre_mayor)
{
  if (precio > mayor)
  {
    mayor = precio;
    codigo_mayor = codigo;
    nombre_mayor = nombre;
  }
}

void lista_marcas(string marca, string listado_marcas[], int cantidad[])
{
  for (int i = 0; i < 4; i++)
  {
    encontrar_elemento_marca(marca, listado_marcas, cantidad);
  }
}

void encontrar_elemento_marca(string marca, string listado_marca[], int cantidad[])
{
  for (int i = 0; i < 4; i++)
  {
    if (listado_marca[i] == marca)
    {
      cantidad[i]++;
      break;
    }
  }
}
void mostrar_lista_marcas(string listado_marcas[], int cantidad[])
{

  for (int i = 0; i < 4; i++)
  {
    cout << listado_marcas[i] << " ventas: " << (cantidad[i] / 4) << endl;
  }
}