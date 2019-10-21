#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <fstream>
int main()
{
    //LPWSTR szCurrentPath = NULL;
    char szFilePath[MAX_PATH + 1]={0};  
    GetModuleFileNameA(NULL, szFilePath, MAX_PATH);  
    (strrchr(szFilePath, '\\'))[0] = 0; // 删除文件名，只获得路径字串  
    //std::string result("file://");
    std::string result = "";
    result.append(szFilePath);
    result.append("\\experiments\\algorithmTesting\\finalAnalysisReport.txt");
    // printf(result.c_str());

    int b = 1000000;      // data block size , !<10000
    int s = 10;         // stream num, every stream is a block ( b )
    int t = 1;          // data type 0 - ascii , 1 - binary
    std::string f = "all.bin";
    char assess[1024] = { 0 };
    sprintf(assess, "assess.exe %d %s %d %d", b, f.c_str(), s, t);
    system(assess);
    // system(result.c_str());

    int state = 0;
    char readBuf[1024] = {0};
    std::ifstream read(result.c_str());
    while(read.getline(readBuf,1024))
    {
        std::string tmp(readBuf);
        if(tmp.find("*") != std::string::npos)
        {
            state = 1;
            break;
        }
    }
    if(state)
    {
        printf("err\n");
        system(result.c_str());
    }
    else
        printf("done\n");

    read.close();
    //system("D://a.cer");
    return 0;
}