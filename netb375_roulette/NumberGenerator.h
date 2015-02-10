#ifndef NUMBER_GENERATOR_H
#define NUMBER_GENERATOR_H

#include "NumberGenerator.h"
#include <QTime>
#include <QtGlobal>

class NumberGenerator {
private:
	int start;
	int end;
public:
	//constructors
	NumberGenerator();
	NumberGenerator(const int& start, const int& end);
	//other
	int rand() const;
	void set_seed(unsigned int& seed) const;
	void set_seed(QTime seed) const;
	//get set
	int get_start() const;
	int get_end() const;
	void set_start(const int& new_start);
	void set_end(const int& new_end);
};

#endif