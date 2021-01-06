#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
unsigned int add_checksum(unsigned int n);
void add_checksum(unsigned int array[], std::size_t capacity);
bool verify_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n);
void remove_checksum(unsigned int array[], std::size_t capacity);
#endif

#ifndef MARMOSET_TESTING
int main() {
	unsigned int value_to_protect { 21352411 };
	unsigned int protected_value = add_checksum(value_to_protect);

	std::cout << "The value " << value_to_protect
			<< " with the checksum added is " << protected_value << "."
			<< std::endl;

	if (verify_checksum(protected_value)) {
		std::cout << "The checksum is valid." << std::endl;
	} else {
		std::cout << "The checksum is invalid." << std::endl;
	}

	std::size_t const qty_values { 3 };
	unsigned int value_series[qty_values] { 20201122, 20209913, 20224012 };

	add_checksum(value_series, qty_values);

	std::cout << "Series with checksums added: ";
	for (std::size_t series_index { 0 }; series_index < qty_values;
			series_index++) {
		std::cout << value_series[series_index] << " ";
	}
	std::cout << std::endl;


		remove_checksum(value_series, qty_values);

		std::cout << "Series with checksums removed: ";
		for (std::size_t series_index { 0 }; series_index < qty_values;
				series_index++) {
			std::cout << value_series[series_index] << " ";
		}
		std::cout << std::endl;




	return 0;
}
#endif

unsigned int add_checksum(unsigned int n) {

	if (n < 99999999) {
		int checked_sum { 0 };
		unsigned int new_n { n }; // to have the value of n somewhere stacked away
		int digit_1; //rightmost digit (first digit to multiply by two)
		unsigned int digit_2; //second digit

		//calculate the checksum

		while (n > 0) {    //condition can also be n != 0

			digit_1 = (n % 10) * 2;

			if (digit_1 > 9) {
				digit_1 = (1 + (digit_1 - 10)); // because no digit that is greater than 18 (9*2)
			}

			//chop off the rightmost digit IOW get new n
			n = n / 10;

			//Get to digit_2
			digit_2 = (n % 10);
			n = n / 10;

			checked_sum = checked_sum + digit_1 + digit_2;
		}

		checked_sum = ((checked_sum * 9) % 10);
		new_n = (new_n * 10) + checked_sum;
		return new_n;

	}

	else {
		return UINT_MAX;
	}
}

void add_checksum(unsigned int array[], std::size_t capacity) {     //REVISE ARRAYS

//	array[0] = add_checksum(array[0]); don't need this so what this line does is that it looks for the first array size and adds checksum to that array element and stores it

	for (std::size_t array_index { 0 }; array_index < capacity; array_index++) { //this works for array of size capacity (n). ---> reason is < capacity is because if capacity is 3, it runs for 0,1,2.

		array[array_index] = add_checksum(array[array_index]);
	}

	// Lets do another loop for the same purpose but now a WHILE loop ~~ when we are working with arrays we are directly access memory using size_t so it is related to how memory is accessed on computer.

//	while (array_index < capacity) {
//		array[array_index] = add_checksum(array[array_index]);
//				array_index++;
//	}
}

bool verify_checksum(unsigned int n) {

	if (n < 999999999) {

	//		add_checksum(n/10); // other way, name this as a variable and call that in the if statement

		if (add_checksum(n/10) == n) {
			return true;
		}

		else {

			return false;
		}
	}

	else {
		return false;
	}
}

unsigned int remove_checksum(unsigned int n) {

	if (n < 999999999) {

		if (verify_checksum(n)) {
			return n / 10;
		}

		else {
			return UINT_MAX;
		}

	}
	else {
		return UINT_MAX;
	}
}


void remove_checksum(unsigned int array[], std::size_t capacity) {  //REVISE ARRAYS (2)

//	array[0] = remove_checksum(array[0]); don't need this

	for (std::size_t array_index { 0 }; array_index < capacity; array_index++) {

		array[array_index] = remove_checksum(array[array_index]);
	}
}

// we need to have array size in order to call function in array could be a variable - unknown
