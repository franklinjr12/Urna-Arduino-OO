#ifndef DATABASE_H
#define DATABASE_H
class Database{
private:
    unsigned int dataSize;
    unsigned int dataPointer[dataSize];
    char* char[dataSize];
public:
    virtual void writeData(char* data) = 0;
    virtual char* getData(int id) = 0;
    virtual char* listData() = 0;
    //virtual void eraseData(int startPoint, int endPoint) = 0;
};

class DatabaseFactory{
public:
    Database* createDatabase();
};
#endif // DATABASE_H
