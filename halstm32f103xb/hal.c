#include <math.h>
#include "hal.h"


const unsigned int baudrate=9600;


void hal_delay_ms(uint32_t ms)
{
    volatile uint32_t a;
    while(ms--)
    {
        for(a=1600; a; a--); 
    }
}

void test_hal_delay_ms(void)
{
    while(1)
    {
        hal_delay_ms(1000);
    }
}


void hal_rcc_init(void)
{  
    /* Enable ADC & SYSCFG clocks */
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_SYSCFG , ENABLE);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
}

 
int hal_init(void)
{
    hal_rcc_init();
    hal_debug_init();
    hal_gpio_init();
    hal_led_init();
    if( !hal_uart_init(baudrate) )
        return 0;
    return 1;
}



