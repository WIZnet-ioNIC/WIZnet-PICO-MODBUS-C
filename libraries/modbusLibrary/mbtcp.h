#ifndef _MBTCP_H_
#define _MBTCP_H_

#include "stdio.h"

extern uint8_t mbTCPtid1;
extern uint8_t mbTCPtid2;
	
extern volatile uint8_t *pucRTUBufferCur;
extern volatile uint16_t usRTUBufferPos;
extern volatile uint8_t *pucTCPBufferCur;
extern volatile uint16_t usTCPBufferPos;

int MBudp2rtuFrame(void);
int MBtcp2rtuFrame(void);

void mbTCPtoEVB(uint8_t sn);
void mbEVBtoTCP(void);
void do_Modbus(uint8_t sn);
#endif


