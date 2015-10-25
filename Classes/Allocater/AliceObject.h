#pragma once
#include "tlsf.h"

namespace Alice
{
	class Object
	{
	public:
		static void Init();
	protected:
		static void*	m_pPool;
		static size_t	m_UsedSize;
	};
}