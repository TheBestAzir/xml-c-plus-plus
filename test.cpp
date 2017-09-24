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
	TiXmlElement* rootElement = doc.RootElement();  //School元素    
	TiXmlElement* classElement = rootElement->FirstChildElement();  // Class元素  
	TiXmlElement* studentElement = classElement->FirstChildElement();  //Students    
	for (; studentElement != NULL; studentElement = studentElement->NextSiblingElement()) {
		TiXmlAttribute* attributeOfStudent = studentElement->FirstAttribute();  //获得student的name属性    
		for (; attributeOfStudent != NULL; attributeOfStudent = attributeOfStudent->Next()) {
			cout << attributeOfStudent->Name() << " : " << attributeOfStudent->Value() << std::endl;
		}

		TiXmlElement* studentContactElement = studentElement->FirstChildElement();//获得student的第一个联系方式   
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

