#include "xparameters.h"
#include "xgpio.h"
#include "xutil.h"
  

//====================================================

int main (void) 
{

	//----------变量定义-------------
		XGpio led,push; //2个GPIO  led灯 和 button(push)
		int i,psb_check;//psb_check为push的返回值

	    xil_printf("-- Start of the Program --\r\n");
	    xil_printf("result");
	    //GPIO口的初始化 及 输入输出设置
		XGpio_Initialize(&led,XPAR_SW_4BIT_DEVICE_ID);
		XGpio_SetDataDirection(&led,1,0x00000000);//led  0是输出

		XGpio_Initialize(&push, XPAR_BTNS_4BIT_DEVICE_ID);
		XGpio_SetDataDirection(&push, 1, 0xffffffff);//button 1是输入


		//try 1  按1亮
		while (1)
		{
	        //按下button,得到按下哪个按钮
			psb_check = XGpio_DiscreteRead(&push,1);
			xil_printf("psb_check %x\r\n",psb_check);

			if(psb_check==1)
			{
				//按下按钮BTN0，接在JE2上的绿灯会发光，绿灯用于控制短亮
				XGpio_DiscreteWrite(&led,1,2);
			}
			else if(psb_check==4)
			{
				//按下按钮BTN2，接在JE4上的蓝灯会发光，蓝灯用于控制长亮
				XGpio_DiscreteWrite(&led,1,8);
			}
			else
				XGpio_DiscreteWrite(&led,1,1);
		    for (i=0; i<9999999; i++);
		}

}
 
