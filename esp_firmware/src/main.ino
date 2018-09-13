#include <Arduino.h>
#include <OSCMessage.h>
#include <Ticker.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <data_handler.h>
#define DIGITAL_2 D4 
#define NUM_STATES 12
//------ interrupts
void handle_interrupts();
// network ettings --------------
//

char ssid[] = "SSID";//name of the network 
char psswd[] = "PASSWD";// password

WiFiUDP Udp;
const IPAddress outIp(192,168,1,10);
const unsigned int outPort = 4000;
const unsigned int localPort = 4001;

// osc settings
OSCErrorCode error;


//timed osc messages
bool sendingOscPacket = false;


// serial handling
data_handler my_data_handler;
int * serialBytes;
// interrupts
int states[NUM_STATES];
int last_states[NUM_STATES];
int state = 1;// input_pullup inputs
int lastState = 1;//we assume nothing changed at first
volatile byte interruptCounter;

void setup() {

  pinMode(DIGITAL_2, OUTPUT);

  Serial.begin(115200);

  //copy the pointer array of data

  serialBytes = my_data_handler.pointerArray;
// inititialize all states to off
  for(int i = 0; i < NUM_STATES; i++) {

    states[i] = 1;
    last_states[i] = 1;
  }
  // connect to the network

  WiFi.begin(ssid,psswd);

  while(WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");

  }

  Serial.println("wifi connected");
  Serial.println(WiFi.localIP());
  Serial.println("starting udp");
  Udp.begin(localPort);
}


void dispatch_osc_messages() {

  sendingOscPacket = true;
  Serial.println("sending messages");
  OSCMessage msg("/buttons");
  msg.add(state);
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp);
  Udp.endPacket();
  msg.empty();
  Serial.print("sent:  ");
  Serial.println(my_data_handler.serialInArray[1]);
  yield();

}
void loop() {

  my_data_handler.handleData();

  //--- TODO: work on for or helper functions 

  /*for(int i = 1; i <= NUM_STATES; i++) {
    // state = my_data_handler.serialInArray[1];

    states[i-1] = *(serialBytes+i); // filter 1st byte 
    delay(1);
    yield();
  }*/

  states[0] = *(serialBytes+1);
  states[1] = *(serialBytes+2);
  states[2] = *(serialBytes+3);
  states[3] = *(serialBytes+4);
  states[4] = *(serialBytes+5);
  states[5] = *(serialBytes+6);
  states[6] = *(serialBytes+7);
  states[7] = *(serialBytes+8);
  states[8] = *(serialBytes+9);
  states[9] = *(serialBytes+10);
  states[10] = *(serialBytes+11);
  states[11] = *(serialBytes+12);
  yield();

  // mtfucker ifs

  if(last_states[0] != states[0]) {
      OSCMessage m("/button_1");
      m.add(states[0]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  }
 if(last_states[1] != states[1]){
     OSCMessage m("/button_2");
      m.add(states[1]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  }
  if(last_states[2] != states[2]){
     OSCMessage m("/button_3");
      m.add(states[2]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  }
  if(last_states[3] != states[3]){
     OSCMessage m("/button_4");
      m.add(states[3]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  }
  if(last_states[4] != states[4]){
     OSCMessage m("/button_5");
      m.add(states[4]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  }
  if(last_states[5] != states[5]){
     OSCMessage m("/button_6");
      m.add(states[5]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  }
  
  if(last_states[6] != states[6]){
     OSCMessage m("/button_7");
      m.add(states[6]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  } 
  if(last_states[7] != states[7]){
     OSCMessage m("/button_8");
      m.add(states[7]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  }
  
  if(last_states[8] != states[8]){
     OSCMessage m("/button_9");
      m.add(states[8]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  }
  
  if(last_states[9] != states[9]){
     OSCMessage m("/button_10");
      m.add(states[9]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  }
  
  if(last_states[10] != states[10]){
     OSCMessage m("/button_11");
      m.add(states[10]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  } 
  if(last_states[11] != states[11]){
     OSCMessage m("/button_12");
      m.add(states[11]);
      Udp.beginPacket(outIp,outPort);
      m.send(Udp);
      Udp.endPacket();
      m.empty();
      delay(1);
  
  }

 last_states[0] = states[0];
 last_states[1] = states[1];
  last_states[2] = states[2];
  last_states[3] = states[3];
  last_states[4] = states[4];
  last_states[5] = states[5];
  last_states[6] = states[6];
  last_states[7] = states[7];
  last_states[8] = states[8];
  last_states[9] = states[9];
  last_states[10] = states[10];
  last_states[11] = states[11];



  yield();
}
