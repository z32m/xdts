#ifndef __x_uart_h__
#define __x_uart_h__

#include <xdts.h>
#include <zephyr/drivers/uart.h>

typedef struct uart_config uart_config_t;

typedef struct
{
    const device_t *uart;
    const uart_config_t config;
    const size_t buffer_length;
    const uint32_t receive_timeout;
} uart_spec_t;

#define UART_CONFIG_DT(_node)                  \
    {                                          \
        .baudrate = DT_PROP(_node, baud_rate), \
        .parity = UART_CFG_PARITY_NONE,        \
        .stop_bits = UART_CFG_STOP_BITS_1,     \
        .flow_ctrl = UART_CFG_FLOW_CTRL_NONE,  \
        .data_bits = UART_CFG_DATA_BITS_8,     \
    }

#define DEFINE_UART(_node_label)                                \
    const uart_spec_t _node_label = {             \
        .uart = DEVICE_DT_GET(DT_PROP(L(_node_label), uart)),    \
        .config = UART_CONFIG_DT(L(_node_label)), \
        .buffer_length = DT_PROP(L(_node_label), buffer_length),\
        .receive_timeout = DT_PROP(L(_node_label), receive_timeout)}

#endif