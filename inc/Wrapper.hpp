#ifndef  WRAPPER_HPP

# define WRAPPER_HPP

template <typename T>
class Wrapper_around
{
public:
	Wrapper_around(T value)
			: _value(value)
	{ }
	T operator *()
	{
		return _value;
	}
	virtual ~Wrapper_around()
	{
		delete _value;
	}
	T	getValue()
	{
		return (_value);
	}
private:
	T _value;
};

#endif