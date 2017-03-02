char* StrStr(const char *str, const char *target) {
    if(!*target)
        return str;
    char *p1 = (char*)str;
    while(*p1){
        char *pbegin = p1,*p2 = target;
        while(*p1 && *p2 && *p1 == *p2){
            p1++;
            p2++;
        }
        if(!*p2)
            return pbegin;
        else{
            p1 = pbegin + 1;
        }
    }
    return nullptr;
}