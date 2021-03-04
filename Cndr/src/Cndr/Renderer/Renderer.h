#pragma once

#include "Cndr/Interface/RenderApi.h"


// Libs for DirectX 
#include "Cndr/Log.h"
#include <d3d11.h>
#pragma comment(lib,"d3d11.lib")
//


/*
#include "Platform/RenderPlatform.h" 
*/ 

namespace Cndr
{

	class Renderer //: public RenderApi
	{
	public :

		void Init();// override;
		void Clear();// override;

		//static Renderer* GetRenderer();
	private :
		ID3D11Device* m_d3d_device;
		D3D_FEATURE_LEVEL m_feature_level;
		ID3D11DeviceContext* m_imm_context;
	};

}