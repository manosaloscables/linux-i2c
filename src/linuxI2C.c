#include <linuxI2C.h>

void miImpresionHolaMake(void) {

  printf("Hola Makefiles\n");

  return;
}

void openI2C(int* ptrFile, uint8_t adapterN){
  /* -----------------------> Abrir el adaptador I2C <----------------------- */
  char filename[11]; // Para almacenar /dev/i2c-#

  /* Acceder un adaptador I2C desde un programa en C */
  snprintf(filename, sizeof(filename), "/dev/i2c-%d", adapterN);

  /* Abrir el driver del bus I2C */
  if ((*ptrFile = open(filename, O_RDWR)) < 0) {
    /* MANEJO DE ERROR: revisar el errno para ver que salió mal */
    perror("Fallo al abrir el bus I2C.\n");
    exit(1);
  }
}
//
// void chooseDevice(int* ptrFile, uint8_t devAdd){
//   /* -------> Especificar la dirección del dispositivo a comunicar <--------- */
//   if (ioctl(*ptrFile, I2C_SLAVE, devAdd) < 0){
//     printf("Failed to acquire bus access and/or talk to slave.\n");
//     /* ERROR HANDLING; you can check errno to see what went wrong */
//     exit(1);
//   }
// }
