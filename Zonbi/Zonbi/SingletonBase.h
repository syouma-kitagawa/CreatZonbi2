#ifndef SINGLETONBASE_H
#define SINGLETONBASE_H

template <class T>

class SingletonBase {
public:

	virtual ~SingletonBase() = 0;

    virtual static T GetpInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new T();
		}
		return m_pInstance;
	}
private:
	SingletonBase() = 0;
	static T * m_pInstance;
};

#endif