#include "conversion.h"
#include <string>


char* string2char(System::String^ chaineVS){
    char* chaine =new char[chaineVS->ToCharArray()->Length+1];
    int i;
    for(i=0;i< chaineVS->ToCharArray()->Length;i++){
        chaine[i]=chaineVS->ToCharArray()[i];
    }
    chaine[i] = '\0';
    return chaine;
}



std::string String2StdString(System::String^ managedString) {
	std::string result;
	for (int i = 0; i < managedString->Length; i++) {
		result += static_cast<char>(managedString[i]);  // Convert each character
	}
	return result;
}