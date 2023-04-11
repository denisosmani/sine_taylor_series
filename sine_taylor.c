#include <reg51.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned char frequency_divider=0;

unsigned char rows = 0xff; //initialize, means no buttons pushed
unsigned char columns = 0xff;
bit button_row;
bit button_column;

sbit RS = P2^0; //register_select pin of lcd
sbit EN = P2^1; //enable pin of lcd

bit dot = 0; //stores 1 if dot '.' is pushed

char argument[9]={"000000000"};
signed char count_arg_digits = -1;

void get_updated_buttons(void); //redefinition
void print_digits(void);
void transmit_data(void);
void conversions(void);
void T0ISR(void) interrupt 1
{
	frequency_divider++;
	
	if(frequency_divider==4){
		frequency_divider = 0;
			
			get_updated_buttons();
	
	}
}

//redefinitions
void lcd_initialization(void);
void lcd_write_data(char m_data);
void check_buttons(void);
void lcd_write_cmd(char m_command);
void clear_lcd(void);

void main(void){
	IE = 0x82;
	TMOD = 0x22; //timer1 and timer0 in 8_bit auto_reload
	TH0  = 6;
	TL0 =  6;
	TR0 = 1;
	
	lcd_initialization();
	
	while(1){
		check_buttons();
	}
	
}


void get_updated_buttons(void){
	P1 = 0x0F; //ground the columns and read the rows
	rows = P1;
	
	P1 = 0xF0; //ground the rows and read the columns
	columns = P1;
	
}
void check_buttons(void){
	//P2 = rows;
	//P3 = columns;
	
	//row 0
	button_row = ((rows>>0) & 1);
	button_column = ((columns>>4) & 1);
	
	if( (button_row == 0) & ( button_column == 0) & (count_arg_digits<8) ){ //row 0
		//pressed 1
	
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>0) & 1);
			button_column = ((columns>>4) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '1';
		
		lcd_write_data('1');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
	
	button_row = ((rows>>0) & 1);
	button_column = ((columns>>5) & 1);	
	if((button_row == 0) & ( button_column == 0)  & (count_arg_digits<8)){
	//pressed 2
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>0) & 1);
			button_column = ((columns>>5) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '2';
		
		lcd_write_data('2');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
	
		button_row = ((rows>>0) & 1);
	button_column = ((columns>>6) & 1);	
	if((button_row == 0) & ( button_column == 0) & (count_arg_digits<8)){
	//pressed 3
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>0) & 1);
			button_column = ((columns>>6) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '3';
		
		lcd_write_data('3');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
	
	button_row = ((rows>>0) & 1);
	button_column = ((columns>>7) & 1);	
	if((button_row == 0) & ( button_column == 0) & (dot == 0) & (count_arg_digits<7)){
	//pressed '.' dot
		dot = 1; //pushed once
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>0) & 1);
			button_column = ((columns>>7) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '.';
		
		lcd_write_data('.');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
	
	//row 1
		button_row = ((rows>>1) & 1);
	button_column = ((columns>>4) & 1);	
	if((button_row == 0) & ( button_column == 0) & (count_arg_digits<8)){
	//pressed 4
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>1) & 1);
			button_column = ((columns>>4) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '4';
		
		lcd_write_data('4');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
		button_row = ((rows>>1) & 1);
	button_column = ((columns>>5) & 1);	
	if((button_row == 0) & ( button_column == 0) & (count_arg_digits<8)){
	//pressed 5
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>1) & 1);
			button_column = ((columns>>5) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '5';
		
		lcd_write_data('5');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
		button_row = ((rows>>1) & 1);
	button_column = ((columns>>6) & 1);	
	if((button_row == 0) & ( button_column == 0) & (count_arg_digits<8)){
	//pressed 6
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>1) & 1);
			button_column = ((columns>>6) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '6';
		
		lcd_write_data('6');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
	
	
		//row 2
		button_row = ((rows>>2) & 1);
	button_column = ((columns>>4) & 1);	
	if((button_row == 0) & ( button_column == 0) & (count_arg_digits<8)){
	//pressed 7
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>2) & 1);
			button_column = ((columns>>4) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '7';
		
		lcd_write_data('7');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
		button_row = ((rows>>2) & 1);
	button_column = ((columns>>5) & 1);	
	if((button_row == 0) & ( button_column == 0) & (count_arg_digits<8)){
	//pressed 8
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>2) & 1);
			button_column = ((columns>>5) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits]='8';
		
		lcd_write_data('8');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
		button_row = ((rows>>2) & 1);
	button_column = ((columns>>6) & 1);	
	if((button_row == 0) & ( button_column == 0) & (count_arg_digits<8)){
	//pressed 9
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>2) & 1);
			button_column = ((columns>>6) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '9';
		
		lcd_write_data('9');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
	
			//row 3
		button_row = ((rows>>3) & 1);
	button_column = ((columns>>4) & 1);	
	if((button_row == 0) & ( button_column == 0)){
	//pressed Clear
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>3) & 1);
			button_column = ((columns>>4) & 1);
		}
		
		clear_lcd();
	}
		button_row = ((rows>>3) & 1);
	button_column = ((columns>>5) & 1);	
	if((button_row == 0) & ( button_column == 0) & (count_arg_digits<8)){
	//pressed 0
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>3) & 1);
			button_column = ((columns>>5) & 1);
		}
		
		count_arg_digits++;
		argument[count_arg_digits] = '0';
		
		lcd_write_data('0');
		lcd_write_data(')');
		lcd_write_cmd(0x10);
	}
		button_row = ((rows>>3) & 1);
	button_column = ((columns>>6) & 1);	
	if((button_row == 0) & ( button_column == 0)){
	//pressed Ans
		
			//unpush
		while( (button_row == 0) & ( button_column == 0)){
			button_row = ((rows>>3) & 1);
			button_column = ((columns>>6) & 1);
		}

		if(dot == 0){//if ans was pushed without pressing dot
			argument[count_arg_digits+1] = '.';
		}
		conversions();
		print_digits();
	}
	
	
}

void delay_lcd(void){
unsigned char k;
	for(k=0;k<40;k++){
		
	}
}

void clr_delay_lcd(void){
unsigned int l;
	for(l=0;l<3000;l++){
		
	}
	}


void lcd_write_cmd(char m_command){
	RS = 0;
	delay_lcd();
	EN = 1;
	delay_lcd();
	P0 = m_command;
	EN = 0;
	delay_lcd();
}

void lcd_write_data(unsigned char m_data){
	RS = 1;
	delay_lcd();
	EN = 1;
	delay_lcd();
	P0 = m_data;
	EN = 0;
	delay_lcd();
}


void lcd_initialization(void){
	lcd_write_cmd(0x38);
	lcd_write_cmd(0x0f);
	lcd_write_cmd(0x80);
	
	//sin( )
	lcd_write_data('s');
	lcd_write_data('i');
	lcd_write_data('n');
	lcd_write_data('(');
	lcd_write_data(' ');
	lcd_write_data(')');
	lcd_write_cmd(0x10);
	lcd_write_cmd(0x10);
}

void clear_lcd(void){
	unsigned char index00;
	lcd_write_cmd(0x01);
	clr_delay_lcd();
	lcd_initialization();
	dot = 0; //so it can be typed again
	count_arg_digits = -1;//so it stores values in array again
	
	for(index00 = 0; index00 < 9; index00++){
		argument[index00] = '0';
	}
	
}

void print_digits(void){
	unsigned char index0;
	lcd_write_cmd(0xC0);
	lcd_write_data('=');
	for(index0 = 0; index0 < 9; index0++){
		lcd_write_data(argument[index0]);
	}
}

double taylor_expansion(double x);

void conversions(void){
	double d_argument = atof(argument); //convert _char array to _float
	//f_argument = fmod(f_argument,6.28);    //convert any f_argument to range 0 - 2pi
	d_argument = taylor_expansion(d_argument);	
	sprintf(argument, "%lf", d_argument);//conver _float to _char array
}

long int factorial(int n) {
    long int result = 1;
		int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double taylor_expansion(double x){
	unsigned char term;
	double temp=0;
	x = fmod(x,6.28);
	for(term = 0; term<10; term++){
		temp = temp + (double)pow(-1,term)*(((double)pow(x,((2*term)+1)))/((double)factorial(2*term+1)));
	}
	return temp;
}
