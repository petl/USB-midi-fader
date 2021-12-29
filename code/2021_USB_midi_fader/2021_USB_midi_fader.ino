

/*
 * MIDI controller
 * Features 4 sliders, 3 button, 4 switches, and a couple of LEDs 
 * to be used with hairless MIDI
 * 
 * 12.2021
 * peter@traunmueller.net
 * 
 * Thanks to for the tutorial: https://www.instructables.com/DIY-USB-Midi-Controller-With-Arduino-a-Beginners-G/
 * 
 */

#define button_red_in  7
int button_red_in_prev = 0 ; 
#define button_red_out  4

#define button_green_in  8
int button_green_in_prev = 0 ; 
#define button_green_out  5

#define button_blue_in  9
int button_blue_in_prev = 0 ; 
#define button_blue_out  6

#define switch_red_in  2
int switch_red_in_prev = 0 ; 
#define switch_red_out  3

#define switch_top_in  A1
int switch_top_in_prev = 0 ; 
#define switch_top_out  12

#define switch_middle_in  A0
int switch_middle_in_prev = 0 ; 
#define switch_middle_out  11

#define switch_bottom_in  13
int switch_bottom_in_prev = 0 ; 
#define switch_bottom_out 10

#define slider_1_in  A5
int slider_1_in_prev = 0 ; 
#define slider_2_in  A4
int slider_2_in_prev = 0 ; 
#define slider_3_in  A3
int slider_3_in_prev = 0 ; 
#define slider_4_in  A2
int slider_4_in_prev = 0 ; 

#define led_green_out  0
#define led_red_out  1

// MIDI Assignments 
byte midiCh = 1; //* MIDI channel to be used
byte note = 36; //* Lowest note to be used; 36 = C2; 60 = Middle C
byte cc = 1; //* Lowest MIDI CC to be used



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(button_red_in ,INPUT_PULLUP);
  pinMode(button_green_in ,INPUT_PULLUP);
  pinMode(button_blue_in ,INPUT_PULLUP);
  pinMode(switch_red_in ,INPUT_PULLUP);
  pinMode(switch_top_in ,INPUT_PULLUP);
  pinMode(switch_middle_in ,INPUT_PULLUP);
  pinMode(switch_bottom_in ,INPUT_PULLUP);

  pinMode(button_red_out ,OUTPUT);
  pinMode(button_green_out ,OUTPUT);
  pinMode(button_blue_out ,OUTPUT);
  pinMode(switch_red_out ,OUTPUT);
  pinMode(switch_top_out ,OUTPUT);
  pinMode(switch_middle_out ,OUTPUT);
  pinMode(switch_bottom_out ,OUTPUT);
  digitalWrite(switch_red_out, HIGH);
  digitalWrite(switch_top_out, HIGH);
  digitalWrite(switch_middle_out, HIGH);
  digitalWrite(switch_bottom_out, HIGH);
  //pinMode(led_green_out ,OUTPUT);
  //pinMode(led_red_out ,OUTPUT);

}

void loop() {
  //BUTTONS
  if(digitalRead(button_red_in) != button_red_in_prev){
    if(digitalRead(button_red_in) == HIGH){
      noteOn(midiCh+0, note + 0, 127);
      digitalWrite(button_red_out, LOW);
      button_red_in_prev = 1;
    }
    else{
      noteOn(midiCh+0, note + 0, 0);
      digitalWrite(button_red_out, HIGH);
      button_red_in_prev = 0;
    }
  }
  if(digitalRead(button_green_in) != button_green_in_prev){
    if(digitalRead(button_green_in) == HIGH){
      noteOn(midiCh+0, note + 1, 127);
      digitalWrite(button_green_out, LOW);
      button_green_in_prev = 1;
    }
    else{
      noteOn(midiCh+0, note + 1, 0);
      digitalWrite(button_green_out, HIGH);
      button_green_in_prev = 0;
    }
  }
  if(digitalRead(button_blue_in) != button_blue_in_prev){
    if(digitalRead(button_blue_in) == HIGH){
      noteOn(midiCh+0, note + 2, 127);
      digitalWrite(button_blue_out, LOW);
      button_blue_in_prev = 1;
    }
    else{
      noteOn(midiCh+0, note + 2, 0);
      digitalWrite(button_blue_out, HIGH);
      button_blue_in_prev = 0;
    }
  }

  //SWITCHES
  if(digitalRead(switch_red_in) != switch_red_in_prev){
    if(digitalRead(switch_red_in) == HIGH){
      noteOn(midiCh+0, note + 3, 127);
      digitalWrite(switch_red_out, LOW);
      switch_red_in_prev = 1;
    }
    else{
      noteOn(midiCh+0, note + 3, 0);
      digitalWrite(switch_red_out, HIGH);
      switch_red_in_prev = 0;
    }
  }
  if(digitalRead(switch_top_in) != switch_top_in_prev){
    if(digitalRead(switch_top_in) == HIGH){
      noteOn(midiCh+0, note + 4, 127);
      digitalWrite(switch_top_out, LOW);
      switch_top_in_prev = 1;
    }
    else{
      noteOn(midiCh+0, note + 4, 0);
      digitalWrite(switch_top_out, HIGH);
      switch_top_in_prev = 0;
    }
  }
  if(digitalRead(switch_middle_in) != switch_middle_in_prev){
    if(digitalRead(switch_middle_in) == HIGH){
      noteOn(midiCh+0, note + 5, 127);
      digitalWrite(switch_middle_out, LOW);
      switch_middle_in_prev = 1;
    }
    else{
      noteOn(midiCh+0, note + 5, 0);
      digitalWrite(switch_middle_out, HIGH);
      switch_middle_in_prev = 0;
    }
  }
  if(digitalRead(switch_bottom_in) != switch_bottom_in_prev){
    if(digitalRead(switch_bottom_in) == HIGH){
      noteOn(midiCh+0, note + 6, 127);
      digitalWrite(switch_bottom_out, LOW);
      switch_bottom_in_prev = 1;
    }
    else{
      noteOn(midiCh+0, note + 6, 0);
      digitalWrite(switch_bottom_out, HIGH);
      switch_bottom_in_prev = 0;
    }
  }  

  //POTENTIOMETERS
  if( (analogRead(slider_1_in) < slider_1_in_prev - 2) || (analogRead(slider_1_in) > slider_1_in_prev + 2)){
    slider_1_in_prev = analogRead(slider_1_in);
    controlChange(midiCh+1, cc + 0, map(slider_1_in_prev, 0, 1023, 0, 127));
  }
  if( (analogRead(slider_2_in) < slider_2_in_prev - 2) || (analogRead(slider_2_in) > slider_2_in_prev + 2)){
    slider_2_in_prev = analogRead(slider_2_in);
    controlChange(midiCh+2, cc + 0, map(slider_2_in_prev, 0, 1023, 0, 127));
  }
  if( (analogRead(slider_3_in) < slider_3_in_prev - 2) || (analogRead(slider_3_in) > slider_3_in_prev + 2)){
    slider_3_in_prev = analogRead(slider_3_in);
    controlChange(midiCh+3, cc + 0, map(slider_3_in_prev, 0, 1023, 0, 127));
  }
  if( (analogRead(slider_4_in) < slider_4_in_prev - 2) || (analogRead(slider_4_in) > slider_4_in_prev + 2)){
    slider_4_in_prev = analogRead(slider_4_in);
    controlChange(midiCh+4, cc + 0, map(slider_4_in_prev, 0, 1023, 0, 127));
  }
}
// Arduino MIDI functions
void noteOn(byte channel, byte pitch, byte velocity) {
  //byte buf[] = {0x09, 0x90 | channel, pitch, velocity};
  byte buf[] = {0x90 | channel, pitch, velocity};
  int len = 3;
  Serial.write(buf, len);
  /*byte channel_write = 0x90 | channel;
  Serial.write(channel_write);
  Serial.write(pitch);
  Serial.write(velocity);
  */
}
/*
void noteOff(byte channel, byte pitch, byte velocity) {
  byte buf[] = {0x08, 0x80 | channel, pitch, velocity};
  int len = 3;
  Serial.write(buf, len);
}
*/
void controlChange(byte channel, byte control, byte value) {
  //byte buf[] = {0x0B, 0xB0 | channel, control, value};
  byte buf[] = {0xB0 | channel, control, value};
  int len = 3;
  Serial.write(buf, len);
}
