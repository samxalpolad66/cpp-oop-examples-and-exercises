#include<iostream>
#include<string>
using namespace std;

class DataStorage {
    public:
    virtual ~DataStorage() {}  
    virtual void storeData(string data) = 0;
    virtual string retrieveData() = 0;
};

class FileStorage : public DataStorage {
    private:
    string fileData;
    
    public:
    void storeData(string data) override {
        fileData = data;
        cout << "using file: " << data << endl;
    }
    string retrieveData() override {
        return fileData;
    }
    ~FileStorage() {
        cout << "FileStorage Destructor" << endl;
    }
};

class DatabaseStorage : public DataStorage {
    private:
    string dbData;
    
    public:
    void storeData(string data) override {
        dbData = data;
        cout << "using database: " << data << endl;
    }
    string retrieveData() override {
        return dbData;
    }
    ~DatabaseStorage() {
        cout << "DatabaseStorage Destructor" << endl;
    }
};

int main() {
    FileStorage fileStorage;
    fileStorage.storeData("FileStorage Data");
    cout << "FileStorage: " << fileStorage.retrieveData() << endl;

    DatabaseStorage databaseStorage;
    databaseStorage.storeData("DatabaseStorage Data");
    cout << "DatabaseStorage: " << databaseStorage.retrieveData() << endl;
}
