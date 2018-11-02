#include <iostream>
#include "Graphic.h"
#include "GraphicProxy.h"

GraphicProxy::GraphicProxy()
{
	this->graphic = 0;
}

GraphicProxy::~GraphicProxy()
{
	if (graphic)
		delete graphic;
}
/// <summary>
/// wont be initialised until getInstance is called (Lazy Loading)
/// </summary>
/// <returns></returns>
Graphic* GraphicProxy::getInstance(void)
{
	if (!graphic)
		graphic = new Graphic();
	return graphic;
}

void GraphicProxy::Draw()
{
	getInstance()->Draw();
}