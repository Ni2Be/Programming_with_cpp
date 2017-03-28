#pragma once
namespace not_std
{
	template <class T>
	class allocator
	{
	public:
		T* allocate(int n);
		void deallocate(T* p, int n);
		void construct(T* p, const T& v);
		void destroy(T* p);
	};
}

template <class T>
T* not_std::allocator<T>::allocate(int n)
{
	T* p = (T*)malloc(n * sizeof(T));
	return p;
}

template <class T>
void not_std::allocator<T>::deallocate(T* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(p);
		p++;
	}
}

template <class T>
void not_std::allocator<T>::construct(T* p, const T& v)
{
	*p = v;
}

template <class T>
void not_std::allocator<T>::destroy(T* p)
{
	p = 0;
}

