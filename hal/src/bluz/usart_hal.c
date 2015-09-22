/**
 ******************************************************************************
 * @file    usart_hal.c
 * @author  Satish Nair, Brett Walach
 * @version V1.0.0
 * @date    12-Sept-2014
 * @brief
 ******************************************************************************
  Copyright (c) 2013-2015 Particle Industries, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "usart_hal.h"

//Need this here. Particle HAL defines some symbols that are replicated in the Nordic SDK
#undef SCK
#undef MOSI
#undef MISO
#undef SS
#include "gpio_hal.h"
#include "app_uart.h"
#include "nrf51_callbacks.h"
#include "pinmap_impl.h"
#include "simple_uart.h"

void HAL_USART_Init(HAL_USART_Serial serial, Ring_Buffer *rx_buffer, Ring_Buffer *tx_buffer)
{
}
void HAL_USART_Begin(HAL_USART_Serial serial, uint32_t baud)
{
//    uint32_t nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud38400;
//    switch (baud) {
//        case 1200:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud1200;
//            break;
//        case 2400:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud2400;
//            break;
//        case 4800:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud4800;
//            break;
//        case 9600:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud9600;
//            break;
//        case 14400:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud14400;
//            break;
//        case 19200:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud19200;
//            break;
//        case 28800:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud28800;
//            break;
//        case 38400:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud38400;
//            break;
//        case 57600:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud57600;
//            break;
//        case 115200:
//            nrfBaudRate = UART_BAUDRATE_BAUDRATE_Baud115200;
//            break;
//    }
//    
//    int err_code;
//    const app_uart_comm_params_t comm_params =
//      {
//          PIN_MAP[RX].gpio_pin,
//          PIN_MAP[TX].gpio_pin,
//          11, /*random unused pin*/
//          20, /*random unused pin*/
//          APP_UART_FLOW_CONTROL_DISABLED,
//          false,
//          nrfBaudRate
//      };
//
//    APP_UART_FIFO_INIT(&comm_params,
//                         256,
//                         256,
//                         uart_error_handle,
//                         APP_IRQ_PRIORITY_LOW,
//                         err_code);
//
//    APP_ERROR_CHECK(err_code);
    simple_uart_config(11, PIN_MAP[TX].gpio_pin, 20, PIN_MAP[RX].gpio_pin, false);
}

void HAL_USART_End(HAL_USART_Serial serial)
{
//    app_uart_close(0);
}

uint32_t HAL_USART_Write_Data(HAL_USART_Serial serial, uint8_t data)
{
//    app_uart_put(data);
    simple_uart_put(data);
}

int32_t HAL_USART_Available_Data(HAL_USART_Serial serial)
{
    return 0;
}

int32_t HAL_USART_Read_Data(HAL_USART_Serial serial)
{
//    uint8_t* byte = NULL;
//    app_uart_get(byte);
//    return *byte;
}

int32_t HAL_USART_Peek_Data(HAL_USART_Serial serial)
{
    return 0;
}

void HAL_USART_Flush_Data(HAL_USART_Serial serial)
{
//    app_uart_flush();
}

bool HAL_USART_Is_Enabled(HAL_USART_Serial serial)
{
    return true;
}

void HAL_USART_Half_Duplex(HAL_USART_Serial serial, bool Enable)
{
}