#pragma once
#include "GameObject.h"

class Colision
{
public:
	Colision();

	//bool Initialize(GameObject*Go1, GameObject*Go2);

	bool ColisionSphere(Transforms*t1, Transforms*t2);
	//Colsiona al terrno deacuerdo con el radio esferico del modelo
	//bool ColsionTerrain(GameObject*terrain, Transforms*transform);
private:
protected:
};