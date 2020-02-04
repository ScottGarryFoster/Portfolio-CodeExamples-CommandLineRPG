#pragma once
#include <string>

using namespace std;
class InformationField
{
public:
	enum InfoField_Type : int {ift_text = 0, ift_textValue, ift_labelValueMax};
	enum InfoField_EntryType : int { ifet_int = 0, ifet_float, ifet_double, ifet_string, ifet_bool};

	bool m_isValid;

	InfoField_Type m_type;
	string *m_fieldName;

	InfoField_EntryType m_entry1Type;
	int *m_iEntry1;
	float *m_fEntry1;
	double *m_dEntry1;
	string *m_sEntry1;
	bool *m_bEntry1;

	InfoField_EntryType m_entry2Type;
	int* m_iEntry2;
	float* m_fEntry2;
	double* m_dEntry2;
	string* m_sEntry2;
	bool* m_bEntry2;
public:
	InformationField();

	InformationField(InfoField_Type type, string *pointerToLabel);

	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, int *pointToEntryOne);
	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, float *pointToEntryOne);
	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, double *pointToEntryOne);
	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, string *pointToEntryOne);
	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, bool *pointToEntryOne);

	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, int*pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo);
	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, float*pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo);
	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, double*pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo);
	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, string*pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo);
	InformationField(InfoField_Type type, string *pointerToLabel, InfoField_EntryType entryOneType, bool*pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo);

	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo);

	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo);

	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo);

	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo);
	InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo);

	virtual ~InformationField();

	const bool isVaild() { return m_isValid; }

	string buildOutput();
private:
	string returnEntryOne();
	string returnEntryTwo();
};

