#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/cm3/nvic.h>
#include <stdio.h>
#include <errno.h>

int _write(int file, char *ptr, int len);

#define LEDPORT (GPIOC)
#define LEDPIN (GPIO13)
#define GPIO_MODE_OUTPUT GPIO_MODE_OUTPUT_2_MHZ
#define GPIO_PUPD_NONE GPIO_CNF_OUTPUT_PUSHPULL

static void clock_setup(void) {
	rcc_periph_clock_enable(RCC_GPIOC);

	/* Enable clocks for GPIO port A (for GPIO_USART1_TX) and USART1. */
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_AFIO);
	rcc_periph_clock_enable(RCC_USART1);
}

static void usart_setup(void) {
	/* Setup GPIO pin GPIO_USART1_RE_TX on GPIO port B for transmit. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART1_TX);

	/* Setup UART parameters */
	usart_set_baudrate(USART1, 115200);
	usart_set_databits(USART1, 8);
	usart_set_stopbits(USART1, USART_STOPBITS_1);
	usart_set_parity(USART1, USART_PARITY_NONE);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);
	usart_set_mode(USART1, USART_MODE_TX_RX);

	/* Finally enable the USART. */
	usart_enable(USART1);
}

static void gpio_setup(void) {
	gpio_set_mode(LEDPORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LEDPIN);
}

int _write(int file, char *ptr, int len) {
	if (file == 1) {
		uint16_t i = 0;

		for (i = 0; i < len; i++)
			usart_send_blocking(USART1, ptr[i]);
		return i;
	}

	errno = EIO;

	return -1;
}

int main(void) {
	clock_setup();
	gpio_setup();
	usart_setup();

	while (1) {
		gpio_toggle(LEDPORT, LEDPIN);

		for (uint32_t i = 0; i < 1000000; i++) {
			__asm__("nop");
		}

		printf("Hello World! %i %f %f\r\n", 4, 3.7f, 1.3f);
	}

	return 0;
}
