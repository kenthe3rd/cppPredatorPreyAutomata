/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall 	3/04/2018	
 *
 *CS 162 400	Project 4
 *:::INPUT VALIDATION HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

class InputValidation
{
	private:
		bool validInput = false;
	public:
		int enforceInt();
		int enforceInt(int, int);
		int enforcePositiveInt();
		int enforcePositiveInt(int);
		double enforcePositiveDouble(double);
};
#endif

