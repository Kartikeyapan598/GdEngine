#pragma once

#include "Cndr/Core.h"

namespace Cndr
{

	class RenderApi
	{
	public :
		enum class API
		{
			None = 0, 
			OpenGL,
			DirectX,
			Vulcun
		};

	public :
		virtual ~RenderApi() = default;

		virtual void Init() = 0;
		virtual void Clear() = 0;

		static API GetAPI() { return m_api; }
		static void set_API(API user_api) { m_api = user_api; }

		//static Scope<RenderApi> Create();

	private	:
		static API m_api;
	};

}