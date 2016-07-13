#include "RLE.h"
#include <iostream>
using namespace std;


int main()
{
	cout<<"======= RLE Encoding =======\n"<<endl;
	cout<<"default constructor, << and decode()"<<endl;
	char* s1 = "AAAABBBBCCCAABBBB";
	RLE s1RLE(s1);
	cout<<s1<<endl;
	cout<<s1RLE<<endl;
	cout<<s1RLE.decode()<<endl;
	cout<<"========\n\n";

	cout<<"operator ="<<endl;
	RLE s("");
	s = s1RLE;
	cout<<s<<endl;
	cout<<s.decode()<<endl;
	cout<<"========\n\n";

	cout<<"copy-contructor and []"<<endl;
	RLE p = s;
	cout<<p<<endl;
	cout<<p.decode()<<endl;
	cout<<"p[0]: "<<p[0]<<endl;
	cout<<"p[16]: "<<p[16]<<endl;
	cout<<"p[17]: "<<p[17]<<endl;
	cout<<"========\n\n";

	cout<<"operator>>"<<endl;
	char s2[1000];
	cin>>s2;
	RLE s2RLE(s2);
	cout<<s2RLE<<endl;
	cout<<s2RLE.decode()<<endl;
	cout<<"s2RLE[1]: "<<s2RLE[1]<<endl;
	cout<<"========\n\n";

	cout<<"+="<<endl;
	s1RLE += s2RLE;
	cout<<s1RLE<<endl;
	cout<<s1RLE.decode()<<endl;
	cout<<"========\n\n";

	cout<<"+"<<endl;
	RLE s3RLE = (s1RLE+s2RLE);
	cout<<s3RLE<<endl;
	cout<<s3RLE.decode()<<endl;
	cout<<"========\n\n";

	cout<<"++obj"<<endl;
	RLE s4RLE(s1);
	++s4RLE;
	cout<<s4RLE<<endl;
	cout<<s4RLE.decode()<<endl;
	cout<<"========\n\n";

	cout<<"obj++"<<endl;
	cout<<s4RLE++<<endl;
	cout<<s4RLE<<endl;
	cout<<s4RLE.decode()<<endl;
	cout<<"========\n\n";

	cout<<"++ on empty obj"<<endl;
	RLE s5RLE("");
	++s5RLE;
	cout<<s5RLE<<endl;
	cout<<s5RLE.decode()<<endl;
	cout<<s5RLE++<<endl;
	cout<<s5RLE<<endl;
	cout<<s5RLE.decode()<<endl;
	cout<<"========\n\n";

	cout<<"--obj"<<endl;
	--s4RLE;
	cout<<"--"<<endl;
	cout<<s4RLE<<endl;
	cout<<s4RLE.decode()<<endl;
	cout<<"========\n\n";

	cout<<"obj--"<<endl;
	cout<<s4RLE--<<endl;
	cout<<s4RLE<<endl;
	cout<<s4RLE.decode()<<endl;
	cout<<"========\n\n";

	cout<<"-- on empty obj"<<endl;
	RLE s6RLE("");
	--s6RLE;
	cout<<s6RLE<<endl;
	cout<<s6RLE.decode()<<endl;
	cout<<s6RLE--<<endl;
	cout<<s6RLE<<endl;
	cout<<s6RLE.decode()<<endl;
	cout<<"========\n\n";

	cout<<"operator() for finding smaller RLE list"<<endl;
	cout<<p(7,5)<<endl;
	cout<<"========\n\n";

	cout<<"operator() for inserting given RLE list"<<endl;
	RLE c("CCCB");
	cout<<c<<endl;
	s(6,c);
	cout<<s<<endl;
	cout<<"========\n\n";

	cout<<"deleting symbols"<<endl;
	RLE s7RLE(s1);
	cout<<s7RLE<<endl;
	cout<<s7RLE.deleteSymbols(6,8)<<endl;
	cout<<"========\n\n";

	cout<<"== and !="<<endl;
	cout<<(s1RLE == s1RLE)<<endl;
	cout<<(s1RLE == s7RLE)<<endl;
	cout<<(s7RLE != s1RLE)<<endl;
	cout<<"========\n\n";

	cout<<">, >=. <, <="<<endl;
	RLE podspisak("BBC");
	cout<<(p > podspisak)<<endl;
	RLE nepodspisak("CAAABC");
	cout<<(nepodspisak < p)<<endl;
	cout<<"========\n\n";

	cout<<"operator*"<<endl;
	cout<<*p<<endl;
}