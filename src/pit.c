//
// Created by root on 5/11/18.
//

#include "pit.h"
#include "isr.h"
#include "Input_Output.h"
#include "monitor.h"

#define CHANNEL0_DATA 0x40
#define CHANNEL1_DATA 0x41
#define CHANNEL2_DATA 0x42
#define COMMAND_REGISTER 0x43

#define CHANNEL0 0
#define CHANNEL1 1
#define CHANNEL2 2

#define ACCESS_LOBYTE 0x01
#define ACCESS_HIBYTE 0x02
#define ACCESS_LOHIBYTE 0x03

#define OPERATION_INTERRUPT_COUNT 0x00
#define OPERATION_RETRIGGERABLE_ONESHOT 0x01
#define OPERATION_RATE_GENERATOR 0x02
#define OPERATION_SQUARE_WAVE_GENERATOR 0x03
#define OPERATION_SOFTWARE_STROBE 0x04
#define OPERATION_HARDWARE_STROBE 0x05

#define BINARY_MODE 0x00
#define BCD_MODE 0x01

uint32_t ticks = 0;

void io_wait_pit()
{
    for(int i =0; i < 200; i++);
}

static void timer_callback(registers_t regs)
{
    printf("Tick : %d \n", ticks);
    ticks++;
}

void init_timer(uint32_t frequency)
{
    register_interrupt_handler(IRQ0, &timer_callback);
    uint32_t divisor = PIT_FREQUENCY / frequency;

    printf("Divisor : %d", divisor);

    uint8_t command = (CHANNEL0 << 6) | (ACCESS_LOHIBYTE << 4) | (OPERATION_SQUARE_WAVE_GENERATOR << 1) | (BINARY_MODE);

    printf("Command : 0x%x", command);

    outByte(COMMAND_REGISTER,command);
    io_wait_pit();
    outByte(CHANNEL0_DATA, (uint8_t) (divisor & 0xFF));
    io_wait_pit();
    outByte(CHANNEL0_DATA, (uint8_t) ((divisor >> 8) & 0xFF));
    io_wait_pit();
}