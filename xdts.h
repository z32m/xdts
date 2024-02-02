#ifndef __xdts_h__
#define __xdts_h__

#include <zephyr/kernel.h>
#include <zephyr/drivers/pwm.h>

typedef struct device device_t;
typedef struct gpio_dt_spec gpio_dt_spec_t;
typedef struct adc_dt_spec adc_dt_spec_t;
typedef struct k_mutex k_mutex_t;
typedef struct k_timer k_timer_t;
typedef struct k_event k_event_t;
typedef struct k_pipe k_pipe_t;
typedef struct pwm_dt_spec pwm_t;

#define L(_node_label) DT_NODELABEL(_node_label)
#define DEFINE_DEVICE(_node_label) const struct device *_node_label = DEVICE_DT_GET(L(_node_label))

#define TTY_DEVICE(_node_label) DEVICE_DT_GET(DT_PROP(L(_node_label), device))
#define DEFINE_TTY_DT(_node_label) const struct device *_node_label = TTY_DEVICE(_node_label)
#define DEFINE_TTY_DT_EXTERN(_node_label) extern const struct device *_node_label

#define TTY_DT_SPEC(_node_label)                        \
    {                                                   \
        .baudrate = DT_PROP(L(_node_label), baud_rate), \
        .parity = UART_CFG_PARITY_NONE,                 \
        .stop_bits = UART_CFG_STOP_BITS_1,              \
        .flow_ctrl = UART_CFG_FLOW_CTRL_NONE,           \
        .data_bits = UART_CFG_DATA_BITS_8,              \
    }

#define DEFINE_TTY_DT_SPEC(_node_label) const struct uart_config _node_label##_spec = TTY_DT_SPEC(_node_label)
#define TTY_DT_SPEC_GET_EXTERN(_node_label) extern const struct uart_config _node_label##_spec

#endif