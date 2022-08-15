#ifndef COMMONUTIL_H
#define COMMONUTIL_H

#include <QString>

class CommonUtil {
public:
    // 格式化数字，前面补0
    static QString formatNum(int num);

    // 格式化歌曲时长
    static QString formatDuration(int duration);
    //
};

#endif // COMMONUTIL_H
