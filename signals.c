#include "main.h"

/**
 * sigint_handler - CRTL + C handler
 * @signum: signal number
 *
 */
void sigint_handler(int __attribute__((unused)) signum)
{
	_putchar('\n');
	prompt();
}
/**
 * sigterm_handler - handles termination
 * @signum: The signal number
 */
void sigterm_handler(int __attribute__((unused)) signum)
{
	terminate_prog = 0;
}
