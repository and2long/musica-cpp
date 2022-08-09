#include "CommonUtil.h"
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

QString CommonUtil::formatNum(int num)
{
    if (num >= 100)
    {
        return QString::number(num);
    }
    stringstream s;
    s << setw(2) << setfill('0') << num;
    string ss;
    s >> ss;
    return QString::fromStdString(ss);
}

QString CommonUtil::formatDuration(int duration)
{
    int d = duration / 1000;
    int min = d / 60;
    int sec = d % 60;

    stringstream minss;
    minss << setw(2) << setfill('0') << min;
    string mins;
    minss >> mins;
    stringstream secss;
    secss << setw(2) << setfill('0') << sec;
    string secs;
    secss >> secs;

    return QString::fromStdString(mins.append(":").append(secs));
}
