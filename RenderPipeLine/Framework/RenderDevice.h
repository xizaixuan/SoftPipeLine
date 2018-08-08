/////////////////////////////////////////////////////////////////////////////////
/// Copyright (C), 2017, xizaixuan. All rights reserved.
/// \brief   绘制类
/// \author  xizaixuan
/// \date    2017-07
/////////////////////////////////////////////////////////////////////////////////
#ifndef _RenderDevice_H_
#define _RenderDevice_H_

#include <windows.h>
#include <D2D1_1.h>
#include "..\Utility\Singleton.h"




class RenderDevice :public Singleton <RenderDevice>
{
	SINGLETON_DEFINE(RenderDevice)
private:
	RenderDevice(void);
	~RenderDevice(void);

public:
	/// \brief 初始化渲染设备
	void initRenderDevice(HWND hWndMain,int WindowWidth,int WindowHeight);

	/// brief 渲染开始
	void renderBegin();

	/// brief 渲染结束
	void renderEnd();

	/// \brief 更新Buffer
	void renderBuffer();
	
	/// \brief 绘制color
	void drawPixel(DWORD x, DWORD y, DWORD color);

private:
	///	窗口宽度
	DWORD	m_WindowWidth;

	///	窗口高度
	DWORD	m_WindowHeight;

	///	窗口句柄
	HWND	m_HWND;

	/// 实例工厂
	ID2D1Factory*			m_D2DFactory;

	/// 渲染目标
	ID2D1HwndRenderTarget*	m_RenderTarget;

	/// 位图
	ID2D1Bitmap*			m_Bitmap;

	/// 渲染数据
	DWORD*					m_DataBuffer;
};

#endif
