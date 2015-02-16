#include "NumberGenerator.h"


//Constructors
NumberGenerator::NumberGenerator() {
	start = 0;
	end = 36;
	qsrand(1);
}

NumberGenerator::NumberGenerator(const int& start, const int& end) {
    this->start = start;
    this->end = end;
	qsrand(1);
}

//other
int NumberGenerator::rand() const {
	return (qrand() % (end + 1 - start) + start);
}

void NumberGenerator::set_seed(unsigned int seed) const {
	qsrand(seed);
}

void NumberGenerator::set_seed(QTime seed) const {
	qsrand((uint)seed.msec());
}

//get, set
int NumberGenerator::get_start() const {
	return start;
}

int NumberGenerator::get_end() const {
	return end;
}

void NumberGenerator::set_start(const int& new_start) {
	start = new_start;
}

void NumberGenerator::set_end(const int& new_end) {
	end = new_end;
}
