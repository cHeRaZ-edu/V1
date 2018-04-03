#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <fstream>
#include "ConstantBuffer.h"
#include "Material.h"

#define MATRIX_BUFFER_ID			0
#define CUSTOM_BUFFER_ID			1

using namespace DirectX;
using namespace std;



enum class ShaderType {
	BasicShader = 1,
	MaterialShader = 2,
};

class Shader : public DxComponent<Shader>
{
private:
	struct MatrixConstantBufferType
	{
		XMMATRIX projectionViewWorld;
	};

protected:
	bool Create(D3D11_INPUT_ELEMENT_DESC* inputLayout, unsigned int layoutCount, const std::string&, const std::string&);
	void AddConstantBuffer(const string& bufferName, const ConstantBuffer &buffer);
public:
	Shader( ShaderType type );
	~Shader();

	ShaderType type;

	virtual bool Initialize(const std::string&, const std::string& ) = 0;
	void Shutdown();
	void BindShader();

	bool SetShaderParameters(XMMATRIX, XMMATRIX, XMMATRIX);
	bool SetShaderConstantBuffer(const std::string& bufferName, const void *values);
	string Name;
private:
	void OutputShaderErrorMessage(ID3D10Blob*, LPCTSTR);
	std::wstring s2ws(const std::string& s);

private:
	ID3D11VertexShader* VertexShader;
	ID3D11PixelShader* PixelShader;
	ID3D11InputLayout* Layout;
	std::map<string, ConstantBuffer> constantBufferMap;
};

