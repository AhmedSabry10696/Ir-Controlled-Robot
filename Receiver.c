sbit ir_in at RA0_bit;
sbit ir_in_direction at TRISA0_bit;
sbit LCD_RS at Ra1_bit;
sbit LCD_EN at Ra2_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;
sbit LCD_RS_Direction at TRISa1_bit;
sbit LCD_EN_Direction at TRISa2_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;

unsigned int retint;
unsigned char ir_byte,COUNT,bouton;
unsigned char ir_result[3];

void interrupt(){
     count++;
     intcon=0b00100000;
     TMR0=0;
}

unsigned int get_mark(){
      TMR0= 0; count=0;
      for(;!ir_in;){}
      retint=2*(TMR0+(count*256));
      return retint;
}

unsigned int get_space(){
      TMR0= 0; count=0;
      for(;ir_in;){}
      retint=2*(TMR0+(count*256));
      return retint;
}
unsigned char get_sony_byte(char nbits){
char n;
unsigned char ir_byte;
unsigned int temp_ir;

    ir_byte = 0;
    for(n=0 ; n<nbits ; n++){
        temp_ir = get_space();
     temp_ir = get_mark();
          ir_byte >>= 1;
       if ((temp_ir > 1000)&&(temp_ir < 1300)) {
            ir_byte += 0x80;
        }
    }
    ir_byte >>= 8-nbits;
    return ir_byte;
}
void sony_read(){
unsigned int temp_ir;

    ir_result[0] = 0;
    ir_result[1] = 0;
    while(ir_in);
    temp_ir = get_mark();
    if((temp_ir>2000)&&(temp_ir<3000)) {
        ir_result[0] = get_sony_byte(7);
        ir_result[1] = get_sony_byte(5);
        Delay_ms(10);
    }
}
int i;
void main() {
    trisa=0b00000001;
    trisb=0b00000000;
    PORTB=0;
    porta=0;
    cmcon=7;
    option_reg= 0b10000000;
    intcon= 0b10100000;
    TMR0 = 0;
    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    while(1){
        sony_read();
        if(ir_result[1]==1){
            bouton = ir_result[0];
            switch (bouton){
                case 1:
                      {
                       Portb.F0 = ~Portb.F0;
                       Portb.F2 = ~Portb.F2;Delay_ms(100);break;
                      }
                case 7:
                     { 
                      Portb.F1 = ~Portb.F1;
                      Portb.F3 = ~Portb.F3;Delay_ms(100);break;
                      }
                case 5: Portb.F0 = ~Portb.F0;Delay_ms(100);break;
                case 3: Portb.F2 = ~Portb.F2;Delay_ms(100);break;
                case 4:
                      { 
                       Portb.F0 = ~Portb.F0;
                       Portb.F3 = ~Portb.F3;Delay_ms(100);break;
                      }                                                  /
                case 0: {
                          lcd_out(1,5,"LOADING");
                          for(i=1;i<=16;++i)
                          {
                           lcd_out(2,i,"_");
                           delay_ms(150);
                          }
                           Lcd_Cmd(_LCD_CLEAR);
                           delay_ms(200);
                           lcd_out(1,1,"PERFECTING TEAM");
                           lcd_out(2,3,"IEEE ^_^ STC");

                           break;
                        }
                case 2: {
                           Lcd_Cmd(_LCD_CLEAR);
                           Lcd_Cmd(_LCD_CURSOR_OFF);
                           break;
                        }
               case 21: {
                             PORTA.f6=~PORTA.f6;
                             delay_ms(100);
                           break;
                       }
                       case 20:
                            {
                             PORTA.f7=~PORTA.f7;
                             delay_ms(100);
                             break;
                            }

                default:break;
            }
        }
    }
}