#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void){
	srand(static_cast<unsigned int>(time(0)));
	int r = rand() % 3;

	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p){
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...){}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...){}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...){}
}

int main(){
	Base* Base;

	Base = generate();
	identify(Base);

	identify(*Base);
	delete Base;
	return 0;
}