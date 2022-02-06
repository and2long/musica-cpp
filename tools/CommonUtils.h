#ifndef COMMONUTILS_H
#define COMMONUTILS_H
#include <QString>

class CommonUtils
{
public:
    CommonUtils();
    // 格式化数字，前面补0
    static QString formatNum(int num);
    // 格式化歌曲时长
    static QString formatDuration(int duration);
};
#endif // COMMONUTILS_H
