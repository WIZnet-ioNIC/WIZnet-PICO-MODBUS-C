#include "mbtcp.h"
#include "mbascii.h"
#include "socket.h"
#include "stdio.h"
#include "pico/stdlib.h"
#include "string.h"
#include "mb.h"

volatile uint8_t *pucASCIIBufferCur;
volatile uint16_t usASCIIBufferPos;
volatile uint8_t *pucTCPBufferCur;
volatile uint16_t usTCPBufferPos;

extern uint8_t rip[4];
extern uint16_t port;
uint8_t recv_data[2048] = {0};
uint16_t recv_len = 0;
uint8_t send_data[2048] = {0};
uint16_t send_len = 0;

void mbTCPtoEVB(uint8_t sn)
{
	int32_t ret;
	gpio_init(USER_LED);
	gpio_set_dir(USER_LED, GPIO_OUT);

	if (MBtcp2evbFrame() != 0) // Frame received complete
	{
		uint16_t maxsize = 0;
		if (pucASCIIBufferCur[0] == 0x01)//Check whether the device address is 0x01
		{
			if ((uint8_t)pucASCIIBufferCur[1] == 0x05)//Write to a single device
			{
				if ((uint8_t)pucASCIIBufferCur[4] == 0xff)
				{
					gpio_put(USER_LED, 1);
					printf("LED ON\r\n");
				}
				else if ((uint8_t)pucASCIIBufferCur[4] == 0x00)
				{
					printf("LED OFF\r\n");
					gpio_put(USER_LED, 0);
				}
				send(sn, recv_data, recv_len);
			}
			else if ((uint8_t)pucASCIIBufferCur[1] == 0x01)//Read Write to a single device
			{
				if (recv_data[recv_len - 1] != 0x01)
				{
					printf("len error!\r\n");
				}
				else
				{
					printf("Read OK!\r\n");
					send_data[0] = recv_data[0];
					send_data[1] = recv_data[1];
					send_data[2] = recv_data[2];
					send_data[3] = recv_data[3];
					send_data[4] = 0x00;
					send_data[5] = 0x04;
					send_data[6] = 0x01;
					send_data[7] = 0x01;
					send_data[8] = 0x01;
					send_data[9] = gpio_get(USER_LED);
					send_len = 10;
					send(sn, (uint8_t *)send_data, send_len);
					memset(send_data, 0, send_len);
				}
			}
			else
			{
				printf("error code!\r\n");
			}
		}
		else
		{
			printf("address error!\r\n");
		}
	}
}

void mbEVBtoTCP(void)
{
	if (MBevb2tcpFrame() != 0)
	{
		switch (getSn_SR(0))
		{
		case SOCK_ESTABLISHED:
		case SOCK_CLOSE_WAIT:
			send(0, (uint8_t *)pucTCPBufferCur, usTCPBufferPos);
			break;
		default:
			break;
		}
	}
}
