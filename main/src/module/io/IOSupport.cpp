#include "module/io/IOSupport.h"

const  short IOSupport::READ_STREAM=1;

const  short IOSupport::WRTITE_STREAM=2;

IOSupport::IOSupport(string fileName){
    this->fileName = fileName;
    this->ifs = nullptr;
    this->ofs = nullptr;
};
IOSupport::IOSupport(string fileName,short type,openmode &readmode){
    this->fileName = fileName;
    if(type==READ_STREAM){
        this->ifs =  new ifstream(fileName,readmode);
        this->readmode = readmode;
        this->ofs = nullptr;

    } else if(type==WRTITE_STREAM){
        this->ifs = nullptr;

        this->ofs = new ofstream(fileName,readmode);
        this->writemode = readmode;
    }

};
IOSupport::IOSupport(string fileName,openmode &readmode,openmode &writemode){
    this->fileName = fileName;
    this->ifs = new ifstream(fileName,readmode);
    this->readmode = readmode;

    this->ofs = new ofstream(fileName,writemode);
    this->writemode = writemode;

};


bool IOSupport::good(short type){

};

void IOSupport::readOpen(openmode &readmode){

};

void IOSupport::writeOpen(openmode &writemode){

};

string IOSupport::readLine(){

};

vector<string> IOSupport::readLines(){

};

bool IOSupport::writeLine(const string& data){

};

bool IOSupport::writeLines(const vector<string>& data){

};

bool IOSupport::refresh(){

};

bool IOSupport::closeAll(){

};

bool IOSupport::close(short type){

};

bool IOSupport::clearAll(){

};

bool IOSupport::clear(short type){

};

std::fpos<mbstate_t> IOSupport::tell(short type){

};

void IOSupport::seek(short type ,std::fpos<mbstate_t> offset, seekdir seekdir){

};

~IOSupport::IOSupport(){

};