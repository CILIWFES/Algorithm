#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
typedef std::_Ios_Openmode openmode;
typedef std::_Ios_Seekdir seekdir;
using std::ifstream,std::ofstream,std::vector,std::string,std::endl,std::cout;

class IOSupport {
public:
    const static short READ_STREAM;
    const static short WRTITE_STREAM;
    IOSupport(string fileName);
    IOSupport(string fileName,short type,openmode& mode);
    IOSupport(string fileName,openmode& readmode,openmode& writemode);

    /**
     * 验证流是否有效
     * @param type
     * @return
     */
    bool good(short type);

    /**
     * 重建/新建输入流
     */
    void readOpen(openmode& readmode);

    /**
     * 重建/新建 输出流
     */
    void writeOpen(openmode& writemode);


    /**
     * 读取一行
     */
    string readLine();

    /**
     * 读取所有行
     */
    vector<string> readLines();

    /**
     * 写入一行
     */
    bool writeLine(const string& data);

    /**
     * 写入列表
     */
    bool writeLines(const vector<string>& data);

    /**
     * 刷新缓存
     */
    bool refresh();

    /**
     * 关闭流
     * @return
     */
    bool closeAll();

    /**
     * 通过类型关闭流
     * @param type
     * @return
     */
    bool close(short type);


    /**
     * 清空所有流
     * @return
     */
    bool clearAll();

    /**
     * 清空流
     * @param type
     * @return
     */
    bool clear(short type);

    /**
     * 返回流当前位置
     * @param type
     * @return
     */
    std::fpos<mbstate_t> tell(short type);
    //

    /**
     * 设置流偏移
     * @param type
     * @param offset 偏移量
     * @param seekdir 偏移方向
     * @return
     */
    void seek(short type ,std::fpos<mbstate_t> offset,seekdir seekdir);

    ~IOSupport();

protected:
    string fileName;
    ifstream *ifs;
    ofstream *ofs;
    openmode readmode;
    openmode writemode;

};

