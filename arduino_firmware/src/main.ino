/*asigna todos los pines digitales del arduino a botones
  para luego enviar por el puerto serial un paquete con el valor de cada uno
  0-1, el primer byte es 255*/

// pin settings
#define NUM_PINS 12
int pin_array[NUM_PINS];
int pin_states[NUM_PINS];
//--serial com settings 
int initial_byte = 255;
int inByte = 0; // incoming serial byte

void setup() {

  Serial.begin(115200);
  // +2 por el pin offset 
  for(int i = 2; i < NUM_PINS + 2; i++){

    // 
    pin_array[i-2] = i;
    //    pinMode(pin_array[i], INPUT_PULLUP);
    // only write to serial when there is a change with the buttons
//    Serial.println(pin_array[i-2]);
    delay(2);
  }

  //pinMode(13,OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

  // shake hands function
 // establishContact();
}


void loop() {

  // comment/uncomment for debbuging

  /*  Serial.print(pin_states[0]);
      Serial.print(pin_states[1]);
      Serial.print(pin_states[2]);
      Serial.print(pin_states[3]);
      Serial.print(pin_states[4]);
      Serial.print(pin_states[5]);
      Serial.print(pin_states[6]);
      Serial.print(pin_states[7]);
      Serial.print(pin_states[8]);
      Serial.print(pin_states[9]);
      Serial.print(pin_states[10]);
      Serial.println(pin_states[11]);*/ 
  //---------------


 // if(Serial.available()) {

    //  inByte = Serial.read();

      for(int i = 0; i < NUM_PINS; i++){

      pin_states[i] = digitalRead(pin_array[i]);

      }
      // write the values to the serial 
        Serial.write(byte(initial_byte));
        Serial.write(byte(pin_states[0]));
        Serial.write(byte(pin_states[1]));
        Serial.write(byte(pin_states[2]));
        Serial.write(byte(pin_states[3]));
        Serial.write(byte(pin_states[4]));
        Serial.write(byte(pin_states[5]));
        Serial.write(byte(pin_states[6]));
        Serial.write(byte(pin_states[7]));
        Serial.write(byte(pin_states[8]));
        Serial.write(byte(pin_states[9]));
        Serial.write(byte(pin_states[10]));
        Serial.write(byte(pin_states[11]));

      yield();
  //}
}

void establishContact () {

  while(Serial.available() <= 0) {

    Serial.print('A');
    delay(300);
  }

}
