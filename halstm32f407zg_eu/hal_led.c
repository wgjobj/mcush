#include "hal.h"
#include "hal_led.def"


void hal_led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    int i;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    for( i=0; i<led_num; i++ )
    {
        GPIO_InitStructure.GPIO_Pin = led_pins[i];
        GPIO_Init(led_ports[i], &GPIO_InitStructure);
        GPIO_SetBits(led_ports[i], led_pins[i]);
    }
}

int hal_led_get_num(void)
{
    return led_num;
}

void hal_led_set(int index)
{
    GPIO_ResetBits(led_ports[index], led_pins[index]);
}

void hal_led_clr(int index)
{
    GPIO_SetBits(led_ports[index], led_pins[index]);
}

void hal_led_toggle(int index)
{
    GPIO_WriteBit(led_ports[index], led_pins[index], \
            GPIO_ReadOutputDataBit(led_ports[index], led_pins[index]) ? 0 : 1);
}

int hal_led_get(int index)
{
    return GPIO_ReadOutputDataBit(led_ports[index], led_pins[index]) ? 0 : 1;
}


