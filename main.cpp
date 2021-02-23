#include <iostream>
#include <ctime>
#include <unistd.h>
#include <set>
using namespace std;

string gen_random(const int len) {
    
    string tmp_s;
    static const char zerone[] ="01";
    
    srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) 
        tmp_s += zerone[rand() % (sizeof(zerone) - 1)];
    
    
    return tmp_s;
    
}

int *getMaxSequenceIndex(string s,char c)
{
    cout<< __func__<<":"<< endl;
    int * pointerToMaxSequence;
    pointerToMaxSequence = new int;
    // int pointerToMaxSequence;
    set <int>setmaxs;
    int counter = 0 ;
    int i;
    for (i=0; i<s.length();i++)
    {
        if(s[i]==c)
        {
            int j ;
            counter ++ ;
            for(j=i+1;j<s.length();j++)
            {
                if(s[j]!=c)
                {
                    setmaxs.insert(counter);
                    counter = 0 ;
                    break;
                }
                else
                    counter ++ ;
            }
        }
    }
    if(!setmaxs.empty())
    {
        *pointerToMaxSequence=*(setmaxs.end());      
    }
    return pointerToMaxSequence ;
}

int main(int argc, char *argv[]) {
    
    // cout << gen_random(20) << endl;
    // string s="01010111101001101101";
    string s= gen_random(20);
    cout << s << endl;
    cout <<*getMaxSequenceIndex(s,'1')<<endl;
    cout <<*getMaxSequenceIndex(s,'0')<<endl;
    return 0;
}