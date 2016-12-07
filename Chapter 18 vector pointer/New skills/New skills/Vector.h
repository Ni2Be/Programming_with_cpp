#pragma once

namespace not_std {
	class vector
	{
	private:
		//std private:
		int sz;
		double* elem;
		void copy(const vector& arg);
	public:
		explicit vector(int size)
			:sz(size), elem(new double[size]) {}
		
		~vector() 
		{
			delete(elem);
		}

		vector(const vector&);
		double& operator[](int idx);
		const double& operator[](int idx) const;
		vector& operator=(const vector&);
	};
}
