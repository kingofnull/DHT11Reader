
#define DDRV DDR SPIN
#define OUT_PIN PORT SPIN
#define IN_PIN PIN SPIN
#define setDHT11Pin(x) # define IN_PIN x



// count bit
unsigned char bit_count = 0;
// feedback count bit return
unsigned char c = 0;
// temperature and humidity value

// loop count
unsigned char cl = 0;

//***** start methods *****//

void request(void)
{
    DDRV = 1;
    // DDRD |= (1<<0);

    OUT_PIN = 0;
    // PORTD &= ~(1<<0);
    
    // delay_ms(18);     
              
    
    delay_ms(18);
                
    
    OUT_PIN = 1;
    // PORTD |= (1<<0);
}



void response()
{    
    // PIND
    //DDRD &= ~(1<<0);        
    DDRV = 0;

    while(IN_PIN)
    {
        delay_us(1);
        cl++;
        if (cl > 80) break;
    }

    cl = 0;
    while(IN_PIN==0)
    {    
        delay_us(40);
        cl++;
        if (cl > 2) break;
    }

    cl = 0;    
    while(IN_PIN)
    {
        delay_us(40);
        cl++;
        if (cl > 2) break;
    }
}


int i;  
unsigned char recive()
{
    while(bit_count<8)
    {
        bit_count++;

        while(IN_PIN==0);

        delay_us(30);

        if(IN_PIN)
        {
            c=(c<<1)|(0x01);
        } else {
            c=c<<1;
        }
       
                   
        for (i=0;((i<1000) && IN_PIN);i++){ delay_us(10);};   
        
        // while(IN_PIN); 
    }

    bit_count=0;

    return c;
}

unsigned char readDHT11(char *temp,unsigned char *hum){
    unsigned char  d_rh, d_temp, check;              
    #asm ("cli") ;
    request();
    response();
    *hum   = recive();
    d_rh   = recive();
    *temp = (char)recive();
    d_temp = recive();
    check  = recive();     
    #asm ("sei") ;               
     
     
   return ((*hum  + d_rh + *temp + d_temp) == check) ;
}