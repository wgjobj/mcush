#include "hal.h"

const char gpio_start='a', gpio_stop='g';

GPIO_TypeDef *ports[] = { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG };



static void _set_dir( int port, int bits, GPIOMode_TypeDef mode, int pull )
{
    GPIO_InitTypeDef GPIO_InitStructure;
    int i;
        
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Mode = mode;
    GPIO_InitStructure.GPIO_PuPd = pull;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    for( i=0; i<32; i++ )
    {
        if( bits & (1<<i) )
        { 
            GPIO_InitStructure.GPIO_Pin = 1<<i;
            GPIO_Init(ports[port], &GPIO_InitStructure);
        }
    }
}


int hal_gpio_get_port_num(void)
{
    return gpio_stop - gpio_start + 1;
}


void hal_gpio_init(void)
{
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOD, ENABLE);
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOF, ENABLE);
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOG, ENABLE);
}


void hal_gpio_set_input(int port, int bits)
{
    _set_dir( port, bits, GPIO_Mode_IN, GPIO_PuPd_UP );
}


void hal_gpio_set_input_pull(int port, int bits, int pull)
{
    _set_dir( port, bits, GPIO_Mode_IN, pull ? GPIO_PuPd_UP : GPIO_PuPd_DOWN );
}


void hal_gpio_set_output(int port, int bits)
{
    _set_dir( port, bits, GPIO_Mode_OUT, 0 );
}


void hal_gpio_set(int port, int bits)
{
    GPIO_SetBits(ports[port], bits);
}


void hal_gpio_clr(int port, int bits)
{
    GPIO_ResetBits(ports[port], bits);
}


void hal_gpio_toggle(int port, int bits)
{
    GPIO_Write(ports[port], GPIO_ReadInputData(ports[port]) ^ bits);
}


int hal_gpio_get(int port, int bits)
{
    return GPIO_ReadInputData(ports[port]) & bits;
}



