// File Name: gsm interface on 8051
// Author: R.venkatesan
// lcd 16X2 8bit method 
 // lcd pin connection port0 -data pin (D0-D7)
 // control pin lcd conection  RS=P2^7, R/W=P2^6, E=P2^5
 

# include <reg51.h>
# include <stdio.h>
# include "lcd.h"  // lcd library 
/* if want change the lcd pin connection open lcd file library change the pin as per your aspect 
 And also remain you change busy flag= bf(used name in lcdlibrary ) also for inlcd pin data  lcd file libary  */
 # include "serial data.h"
 sbit ir=P1^0;  // interface  ir sensor on call make
 void call();
 void main()
 {
  port(); // pulldown the all pin in micro controller
	lcd_initial(); // lcd basic initialization cammand line 
	 serial();  // set 9600 baud rate
	 ir=1;
	 {
	 while(1)
	 {
	   lcd_com(0x01);  // lcd cammand dispaly frist line
		 lcd_string(" gsm interface  "); // write your own word in double quotes
		 
		 lcd_com (0xc0);  // lcd cammand dispaly second line
		 lcd_string(" make calling");  // write your own word in double quotes
		 
		  delay(100); // delay for seen the lcd lines display
		 
		 if(ir==1)
		 {
			 lcd_com(0x01);  // lcd cammand dispaly frist line
		 lcd_string(" calling  "); // write your own word in double quotes
		 call();
			 
		 }
	 }
 }	 
 }
 
 void call()
	{
	str("at\r\n");
	 delay(100);
	 str("atd9677956436;\r\n");
	 delay(6000);
	 str("ath\r\n");
	}

	 