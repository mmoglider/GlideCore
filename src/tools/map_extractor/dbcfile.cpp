#define _CRT_SECURE_NO_DEPRECATE

#include "dbcfile.h"

DBCFile::DBCFile(HANDLE file) :
    _file(file), _data(NULL), _stringTable(NULL)
{
}

bool DBCFile::open()
{
    char header[4];
    unsigned int na, nb, es, ss;

    DWORD readBytes = 0;
    SFileReadFile(_file, header, 4, &readBytes, NULL);
    if (readBytes != 4)
	{                                         // Number of records
        return false;
		printf("Error at 1", _file);
	}

    if (header[0] != 'W' || header[1] != 'D' || header[2] != 'B' || header[3] != 'C')
	{
        return false;
		printf("Error at 2", _file);
	}
    SFileReadFile(_file, &na, 4, &readBytes, NULL);
    if (readBytes != 4)
	{                                         // Number of records
        return false;
		printf("Error at 3", _file);
	}

    SFileReadFile(_file, &nb, 4, &readBytes, NULL);
    if (readBytes != 4)
	{                                         // Number of records
        return false;
		printf("Error at 4", _file);
	}

    SFileReadFile(_file, &es, 4, &readBytes, NULL);
    if (readBytes != 4)
	{                                         // Number of records
        return false;
		printf("Error at 5", _file);
	}

    SFileReadFile(_file, &ss, 4, &readBytes, NULL);
    if (readBytes != 4)
	{                                         // Number of records
        return false;
		printf("Error at 6", _file);
	}

    _recordSize = es;
    _recordCount = na;
    _fieldCount = nb;
    _stringSize = ss;
    if (_fieldCount * 4 != _recordSize)
    {                                         // Number of records
        return false;
		printf("Error at 7", _file);
	}

    _data = new unsigned char[_recordSize * _recordCount + _stringSize];
    _stringTable = _data + _recordSize*_recordCount;

    size_t data_size = _recordSize * _recordCount + _stringSize;
    SFileReadFile(_file, _data, data_size, &readBytes, NULL);
    if (readBytes != data_size)
	{                                         // Number of records
        return false;
		printf("Error at 8");
	}

    return true;
}

DBCFile::~DBCFile()
{
    delete [] _data;
}

DBCFile::Record DBCFile::getRecord(size_t id)
{
    assert(_data);
    return Record(*this, _data + id*_recordSize);
}

size_t DBCFile::getMaxId()
{
    assert(_data);

    size_t maxId = 0;
    for(size_t i = 0; i < getRecordCount(); ++i)
        if (maxId < getRecord(i).getUInt(0))
            maxId = getRecord(i).getUInt(0);

    return maxId;
}

DBCFile::Iterator DBCFile::begin()
{
    assert(_data);
    return Iterator(*this, _data);
}

DBCFile::Iterator DBCFile::end()
{
    assert(_data);
    return Iterator(*this, _stringTable);
}
