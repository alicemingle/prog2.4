#include "CComplexVector1.h"

CComplexVector1 operator+(const CComplexVector1& left, const CComplexVector& right) {
	CComplexVector1 a(std::max(left.vecsize, CComplexVector1(right).vecsize));
	std::copy(left.data.begin(), left.data.end(), a.data.begin());
	a += right;
	return a;
}

CComplexVector1 operator-(const CComplexVector1& left, const CComplexVector& right) {
	CComplexVector1 a(std::max(left.vecsize, CComplexVector1(right).vecsize));
	std::copy(left.data.begin(), left.data.end(), a.data.begin());
	a -= right;
	return a;
}

void CComplexVector1::setFilename(const char* FileName) {
	this->FileName = FileName;
}

const char* CComplexVector1::getFilename() const {
	return this->FileName.c_str();
}

int CComplexVector1::output(const char* FileName) {
	if (FileName == nullptr) {
		std::cout << "Error occured while working with file!" << std::endl;
		return 1;
	}
	std::ofstream out(FileName, std::ios::app);
	for (int i = 0; i < vecsize; i++) {
		if (data[i].im > 0) {
			out << data[i].re << "+" << data[i].im << "i" << " ";
		}
		else if (data[i].im < 0) {
			out << data[i].re << data[i].im << "i" << " ";
		}
		else {
			out << data[i].re << " ";
		}
	}
	out << std::endl << std::endl;
	out.close();
	return 0;
}
