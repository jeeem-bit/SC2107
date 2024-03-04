// IRDistance.c
// Runs on MSP432
// Provide mid-level functions that convert raw ADC
// values from the GP2Y0A21YK0F infrared distance sensors to
// distances in mm.
// Jonathan Valvano
// May 25, 2017

/* This example accompanies the books
   "Embedded Systems: Introduction to the MSP432 Microcontroller",
       ISBN: 978-1512185676, Jonathan Valvano, copyright (c) 2017
   "Embedded Systems: Real-Time Interfacing to the MSP432 Microcontroller",
       ISBN: 978-1514676585, Jonathan Valvano, copyright (c) 2017
   "Embedded Systems: Real-Time Operating Systems for ARM Cortex-M Microcontrollers",
       ISBN: 978-1466468863, , Jonathan Valvano, copyright (c) 2017
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/

Simplified BSD License (FreeBSD License)
Copyright (c) 2017, Jonathan Valvano, All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are
those of the authors and should not be interpreted as representing official
policies, either expressed or implied, of the FreeBSD Project.
*/

// Pololu #3543 Vreg (5V regulator output) connected to all three Pololu #136 GP2Y0A21YK0F Vcc's (+5V) and MSP432 +5V (J3.21)
// Pololu #3543 Vreg (5V regulator output) connected to positive side of three 10 uF capacitors physically near the sensors
// Pololu ground connected to all three Pololu #136 GP2Y0A21YK0F grounds and MSP432 ground (J3.22)
// Pololu ground connected to negative side of all three 10 uF capacitors
// MSP432 P9.0 (J5) (analog input to MSP432) connected to right GP2Y0A21YK0F Vout
// MSP432 P4.1 (J1.5) (analog input to MSP432) connected to center GP2Y0A21YK0F Vout
// MSP432 P9.1 (J5) (analog input to MSP432) connected to left GP2Y0A21YK0F Vout

#include <stdint.h>
#include "../inc/ADC14.h"
#include "msp.h"
#include <stdio.h>
#include <math.h>


/*
 * Routine to convert Filtered Raw ADC values to distance data.
 * Either via curve fitting (hyperbolic, polynomial, log etc), or piece-wise linear method.
 */
int32_t LeftConvert(int32_t nl){        // returns left distance in mm
  // write this for Lab 4
    //length += (-0.325)*nl*nl*nl + 35.692*nl*nl - 1328.6*nl + 20094;
    //uint32_t length = n
    //uint32_t length = 90577.36/(nl-312.0392);
    //length = 100000 / (nl + 2140) * 10;
    uint32_t length = 100000 / (nl - 2630);

    return length;
}

int32_t CenterConvert(int32_t nc){   // returns center distance in mm
  // write this for Lab 4
    //length += (-0.2213)*nc*nc*nc + 26.863*nc*nc - 1146.2*nc + 20422;
    //length = 723958*pow(nc, -1.208);
    //length = 125000 / (nc + 2500) * 10;
    uint32_t length = 100000 / (nc - 2620);
    return length;
}

int32_t RightConvert(uint32_t nr){      // returns right distance in mm
  // write this for Lab 4
    //length += (-0.3179)*nr*nr*nr + 34.969*nr*nr - 1303.2*nr + 19834;
    //length = (-2)*pow(10, -18)*pow(nr, 5) + 8*pow(10, -14)*pow(nr, 4) - 2*pow(10, -9)*pow(nr, 3) + pow(10, -5)*nr*nr - 0.0722*nr + 160.09;
    //length = pow(10, 5) / (nr - 2320) * 10;
    //length = 100000 / (nr - 980) * 10;
    uint32_t length = 100000 / (nr - 2390);
    return length;
}
