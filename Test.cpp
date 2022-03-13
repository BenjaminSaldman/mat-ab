#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
using namespace std;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
TEST_CASE("Good input full matrix") {
	string s=nospaces("@@@@@@@@@\n"
					   "@-------@\n"
					   "@-@@@@@-@\n"
					   "@-@---@-@\n"
					   "@-@@@@@-@\n"
					   "@-------@\n"
					   "@@@@@@@@@");
	
	CHECK(nospaces(mat(9, 7, '@', '-')) == s);
	s=nospaces("#####\n"
				"#---#\n"
				"#####");
	CHECK(nospaces(mat(5,3,'#','-'))== s);
	s=nospaces("***********\n"
				"*---------*\n"
				"*-*******-*\n"
				"*---------*\n"
				"***********");
	CHECK(nospaces(mat(11,5,'*','-'))== s);
	s=nospaces("&&&\n"
				"&*&\n"
				"&&&");
	CHECK(nospaces(mat(3,3,'&','*'))== s);
	s=nospaces("^^^^^\n"
				"^###^\n"
				"^#^#^\n"
				"^###^\n"
				"^^^^^");
	CHECK(nospaces(mat(5,5,'^','#'))== s);
	s=nospaces("^^^^^^^\n"
				"^*****^\n"
				"^*^^^*^\n"
				"^*^*^*^\n"
				"^*^^^*^\n"
				"^*****^\n"
				"^^^^^^^");
	CHECK(nospaces(mat(7,7,'^','*'))== s);
	s=nospaces("#######\n"
				"#^^^^^#\n"
				"#^###^#\n"
				"#^#^#^#\n"
				"#^#^#^#\n"
				"#^#^#^#\n"
				"#^#^#^#\n"
				"#^#^#^#\n"
				"#^###^#\n"
				"#^^^^^#\n"
				"#######");
	CHECK(nospaces(mat(7,11,'#','^'))== s);
}

TEST_CASE("Bad input - even row/column or negative numbers") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(11, -5, '$', '%'));
	CHECK_THROWS(mat(-11, 5, '$', '%'));
	CHECK_THROWS(mat(-12, 5, '$', '%'));
	CHECK_THROWS(mat(10, 4, '$', '%'));
	CHECK_THROWS(mat(11, 0, '$', '%'));
	CHECK_THROWS(mat(0, 5, '$', '%'));
	CHECK_THROWS(mat(0, 0, '$', '%'));
	CHECK_THROWS(mat(10, -5, '$', '%'));
	CHECK_THROWS(mat(11, 5, ' ', '%'));
	CHECK_THROWS(mat(11, 5, '$', ' '));
	CHECK_THROWS(mat(11, 5, ' ', ' '));
	CHECK_THROWS(mat(11, 5, '\n', '$'));
	CHECK_THROWS(mat(11, 5, '$', '\n'));
	CHECK_THROWS(mat(11, 5, '\n', '\n'));
	CHECK_THROWS(mat(4, 1, '$', '%'));
	CHECK_THROWS(mat(1, 4, '$', '%'));

}
TEST_CASE("Speacial inputs"){
	string s=nospaces("*************");
	CHECK(nospaces(mat(13,1,'*','$'))==s);
	s=nospaces("*\n"
				"*\n"
				"*\n"
				"*\n"
				"*");
	CHECK(nospaces(mat(1,5,'*','#'))==s);
	s=nospaces("@@@@@@@@@\n"
				"@@@@@@@@@\n"
				"@@@@@@@@@\n"
				"@@@@@@@@@\n"
			    "@@@@@@@@@\n"
				"@@@@@@@@@\n"
				"@@@@@@@@@");
	CHECK(nospaces(mat(9, 7, '@', '@')) == s);
	s=nospaces("^^^^^^^\n"
				"^^^^^^^\n"
				"^^^^^^^\n"
				"^^^^^^^\n"
				"^^^^^^^\n"
				"^^^^^^^\n"
				"^^^^^^^");
	CHECK(nospaces(mat(7,7,'^','^'))== s);
	s=nospaces("^^^^^\n"
				"^^^^^\n"
				"^^^^^\n"
				"^^^^^\n"
				"^^^^^");
	CHECK(nospaces(mat(5,5,'^','^'))== s);
	s=nospaces("*");
	CHECK(nospaces(mat(1,1,'*','^'))== s);

}