#ifndef __HAL_PLATFORM_H__
#define __HAL_PLATFORM_H__

#define HSE_VALUE  25000000

#define HAL_LED_REV
#define HAL_LED_NUM   4
#define HAL_LED_PORTS  { 3, 7, 7, 7 } 
#define HAL_LED_PINS  { 12, 10, 11, 12 }

#define HAL_KEY_NUM   2
#define HAL_KEY_PORTS   { 0, 2 }
#define HAL_KEY_PINS  { 0, 13 }


#ifndef HAL_RTC
  #define HAL_RTC  1
  #define USE_CMD_RTC  1
#endif

#include <time.h>
int  hal_rtc_get( struct tm *t );
int  hal_rtc_set( struct tm *t );
int  hal_rtc_get_tick( uint64_t *tick );
void hal_rtc_init(void);

#ifndef HAL_RNG
#define HAL_RNG   1
#endif
void hal_rng_init(void);
uint32_t hal_rng_get(void);



#ifndef USE_CMD_SGPIO
#define USE_CMD_SGPIO  0
#endif

#ifndef MCUSH_SPIFFS
#define MCUSH_SPIFFS  1
#endif

//#define HAL_SPIFFS_CHIPID  0xEF4018  // W25P128
#define sFLASH_SPI                           SPI5
#define sFLASH_SPI_CLK                       RCC_APB2Periph_SPI5
#define sFLASH_SPI_CLK_INIT                  RCC_APB2PeriphClockCmd
/* clk */
#define sFLASH_SPI_SCK_PIN                   GPIO_Pin_7
#define sFLASH_SPI_SCK_GPIO_PORT             GPIOF
#define sFLASH_SPI_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOF
#define sFLASH_SPI_SCK_SOURCE                GPIO_PinSource7
#define sFLASH_SPI_SCK_AF                    GPIO_AF_SPI2
/* miso */
#define sFLASH_SPI_MISO_PIN                  GPIO_Pin_8
#define sFLASH_SPI_MISO_GPIO_PORT            GPIOF
#define sFLASH_SPI_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOF
#define sFLASH_SPI_MISO_SOURCE               GPIO_PinSource8
#define sFLASH_SPI_MISO_AF                   GPIO_AF_SPI2
/* mosi */
#define sFLASH_SPI_MOSI_PIN                  GPIO_Pin_9
#define sFLASH_SPI_MOSI_GPIO_PORT            GPIOF
#define sFLASH_SPI_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOF
#define sFLASH_SPI_MOSI_SOURCE               GPIO_PinSource9
#define sFLASH_SPI_MOSI_AF                   GPIO_AF_SPI2
/* cs */
#define sFLASH_CS_PIN                        GPIO_Pin_6
#define sFLASH_CS_GPIO_PORT                  GPIOF
#define sFLASH_CS_GPIO_CLK                   RCC_AHB1Periph_GPIOF

#include "mcush_vfs.h"



#define LCD_ROW_NUM    320
#define LCD_COL_NUM    240

void hal_lcd_init(void);
void hal_lcd_backlight(int on);
void hal_lcd_clrscr(uint16_t backcolor);
void hal_lcd_pixel(uint16_t x0, uint16_t y0, uint16_t color);
void hal_lcd_rectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
void hal_lcd_circle(uint16_t x0, uint16_t y0, uint8_t r, uint16_t color);
void hal_lcd_hline(uint8_t y, uint8_t x0, uint8_t x1, uint16_t color);
void hal_lcd_vline(uint8_t x, uint8_t y0, uint8_t y1, uint16_t color);
uint16_t hal_lcd_get_pixel(uint16_t x0, uint16_t y0);

#if HAL_SDRAM
#include "hal_sdram.h"
#endif

#if HAL_CAN
#include "hal_can.h"
#endif

#endif
