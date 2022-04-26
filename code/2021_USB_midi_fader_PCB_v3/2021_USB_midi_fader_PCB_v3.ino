

/*
   MIDI controller
   Features 4 sliders, 3 button, 4 switches, and a couple of LEDs
   Runs on an ATmega32U4 with the mattairTech stuff

   12.2021, 2.2022, 4.2022
   peter@traunmueller.net

   Thanks to for the tutorial: https://www.instructables.com/DIY-USB-Midi-Controller-With-Arduino-a-Beginners-G/

*/
//uint8_t USB_EP_SIZE = 64

#include "MIDIUSB.h"


//Define the pinout and variables to store the previous values
// Could have done this in an array, but i think it's easier to understand like this
#define button_main_in  10 // big sqare button, left side
int button_main_in_prev = 0 ;
#define button_main_out  19

#define button_top_in  2 //button row in the middle left
int button_top_in_prev = 0 ;
#define button_top_out  22

#define button_middle_in  1 //button row in the middle left
int button_middle_in_prev = 0 ;
#define button_middle_out  21

#define button_bottom_in  0 //button row in the middle left
int button_bottom_in_prev = 0 ;
#define button_bottom_out  20

#define switch_top_in  15 //switch row on the right
int switch_top_in_prev = 0 ;
#define switch_top_out  25

#define switch_middle_in  4//switch row on the right
int switch_middle_in_prev = 0 ;
#define switch_middle_out  24

#define switch_bottom_in  3//switch row on the right
int switch_bottom_in_prev = 0 ;
#define switch_bottom_out 23

#define slider_1_in  A9 // sliders are numbered LEFT to RIGHT
int slider_1_in_prev = 0 ;
#define slider_2_in  A8
int slider_2_in_prev = 0 ;
#define slider_3_in  A7
int slider_3_in_prev = 0 ;
#define slider_4_in  A6 // this is the rightmost slider
int slider_4_in_prev = 0 ;

//#define led_green_out  0 // Don't use this as outputs, they are connected to RX/TX!
#define led_red_out  18 //  10mm red LED left bottom, indicate RX/TX!

#define led_blue1_out  13 //  small blue LED for debugging
#define led_blue2_out  14 //  small blue LED for debugging



// MIDI Assignments
byte midiCh = 1; //* MIDI channel to be used
byte note = 36; //* Lowest note to be used; 36 = C2; 60 = Middle C
byte cc = 1; //* Lowest MIDI CC to be used



void setup() {
  pinMode(led_blue1_out ,OUTPUT);
  pinMode(led_blue2_out ,OUTPUT);
  digitalWrite(led_blue2_out, LOW);
  digitalWrite(led_blue1_out, HIGH);
  
  //hairless midi uses 115200 by default
  //while(!Serial);//wait for serial to become available
  //Serial.begin(115200);

  //we have to enable pullups for our inputs, as they would be floating otherwise
  pinMode(button_main_in , INPUT_PULLUP);
  pinMode(button_middle_in , INPUT_PULLUP);
  pinMode(button_bottom_in , INPUT_PULLUP);
  pinMode(button_top_in , INPUT_PULLUP);
  pinMode(switch_top_in , INPUT_PULLUP);
  pinMode(switch_middle_in , INPUT_PULLUP);
  pinMode(switch_bottom_in , INPUT_PULLUP);

  pinMode(button_main_out , OUTPUT);
  pinMode(button_middle_out , OUTPUT);
  pinMode(button_bottom_out , OUTPUT);
  pinMode(button_top_out , OUTPUT);
  pinMode(switch_top_out , OUTPUT);
  pinMode(switch_middle_out , OUTPUT);
  pinMode(switch_bottom_out , OUTPUT);
  //set the switch outputs to high, so they initialize correctly
  digitalWrite(button_top_out, HIGH);
  digitalWrite(switch_top_out, HIGH);
  digitalWrite(switch_middle_out, HIGH);
  digitalWrite(switch_bottom_out, HIGH);
  //pinMode(led_green_out ,OUTPUT);
  pinMode(led_red_out ,OUTPUT);

  digitalWrite(led_blue2_out, HIGH);

}

void loop() {
  //in here we just check if something has changed repeatedly

  //BUTTONS
  if (digitalRead(button_main_in) != button_main_in_prev) {
    if (digitalRead(button_main_in) == HIGH) {
      noteOn(midiCh + 0, note + 0, 0);
      digitalWrite(button_main_out, LOW);
      button_main_in_prev = 1;
    }
    else {
      noteOn(midiCh + 0, note + 0, 127);
      digitalWrite(button_main_out, HIGH);
      button_main_in_prev = 0;
    }
  }
  if (digitalRead(button_middle_in) != button_middle_in_prev) {
    if (digitalRead(button_middle_in) == HIGH) {
      noteOn(midiCh + 0, note + 1, 0);
      digitalWrite(button_middle_out, LOW);
      button_middle_in_prev = 1;
    }
    else {
      noteOn(midiCh + 0, note + 1, 127);
      digitalWrite(button_middle_out, HIGH);
      button_middle_in_prev = 0;
    }
  }
  if (digitalRead(button_bottom_in) != button_bottom_in_prev) {
    if (digitalRead(button_bottom_in) == HIGH) {
      noteOn(midiCh + 0, note + 2, 0);
      digitalWrite(button_bottom_out, LOW);
      button_bottom_in_prev = 1;
    }
    else {
      noteOn(midiCh + 0, note + 2, 127);
      digitalWrite(button_bottom_out, HIGH);
      button_bottom_in_prev = 0;
    }
  }

  //SWITCHES
  if (digitalRead(button_top_in) != button_top_in_prev) {
    if (digitalRead(button_top_in) == HIGH) {
      noteOn(midiCh + 0, note + 3, 0);
      digitalWrite(button_top_out, LOW);
      button_top_in_prev = 1;
    }
    else {
      noteOn(midiCh + 0, note + 3, 127);
      digitalWrite(button_top_out, HIGH);
      button_top_in_prev = 0;
    }
  }
  if (digitalRead(switch_top_in) != switch_top_in_prev) {
    if (digitalRead(switch_top_in) == HIGH) {
      noteOn(midiCh + 0, note + 4, 0);
      digitalWrite(switch_top_out, LOW);
      switch_top_in_prev = 1;
    }
    else {
      noteOn(midiCh + 0, note + 4, 127);
      digitalWrite(switch_top_out, HIGH);
      switch_top_in_prev = 0;
    }
  }
  if (digitalRead(switch_middle_in) != switch_middle_in_prev) {
    if (digitalRead(switch_middle_in) == HIGH) {
      noteOn(midiCh + 0, note + 5, 0);
      digitalWrite(switch_middle_out, LOW);
      switch_middle_in_prev = 1;
    }
    else {
      noteOn(midiCh + 0, note + 5, 127);
      digitalWrite(switch_middle_out, HIGH);
      switch_middle_in_prev = 0;
    }
  }
  if (digitalRead(switch_bottom_in) != switch_bottom_in_prev) {
    if (digitalRead(switch_bottom_in) == HIGH) {
      noteOn(midiCh + 0, note + 6, 0);
      digitalWrite(switch_bottom_out, LOW);
      switch_bottom_in_prev = 1;
    }
    else {
      noteOn(midiCh + 0, note + 6, 127);
      digitalWrite(switch_bottom_out, HIGH);
      switch_bottom_in_prev = 0;
    }
  }

  //POTENTIOMETERS
  if ( (analogRead(slider_1_in) < slider_1_in_prev - 2) || (analogRead(slider_1_in) > slider_1_in_prev + 2)) {
    slider_1_in_prev = analogRead(slider_1_in);
    controlChange(midiCh + 1, cc + 0, map(slider_1_in_prev, 0, 1023, 127, 0));
  }
  if ( (analogRead(slider_2_in) < slider_2_in_prev - 2) || (analogRead(slider_2_in) > slider_2_in_prev + 2)) {
    slider_2_in_prev = analogRead(slider_2_in);
    controlChange(midiCh + 2, cc + 0, map(slider_2_in_prev, 0, 1023, 127, 0));
  }
  if ( (analogRead(slider_3_in) < slider_3_in_prev - 2) || (analogRead(slider_3_in) > slider_3_in_prev + 2)) {
    slider_3_in_prev = analogRead(slider_3_in);
    controlChange(midiCh + 3, cc + 0, map(slider_3_in_prev, 0, 1023, 127, 0));
  }
  if ( (analogRead(slider_4_in) < slider_4_in_prev - 2) || (analogRead(slider_4_in) > slider_4_in_prev + 2)) {
    slider_4_in_prev = analogRead(slider_4_in);
    controlChange(midiCh + 4, cc + 0, map(slider_4_in_prev, 0, 1023, 127, 0));
  }
}
// Arduino MIDI functions
/*
void noteOn(byte channel, byte pitch, byte velocity) {
  //byte buf[] = {0x09, 0x90 | channel, pitch, velocity};
  byte buf[] = {0x90 | channel, pitch, velocity};
  int len = 3;
  digitalWrite(led_red_out, HIGH);
  Serial.write(buf, len);
  digitalWrite(led_red_out, LOW);

}

void controlChange(byte channel, byte control, byte value) {
  //byte buf[] = {0x0B, 0xB0 | channel, control, value};
  byte buf[] = {0xB0 | channel, control, value};
  int len = 3;
  digitalWrite(led_red_out, HIGH);
  Serial.write(buf, len);
  digitalWrite(led_red_out, LOW);
}
*/

void controlChange(byte channel, byte control, byte value) {
  //byte buf[] = {0x0B, 0xB0 | channel, control, value};
  //byte buf[] = {0xB0 , channel, control, value};
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  int len = 3;
  digitalWrite(led_red_out, HIGH);
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
  digitalWrite(led_red_out, LOW);
}
void noteOn(byte channel, byte pitch, byte velocity)  {
  //byte buf[] = {0x90 , channel, pitch, velocity};
  //{0x09, 0x90, pitch, 127})
  midiEventPacket_t event = {0x0B, 0xB0 | channel, pitch, velocity};
  digitalWrite(led_red_out, HIGH);
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
  digitalWrite(led_red_out, LOW);
}
