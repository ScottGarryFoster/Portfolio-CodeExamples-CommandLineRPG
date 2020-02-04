#include "InformationField.h"



InformationField::InformationField()
{
	m_isValid = false;

	m_type = InfoField_Type::ift_text;
	m_fieldName = nullptr;

	m_entry1Type = InfoField_EntryType::ifet_string;
	m_iEntry1 = nullptr;
	m_fEntry1 = nullptr;
	m_dEntry1 = nullptr;
	m_sEntry1 = nullptr;
	m_bEntry1 = nullptr;

	m_entry2Type = InfoField_EntryType::ifet_string;
	m_iEntry2 = nullptr;
	m_fEntry2 = nullptr;
	m_dEntry2 = nullptr;
	m_sEntry2 = nullptr;
	m_bEntry2 = nullptr;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel) : InformationField()
{
	if (type != InfoField_Type::ift_text) return;
	if (pointerToLabel == nullptr) return;

	m_type = InfoField_Type::ift_text;
	m_fieldName = pointerToLabel;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne) : InformationField()
{
	if (type != InfoField_Type::ift_textValue) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryOne == nullptr) return;

	m_type = InfoField_Type::ift_textValue;
	m_fieldName = pointerToLabel;
	m_entry1Type = entryOneType;
	m_iEntry1 = pointToEntryOne;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne) : InformationField()
{
	if (type != InfoField_Type::ift_textValue) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryOne == nullptr) return;

	m_type = InfoField_Type::ift_textValue;
	m_fieldName = pointerToLabel;
	m_entry1Type = entryOneType;
	m_fEntry1 = pointToEntryOne;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne) : InformationField()
{
	if (type != InfoField_Type::ift_textValue) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryOne == nullptr) return;

	m_type = InfoField_Type::ift_textValue;
	m_fieldName = pointerToLabel;
	m_entry1Type = entryOneType;
	m_dEntry1 = pointToEntryOne;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne) : InformationField()
{
	if (type != InfoField_Type::ift_textValue) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryOne == nullptr) return;

	m_type = InfoField_Type::ift_textValue;
	m_fieldName = pointerToLabel;
	m_entry1Type = entryOneType;
	m_sEntry1 = pointToEntryOne;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne) : InformationField()
{
	if (type != InfoField_Type::ift_textValue) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryOne == nullptr) return;

	m_type = InfoField_Type::ift_textValue;
	m_fieldName = pointerToLabel;
	m_entry1Type = entryOneType;
	m_bEntry1 = pointToEntryOne;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_iEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_iEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_fEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_iEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_dEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_iEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_sEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_iEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne, InfoField_EntryType entryTwoType, int* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_bEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_iEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_iEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_fEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_fEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_fEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_dEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_fEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_sEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_fEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne, InfoField_EntryType entryTwoType, float* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_bEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_fEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_iEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_dEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_fEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_dEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_dEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_dEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_sEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_dEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne, InfoField_EntryType entryTwoType, double* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_bEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_dEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_iEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_sEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_fEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_sEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_double) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_dEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_sEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_sEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_sEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne, InfoField_EntryType entryTwoType, string* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_string) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_bEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_sEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, int* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_int) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_iEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_bEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, float* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_fEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_bEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, double* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_dEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_bEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, string* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_sEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_bEntry2 = pointToEntryTwo;

	m_isValid = true;
}

InformationField::InformationField(InfoField_Type type, string* pointerToLabel, InfoField_EntryType entryOneType, bool* pointToEntryOne, InfoField_EntryType entryTwoType, bool* pointToEntryTwo) : InformationField()
{
	if (type != InfoField_Type::ift_labelValueMax) return;
	if (pointerToLabel == nullptr) return;
	if (entryOneType != InfoField_EntryType::ifet_float) return;
	if (pointToEntryOne == nullptr) return;
	if (entryTwoType != InfoField_EntryType::ifet_bool) return;
	if (pointToEntryTwo == nullptr) return;

	m_type = InfoField_Type::ift_labelValueMax;
	m_fieldName = pointerToLabel;

	m_entry1Type = entryOneType;
	m_bEntry1 = pointToEntryOne;

	m_entry2Type = entryTwoType;
	m_bEntry2 = pointToEntryTwo;

	m_isValid = true;
}


InformationField::~InformationField()
{
	//You don't have to clean up anything you just show the values.
}

string InformationField::buildOutput()
{
	if (!m_isValid) return "";
	switch (m_type)
	{
	case InfoField_Type::ift_text:
		if (m_fieldName == nullptr) return "";
		return *m_fieldName;
	case InfoField_Type::ift_textValue:
		if (m_fieldName == nullptr) return "";
		return *m_fieldName + ": " + returnEntryOne();
	case InfoField_Type::ift_labelValueMax:
		if (m_fieldName == nullptr) return "";
		return *m_fieldName + ": " + returnEntryOne() + "/" + returnEntryTwo();
	}
	return "";
}

string InformationField::returnEntryOne()
{
	switch (m_entry1Type)
	{
	case InfoField_EntryType::ifet_int:
		if (m_iEntry1 == nullptr) return "";
		return to_string(*m_iEntry1);
	case InfoField_EntryType::ifet_float:
		if (m_fEntry1 == nullptr) return "";
		return to_string(*m_fEntry1);
	case InfoField_EntryType::ifet_double:
		if (m_dEntry1 == nullptr) return "";
		return to_string(*m_dEntry1);
	case InfoField_EntryType::ifet_string:
		if (m_sEntry1 == nullptr) return "";
		return *m_sEntry1;
	case InfoField_EntryType::ifet_bool:
		if (m_bEntry1 == nullptr) return "";
		if(*m_bEntry1) return "True"; else return "False";
	}
	return "";
}

string InformationField::returnEntryTwo()
{
	switch (m_entry2Type)
	{
	case InfoField_EntryType::ifet_int:
		if (m_iEntry2 == nullptr) return "";
		return to_string(*m_iEntry2);
	case InfoField_EntryType::ifet_float:
		if (m_fEntry2 == nullptr) return "";
		return to_string(*m_fEntry2);
	case InfoField_EntryType::ifet_double:
		if (m_dEntry2 == nullptr) return "";
		return to_string(*m_dEntry2);
	case InfoField_EntryType::ifet_string:
		if (m_sEntry2 == nullptr) return "";
		return *m_sEntry2;
	case InfoField_EntryType::ifet_bool:
		if (m_bEntry2 == nullptr) return "";
		if (*m_bEntry1) return "True"; else return "False";
	}
	return "";
}