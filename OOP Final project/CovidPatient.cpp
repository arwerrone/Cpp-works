#include <iostream>
#include "CovidPatient.h"

using namespace std;
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient():Patient(nextCovidTicket) {
	   nextCovidTicket += 1;
   }

   char CovidPatient::type() const {
	   char ret = 'C';
	   return ret;
   }

   std::istream& CovidPatient::csvRead(std::istream& istr) {
	   Patient::csvRead(istr);
	   nextCovidTicket = Patient::number() + 1;
	   istr.ignore(1000,'\n');
	   return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr)const {
	   if (Patient::fileIO()) {
		   Patient::csvWrite(ostr);
	   }
	   else {
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr);
		   ostr << endl;
	   }
	   return ostr;
   }

   std::istream& CovidPatient::read(std::istream& istr) {
	   if (Patient::fileIO())
		   csvRead(istr);
	   else
		   Patient::read(istr);

	   return istr;
   }

}
