#pragma once

template<class T>
class ISingleton {
protected:
    static T* _instance;

    ISingleton() {}
    virtual ~ISingleton() {}
    ISingleton(const ISingleton&) {}
    ISingleton& operator=(const ISingleton&) {}

public:
    static T* getInstance();
    static void destroyInstance();
};

template <class T>
T* ISingleton<T>::_instance = nullptr;

template<class T>
inline T* ISingleton<T>::getInstance()
{
    if (_instance == nullptr)
        _instance = new T();
    return _instance;
}

template<class T>
inline void ISingleton<T>::destroyInstance()
{
    if (_instance) delete _instance;
    _instance = nullptr;
}