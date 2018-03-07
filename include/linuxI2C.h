#ifndef _LINUXI2C_H_
#define _LINUXI2C_H_

#include <stdio.h>          // Needed for printf, snprintf, perror
#include <stdint.h>         // Needed for unit uint8_t data type
#include <fcntl.h>          // Needed for open()
// #include <unistd.h>         // Needed for close()
#include <stdlib.h>         // Needed for exit()
// #include <sys/ioctl.h>      // Needed for ioctl
// #include <linux/i2c-dev.h>  // Needed to use the I2C Linux driver (I2C_SLAVE)

void miImpresionHolaMake(void);
void openI2C(int* ptrFile, uint8_t adapterN);
// void chooseDevice(int* ptrFile, uint8_t devAdd);

#endif // _LINUXI2C_H_
