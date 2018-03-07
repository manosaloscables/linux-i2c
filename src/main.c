/*******************************************************************************
* Apliciación de demostración de comunicación I2C usando un Raspberry Pi 2 y un
* Arduino UNO
* Autor: Byron Quezada
*
* Ejemplo de comunicación I2C entre un Arduino y Linux. La distribución de Linux
* usada es Raspbian. Probablemente funcione con otros procesadores ARM que
* ejecuten una versión de Debian.
* El adaptador de I2C se selecciona del espacio de usuario a través de la
* interfaz /dev y se necesita el módulo i2c-dev que usualmente se carga por
* defecto.
* Creado el 7 de enero de 2018 basado en:
* <http://elinux.org/Interfacing_with_I2C_Devices>
* <https://www.kernel.org/doc/Documentation/i2c/dev-interface>
*******************************************************************************/

//#include <linuxI2C.h>

int main() {
  // Llamar una función en otro archivo
  miImpresionHolaMake();

  return(0);
}
