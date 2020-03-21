#include "Dictionary.h"

Dictionary* Dictionary::m_instance = nullptr;

Dictionary* Dictionary::instance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Dictionary;
	}
	return m_instance;
}

void Dictionary::release()
{
	delete m_instance;
	m_instance = nullptr;
}

