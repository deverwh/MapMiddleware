#ifndef Dictionary_H
#define Dictionary_H

class Dictionary
{
public:
	static Dictionary* instance();
	void release();

private:
	static Dictionary* m_instance;
};

#endif // Dictionary_H