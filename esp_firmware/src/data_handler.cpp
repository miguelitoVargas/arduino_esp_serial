#include <Arduino.h>
#include <data_handler.h>


void data_handler::handleData() {

  if(Serial.available()){

    int inByte = Serial.read();

    if(inByte == 255 || inByte >= NUM_BYTES) serialCount = 0;

    // add a byte
    serialInArray[serialCount] = inByte;
    serialCount++;
//    Serial.write('A'); // ask for more

    yield();

  }else {

/*    if(inByte == 'A'){
      Serial.flush();
      firstContact = true;
      Serial.write('A'); // ask for more*/
    }

  
}




