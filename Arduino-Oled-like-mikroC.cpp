#include <Arduino.h>
#include "Arduino-Oled-like-mikroC.h"
#include <Wire.h>

void Oled_Init() {
  delay(100);
  Oled_Cmd(ClearDisplay);
  delay(20);
  Oled_Cmd(ReturnHome);
  delay(2);
  Oled_Cmd(DisplayON);
  delay(2);
  Oled_Cmd(ClearDisplay);
  delay(20);
}

void Oled_Cmd(byte out_char) {
  Wire.beginTransmission(OLED_ADDRESS);
  Wire.write(0x00);
  Wire.write(out_char);
  Wire.endTransmission();
  delay(10);
}

void Oled_Out(byte row, byte col, char *text) { 
  Oled_Set_Cursor(row, col);
  Oled_Out_Cp(text);
}

void Oled_Out_Cp(char *text) {
  for (int i = 0; i < strlen(text); i++) {
    Oled_Chr_Cp(text[i]);
  }
}

void Oled_Chr(byte row, byte col, byte out_char) {
  Oled_Set_Cursor(row, col);
  Oled_Chr_Cp(out_char);
}

void Oled_Chr_Cp(byte out_char) {
  Wire.beginTransmission(OLED_ADDRESS);
  Wire.write(0x40);
  Wire.write(out_char);
  Wire.endTransmission();
  delay(1);
}

void Oled_Set_Cursor(byte row, byte col) {
  byte posi;
   if (row == 1) {
    posi = 0x00;
  } else if (row == 2) {
    posi = 0x20;
  }
  posi += (col - 1);
  Oled_Cmd(posi + 0x80);
}


void Oled_Set_Contrast(byte contrast) {
  Oled_Cmd(0x2A);
  Oled_Cmd(0x79);
  Oled_Cmd(0x81);
  Oled_Cmd(contrast);
  Oled_Cmd(0x78);
  Oled_Cmd(0x28);
  delay(100);
}

void Oled_Max_Contrast() {
  Oled_Cmd(0x2A);
  Oled_Cmd(0x79);
  Oled_Cmd(0x81);
  Oled_Cmd(0xFF);
  Oled_Cmd(0x78);
  Oled_Cmd(0x28);
  delay(100);
}

void Oled_Min_Contrast() {
  Oled_Cmd(0x2A);
  Oled_Cmd(0x79);
  Oled_Cmd(0x81);
  Oled_Cmd(0x00);
  Oled_Cmd(0x78);
  Oled_Cmd(0x28);
  delay(100);
}

