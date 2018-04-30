#pragma once
//#ifndef _ResourceManager_H_
//#define _ResourceManager_H_
#include "GameObject.h"
#include "Model.h"
#include "Texture.h"
#include "Shader.h"
#include "BasicShader.h"
#include "MaterialShader.h"
#include "Material.h"
#include "Light.h"
#include "KeyHandler.h"
struct ObjectInformation {
	string Name, Type, CreatedBy;
};
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static bool AddModel(string idFrom,string path, string name);
	static bool AddTexture(string idFrom,string path, string name);
	static bool AddStage(string idFrom,string path, string name, float Cells, float Witdth,float Height);
	static bool AddShader(string idFrom,string name, Shader* shader);
	static bool AddMaterial(string idFrom,string Nombre, vec3 Color);
	static bool AddLight(string idFrom,string Nombre, vec4 ambient, vec4 diffuse, vec3 direction);
	//Not delete change Scene
	//Define defualt system
	static bool AddBillboard(string idFrom, string Nombre, vec2 coordPositivo, vec2 coordNegativo);//1 Billboard Default
	static bool AddBitmap(string idFrom, string Nombre, vec4 rectBimap);//Count n  Bitmaps Default System

	static string BuildGameObject(string idFrom, string nameGameObject, string meshname, string texturename, string shadername, string materialname, string lightname);
	static GameObject* GetObjectByName(string Name);
	


	static bool DestroyItemsFromScene(string idFrom);
	static bool DestroyAllGameObjects();
	static bool DestroyAllSahders();
	static bool DestroyAllModels();//Not Delete Mesh Billbaord and Bitmaps
	static bool DestoryAllMaterial();
	static bool DestroyAllTexture();
	static bool DestroyAllLight();

	static string AsingTextureToGameObject(string nameGameObject, string nameTexture);
	static Material*GetMaterial(string nameMaterial);

	static bool bindShader(Shader* basicshader);
	static bool bindModel(Model * model);

	static void Shutdown();

	using GameObjectMap = std::map<string, GameObject>;
	using ModelMap = std::map<string, Model>;
	using TextureMap = std::map<string, Texture>;
	using ShaderMap = std::map<string, Shader*>;
	using MaterialMap = std::map<string, Material>;
	using LightMap = std::map<string, Light>;
	using GlobalResourcesMap = std::map<string, ObjectInformation>;

	//Informacion de pantalla
	static int ScreenWidthF;
	static int ScreenHeightF;
	static int ScreenWidth;
	static int ScreenHeight;
	static char GraphicMode;

	//Player 1
	static KeyHandler* Player1;


protected:
	static bool AddGameObject(GameObject gameObject, string idFrom);
	//Actuales
	static Shader* ShaderActual;
	static Model* ModeloActual;
	//Objetos
	static GameObjectMap GameObjectIdentifier;
	static int GameObjectIndex;
	//Modelos
	static ModelMap ModelIdentifier;
	static int ModelIndex;
	//Texture
	static TextureMap TextureIdentifier;
	static int TextureIndex;
	//Shader
	static ShaderMap ShaderIdentifier;
	//Material
	static MaterialMap MaterialIdentifier;
	static int MaterialIndex;
	//Material
	static LightMap LightIdentifier;
	static int LightIndex;
	//SceneResources
	static GlobalResourcesMap GlobalObjectsIdentifier;
	static int GlobalObjectsCounter;
};

//#endif