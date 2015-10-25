#include "AliceObject.h"

namespace Alice
{
	void*Object::m_pPool = nullptr;
	void Object::Init()
	{
		size_t totalSize = 1024000;
		m_pPool = new char[totalSize];
		init_memory_pool(totalSize,m_pPool);
	}
}