#include "readGameXML.h"
#include <map>

map<string, string> item;
void readItemFile(char* filePath)
{
	XMLDocument doc;
	doc.LoadFile(filePath);
	XMLElement* itemRoot = doc.RootElement();
	XMLElement* itemNode = itemRoot->FirstChildElement("item");
	
	while (itemNode)
	{
			const XMLAttribute* itemAttribtue = itemNode->FirstAttribute();
			//cout << itemAttribtue->Value() << itemAttribtue->Next()->Value() << endl;
			item.insert(map<string, string>::value_type(itemAttribtue->Value(), itemAttribtue->Next()->Value()));
			itemNode = itemNode->NextSiblingElement();
	}
	
}

int main()
{
	readItemFile("item.xml");
	map<string, string>::const_iterator map_it = item.begin();
	while (map_it!=item.end())
	{
		cout << map_it->first << endl;
		++map_it;
	}
}