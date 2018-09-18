#pragma once
#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "IGraphic.h"

//Common Interface 
class Graphic : public
IGraphic 
{
public:
	Graphic();
	~Graphic();
	void Draw();
};
#endif