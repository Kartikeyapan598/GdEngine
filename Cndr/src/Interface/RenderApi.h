#pragma once

#include "Cndr/Core/Core.h"

namespace Cndr
{
	enum class CR_API API
	{
		None = 0,
		OpenGL,
		DirectX,
		Vulcun
	};

	class CR_API RenderApi
	{
	public:
		virtual ~RenderApi() {}

		virtual void Init() = 0;
		virtual void Clear() = 0;

		//static API GetAPI() { return m_api; }
		static void set_API(API user_api) { m_api = user_api; }

		//static Scope<RenderApi> Create();

		RenderApi* GetRenderer(API m_api = API::DirectX);

	private:
		static inline API m_api;
	};
}