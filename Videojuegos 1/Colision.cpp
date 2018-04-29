#include "stdafx.h"

Colision::Colision()
{

}



bool Colision::Initialize(GameObject*Go1,GameObject*Go2)
{
	//float SizeX = 256.0f, SizeZ = 256.0f;

	//vec3 GridQuadSize = vec3(1.0f / SizeX * SizeX, 0.0f, 1.0f / SizeZ * SizeZ);

	//vec2 GridCoord = vec2((int)(pos.x / GridQuadSize.x), (int)(pos.z / GridQuadSize.z));

	//if (GridCoord.x>(SizeX / 2) || GridCoord.x<-(SizeX / 2) || GridCoord.y>(SizeZ / 2) || GridCoord.y <-(SizeZ / 2))
	//{
	//	return false;
	//}

	//int index = ((SizeZ/2)*SizeX) + GridCoord.y *SizeX + (SizeX/2) + GridCoord.x;
	//pos.y = Mesh.GetVertex(index).y + 3;

	return true;
}

bool Colision::ColisionSphere(Transforms*transform1, Transforms*transform2)
{
	double escalar1;
	double escalar2;
	double distancia;
	
	if (transform1->GetScale().x != transform1->GetScale().y || transform1->GetScale().x != transform1->GetScale().z)
	{
		escalar1 = transform1->GetScale().x;
		if(escalar1<transform1->GetScale().y)
			escalar1 = transform1->GetScale().y;
		if (escalar1<transform1->GetScale().z)
			escalar1 = transform1->GetScale().z;
	}
	else
		escalar1 = transform1->GetScale().x;

	if (transform2->GetScale().x != transform2->GetScale().y || transform2->GetScale().x != transform2->GetScale().z)
	{
		escalar2 = transform2->GetScale().x;
		if (escalar2<transform2->GetScale().y)
			escalar2 = transform2->GetScale().y;
		if (escalar2<transform2->GetScale().z)
			escalar2 = transform2->GetScale().z;
	}
	else
		escalar2 = transform2->GetScale().x;

	distancia = sqrt(
					  pow(transform1->GetTranslation().x - transform2->GetTranslation().x, 2)
					+ pow(transform1->GetTranslation().y - transform2->GetTranslation().y, 2)
					+ pow(transform1->GetTranslation().z - transform2->GetTranslation().z, 2)
					);
	// d> r1+r2 = false
	// d < r1+r2 = true - Colsion 
	if (distancia < (transform1->GetRadio()*escalar1) + (transform2->GetRadio()*escalar2))
		return true;

	return false;
}

bool Colision::ColsionTerrain(GameObject*terrain, Transforms*transform)
{
	double escalar;
	double distancia;
	//Vertice donde esta el objecto
	vec3 vertexTerreno = transform->GetTranslation();
	//Checkar si esta adentro del terreno
	if (!terrain->GetModel()->isIntoTerrain(vertexTerreno))
		return false;
	//Obtener vertice a calcular
	vertexTerreno.y = terrain->GetModel()->GetPositionHeightMap(vertexTerreno);
	//Checkar si hay un cambio de escala en el modelo
	if (transform->GetScale().x != transform->GetScale().y || transform->GetScale().x != transform->GetScale().z)
	{
		escalar = transform->GetScale().x;
		if (escalar<transform->GetScale().y)
			escalar = transform->GetScale().y;
		if (escalar<transform->GetScale().z)
			escalar = transform->GetScale().z;
	}
	else
		escalar = transform->GetScale().x;

	//En teoria solo debe de medir Y
	distancia = sqrt(
		pow(vertexTerreno.x - transform->GetTranslation().x, 2)
		+ pow(vertexTerreno.y - transform->GetTranslation().y, 2)
		+ pow(vertexTerreno.z - transform->GetTranslation().z, 2)
	);

	//checar colsion
	if (distancia < (transform->GetRadio()*escalar))
		return true;

	return false;
}