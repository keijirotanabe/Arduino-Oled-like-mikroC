#ifndef _Arduino-Oled-like-mikroC
#define _Arduino-Oled-like-mikroC

#define OLED_ADDRESS  0x3C

#define ClearDisplay  0x01
#define ReturnHome  0x02
#define DisplayON     0x0F
#define DisplayOFF   0x08
#define CursorON      0x0F
#define CursorOFF    0x0D
#define BlinkON         0x0F
#define BlinkOFF       0x0E
#define ShiftLeft         0x18
#define ShiftRight      0x1C
#define CursorLeft     0x10
#define CursorRight   0x14

void Oled_Init();
void Oled_Cmd(byte out_char);
void Oled_Out(byte row, byte col, char *text);
void Oled_Out_Cp(char *text);
void Oled_Chr(byte row, byte col, byte out_char);
void Oled_Chr_Cp(byte out_char);
void Oled_Set_Cursor(byte row, byte col);
void Oled_Set_Contrast(byte contrast);
void Oled_Max_Contrast();
void Oled_Min_Contrast();

#endif
