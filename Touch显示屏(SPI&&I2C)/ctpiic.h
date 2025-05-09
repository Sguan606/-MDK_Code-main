/*
 * @Author: 星必尘Sguan
 * @Date: 2025-04-12 22:23:15
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2025-04-14 01:06:20
 * @FilePath: \test_F407main\Hardware\ctpiic.h
 * @Description: 
 * 
 * Copyright (c) 2025 by $JUST, All Rights Reserved. 
 */
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机STM32F407ZGT6,正点原子Explorer STM32F4开发板,主频168MHZ，晶振12MHZ
//QDtech-TFT液晶驱动 for STM32 IO模拟
//xiao冯@ShenZhen QDtech co.,LTD
//公司网站:www.qdtft.com
//淘宝网站：http://qdtech.taobao.com
//wiki技术网站：http://www.lcdwiki.com
//我司提供技术支持，任何技术问题欢迎随时交流学习
//固话(传真) :+86 0755-23594567 
//手机:15989313508（冯工） 
//邮箱:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com 
//技术支持QQ:3002773612  3002778157
//技术交流QQ群:324828016
//创建日期:2018/08/09
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 深圳市全动电子技术有限公司 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================电源接线================================================//
//     LCD模块                STM32单片机
//      VCC          接        DC5V/3.3V      //电源
//      GND          接          GND          //电源地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为SPI总线
//     LCD模块                STM32单片机    
//    SDI(MOSI)      接          PB5          //液晶屏SPI总线数据写信号
//    SDO(MISO)      接          PB4          //液晶屏SPI总线数据读信号，如果不需要读，可以不接线
//=======================================液晶屏控制线接线==========================================//
//     LCD模块 					      STM32单片机 
//       LED         接          PB13         //液晶屏背光控制信号，如果不需要控制，接5V或3.3V
//       SCK         接          PB3          //液晶屏SPI总线时钟信号
//     LCD_RS        接          PB14         //液晶屏数据/命令控制信号
//     LCD_RST       接          PB12         //液晶屏复位控制信号
//     LCD_CS        接          PB15         //液晶屏片选控制信号
//=========================================触摸屏触接线=========================================//
//如果模块不带触摸功能或者带有触摸功能，但是不需要触摸功能，则不需要进行触摸屏接线
//	   LCD模块                STM32单片机 
//     CTP_INT       接          PB1          //电容触摸屏中断信号
//     CTP_SDA       接          PF11         //电容触摸屏IIC数据信号
//     CTP_RST       接          PC5          //电容触摸屏复位信号
//     CTP_SCL       接          PB0          //电容触摸屏IIC时钟信号
**************************************************************************************************/	
 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/
#ifndef __CTPIIC_H
#define __CTPIIC_H    
  	   		   

#include "stm32f4xx_hal.h"

// //IIC IO方向设置
// #define CTP_SDA_IN()  do{ \
//   GPIO_InitTypeDef GPIO_InitStruct = {0}; \
//   GPIO_InitStruct.Pin = GPIO_PIN_11; \
//   GPIO_InitStruct.Mode = GPIO_MODE_INPUT; \
//   GPIO_InitStruct.Pull = GPIO_PULLUP; \  // 根据需要选择上拉/下拉/无拉
//   HAL_GPIO_Init(GPIOF, &GPIO_InitStruct); \
// }while(0)

// #define CTP_SDA_OUT() do{ \
//   GPIO_InitTypeDef GPIO_InitStruct = {0}; \
//   GPIO_InitStruct.Pin = GPIO_PIN_11; \
//   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; \  // 推挽输出
//   GPIO_InitStruct.Pull = GPIO_NOPULL; \          // 输出模式通常不需要上下拉
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; \ // 根据需求选择速度
//   HAL_GPIO_Init(GPIOF, &GPIO_InitStruct); \
// }while(0)


//IIC所有操作函数
void CTP_IIC_Init(void);                	//初始化IIC的IO口				 
void CTP_IIC_Start(void);				//发送IIC开始信号
void CTP_IIC_Stop(void);	  				//发送IIC停止信号
void CTP_IIC_Send_Byte(uint8_t txd);			//IIC发送一个字节
uint8_t CTP_IIC_Read_Byte(unsigned char ack);	//IIC读取一个字节
uint8_t CTP_IIC_Wait_Ack(void); 				//IIC等待ACK信号
void CTP_IIC_Ack(void);					//IIC发送ACK信号
void CTP_IIC_NAck(void);					//IIC不发送ACK信号

#endif







