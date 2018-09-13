#pragma once

#include <Arduino.h>
// waiting for  13 bytes counting byte=255
#define NUM_BYTES 13 

class data_handler {

  public:

    // data array 
    int serialInArray[NUM_BYTES];
    int serialCount;
    bool firstContact = false;
  // assign address in declaration
    int * pointerArray = serialInArray;

    // handlers
    void handleData();


};
