#ifndef SPLIT_H
#define SPLIT_H


#include "Sequence.h"
using namespace std;

template <typename Key, typename Info>
int Split (const Sequence<Key, Info> &source, int start,
           Sequence<Key, Info> &result1, int step1,
           Sequence<Key, Info> &result2, int step2)
{
    if(source.size()<=0)
    {
        throw invalid_argument("Empty source!");
        return 0;
    }
    if(start<0||start>=source.size())
    {
        throw invalid_argument("Wrong range! Wrong start parameter!");
        return 0;
    }
    if (step1<0||step2<0)
    {
        if(step1<0) throw invalid_argument("Negative argument for step1!");
        if(step2<0) throw invalid_argument("Negative argument for step2!");
        return 0;
    }


    int iterPosition = 0;
    typename Sequence<Key, Info>::Iterator iter=source.begin();
    typename Sequence<Key, Info>::Iterator iterEnd=source.end();

    while((iterPosition!=start)&&(iter!=iterEnd))
    {
        iterPosition++;
        iter++;
    }
    while (iter!=iterEnd)
    {

        for (int i=0; i<step1; i++)
        {
            if(iter==iterEnd) break;
            result1.pushBack(iter.showKey(), iter.showInfo());
            iter++;
        }
        for (int i=0; i<step2; i++)
        {
            if(iter==iterEnd) break;
            result2.pushBack(iter.showKey(), iter.showInfo());
            iter++;
        }
    }

    return source.size() - start;

}

#endif // SPLIT_H
