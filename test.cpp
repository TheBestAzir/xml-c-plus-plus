#include <iostream>  
#include "tinystr.h"  
#include "tinyxml.h"  
#include <string>  
using namespace std;
void readSchoolXml() {
	using namespace std;
	const char * xmlFile = "E:\Notepad++\zr.xml";
	
	TiXmlDocument doc;
	if (doc.LoadFile(xmlFile)) {
		doc.Print();
	}
	else {
		cout << "can not parse zr.xml" << endl;
		return;
	}
	TiXmlElement* rootElement = doc.RootElement();  //SchoolԪ��    
	TiXmlElement* classElement = rootElement->FirstChildElement();  // ClassԪ��  
	TiXmlElement* studentElement = classElement->FirstChildElement();  //Students    
	for (; studentElement != NULL; studentElement = studentElement->NextSiblingElement()) {
		TiXmlAttribute* attributeOfStudent = studentElement->FirstAttribute();  //���student��name����    
		for (; attributeOfStudent != NULL; attributeOfStudent = attributeOfStudent->Next()) {
			cout << attributeOfStudent->Name() << " : " << attributeOfStudent->Value() << std::endl;
		}

		TiXmlElement* studentContactElement = studentElement->FirstChildElement();//���student�ĵ�һ����ϵ��ʽ   
		for (; studentContactElement != NULL; studentContactElement = studentContactElement->NextSiblingElement()) {
			string contactType = studentContactElement->Value();
			string contactValue = studentContactElement->GetText();
			cout << contactType << " : " << contactValue << std::endl;
		}

	}
}
int main() {
	readSchoolXml();
	system("pause");
	return 1;
}

