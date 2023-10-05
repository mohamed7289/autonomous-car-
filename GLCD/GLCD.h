/*
 * GLCD.h
 *
 * Created: 4/20/2023 8:53:21 PM
 *  Author: mohamed adel
 */ 


#ifndef GLCD_H_
#define GLCD_H_

#include "STD_Types.h"
#include "DIO.h"
#include "Clock.h"
#include "ALPHABET.h"


#define DATA_PORT DIO_PortD
#define COMMAND_PORT DIO_PortC
#define En DIO_ChannelC0
#define RW DIO_ChannelC1
#define RS DIO_ChannelC2
#define CS1 DIO_ChannelC3
#define CS2 DIO_ChannelC4
#define RST DIO_ChannelC5

static const char ALPHABET[]= {
	0x06, 0x00, 0x7E, 0x11, 0x11, 0x11, 0x7E,  // Code for char A
	0x06, 0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,  // Code for char B
	0x06, 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,  // Code for char C
	0x06, 0x00, 0x7F, 0x41, 0x41, 0x41, 0x3E,  // Code for char D
	0x06, 0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,  // Code for char E
	0x06, 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,  // Code for char F
	0x06, 0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,  // Code for char G
	0x06, 0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,  // Code for char H
	0x05, 0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,  // Code for char I
	0x06, 0x00, 0x30, 0x40, 0x40, 0x40, 0x3F,  // Code for char J
	0x06, 0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,  // Code for char K
	0x06, 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,  // Code for char L
	0x06, 0x00, 0x7F, 0x02, 0x04, 0x02, 0x7F,  // Code for char M
	0x06, 0x00, 0x7F, 0x02, 0x04, 0x08, 0x7F,  // Code for char N
	0x06, 0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,  // Code for char O
	0x06, 0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,  // Code for char P
	0x06, 0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,  // Code for char Q
	0x06, 0x00, 0x7F, 0x09, 0x09, 0x19, 0x66,  // Code for char R
	0x06, 0x00, 0x26, 0x49, 0x49, 0x49, 0x32,  // Code for char S
	0x06, 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,  // Code for char T
	0x06, 0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,  // Code for char U
	0x06, 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,  // Code for char V
	0x06, 0x00, 0x3F, 0x40, 0x3C, 0x40, 0x3F,  // Code for char W
	0x06, 0x00, 0x63, 0x14, 0x08, 0x14, 0x63,  // Code for char X
	0x06, 0x00, 0x07, 0x08, 0x70, 0x08, 0x07,  // Code for char Y
	0x05, 0x00, 0x71, 0x49, 0x45, 0x43, 0x00,  // Code for char Z
};
static const char alphabet[]={
	0x06, 0x00, 0x20, 0x54, 0x54, 0x54, 0x78,  // Code for char a
	0x06, 0x00, 0x7F, 0x44, 0x44, 0x44, 0x38,  // Code for char b
	0x06, 0x00, 0x38, 0x44, 0x44, 0x44, 0x28,  // Code for char c
	0x06, 0x00, 0x38, 0x44, 0x44, 0x44, 0x7F,  // Code for char d
	0x06, 0x00, 0x38, 0x54, 0x54, 0x54, 0x08,  // Code for char e
	0x05, 0x00, 0x08, 0x7E, 0x09, 0x09, 0x00,  // Code for char f
	0x06, 0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,  // Code for char g
	0x05, 0x00, 0x7F, 0x04, 0x04, 0x78, 0x00,  // Code for char h
	0x05, 0x00, 0x00, 0x00, 0x7D, 0x40, 0x00,  // Code for char i
	0x05, 0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,  // Code for char j
	0x05, 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,  // Code for char k
	0x05, 0x00, 0x00, 0x00, 0x7F, 0x40, 0x00,  // Code for char l
	0x06, 0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,  // Code for char m
	0x05, 0x00, 0x7C, 0x04, 0x04, 0x78, 0x00,  // Code for char n
	0x06, 0x00, 0x38, 0x44, 0x44, 0x44, 0x38,  // Code for char o
	0x06, 0x00, 0xFC, 0x44, 0x44, 0x44, 0x38,  // Code for char p
	0x06, 0x00, 0x38, 0x44, 0x44, 0x44, 0xFC,  // Code for char q
	0x06, 0x00, 0x44, 0x78, 0x44, 0x04, 0x08,  // Code for char r
	0x06, 0x00, 0x08, 0x54, 0x54, 0x54, 0x20,  // Code for char s
	0x05, 0x00, 0x04, 0x3E, 0x44, 0x24, 0x00,  // Code for char t
	0x05, 0x00, 0x3C, 0x40, 0x20, 0x7C, 0x00,  // Code for char u
	0x06, 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,  // Code for char v
	0x06, 0x00, 0x3C, 0x60, 0x30, 0x60, 0x3C,  // Code for char w
	0x05, 0x00, 0x6C, 0x10, 0x10, 0x6C, 0x00,  // Code for char x
	0x05, 0x00, 0x9C, 0xA0, 0x60, 0x3C, 0x00,  // Code for char y
	0x05, 0x00, 0x64, 0x54, 0x54, 0x4C, 0x00,  // Code for char z
};

void GLCD_Command (u8 command) ;
void GLCD_Init(void) ;
void GLCD_Data(u8 data) ;
void GLCD_CharCapital(u8 alphabet) ;
void GLCD_CharSmall(u8 alphabet) ;
void GLCD_String(const char* image) ;

#endif /* GLCD_H_ */