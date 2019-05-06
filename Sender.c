char x;

void main() {
CMCON=0x07;TRISA=255;TRISB=0;portb=0;
PWM1_Init(38000);
PWM1_Set_Duty(255);


  while (1) {
  if (porta.f0==0){
      PWM1_Start();delay_us(2400);PWM1_Stop();
      delay_us(600);
      for(x=0;x<7;x++){
      PWM1_Start();delay_us(600);PWM1_Stop();delay_us(600); }

      PWM1_Start();delay_us(1200);PWM1_Stop();
        delay_us(600);
         for(x=0;x<4;x++){
      PWM1_Start();delay_us(600);PWM1_Stop();delay_us(600);  }
      delay_ms(250);
        }

        if (porta.f1==0){
      PWM1_Start();delay_us(2400);PWM1_Stop();
      delay_us(600);
      PWM1_Start();delay_us(1200);PWM1_Stop();      //1
      delay_us(600);
      for(x=0;x<6;x++){
      PWM1_Start();delay_us(600);PWM1_Stop();delay_us(600);  }
        PWM1_Start();delay_us(1200);PWM1_Stop();
        delay_us(600);
         for(x=0;x<4;x++){
      PWM1_Start();delay_us(600);PWM1_Stop();delay_us(600);  }
        delay_ms(250);
        }
        if (porta.f2==0){
      PWM1_Start();delay_us(2400);PWM1_Stop();
      delay_us(600);
      PWM1_Start();delay_us(600);PWM1_Stop();      //1
      delay_us(600);
        PWM1_Start();delay_us(1200);PWM1_Stop();     //2
        delay_us(600);
      for(x=0;x<5;x++){
      PWM1_Start();delay_us(600);PWM1_Stop();delay_us(600);  }
        PWM1_Start();delay_us(1200);PWM1_Stop();
        delay_us(600);
         for(x=0;x<4;x++){
      PWM1_Start();delay_us(600);PWM1_Stop();delay_us(600);  }
      delay_ms(250);
        }
       if (porta.f3==0){
      PWM1_Start();delay_us(2400);PWM1_Stop();
      delay_us(600);
      for(x=0;x<2;x++){
      PWM1_Start();delay_us(1200);PWM1_Stop();delay_us(600);  }
       for(x=0;x<5;x++){
      PWM1_Start();delay_us(600);PWM1_Stop();delay_us(600);  }
       PWM1_Start();delay_us(1200);PWM1_Stop();
        delay_us(600);
         for(x=0;x<4;x++){
      PWM1_Start();delay_us(600);PWM1_Stop();delay_us(600);  }
      delay_ms(250);
        }


      }


  }